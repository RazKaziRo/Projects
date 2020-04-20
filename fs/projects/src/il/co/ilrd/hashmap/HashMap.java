package il.co.ilrd.hashmap;

import java.util.AbstractCollection;
import java.util.AbstractSet;
import java.util.ArrayList;
import java.util.Collection;
import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import il.co.ilrd.pair.Pair; 

public class HashMap<K,V> implements Map<K, V>{ 

	private List<List<Map.Entry<K, V>>> hashMap;
	private final int capacity;
	private final static int DEFAULT_CAPACITY = 16; 
	private Set<Map.Entry<K, V>> entrySet;
	private Set<K> keySet;
	protected int modCount = 0;
	
	public HashMap() {
		
		this(DEFAULT_CAPACITY);
	};
	
	public HashMap(int capacity) { 
		
		this.capacity = capacity;
		hashMap = new ArrayList<List<Map.Entry<K,V>>>();
		for(int i = 0; i < capacity; ++i) {
			hashMap.add(new LinkedList<Map.Entry<K,V>>());
		}
	};
	
	@Override
	public void clear() {
		for(List<Map.Entry<K, V>> element : hashMap) {
			element.clear();
		}
		++modCount;
	}
	
	@Override
	public boolean containsKey(Object key) {
		List<Map.Entry<K, V>> internalList = hashMap.get(getBucket(key));
		for(Map.Entry<K, V> element: internalList) {
			if(key == null || element.getKey().equals(key)) {
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean containsValue(Object value) {
		
		for(V v : values()) {
			if(v.equals(value)) {
				return true;
			}
		}
		
		return false;
	}

	@Override
	public Set<Entry<K, V>> entrySet() {
		if(entrySet == null) {
			entrySet = new EntrySet();
		}
		
		return entrySet;
	}

	@Override
	public V get(Object key) {
		
		Map.Entry<K, V> pair = getEntry(key);
		
		if(pair != null) {
			return pair.getValue();
		}
		
		return null;
	}

	@Override
	public boolean isEmpty() {
		return size() ==  0;
	}

	@Override
	public Set<K> keySet() {
		if(keySet == null) {
			keySet = new KeySet();
		}
		
		return keySet;
	}

	@Override
	public V put(K key, V value) {
		
		if(containsKey(key)) {
			Entry<K, V> pair = getEntry(key);
			
			if(pair != null) {
				return pair.setValue(value);
			}
		}
		
		hashMap.get(getBucket(key)).add(Pair.of(key, value));
		++modCount;
		
		return null;
	}

	@Override
	public void putAll(Map<? extends K, ? extends V> m) {
		
		for(Map.Entry<? extends K, ? extends V> element : m.entrySet()) {
			this.put(element.getKey(), element.getValue());
		}
		
		++modCount;
	}

	@Override
	public V remove(Object key) {
		
		V valueHolder = null;
		
		if(containsKey(key)) {
			Map.Entry<K, V> pair = getEntry(key);
			valueHolder = pair.getValue();
			hashMap.get(getBucket(key)).remove(pair);
		}
		
		++modCount;
		
		return valueHolder;

	}

	@Override
	public int size() {

		int count = 0;
		for(List<Map.Entry<K, V>> bucket : hashMap) {
			count +=  bucket.size();
		}
		
		return count;
	}

	@Override
	public Collection<V> values() {
		return new ValueSet();
	}
	
	
	private int getBucket(Object key) {
		if(key == null) {
			return 0;
		}
		
		return key.hashCode() % capacity;
	}


	private Entry<K, V> getEntry(Object key){
		
		for(Entry<K, V> pair : this.hashMap.get(getBucket(key))) {
			if(pair.getKey() == null || pair.getKey().equals(key)) {
				return pair;
			}
		}
		
		return null;
	}

	
	private class EntrySet extends AbstractSet<Map.Entry<K, V>>{
		
		int expectedModCount = modCount;
		
		@Override
		public Iterator<Entry<K, V>> iterator() {
			return new EntryIterator();
		}

		@Override
		public int size() {
			return HashMap.this.size();
		}
		
		private class EntryIterator implements Iterator<Entry<K,V>>{
			
			Iterator<List<Map.Entry<K, V>>> externalIter = hashMap.iterator();
			Iterator<Map.Entry<K, V>> internalIter = externalIter.next().iterator();
			
			public EntryIterator() {
				while(!internalIter.hasNext() && externalIter.hasNext()) {
					internalIter = externalIter.next().iterator();
				}
			}
			
			@Override
			public boolean hasNext() {
				if(expectedModCount != modCount) {
					throw new ConcurrentModificationException();
				}
				
				return(internalIter.hasNext() || externalIter.hasNext());	
			}

			@Override
			public Entry<K,V> next() {
				Map.Entry<K, V> entry = internalIter.next();
				while(!internalIter.hasNext() && externalIter.hasNext()) {
					internalIter = externalIter.next().iterator();
				}
				
				return entry;
			}
		}
	}
	
	private class KeySet extends AbstractSet<K> implements Iterator<K> {
		
		private Iterator<Map.Entry<K, V>> iter = new EntrySet().iterator();		
		
		@Override
		public boolean hasNext() {
			return iter.hasNext();
		}

		@Override
		public K next() {
			return iter.next().getKey();
		}

		@Override
		public Iterator<K> iterator() {
			return new KeySet();
		}

		@Override
		public int size() {
			return HashMap.this.size();
		}
		
	}
	
	private class ValueSet extends AbstractCollection<V> implements Iterator<V> {

		private Iterator<Map.Entry<K, V>> iter = new EntrySet().iterator();		
		
		@Override
		public boolean hasNext() {
			return iter.hasNext();
		}

		@Override
		public V next() {
			return iter.next().getValue();
		}

		@Override
		public Iterator<V> iterator() {
			return new ValueSet();
		}

		@Override
		public int size() {
			return HashMap.this.size();
		}
		
	}
}

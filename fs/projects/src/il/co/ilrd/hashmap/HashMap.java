package il.co.ilrd.hashmap;

import java.util.AbstractCollection;
import java.util.AbstractSet;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

import il.co.ilrd.pair.Pair; 

public class HashMap<K,V> implements Map<K, V>{ 

	private List<List<Pair<K, V>>> hashMap;
	private final int capacity;
	private final static int DEFAULT_CAPACITY = 16; 
	private Set<Map.Entry<K, V>> entrySet;
	private Set<K> keySet;
	protected int mode = 0;
	
	public HashMap() {
		this(DEFAULT_CAPACITY);
	};
	
	public HashMap(int capacity) { 
		this.capacity = capacity;
		//....TBD
	};
	
	@Override
	public void clear() {
		
	}
	
	@Override
	public boolean containsKey(Object key) {
		return false;
	}

	@Override
	public boolean containsValue(Object value) {
		return false;
	}

	@Override
	public Set<Entry<K, V>> entrySet() {
		return null;
	}

	@Override
	public V get(Object key) {
		return null;
	}

	@Override
	public boolean isEmpty() {
		return false;
	}

	@Override
	public Set<K> keySet() {
		return null;
	}

	@Override
	public V put(K key, V value) {
		return null;
	}

	@Override
	public void putAll(Map<? extends K, ? extends V> m) {
		
	}

	@Override
	public V remove(Object key) {
		return null;
	}

	@Override
	public int size() {
		return 0;
	}

	@Override
	public Collection<V> values() {
		return null;
	}
	
	private class EntrySet extends AbstractSet<Map.Entry<K, V>>{

		@Override
		public Iterator<Entry<K, V>> iterator() {
			return new EntryIterator();
		}

		@Override
		public int size() {
			return 0;
		}
		
		private class EntryIterator implements Iterator<Map.Entry<K, V>>{

			@Override
			public boolean hasNext() {
				return false;
			}

			@Override
			public Entry<K, V> next() {
				return null; 
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
		public Iterator iterator() {
			return null;
		}

		@Override
		public int size() {
			return HashMap.this.size();
		}
		
	}
	
	private class ValueCollection extends AbstractCollection<V> implements Iterator<V> {

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
			return null;
		}

		@Override
		public int size() {
			return HashMap.this.size();
		}
		
	}
}

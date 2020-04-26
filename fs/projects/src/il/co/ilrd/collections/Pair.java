package il.co.ilrd.collections;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class Pair<K, V> implements Map.Entry<K, V>{
	
	private K key;
	private V value;
	
	private Pair(K key, V value) {
		this.key = key;
		this.value = value;
	}
	
	public static <K, V> Pair<K, V> of (K key, V value) {
		return new Pair<K, V>(key, value);
	}

	public static <K, V> Pair<V, K> swap (Pair<K, V> pair) {
		return of(pair.getValue(), pair.getKey());
	}

	/*public K setKey(K key) {
		K keyHolder = getKey();
		this.key = key;
		return keyHolder;
	}*/

	@Override
	public K getKey() {
		return key;
	}
	
	@Override
	public V getValue() {
		return value;
	}
	
	@Override
	public V setValue(V value) {
		V valueHolder = getValue();
		this.value = value;
		return valueHolder;
	}

	@Override
	public String toString() {
		return "Pair [Key = " + key + ", Value = " + value + "]";
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((key == null) ? 0 : key.hashCode());
		result = prime * result + ((value == null) ? 0 : value.hashCode());
		return result;
	}
	
	//read hashcode + equals - effective java
	
	//
	@Override
	public boolean equals(Object obj) {
		
		if (this == obj)
			return true;
		
		if(!(obj instanceof Pair)) {
			return false;
		}
		
		Pair<?, ?> other = (Pair<?, ?>) obj;
		if (key == null) {
			if (other.key != null)
				return false;
		} else if (!key.equals(other.key))
			return false;
		if (value == null) {
			if (other.value != null)
				return false;
		} else if (!value.equals(other.value))
			return false;
		return true;
	}

	private static class comparableToComparator<T extends Comparable<T>> implements Comparator<T>{
		@Override
		public int compare(T arg0, T arg1) {
			return arg0.compareTo(arg1); 
		}
	}
	
	public static<T extends Comparable<T>> Pair<T, T> minMax(T[] array) {
		comparableToComparator<T> comp = new comparableToComparator<T>();
		return minMax(array, comp);
	}
		
	public static <T> Pair<T, T> minMax(T[] array, Comparator<T> cmp) {
		T max = null; 
		T min = null;
		
		if (array.length < 1 | array == null) {
			throw new NullPointerException();
		}
		
		if (array.length == 1) {
			return new Pair<T, T>(array[0], array[0]);
		}
		
		if (0 < cmp.compare(array[0], array[1])) {
			
			max = array[0];
			min = array[1];
		}
		
		else {
			max = array[1];
			min = array[0];
		}

		for (int i = 2; i <= array.length - 2 ; i += 2) {
			
			if (cmp.compare(array[i], array[i+1]) > 0){
				
				if (cmp.compare(array[i], max) > 0) {
					max = array[i];
				}
				if (cmp.compare(array[i+1], min) < 0) {
					
					min = array[i+1];
				}
			}
			
			else {
				
				if (cmp.compare(array[i+1], max) > 0) {
					max = array[i + 1];
				}
				
				if (cmp.compare(array[i],min) < 0) {
					min = array[i];
				}
			}	
		}
		
		if (array.length % 2 == 1) {
			
			if (cmp.compare(min, array[array.length - 1]) > 0){
				min = array[array.length - 1];
			}
			
			if (cmp.compare(max, array[array.length - 1]) < 0 ) {
				max = array[array.length - 1];
			}
			
		}
		return new Pair<T, T>(min, max);
	}	
}

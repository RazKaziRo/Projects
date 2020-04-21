package il.co.ilrd.factory;

import java.util.Map;
import java.util.function.Function;

import il.co.ilrd.hashmap.HashMap;

public class Factory<K,T,D>{
	
	Map<K, Function<D, ? extends T>> map_types = new HashMap<K, Function<D, ? extends T>>();
	
	public void add(K key, Function<D, ? extends T> ctorFunc) {
		map_types.put(key, ctorFunc);
	}
	
	public T create(K key, D data){
		return map_types.get(key).apply(data);
		
	}
	
	class Functions{
		
	}

	public static void main(String[] argv) {
		
		
		Function<Integer, Double> half = a -> a / 2.0;
		Function<Integer, Integer> multiplay2 = a-> a * 2;
		
		Factory<String, Object, Integer> f = new Factory<>();
		f.add("Half", half);
		f.add("Multi", multiplay2);
		
		System.out.println(f.create("Half", 10));
		System.out.println(f.create("Multi", 10));

		
		
		
	}
}

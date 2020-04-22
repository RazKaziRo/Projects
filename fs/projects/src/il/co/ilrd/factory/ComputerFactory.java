package il.co.ilrd.factory;

import java.util.Map;
import il.co.ilrd.hashmap.HashMap;

public class ComputerFactory<K, W, V, U, R> { 

	//K - Key
	//R - Computer
	//U - Ram
	//V - HDD
	//W - CPU
	
	Map<K, ThreeParameterFunction<U, V, W, R>> map_types = new HashMap<>(4);
	public void add(K key, ThreeParameterFunction<U,V,W, R> ctorFunc) {
		map_types.put(key, ctorFunc);
	}
	
	public R create(K key,U ram ,V hdd ,W cpu){
		return map_types.get(key).apply(ram, hdd, cpu);
		
	}

}
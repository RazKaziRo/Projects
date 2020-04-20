package il.co.ilrd.hashmap;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Collection;
import java.util.Map;
import java.util.Set;

import org.junit.jupiter.api.Test;

class HashMapTest {
	@Test
    void testPut() {
        HashMap<Integer, Integer> hash_Map3 = new HashMap<Integer, Integer>();
        hash_Map3.put(1, 10);
        hash_Map3.put(2, 20);
        hash_Map3.put(3, 30);
        hash_Map3.put(4, 40);
        System.out.println(hash_Map3.keySet());
        Set<Integer> s = hash_Map3.keySet();
        assertEquals(4,s.size());
        assertTrue(s.iterator().hasNext());

        System.out.println(hash_Map3.values());
        Collection<Integer> c = hash_Map3.values();
        System.out.println(c.iterator().getClass()); //interesting//

        System.out.println(hash_Map3.entrySet());
        Set<Integer> s2 = hash_Map3.keySet();
        assertEquals(4,s2.size());

        hash_Map3.put(4, 400);
        assertEquals(4,hash_Map3.size());
        System.out.println(hash_Map3.values());
        hash_Map3.remove(4);
        System.out.println(hash_Map3.values());

        assertNull(hash_Map3.put(null, 99));
        System.out.println(hash_Map3.values());

        assertNull(hash_Map3.put(4, 15));
        System.out.println(hash_Map3.values());

        System.out.println(hash_Map3.values());
        assertEquals((Integer)10, hash_Map3.put(1, 8));
    }
	
	@Test
	void testHashMapPut() {
		HashMap<String, Integer> hashMap = new HashMap<String, Integer>(6);
		
		hashMap.put("A", null);
		hashMap.put("B", null);
		hashMap.put("C", 30);
		hashMap.put("D", 40);
		hashMap.put(null, 50);
		hashMap.put(null, 60);
		
		for(Map.Entry<String, Integer> element : hashMap.entrySet()) {
			System.out.println("Element: " +  element);
		}
				
		for(Integer element : hashMap.values()) {
			System.out.println("Values: " +  element);
		}
		
		for(String element : hashMap.keySet()) {
			System.out.println("Key: " +  element);
		}
		
	}
	@Test
	void testHashMapRemove() {
		HashMap<String, Integer> hashMap = new HashMap<String, Integer>(6);
		assertEquals(0, hashMap.size());

		hashMap.put("A", null);
		hashMap.put("B", null);
		hashMap.put("C", 30);
		hashMap.put("D", 40);
		hashMap.put(null, 50);
		hashMap.put(null, 60);
		assertEquals(5, hashMap.size());

		hashMap.remove("A");
		assertEquals(4, hashMap.size());		
	}
	
	@Test
	void testHashMapClear() {
		HashMap<String, Integer> hashMap = new HashMap<String, Integer>(4);
		hashMap.put("A", 10);
		hashMap.put("B", 20);
		assertEquals(20, hashMap.put("B", 21));
		hashMap.put("C", 30);
		hashMap.put("D", 40);		
		assertEquals(false, hashMap.isEmpty());
		assertEquals(4, hashMap.size());
		hashMap.clear();
		assertEquals(0, hashMap.size());
		assertEquals(true, hashMap.isEmpty());
	}
	
	@Test
	void testHashMapPutAll() {
		
		HashMap<String, Integer> hashMap = new HashMap<String, Integer>(4);
		hashMap.put("A", 10);
		hashMap.put("B", 20);
		hashMap.put("C", 30);
		hashMap.put("D", 40);
		HashMap<String, Integer> copyHashMap = new HashMap<String, Integer>(4);
		assertEquals(0, copyHashMap.size());
		copyHashMap.putAll(hashMap);
		assertEquals(4, copyHashMap.size());

	}
	
	@Test
	void testGetValue() {
		HashMap<String, Integer> hashMap = new HashMap<String, Integer>(4);
		hashMap.put("A", 10);
		hashMap.put("B", 20);
		hashMap.put("C", 30);
		hashMap.put("D", 40);
		assertEquals(10, hashMap.get("A"));
		assertEquals(20, hashMap.get("B"));
		assertEquals(30, hashMap.get("C"));
		assertEquals(40, hashMap.get("D"));
		assertEquals(null, hashMap.get("E"));		
	}
	
	@Test
	void testHashMapSize() {
		HashMap<String, Integer> hashMap = new HashMap<String, Integer>(6);
		
		hashMap.put("A", null);
		hashMap.put("B", null);
		hashMap.put("C", 30);
		hashMap.put("D", 40);
		hashMap.put(null, 50);
		hashMap.put(null, 60);
		
		assertEquals(5, hashMap.entrySet().size());
		assertEquals(5, hashMap.entrySet().size());
		assertEquals(5, hashMap.keySet().size());
		assertEquals(5, hashMap.values().size());

	}
	

	

}

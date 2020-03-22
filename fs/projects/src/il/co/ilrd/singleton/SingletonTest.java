package il.co.ilrd.singleton;

import static org.junit.Assert.*;

import org.junit.Test;

public class SingletonTest {

	@Test
	public void ClassicTest() {
		
		Classic singleton1 = Classic.getInstance();
		Classic singleton2 = Classic.getInstance();
		Classic singleton3 = Classic.getInstance();

		assertEquals(singleton1, singleton2);
		assertEquals(singleton1, singleton3);	
		System.out.println("Singleton 1 HashCode: " + singleton1.hashCode());
		System.out.println("Singleton 2 HashCode: " + singleton2.hashCode());
		System.out.println("Singleton 3 HashCode: " + singleton3.hashCode());
		System.out.println();
	}
	
	@Test 
	public void DoubleCheckTest() {
		
		DoubleCheck singleton1 = DoubleCheck.getSingleton();
		DoubleCheck singleton2 = DoubleCheck.getSingleton();
		DoubleCheck singleton3 = DoubleCheck.getSingleton();
		
		assertEquals(singleton1, singleton2);
		assertEquals(singleton1, singleton3);	
		
		System.out.println("DoubleCheck Singleton 1 HashCode: " + singleton1.hashCode());
		System.out.println("DoubleCheck Singleton 2 HashCode: " + singleton2.hashCode());
		System.out.println("DoubleCheck Singleton 3 HashCode: " + singleton3.hashCode());
		System.out.println();

	}
	
	@Test 
	public void UltimateTest() {
		
		Ultimate singleton1 = Ultimate.getInstance();
		Ultimate singleton2 = Ultimate.getInstance();
		Ultimate singleton3 = Ultimate.getInstance();
		
		assertEquals(singleton1, singleton2);
		assertEquals(singleton1, singleton3);
		
		System.out.println("Ultimate Singleton 1 HashCode: " + singleton1.hashCode());
		System.out.println("Ultimate Singleton 2 HashCode: " + singleton2.hashCode());
		System.out.println("Ultimate Singleton 3 HashCode: " + singleton3.hashCode());
		System.out.println();
	}

}

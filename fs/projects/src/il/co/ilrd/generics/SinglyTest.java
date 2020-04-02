package il.co.ilrd.generics;

import static org.junit.Assert.assertEquals;
import static org.junit.jupiter.api.Assertions.*;

import java.util.Iterator;

import org.junit.jupiter.api.Test;

import il.co.ilrd.singly_linked_list.ListIterator;
import il.co.ilrd.singly_linked_list.SinglyLinkedList;


class SinglyTest {

	@Test
	public void testSize() {
		
		Singly<Integer> sllOfIntegers = new Singly<Integer>();
		Singly<Character> sllOfCharacters = new Singly<Character>();
		
		assertEquals("FAIL: SIZE 0 ", sllOfIntegers.size(), 0);
		assertEquals("FAIL: SIZE 0 ", sllOfCharacters.size(), 0);

		int j = 1;
		for(Character i = 'a'; i <= 'z'; ++i , ++j) {
			
			sllOfCharacters.pushFront(i);
			
			assertEquals("FAIL: AT SIZE " + j, sllOfCharacters.size(), j);
		}
		
		Singly.printSingly(sllOfCharacters);

		
		for(int i = 1; i <= 1000; ++i) {
			
			sllOfIntegers.pushFront(i);
			
			assertEquals("FAIL: AT SIZE " + i, sllOfIntegers.size(), i);
		}
		
		Singly.printSingly(sllOfIntegers);

		for(int i = 1000; i > 0; --i) {

			sllOfIntegers.popFront();
			
			assertEquals("FAIL: AT POP FRONT " + i, sllOfIntegers.size(), i - 1);
			
		}
		
		assertEquals("FAIL: SIZE 0 ", sllOfIntegers.size(), 0);
	}
	
	
	@Test
	public void testIsEmpty() {
		
		Singly<Integer> sllOfIntegers = new Singly<Integer>();
		Singly<String> sllOfStrings = new Singly<String>();
		
		assertEquals("FAIL: isEmpty: True ", sllOfIntegers.isEmpty(), true);
		assertEquals("FAIL: isEmpty: True ", sllOfStrings.isEmpty(), true);
	
		sllOfStrings.pushFront("String 1");
		sllOfStrings.pushFront("String 2");
		sllOfStrings.pushFront("String 3");
		sllOfStrings.pushFront("String 4");
		sllOfStrings.pushFront("String 5");
		sllOfStrings.pushFront("String 6");
		
		assertEquals("FAIL: isEmpty: False ", sllOfStrings.isEmpty(), false);
 		 
		for(int i = 1; i <= 1000; ++i) {
			
			sllOfIntegers.pushFront(i);
			
			assertEquals("FAIL: isEmpty: False ", sllOfIntegers.isEmpty(), false);

		}
		
		for(int i = 1000; i > 0; --i) {

			assertEquals("FAIL: isEmpty: False ", sllOfIntegers.isEmpty(), false);

			sllOfIntegers.popFront();
		}
		
		assertEquals("FAIL: isEmpty: True ", sllOfIntegers.isEmpty(), true);

	}
	
	@Test
	public void testFind() {
		
		Singly<Integer> sllOfIntegers = new Singly<Integer>();
		
		for(int i = 1; i <= 1000; ++i) {
			
			sllOfIntegers.pushFront(i);
			
		}
		Iterator<Integer> itrFinder = sllOfIntegers.find(1);
		System.out.println(itrFinder.next());

	}
	
	@Test 
	public void testReverse() {
		
		Singly<Integer> sllOfIntegers = new Singly<Integer>();

		for(int i = 1; i <= 1000; ++i) {
			
			sllOfIntegers.pushFront(i);
			
			assertEquals("FAIL: AT SIZE " + i, sllOfIntegers.size(), i);
		}
		
		Singly<Integer> ReveseSllOfIntegers = Singly.newReverse(sllOfIntegers);
		
		for(int i = 1000; i <= 1; --i) {
			
			assertEquals("FAIL: AT SIZE " + i, ReveseSllOfIntegers.popFront().compareTo(i), true);
		}
		
	}

}

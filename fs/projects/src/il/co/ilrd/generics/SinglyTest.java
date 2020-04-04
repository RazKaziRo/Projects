package il.co.ilrd.generics;

import static org.junit.Assert.assertEquals;
import static org.junit.jupiter.api.Assertions.*;

import java.util.ConcurrentModificationException;
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
		Iterator<Integer> itrFinder = sllOfIntegers.find(0);
		//System.out.println("FIND: " + itrFinder.next());

	}
	
	@Test 
	public void testReverse() {
		
		Singly<Integer> sllOfIntegers = new Singly<Integer>();
		
		Iterator<Integer> itr = sllOfIntegers.iterator();
		
		
		for(int i = 1; i <= 1000; ++i) {
			
			sllOfIntegers.pushFront(i);
			
			assertEquals("FAIL: AT SIZE " + i, sllOfIntegers.size(), i);
		}
		
		Singly<Integer> ReveseSllOfIntegers = Singly.newReverse(sllOfIntegers);
		
		for(int i = 1000; i <= 1; --i) {
			
			assertEquals("FAIL: AT SIZE " + i, ReveseSllOfIntegers.popFront().compareTo(i), true);
		}
		
	}
	
	@Test
	public void testMerge() {
		
		Singly<Integer> listA = new Singly<Integer>();
		Singly<Integer> listB = new Singly<Integer>();
		
		for(int i = 1; i <= 1000; ++i) {
			
			listA.pushFront(i);
			listB.pushFront(i + 1000);
		}
		
		Singly<Integer> listC = Singly.merge(listA, listB);
		
		for(int i = 2000; i <= 1; --i) {
			
		assertEquals("FAIL: AT SIZE " + i,listC.popFront().compareTo(i), true);

		}		
	}
	
	@Test 
	public void testFailFast() throws ConcurrentModificationException{
		
		Singly<Integer> listA = new Singly<Integer>();
		
		for(int i = 1; i <= 1000; ++i) {
			
			listA.pushFront(i);
			
		}
		
		try {
		for(Integer element : listA) {
			
			System.out.println("PushFront: " + element);
			if(element.equals(100)) {
				listA.pushFront(0);
			}
	
			}
		}
		catch(ConcurrentModificationException e){
			System.out.println(e);
		}
		
		try {
		for(Integer element : listA) {
			
			System.out.println("PopFront: " + element);
			if(element.equals(100)) {
				listA.popFront();
			}
	
			}
		}
		catch(ConcurrentModificationException e){
			System.out.println(e);
		}
		
		

		
	}

}

import static org.junit.Assert.*;

import org.junit.Test;

public class SinglyLinkedListTest {

	
	@Test
	public void testSize() {
		
		SinglyLinkedList sll = new SinglyLinkedList();

		assertEquals("FAIL: SIZE 0 ", sll.size(), 0);
		
		for(int i = 1; i <= 1000; ++i) {
			
			sll.pushFront(i);
			
			assertEquals("FAIL: AT SIZE " + i, sll.size(), i);
		}
		
		for(int i = 1000; i > 0; --i) {

			sll.popFront();
			
			assertEquals("FAIL: AT POP FRONT " + i, sll.size(), i - 1);
			
		}
		
		assertEquals("FAIL: SIZE 0 ", sll.size(), 0);
	}
	
	@Test
	public void testIsEmpty() {
		
		SinglyLinkedList sll = new SinglyLinkedList();
		
		assertEquals("FAIL: isEmpty: True ", sll.isEmpty(), true);
		
		for(int i = 1; i <= 1000; ++i) {
			
			sll.pushFront(i);
			
			assertEquals("FAIL: isEmpty: False ", sll.isEmpty(), false);

		}
		
		for(int i = 1000; i > 0; --i) {

			assertEquals("FAIL: isEmpty: False ", sll.isEmpty(), false);

			sll.popFront();
		}
		
		assertEquals("FAIL: isEmpty: True ", sll.isEmpty(), true);

	}
	
	@Test
	public void testFind() {
		
		SinglyLinkedList sll = new SinglyLinkedList();
		
		for(int i = 1; i <= 1000; ++i) {
			
			sll.pushFront(i);
			
		}
		ListIterator itrFinder = sll.find(1);
		System.out.println(itrFinder.next());


	}

}

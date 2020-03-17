import static org.junit.Assert.*;

import org.junit.Test;

public class VendingMachineTest {

/*	@Test
	public void testItems() {
		
		Item itemA = new Item("ItemA", 10.5, 3);
		
		assertEquals("itemA.getName()", itemA.getName(),"ItemA" );
		assertEquals("itemA.getQuantity()", itemA.getQuantity(), 3);

	}
	
	@Test
	public void testInventory() {
		
		Inventory invA = new Inventory();
		
		Item itemA = new Item("ItemA", 10, 1);
		Item itemB = new Item("ItemB", 20, 2);
		Item itemC = new Item("ItemC", 30, 3);
		
		invA.addItem(itemA);
		invA.addItem(itemB);
		invA.addItem(itemC);
		
		assertEquals("invA.getItemQuantity(itemA)", invA.getItemQuantity(itemA), 1, 10);
		invA.decreaseQuantity(itemA, 1);
		assertEquals("invA.decreaseQuantity(itemA, 1);", invA.getItemQuantity(itemA), 0, 10);
		assertEquals("invA.getItemPrice(itemB);", invA.getItemPrice(itemB), 20, 10);
		assertEquals("invA.getItemByName();", invA.getItemByName("ItemC"), itemC);
		
		assertEquals("invA.getItemQuantity(itemC);", invA.getItemQuantity(itemC), 3, 10);
		invA.increaseQuantity(itemC, 2);
		assertEquals("invA.getItemQuantity(itemC);", invA.getItemQuantity(itemC), 5, 10);

	
	}*/
	

	@Test
	public void testInitVendingMachine() {
		
		Inventory invA = new Inventory();
		Monitor monitor = new MonitorTest();
		
		Item itemA = new Item("ItemA", 10, 1);
		Item itemB = new Item("ItemB", 20, 2);
		Item itemC = new Item("ItemC", 30, 3);
		
		invA.addItem(itemA);
		invA.addItem(itemB);
		invA.addItem(itemC);
		
		VendingMachine venM = new VendingMachine(invA, monitor);
		
		assertEquals("venM.getCurrentBalance()", venM.getCurrentBalance(), 0, 0);
		assertEquals("venM.getItemPrice(itemA)", venM.getItemPrice(itemA), 10, 0);
		venM.insertCoin(11);
		assertEquals("venM.getCurrentBalance()", venM.getCurrentBalance(), 11, 0);
		assertEquals("venM.getTotalSales()", venM.getTotalSales(), 0, 10);
		venM.orderItem(itemA);
		assertEquals("venM.getCurrentBalance()", venM.getTotalSales(), 10, 0);
		assertEquals("venM.getCurrentBalance()", venM.getCurrentBalance(), 0, 0);
		venM.insertCoin(10);
		venM.orderItem(itemB);
		venM.insertCoin(5);
		venM.orderItem(itemB);
		venM.insertCoin(5);
		venM.orderItem(itemB);
		assertEquals("venM.getTotalSales()", venM.getTotalSales(), 30, 0);
		venM.insertCoin(5);
	}
	
	/*
	@Test
	public void testOrderItem() {
		fail("Not yet implemented");
	}

	@Test
	public void testGetState() {
		fail("Not yet implemented");
	}

	@Test
	public void testGetCurrentBalance() {
		fail("Not yet implemented");
	}

	@Test
	public void testGetTotalSales() {
		fail("Not yet implemented");
	}*/

}

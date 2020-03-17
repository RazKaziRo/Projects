package il.co.ilrd.vending_machine;


public class VendingMachine {
 	
    private double currentBalance; 
    private double totalSales;
	private Inventory itemInventory;
	private State state;
	Monitor monitorItr = null;

	VendingMachine(Inventory itemsInventory, Monitor monitorItr) {
		
	       state = State.INIT.stateInitialize(this, itemsInventory, monitorItr);
	}

	private enum State{

		INIT{
			
			protected State stateInitialize(VendingMachine vm, Inventory itemsInventory, Monitor monitorItr) {
				vm.setCurrentBalance(0);
				vm.setTotalSales(0);
				vm.setItemInventory(itemsInventory);
				vm.setMonitorItr(monitorItr);
				vm.monitorItr.write(Notifications.MACHINE_READY, null);
				return WAIT_FOR_COIN;
			}

			@Override
			protected State gotCoin(VendingMachine vm, double coin) {
				vm.monitorItr.write(Notifications.ERROR, null);
				return INIT;
			}

			@Override
			protected State gotOrder(VendingMachine vm, Item requestedItem) {
				vm.monitorItr.write(Notifications.ERROR, null);
				return INIT;
			}
		},
		
		WAIT_FOR_COIN{

			@Override
			protected State stateInitialize(VendingMachine vm, Inventory itemsInventory, Monitor monitorItr) {
				vm.monitorItr.write(Notifications.ERROR, null);
				return WAIT_FOR_COIN;
			}

			@Override
			protected State gotCoin(VendingMachine vm, double coin) {
				vm.setCurrentBalance(coin);
				vm.monitorItr.write(Notifications.NEW_BALANCE,  vm.currentBalance);
				return WAIT_FOR_ORDER;
				
			}

			@Override
			protected State gotOrder(VendingMachine vm, Item requestedItem) {
				vm.monitorItr.write(Notifications.INSERT_COINS, null);
				return WAIT_FOR_COIN;
			}
		},
		
		WAIT_FOR_ORDER{

			@Override
			protected State stateInitialize(VendingMachine vm, Inventory itemsInventory, Monitor monitorItr) {
				vm.monitorItr.write(Notifications.ERROR, null);
				return WAIT_FOR_ORDER;
			}

			@Override
			protected State gotCoin(VendingMachine vm, double coin) {
				vm.setCurrentBalance(coin);
				return WAIT_FOR_ORDER;
			}

			@Override
			protected State gotOrder(VendingMachine vm, Item requestedItem) {
				
				if(requestedItem.getQuantity() > 0) {
					if(requestedItem.getPrice() <= vm.getCurrentBalance()) {
						vm.monitorItr.write(Notifications.PLEASE_WAIT, null);
						vm.setTotalSales(requestedItem.getPrice());
						vm.returnChange(requestedItem.getPrice());
						vm.itemInventory.decreaseQuantity(requestedItem, 1);
						vm.monitorItr.write(Notifications.PURCHACE_SUCCES, requestedItem.getName());
					}
					else {
						vm.monitorItr.write(Notifications.MORE_COINS_NEEDED, requestedItem.getPrice() - vm.getCurrentBalance() + " Coins");
					}
				}
				else {
					vm.monitorItr.write(Notifications.ITEM_OUT_OF_STOCK, null);
				}
				return WAIT_FOR_COIN;
			}
		};

		protected abstract State stateInitialize(VendingMachine vm, Inventory itemsInventory, Monitor monitorItr);
		protected abstract State gotCoin(VendingMachine vm, double coin);
		protected abstract State gotOrder(VendingMachine vm, Item requestedItem);
	}
		
	public double getItemPrice(Item item) {

		return itemInventory.getItemPrice(item);
	}
	
	public void orderItem(Item requestedItem) {
		
		state = state.gotOrder(this, requestedItem);
	}
	
	private double returnChange(double requestedItemPrice) {
		
		double change = currentBalance - requestedItemPrice;
		currentBalance = 0;
		monitorItr.write(Notifications.CHANGE, change);
		return change;
	}
	
	private void setCurrentBalance(double currentBalance) {this.currentBalance += currentBalance;}
    private void setTotalSales(double totalSales) {this.totalSales += totalSales;}
	public double getCurrentBalance() {return currentBalance;}
	double getTotalSales() {return totalSales;} //for testing propose
	Inventory getItemInventory() {return itemInventory;} //for testing propose
	private void setItemInventory(Inventory itemInventory) {this.itemInventory = itemInventory;}
	private void setMonitorItr(Monitor monitorItr) {this.monitorItr = monitorItr;}
	public void insertCoin(double coin) {state = state.gotCoin(this, coin);}
    
}

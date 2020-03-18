package il.co.ilrd.vending_machine;

public class VendingMachine {
 	
    private double currentBalance; 
    private double totalSales;
	private Inventory itemInventory;
	private VedingMachineState state;
	private Monitor monitorItr;

	public VendingMachine(Inventory itemsInventory, Monitor monitorItr) {
		VedingMachineState.INIT.stateInitialize(this, itemsInventory, monitorItr);
	}
	
	public double getItemPrice(Item item) {
		return itemInventory.getItemPrice(item);
	}
	
	public void orderItem(Item requestedItem) {
		state.gotOrder(this, requestedItem);
	}
	
	private double returnChange(double requestedItemPrice) {
		double change = currentBalance - requestedItemPrice;
		resetCurrentBalance();
		monitorItr.write(Notifications.CHANGE, change);
		return change;
	}
	
	private void setCurrentBalance(double currentBalance) {this.currentBalance += currentBalance;}
	private void resetCurrentBalance() {currentBalance = 0;}
    private void setTotalSales(double totalSales) {this.totalSales += totalSales;}
	public double getCurrentBalance() {return currentBalance;}
	double getTotalSales() {return totalSales;} //for testing propose
	Inventory getItemInventory() {return itemInventory;} //for testing propose
	private void setItemInventory(Inventory itemInventory) {this.itemInventory = itemInventory;}
	private void setMonitorItr(Monitor monitorItr) {this.monitorItr = monitorItr;}
	public void insertCoin(double coin) {state.gotCoin(this, coin);}
	private void setState(VedingMachineState state) {this.state = state;}
	
	private enum VedingMachineState{
		INIT{
			
			protected void stateInitialize(VendingMachine vm, Inventory itemsInventory, Monitor monitorItr) {
				
				vm.resetCurrentBalance();
				vm.setTotalSales(0);
				vm.setItemInventory(itemsInventory);
				vm.setMonitorItr(monitorItr);
				vm.monitorItr.write(Notifications.MACHINE_READY, null);
				vm.setState(WAIT_FOR_COIN);
			}

			@Override
			protected void gotCoin(VendingMachine vm, double coin) {
				vm.monitorItr.write(Notifications.ERROR, null);
				vm.setState(INIT);
			}

			@Override
			protected void gotOrder(VendingMachine vm, Item requestedItem) {
				vm.monitorItr.write(Notifications.ERROR, null);
				vm.setState(INIT);
			}
		},
		
		WAIT_FOR_COIN{

			@Override
			protected void stateInitialize(VendingMachine vm, Inventory itemsInventory, Monitor monitorItr) {
				vm.monitorItr.write(Notifications.ERROR, null);
				vm.setState(WAIT_FOR_COIN);
			}

			@Override
			protected void gotCoin(VendingMachine vm, double coin) {
				vm.setCurrentBalance(coin);
				vm.monitorItr.write(Notifications.NEW_BALANCE,  vm.currentBalance);
				vm.setState(WAIT_FOR_ORDER);				
			}

			@Override
			protected void gotOrder(VendingMachine vm, Item requestedItem) {
				vm.monitorItr.write(Notifications.INSERT_COINS, null);
				vm.setState(WAIT_FOR_COIN);
			}
		},
		
		WAIT_FOR_ORDER{

			@Override
			protected void stateInitialize(VendingMachine vm, Inventory itemsInventory, Monitor monitorItr) {
				vm.monitorItr.write(Notifications.ERROR, null);
				vm.setState(WAIT_FOR_ORDER);
			}

			@Override
			protected void gotCoin(VendingMachine vm, double coin) {
				vm.setCurrentBalance(coin);
				vm.setState(WAIT_FOR_ORDER);
			}

			@Override
			protected void gotOrder(VendingMachine vm, Item requestedItem) {
				
				if(requestedItem.getQuantity() > 0) {
					if(requestedItem.getPrice() <= vm.getCurrentBalance()) {
						vm.monitorItr.write(Notifications.PLEASE_WAIT, null);
						vm.setTotalSales(requestedItem.getPrice());
						vm.returnChange(requestedItem.getPrice());
						vm.itemInventory.decreaseQuantity(requestedItem, 1);
						vm.monitorItr.write(Notifications.PURCHACE_SUCCES, requestedItem.getName());
					}
					else {
						vm.monitorItr.write(Notifications.MORE_COINS_NEEDED,requestedItem.getName() + ", Missing " + (requestedItem.getPrice() - vm.getCurrentBalance()) + " Coins");
					}
				}
				else {
					vm.monitorItr.write(Notifications.ITEM_OUT_OF_STOCK, null);
				}
				vm.setState(WAIT_FOR_COIN);
			}
		};

		protected abstract void stateInitialize(VendingMachine vm, Inventory itemsInventory, Monitor monitorItr);
		protected abstract void gotCoin(VendingMachine vm, double coin);
		protected abstract void gotOrder(VendingMachine vm, Item requestedItem);
	}
    
}

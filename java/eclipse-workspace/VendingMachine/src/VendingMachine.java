
public class VendingMachine {
 	
    private double currentBalance; 
    private double totalSales;
    private Inventory itemInventory;
	private State state;
	Monitor monitorItr = null;

	VendingMachine(Inventory itemInventory, Monitor monitorItr) {
	       currentBalance = 0;
	       totalSales = 0;
	       this.itemInventory = itemInventory;
	       state = State.INIT.stateInitialize();
	       this.monitorItr = monitorItr;
	       monitorItr.write(Notifications.MACHINE_READY, null);
	}

	private void setCurrentBalance(double currentBalance) {
		this.currentBalance += currentBalance;
	}

	private enum State{

		INIT{
			
			protected State stateInitialize() {
				
				return WAIT_FOR_COIN;
				
				
			}

			@Override
			protected State gotCoin(VendingMachine vm, double coin) {
				return null;
			}

			@Override
			protected State gotOrder(VendingMachine vm, Item requestedItem) {
				return null;
			}
		},
		
		WAIT_FOR_COIN{

			@Override
			protected State stateInitialize() {
				return null;
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
			protected State stateInitialize() {
				return null;
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
						vm.totalSales += requestedItem.getPrice();
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

		protected abstract State stateInitialize();
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

	public double getCurrentBalance() {return currentBalance;}

	public double getTotalSales() {return totalSales;}

	public Inventory getItemInventory() {return itemInventory;}

	public void insertCoin(double coin) {
		
        state = state.gotCoin(this, coin);
    }
    
    public void reset(){
  
    	if(currentBalance > 0) {
    		returnChange(0);
    	}
    	
        itemInventory.clear();
        currentBalance = 0;
	    totalSales = 0;
	    state = State.INIT.stateInitialize();
	    monitorItr.write(Notifications.MACHINE_READY, null);
    } 
	
}

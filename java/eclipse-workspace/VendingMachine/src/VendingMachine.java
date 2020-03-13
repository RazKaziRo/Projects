
public class VendingMachine {
 	
    private double currentBalance; 
    private double totalSales;
    private Inventory itemInventory;
	private State state;
	Monitor monitorItr = new MonitorTest();

	VendingMachine(Inventory itemInventory) {
		
	       setCurrentBalance(0);
	       setTotalSales(0);
	       setItemInventory(itemInventory);
	       state = State.INIT.stateInitialize();
	       monitorItr.write(Notifications.MACHINE_READY, null);
	}

	private enum State{

		INIT{
			
			protected State stateInitialize() {
				
				return WAIT_FOR_COIN;
				
				
			}

			@Override
			protected State gotCoin() {
				return null;
			}

			@Override
			protected State gotOrder() {
				return null;
			}
		},
		
		WAIT_FOR_COIN{

			@Override
			protected State stateInitialize() {
				return null;
			}

			@Override
			protected State gotCoin() {
				return WAIT_FOR_ORDER;
			}

			@Override
			protected State gotOrder() {
				return WAIT_FOR_COIN;
			}

			
		},
		
		WAIT_FOR_ORDER{

			@Override
			protected State stateInitialize() {
				return null;
			}

			@Override
			protected State gotCoin() {
				
				return WAIT_FOR_ORDER;
			}

			@Override
			protected State gotOrder() {
				
				return WAIT_FOR_COIN;
			}

		};

		protected abstract State stateInitialize();
		protected abstract State gotCoin();
		protected abstract State gotOrder();
	}
		
	public double getItemPrice(Item item) {
		
		return itemInventory.getItemPrice(item);

	}
	
	public void orderItem(Item item) {
		
		Item requestedItem = itemInventory.getItem(item);
		
		if(state == State.WAIT_FOR_ORDER) {
			
			if(requestedItem.getQuantity() > 0) {
				
				if(requestedItem.getPrice() <= currentBalance) {
					monitorItr.write(Notifications.PLEASE_WAIT, null);
					totalSales += requestedItem.getPrice();
					returnChange(requestedItem.getPrice());
					itemInventory.decreaseQuantity(requestedItem, 1);
					monitorItr.write(Notifications.PURCHACE_SUCCES, requestedItem.getName());
				}
				else {
					
					monitorItr.write(Notifications.MORE_COINS_NEEDED, requestedItem.getPrice() - currentBalance + " Coins");
				}
			}
			else {
				monitorItr.write(Notifications.ITEM_OUT_OF_STOCK, null);
			}
			state = state.gotOrder();
		}
		else {
			monitorItr.write(Notifications.INSERT_COINS, null);
			
		}
		
	}
	
	public double returnChange(double requestedItemPrice) {
		
		double change = currentBalance - requestedItemPrice;
		currentBalance = 0;
		monitorItr.write(Notifications.CHANGE, change);
		return change;
	}

	public double getCurrentBalance() {
		return currentBalance;
	}

	public void setCurrentBalance(double currentBalance) {
		this.currentBalance = currentBalance;
	}

	public double getTotalSales() {
		return totalSales;
	}

	public void setTotalSales(double totalSales) {
		this.totalSales = totalSales;
	}

	public Inventory getItemInventory() {
		return itemInventory;
	}

	public void setItemInventory(Inventory itemInventory) {
		this.itemInventory = itemInventory;
	}

	public void insertCoin(double coin) {
		
    	if(state == State.WAIT_FOR_COIN || state == State.WAIT_FOR_ORDER) {
    		
        	currentBalance += coin;
        	state = state.gotCoin();
        	monitorItr.write(Notifications.NEW_BALANCE , currentBalance);
    	}
    }
    
    public void reset(){
  
    	if(currentBalance > 0) {
    		returnChange(0);
    	}
    	
        itemInventory.clear();
	    setCurrentBalance(0);
	    setTotalSales(0);
	    setItemInventory(itemInventory);
	    state = State.INIT.stateInitialize();
	    monitorItr.write(Notifications.MACHINE_READY, null);
    } 
	
}

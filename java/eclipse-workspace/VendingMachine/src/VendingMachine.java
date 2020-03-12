
public class VendingMachine {
 	
    private double currentBalance; 
    private double totalSales;
    private Inventory itemInventory;
	private State state;

	VendingMachine(Inventory itemInventory) {
		
		state = state.initialize();
		initialize(itemInventory);
	}
	
    public void initialize(Inventory itemInventory){ 
    	
       setCurrentBalance(0);
       setTotalSales(0);
       setItemInventory(itemInventory);
    }
	
	private enum State{

		INIT{
			
			protected State initialize() {
				
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
			protected State initialize() {
				return WAIT_FOR_COIN;
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
			protected State initialize() {
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

		protected abstract State initialize();
		protected abstract State gotCoin();
		protected abstract State gotOrder();
	}
	
	public double getItemPrice(Item item) {
		
		return itemInventory.getItemPrice(item);

	}
	
	public double orderItem(String itemName) {
		
		double change = 0;
		Item requestedItem = itemInventory.getItemName(itemName);
		
		if(state == State.WAIT_FOR_ORDER) {
			
			if(requestedItem != null) {
				if(requestedItem.getPrice() <= currentBalance) {
					
					totalSales += requestedItem.getPrice();
					change = currentBalance - requestedItem.getPrice();
					itemInventory.decreaseQuantity(requestedItem, 1);
					currentBalance = 0;
					//NOTIFY_THANKS_FOR_ORDER
				}
			}
			
			state = state.gotOrder();
			//NOTIFY OUT_OF_STOCK;
		}
		else {
			
			//NOTIFY INSERT COINS
		}
		
		return change;
	}
	
    public State getState() {
		return state;
	}

	public void setState(State state) {
		this.state = state;
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
    	}
    }
    
    public void reset(){
  
        itemInventory.clear();
        initialize(itemInventory);
    } 
	
}

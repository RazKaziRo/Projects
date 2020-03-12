import java.util.ArrayList;

public class Inventory {
	
    private ArrayList<Item> items = new ArrayList<Item>();

    public void addItem(Item item) {
    	
   	 	for (Item  existingItem : this.items) {
   	 		if(0 == existingItem.compareTo(item)) {
   	 			existingItem.setQuantity(existingItem.getQuantity() + item.getQuantity());
   	 			break;
   	 		}
   	 	}
   	 	
   	 	items.add(item);
   	 		
    }
   	 
    public void increaseQuantity(Item item, int extraQuantitiy) {
    	
        for (Item existingItem : this.items) {
        		if(0 == existingItem.compareTo(item) && extraQuantitiy > 0) {
        			existingItem.setQuantity(existingItem.getQuantity() + extraQuantitiy);
            }
        }
    }

    public void decreaseQuantity(Item item, int decrecedQuantity) {
    	
    	int currentQuantity = item.getQuantity();
    	
        for (Item existingItem : this.items) {
        		if(0 == existingItem.compareTo(item)) {
    				if((currentQuantity - decrecedQuantity) >= 0 ) {
    					existingItem.setQuantity(currentQuantity - decrecedQuantity);
    				}
            		else {
            			existingItem.setQuantity(0);
            		}
        		}
        }
    }
    
    public double getItemPrice(Item item) {
    	
    	double price = 0;
    	
        for (Item existingItem : this.items) {
        		if(0 == existingItem.compareTo(item)) {
        			price =  existingItem.getPrice();
        		}
        }
        
        return price;
    }
    
    public double getItemQuantity(Item item) {
    	
    	double quantity = 0;
    	
        for (Item existingItem : this.items) {
        		if(0 == existingItem.compareTo(item)) {
        			quantity =  existingItem.getQuantity();
        		}
        }
        
        return quantity;
    }
    
    public Item getItemName(String name) {
    	
    	Item returnedItem = null;
    	
        for (Item existingItem : this.items) {
        		if(0 == existingItem.getName().compareTo(name)) {
        			returnedItem =  existingItem;
        		}
        }
        
        return returnedItem;
    }
   
    public String toString() {
        String s="";
        s+="Inventory contains:\n";
        for (Item item:this.items) {
            s+='\t'+item.toString() + "\n";
        }
       
        return s;
    }
    
    public void clear() {
    	
    	items.clear();
    }

    public void printInventory() {
        System.out.println(this.toString());
    }
}

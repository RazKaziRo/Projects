package il.co.ilrd.singleton;


public class Classic {
	
    private static Classic instance;
    
    private Classic () {
    	
    }
 
    public static Classic getInstance() {
    	
    	if (instance == null) { //not thread-safe
    		instance = new Classic();
    	}
    	
    	return instance;
    }
}

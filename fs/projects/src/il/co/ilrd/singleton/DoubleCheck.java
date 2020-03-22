package il.co.ilrd.singleton;

public class DoubleCheck {

    private volatile static DoubleCheck instance; 
    private DoubleCheck () {}
 
    public static DoubleCheck getSingleton() {
        if (instance == null) { 
        	
            synchronized (DoubleCheck.class) {
            	
                if (instance == null) {       
                	
                    instance = new DoubleCheck();
                }
            }
        }
        
        return instance;
        
    }
}

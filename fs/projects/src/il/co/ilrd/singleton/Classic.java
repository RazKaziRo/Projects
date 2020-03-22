package il.co.ilrd.singleton;


public class Classic {
	
	//1. Classic Java Singleton pattern
    private static Classic instance;
    private Classic (){}
 
    public static Classic getInstance() {
    if (instance == null) { //not thread-safe
        instance = new Classic();
    }
    return instance;
    }
}

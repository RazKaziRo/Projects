package il.co.ilrd.singleton;

public class ThreadSafe {
	
	    //the variable will be created when the class is loaded 
	    private static final ThreadSafe instance = new ThreadSafe();
	    private ThreadSafe() {
	    	
	    }
	    
	    public static ThreadSafe getInstance(){
	        return instance;
	    }
	}

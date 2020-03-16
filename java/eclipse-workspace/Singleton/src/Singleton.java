
public class Singleton {
	
	//1. Classic Java Singleton pattern
    private static Singleton instance;
    private Singleton (){}
 
    public static Singleton getInstance() {
    if (instance == null) { //not thread-safe
        instance = new Singleton();
    }
    return instance;
    }
    
    //2. A thread-safe singleton pattern in java using Synchronization
    public synchronized static Singleton getInstance() {
    	   if(instance == null) {
    		   instance = new Singleton();
    	   }
    	   return instance;
    	}
    
	//3.  Synchronize the critical code only
    public static Singleton getInstance() {
       if(instance == null) {
          synchronized(Singleton.class) { 
        	  instance = new Singleton();
          }
       }
       return instance;
    }
    

    //4. Double-checked locking
    /* double-checked locking is not guaranteed to work because the compiler is free to assign a value to the singleton member variable before the singleton’s constructor is called*/
    public static Singleton getInstance() {
      if(instance == null) { 
         synchronized(Singleton.class) {
           if(instance == null) {
        	   instance = new Singleton();
           }
        }
      }
      return instance;
    }
    
    //5.Double-checked locking with volatile keyword volatile
    public class Singleton {
        private volatile static Singleton instance; // volatile
        /*The volatile prevents memory writes from being re-ordered, making it impossible for other threads to read uninitialized fields of your singleton through the singleton’s pointer.*/
        private Singleton (){}
     
        public static Singleton getSingleton() {
            if (instance == null) {                         
                synchronized (Singleton.class) {
                    if (instance == null) {       
                        instance = new Singleton();
                    }
                }
            }
            return instance;
        }
    }
    
    //6. Thread-safe but not lazy initialized	
    public class Singleton{
        //the variable will be created when the class is loaded 
        private static final Singleton instance = new Singleton();
        private Singleton(){}
        public static Singleton getInstance(){
            return instance;
        }
    }
    
    //7. The ultimate Thread-safe and efficient singleton pattern in Java 	
    // Correct lazy initialization in Java 
    @ThreadSafe
    class Singleton {
        private static class SingletonHolder {
           public static Singleton instance = new Singleton();
        }
     
        public static Singleton getInstance() {
            return SingletonHolder.instance;
        }
    }
    
    //8. Using Enum
    enum Color {
     
        RED(1), GREEN(2), YELLOW(3);
     
        private int nCode ;
     
        private Color( int _nCode) {
     
            this.nCode = _nCode;
     
        }
     
        @Override
     
        public String toString() {
     
            return String.valueOf ( this . nCode );
     
        }
     
    }
     
    public class ColorTest {
        public static void main(String[] args) {
            Color red = Color.RED;
            Color red2 = Color.RED;
     
            System.out.println(red == red2); // return true
     
        }
    }
}

package il.co.ilrd.singleton;


public class ClassicSingleton {
	
	//1. Classic Java Singleton pattern
    private static ClassicSingleton instance;
    private ClassicSingleton (){}
 
    public static ClassicSingleton getInstance() {
    if (instance == null) { //not thread-safe
        instance = new ClassicSingleton();
    }
    return instance;
    }
}

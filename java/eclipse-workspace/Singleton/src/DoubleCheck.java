
public class DoubleCheck {

    private volatile static DoubleCheck instance; // volatile
    /*The volatile prevents memory writes from being re-ordered, making it impossible for other threads to read uninitialized fields of your singleton through the singleton’s pointer.*/
    private DoubleCheck (){}
 
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

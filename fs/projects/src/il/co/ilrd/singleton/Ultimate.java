package il.co.ilrd.singleton;

public class Ultimate {
 
        private static class SingletonHolder {
           public static Ultimate instance = new Ultimate();
        }
     
        public static Ultimate getInstance() {
            return SingletonHolder.instance;
        }
        
}


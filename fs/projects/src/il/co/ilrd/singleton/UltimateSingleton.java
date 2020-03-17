package il.co.ilrd.singleton;


public class UltimateSingleton {
 
        private static class SingletonHolder {
           public static UltimateSingleton instance = new UltimateSingleton();
        }
     
        public static UltimateSingleton getInstance() {
            return SingletonHolder.instance;
        }
}


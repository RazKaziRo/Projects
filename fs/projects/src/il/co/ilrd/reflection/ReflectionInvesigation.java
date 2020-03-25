package il.co.ilrd.reflection;

public class ReflectionInvesigation {
	
	public boolean b;
	Class c = boolean.class;  // correct

	public void getC() throws InterruptedException {
		
		synchronized (c) {

		}
		c.notify();
		System.out.println();
	}


	public static void main(String[] args) throws InterruptedException {
		ReflectionInvesigation r = new ReflectionInvesigation();
		r.getC();
}
}

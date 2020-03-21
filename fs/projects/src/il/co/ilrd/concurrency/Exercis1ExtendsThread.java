package il.co.ilrd.concurrency;

import java.util.concurrent.TimeUnit;

public class Exercis1ExtendsThread extends Thread{

	private volatile boolean exit = false;
	
	public void run() {
		
		while(!exit) {
			System.out.println(Thread.currentThread().getName() + " Server Is Running...");
		}
		System.out.println("Server is Stopped...");
	}
	
	public void stopServer() {
		exit = true;
	}

	public static void main (String [] argv) throws InterruptedException {
		Exercis1ExtendsThread myServer = new Exercis1ExtendsThread(); 
		Thread t1 = new Thread(myServer, "T1");
		t1.start();
		TimeUnit.MILLISECONDS.sleep(10);
		System.out.println(Thread.currentThread().getName() + " is stopping Server thread"); 
		myServer.stopServer();
		t1.join();
	}
}


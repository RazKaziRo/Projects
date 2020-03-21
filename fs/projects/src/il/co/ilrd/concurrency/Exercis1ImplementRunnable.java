package il.co.ilrd.concurrency;

import java.util.concurrent.TimeUnit;

public class Exercis1ImplementRunnable implements Runnable{

	private volatile boolean exit = false; 
	
	public void run() { 
		
		while(!exit){	
			System.out.println("Server is running....."); 
		} 
		
		System.out.println("Server is stopped...."); 
		} 
	
	public void stop(){ 
		exit = true; 
		
		}


	public static void main(String args[]) throws InterruptedException { 
		Exercis1ImplementRunnable myServer = new Exercis1ImplementRunnable(); 
		Thread t1 = new Thread(myServer, "T1"); 
		t1.start(); //Now, let's stop our Server thread 
		System.out.println(Thread.currentThread().getName() + " is stopping Server thread"); 
		myServer.stop(); //Let's wait to see server thread stopped 
		TimeUnit.MILLISECONDS.sleep(100); 
		System.out.println(Thread.currentThread().getName() + " is finished now");
	}

}

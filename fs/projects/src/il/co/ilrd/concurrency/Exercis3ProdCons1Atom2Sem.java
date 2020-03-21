package il.co.ilrd.concurrency;

import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;

public class Exercis3ProdCons1Atom2Sem  {
	
    public AtomicBoolean stopPingPong = new AtomicBoolean(false);
    private final Semaphore PongAvailable = new Semaphore(0, true);
    private final Semaphore PingAvailable = new Semaphore(1, true);

    
	public class Ping extends Thread{
		
		public void run() {
			
			while(!stopPingPong.get()) {
				
				try {

					PingAvailable.acquire();//-1
					System.out.println("Ping!");
					PongAvailable.release();//+1

					
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				
			}
		}

	}
	
	public class Pong extends Thread{
		
		public void run() {
			
			while(!stopPingPong.get()) {
					try {
						PongAvailable.acquire();//-1
						System.out.println("Pong!");
						PingAvailable.release();//+1

					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					
			}
		}
	
	}
	
	public void stopPingPong() {
		System.out.println("Stopping PingPong...");
		stopPingPong.getAndSet(true);
	}

	public static void main(String[] args) throws InterruptedException {
		Exercis3ProdCons1Atom2Sem ex3 = new Exercis3ProdCons1Atom2Sem();
		Ping pingClass = ex3.new Ping();
		Pong pongClass = ex3.new Pong();
	
		Thread ping = new Thread(pingClass,"Ping");
		ping.start();
		Thread pong = new Thread(pongClass, "Pong");
		pong.start();
		TimeUnit.MILLISECONDS.sleep(100);
		ex3.stopPingPong();
		
	}

}

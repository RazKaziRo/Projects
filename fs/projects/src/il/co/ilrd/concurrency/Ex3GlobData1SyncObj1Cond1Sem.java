package il.co.ilrd.concurrency;

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

public class Ex3GlobData1SyncObj1Cond1Sem {
	
	public static final int NUM_OF_CONSUMERS = 10;
	public static Object data;
    private final Semaphore listAvailable = new Semaphore(0, true);
	final Condition readyToConsume  = ((Lock) listAvailable).newCondition(); 

	public class Producer implements Runnable{
		
		public void setData(Object data) {
			Ex3GlobData1SyncObj1Cond1Sem.data = data;
		}
		
		@Override
		public void run() {
		
			readyToConsume.signal();
		}
		
		
		
	}
	public class Consumers implements Runnable{

		@Override
		public void run() {
			
			try {
				readyToConsume.await();
				System.out.println("Thread: "+ Thread.currentThread().getName() + data);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
		}
		
	}
	
	public static void main(String[] args) {
		
		Ex3GlobData1SyncObj1Cond1Sem ex3 = new Ex3GlobData1SyncObj1Cond1Sem();
		Thread [] consumers = new Thread[NUM_OF_CONSUMERS];
		
		Producer prodClass = ex3.new Producer();
		Consumers conClass = ex3.new Consumers();
		
		Thread producer = new Thread(prodClass, "Producer");
		prodClass.setData("Messege 1");
		producer.start();
		
		for(int i = 0; i < NUM_OF_CONSUMERS; ++i) {
			Thread consumer = new Thread(conClass, "Consumer" + i);

		}

		
		
		
	}

}

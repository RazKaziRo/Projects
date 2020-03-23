package il.co.ilrd.concurrency;

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Ex3GlobData1SyncObj1Cond1Sem {
	
	public static final int NUM_OF_CONSUMERS = 10;
	
	public static int data;
    private final Semaphore semNoOfConsumers = new Semaphore(0, true);
    private final Lock lock = new ReentrantLock();
    private final Condition readyToConsume  = lock.newCondition(); 
	
	public class Producer implements Runnable{
		
		@Override
		public void run() {
			
			while(true) {
				
				for(int i = 0; i < NUM_OF_CONSUMERS; ++i) {
					try {
						semNoOfConsumers.acquire();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				
				lock.lock();
				System.out.println(Thread.currentThread().getName() + "Write: " + ++data);
				readyToConsume.signalAll();
				lock.unlock();
			}
			
			}
		}
			
	public class Consumers implements Runnable{

		@Override
		public void run() {
			
			while(true) {
				
				lock.lock();	
				semNoOfConsumers.release();
				
				try {
					readyToConsume.await();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				System.out.println(Thread.currentThread().getName() + " Read: " + data);
				lock.unlock();				
			} 

		}
}
	public static void main(String[] args) throws InterruptedException {
		
		Ex3GlobData1SyncObj1Cond1Sem ex3 = new Ex3GlobData1SyncObj1Cond1Sem();
		Thread [] consumers = new Thread[NUM_OF_CONSUMERS];
		
		Producer prodClass = ex3.new Producer();
		Consumers conClass = ex3.new Consumers();
		
		Thread producer = new Thread(prodClass, "Producer ");
		producer.start();
		
		for(int i = 0; i < NUM_OF_CONSUMERS; ++i) {
			 consumers[i] = new Thread(conClass, "Consumer " + i);
			 consumers[i].start();
		}
		
		for(int i = 0; i < NUM_OF_CONSUMERS; ++i) {
			 consumers[i].join();
		}
		producer.join();
	
	}

}

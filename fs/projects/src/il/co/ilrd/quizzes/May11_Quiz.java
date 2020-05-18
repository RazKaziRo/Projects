package il.co.ilrd.quizzes;

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class May11_Quiz {
	
	private Lock mutex = new ReentrantLock();
	private Semaphore sem = new Semaphore(0);
	int num_of_readers = 10;
	int num = 0;
	
	public void startWrite()  {
		for(int i = 0; i < num_of_readers; ++i) {
			sem.release();
		}
		mutex.lock();
	}
	
	public void endWrite()  {
		mutex.unlock();

	}
	
	public void startRead() throws InterruptedException  {
		mutex.lock();
		sem.acquire();
		mutex.unlock();
	}
	
	public void endRead() {
		sem.release();
	}
	
	Runnable read = new Runnable() {
		
		@Override
		public void run() {
			
			while(true) {
				
				try {
					startRead();
				} catch (InterruptedException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				System.out.println(Thread.currentThread().getId() + "Reading" + num);
				endRead();
			}
			
			
		}
	};
	
	Runnable write = new Runnable() {
		
		@Override
		public void run() {
			while(true) {
				
				startWrite();
				System.out.println(Thread.currentThread().getId() + "Writing" + ++num);
				endWrite();
			}
			
			
		}
	};
	
	public static void main(String [] argv) throws InterruptedException {
		
		May11_Quiz m = new May11_Quiz();
		Thread tRead[]= new Thread[10];
		Thread tWrite = new Thread(m.write);
		
		for(int i = 0; i<10; ++i) {
			tRead[i] = new Thread(m.read);
			tRead[i].start();
			System.out.println("Read Start");
		}
		tWrite.start();
		

		
		tWrite.join();
	}

}

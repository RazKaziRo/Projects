package il.co.ilrd.quizzes;

import java.util.concurrent.locks.ReentrantLock;

public class March24Quizz {
	ReentrantLock lock = new ReentrantLock();
	SyncWritingReading swr = new SyncWritingReading(lock);
	
	private int data = 0;

	public class Readers implements Runnable {
		
		@Override
		public void run() {
			while(true) {
				
				swr.StartRead();
				System.out.println(Thread.currentThread().getName() + " Reading Data: " + data);
				swr.EndRead();
			}
		}
		
	}
	
	public class Writers implements Runnable {

		@Override
		public void run() {
			while(true) {
				
				swr.StartWrite();
				System.out.println(Thread.currentThread().getName() + " Writing Data..." + ++data);
				swr.EndWrite();
			}

		}
		
	}
    
	public static void main(String[] args) throws InterruptedException {
		
		Thread [] readers = new Thread[10];
		Thread [] writers = new Thread[10];
		
		March24Quizz mr = new March24Quizz();
		Readers readersClass = mr.new Readers();
		Writers writersClass = mr.new Writers();

		
		for(int i = 0; i < 10; ++i) {
			readers[i] = new Thread(readersClass, "Reader: " + i);
			readers[i].start();
		}
		for(int i = 0; i < 10; ++i) {
			writers[i] = new Thread(writersClass, "Writer: " + i);
			writers[i].start();
		}
		
		for(int i = 0; i < 10; ++i) {
			readers[i].join();
			writers[i].join();
		}
				
	}

}

package il.co.ilrd.quizzes;

import java.util.concurrent.locks.ReentrantLock;

import il.co.ilrd.quizzes.April2_Quizz.SemSyncWritingReading;
import il.co.ilrd.quizzes.March24thQuizz.Readers;
import il.co.ilrd.quizzes.March24thQuizz.Writers;

public class April2_Test {
	
	April2_Quizz ap = new April2_Quizz();
	SemSyncWritingReading swr = ap.new SemSyncWritingReading(10);
	
	private int data = 0;

	public class Readers implements Runnable {
		
		@Override
		public void run() {
			while(true) {
				
				try {
					swr.StartRead();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				System.out.println(Thread.currentThread().getName() + " Reading Data: " + data);
				try {
					swr.EndRead();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
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
		
		April2_Test mr = new April2_Test();
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


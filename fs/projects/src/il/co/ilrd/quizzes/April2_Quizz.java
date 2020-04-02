package il.co.ilrd.quizzes;

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;


public class April2_Quizz {

	public class SemSyncWritingReading{
		
		private final Lock lock;
		private Semaphore sem;
		private final int MAX_READERS;
		
		public SemSyncWritingReading(int maxReaders) {
			
			lock = new ReentrantLock();
			MAX_READERS = maxReaders;
			sem = new Semaphore(0);

		}
		
		public void StartWrite() {
			lock.lock();
		}
		
		public void EndWrite() {
			lock.unlock();
			while(sem.availablePermits()>0) {}

		}
		
		public void StartRead() throws InterruptedException {
			lock.lock();
			sem.release();
			lock.unlock();
		}
		
		public void EndRead() throws InterruptedException {
			sem.acquire();
		}
		
	}
	
}

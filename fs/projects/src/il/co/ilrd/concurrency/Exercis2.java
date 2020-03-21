package il.co.ilrd.concurrency;

import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.ReentrantLock;

public class Exercis2 extends Thread {
	
	private final ReentrantLock re = new ReentrantLock();
	public static AtomicInteger c = new AtomicInteger(0);

	@Override
	public void run() {
			
		re.lock();
			
			for(int i = 0; i < 10000000; ++i) {
				c.incrementAndGet();
			}
	
		System.out.println(Thread.currentThread().getName() + " Counter Value: " + c.get());
		
		re.unlock();
	}
	
	public static void main(String[] args) throws InterruptedException {

		Exercis2 ex2 = new Exercis2();
		
		Thread t1 = new Thread(ex2, "T1");
		Thread t2 = new Thread(ex2, "T2");
		
		long startTime = System.currentTimeMillis();

		t1.start();
		t2.start();
		t1.join();
		t2.join();
		
		long endTime = System.currentTimeMillis();
		
		long timeElapsed = endTime - startTime;

		System.out.println("Execution time in milliseconds: " + timeElapsed);
		
		/* Synchronized Method: 
		 * T1 Counter Value: 10000000
		 * T2 Counter Value: 20000000
		 * Execution time in milliseconds: 15
		*/
		
		/* Synchronized Block:
		 * T1 Counter Value: 10000000
		 * T2 Counter Value: 20000000
		 * Execution time in milliseconds: 20
		 */

		/* Atomic Variable
		 * T1 Counter Value: 18915538
		 * T2 Counter Value: 20000000
		 * Execution time in milliseconds: 272
		 */
		
		/* ReentrantLock
		 * T1 Counter Value: 10000000
		 * T2 Counter Value: 20000000
		 * Execution time in milliseconds: 168
		 */
	}

}

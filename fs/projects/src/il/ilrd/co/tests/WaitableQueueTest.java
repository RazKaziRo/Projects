package il.ilrd.co.tests;

import java.util.concurrent.TimeUnit;

import org.junit.jupiter.api.Test;
import il.co.ilrd.collections.WaitableQueue;

class WaitableQueueTest {
	
	class Producer<T> implements Runnable{

		WaitableQueue<T> queue;
		T item;
		
		public Producer(WaitableQueue<T> queue, T item) {
			this.queue = queue;
			this.item = item;
		}
		
		@Override
		public void run() {
			try {
				
				System.out.println("Enque Item: "+ item);
				queue.enqueue(item);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
	
	class Consumer<T> implements Runnable{

		WaitableQueue<T> queue;
		
		public Consumer(WaitableQueue<T> queue) {
			this.queue = queue;
		}
		
		@Override
		public void run() {
			try {
				System.out.println("Dequeue from queue: " + queue.dequeue());
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
	
	class ConsumerWithTimeOut<T> implements Runnable{

		WaitableQueue<T> queue;
		
		public ConsumerWithTimeOut(WaitableQueue<T> queue) {
			this.queue = queue;
		}
		
		@Override
		public void run() {
			try {
				System.out.println("Dequeue from queue With timeout: " + queue.dequeueWithTimeot(1000));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
	
	@Test
	void testEnqueue() throws InterruptedException {
		WaitableQueue<Integer> q = new WaitableQueue<Integer>();
		
		Thread p1 = new Thread(new Producer(q, 100));
		Thread ct1 = new Thread(new ConsumerWithTimeOut(q));

		
		ct1.start();
		ct1.join();

		p1.start();


		
		
	
	}

	@Test
	void testDequeue() {
		
	}

	@Test
	void testDequeueWithTimeot() {
		
	}

}


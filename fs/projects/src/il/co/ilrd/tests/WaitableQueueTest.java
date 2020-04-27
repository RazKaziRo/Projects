package il.co.ilrd.tests;

import java.util.concurrent.TimeUnit;

import org.junit.jupiter.api.Test;
import il.co.ilrd.collections.WaitableQueue;
import il.co.ilrd.concurrency.Ex3LinkedList1SyncObj.Pop;
import il.co.ilrd.concurrency.Ex3LinkedList1SyncObj.Push;

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
				System.out.println(Thread.currentThread().getName() +" Dequeue from queue: " + queue.dequeue());
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
	
	class ConsumerWithTimeOut<T> implements Runnable{

		WaitableQueue<T> queue;
		int timeInsec;
		
		public ConsumerWithTimeOut(WaitableQueue<T> queue, int timeInsec) {
			this.queue = queue;
			this.timeInsec = timeInsec;
		}
		
		@Override
		public void run() {
			try {
				System.out.println(Thread.currentThread().getName() + " Dequeue from queue With timeout: " + queue.dequeueWithTimeot(timeInsec));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
	
	@Test
	void testDequeueWithTimeOut() throws InterruptedException {
		
		WaitableQueue<Integer> q = new WaitableQueue<Integer>();
		
		Thread[] producers = new Thread[100];
		Thread[] consumers = new Thread[100];
		
		for(int j = 0; j < 100; ++j) {
			consumers[j] = new Thread(new ConsumerWithTimeOut(q, 1), "Consumer No: " + j);
			consumers[j].start();
		}
		
		for(int i = 0; i < 100; ++i) {
			producers[i] = new Thread(new Producer(q, i), "Producer No: "+ i);
			producers[i].start();
		}

		for(int i = 0; i < 100; ++i) {
			producers[i].join();
		}
		
		for(int j = 0; j < 100; ++j) {
			consumers[j].join();
		}
	}

	@Test
	void testDequeue() throws InterruptedException {
		
		WaitableQueue<Integer> q = new WaitableQueue<Integer>();
		
		Thread[] producers = new Thread[100];
		Thread[] consumers = new Thread[100];
		
		for(int j = 0; j < 100; ++j) {
			consumers[j] = new Thread(new Consumer(q), "Consumer No: " + j);
			consumers[j].start();
		}
		
		for(int i = 0; i < 100; ++i) {
			producers[i] = new Thread(new Producer(q, i), "Producer No: "+ i);
			producers[i].start();
		}
		
		for(int i = 0; i < 100; ++i) {
			producers[i].join();
		}
		
		for(int j = 0; j < 100; ++j) {
			consumers[j].join();
		}
	}

	@Test
	void testDequeueWithTimeot() {
		
	}

}


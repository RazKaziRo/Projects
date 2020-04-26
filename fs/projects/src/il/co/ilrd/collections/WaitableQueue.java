package il.co.ilrd.collections;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class WaitableQueue<E> {
	
	private Queue<E> queue;
	private final int qCapacity;
	private static final int DEFAULT_CAPACITY = 11;
	
	public WaitableQueue() {
		this(DEFAULT_CAPACITY);
	}
	
	public WaitableQueue(int qCapacity) {
		queue = new PriorityQueue<E>(qCapacity);
		this.qCapacity = qCapacity;
	}
	
	public WaitableQueue(int qCapacity, Comparator<E> cmp) {
		queue = new PriorityQueue<E>(qCapacity, cmp);
		this.qCapacity = qCapacity;
	}
	
	
	public synchronized void enqueue(E item) throws InterruptedException  {
		
		
		while(queue.size() == this.qCapacity) {
		      wait();
		}
		
		queue.add(item);
		
		if(queue.size() == 1) {
			notifyAll();
		}
		
	}
	
	public synchronized E dequeue() throws InterruptedException {
		
		while(queue.size() == 0){
		      wait();
		}
		
		if(queue.size() == this.qCapacity){
		      notifyAll();
		}

		return queue.remove();
	}
	

	public synchronized E dequeueWithTimeot(int timeInSeconds) throws InterruptedException{
		
		long startTime = System.nanoTime();
		
		while(queue.size() == 0 && (startTime + timeInSeconds) > System.nanoTime()) {
			
			wait(timeInSeconds);
		}
				
		if(queue.size() > 0) {
			return queue.remove();
		}
		else {
			return null;
		}
	}
}


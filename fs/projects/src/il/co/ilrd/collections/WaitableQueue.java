package il.co.ilrd.collections;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class WaitableQueue<E> {
	
	private Queue<E> queue;
	
	public WaitableQueue() {
		queue = new PriorityQueue<E>();
	}
	
	public WaitableQueue(Comparator<E> cmp) {
		queue = new PriorityQueue<E>(cmp);
	}
		
	public synchronized void enqueue(E item) throws InterruptedException  {
		
		queue.add(item);
		
		if(queue.size() == 1) {
			notifyAll();
		}
		
	}
	
	public synchronized E dequeue() throws InterruptedException {
		
		while(queue.isEmpty()){
		      wait();
		}

		return queue.remove();
	}
	

	public synchronized E dequeueWithTimeot(int timeInSeconds) throws InterruptedException{
		
		long endTime = System.currentTimeMillis() + timeInSeconds * 1000;
		
		while(queue.isEmpty() && (endTime > System.currentTimeMillis())) {
			wait(endTime -  System.currentTimeMillis());
		}
			
		return (!queue.isEmpty() ? queue.remove() : null);
	}
}


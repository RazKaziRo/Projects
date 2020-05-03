package il.co.ilrd.threadpool;

import java.util.Queue;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

import il.co.ilrd.collections.WaitableQueue;

public class ThreadPool {

	private int totalThreads;
	private WaitableQueue<Task<?>> queue;
	private Queue<WorkerThread> threadPool;
	private volatile boolean shtDnflag = true;
	
	public ThreadPool(int totalThreads) {
		this.totalThreads = totalThreads;
		
		queue = new WaitableQueue<Task<?>>();
		
		for (int i = 0; i < this.totalThreads; ++i) {
			new WorkerThread().start();
		}
	}

	
	public enum Priority {
		LOW (1),
		MID(2),
		HIGH(3);
		
		private int priority;
		private Priority(int priority) {
			this.priority = priority;
		}
		
		public int getPriority() {
			return priority;
		}
	}
//	LOWEST (0)
//	HIGHEST (4)
	
	private class WorkerThread extends Thread{
		
		boolean keep_running = true;
		
		@Override
		public void run() {
			while (keep_running) {
				queue.dequeue
			}
		}

		
	}
	
	private static class Task <T>{
		private int priority;
		private Future<T> future;
		private Callable<T> cb; //turn runnable to callable
		
		public Task(int priority, Callable<T> cb) {
			this.priority = priority;
			future = new Future<T>(cb);
			this.cb = cb;
		}			
	}


	public Future<Object> submit(Runnable r, Priority p) {
		return null;
	}
	
	public <T> Future<T> submit(Runnable r, Priority p, T value) {
		return null;
	}
	
	public <T> Future<T> submit(Callable<T> cb) {
		return null;
	}
	
	public <T> Future<T> submit(Callable<T> cb, Priority p) {
		return null;
	}
	
	public void setNumOfThreads(int num) {
		
	}
	
	public void shutdown() {
		
	}
	
	public void awaitTermination(int timeInSec, TimeUnit unit) throws IllegalStateException {
		
	}

	public void pause() {
		
	}
	
	public void resume() {
		
	}
}
package il.co.ilrd.threadpool;

import java.util.concurrent.Callable;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

import com.sun.org.glassfish.external.amx.MBeanListener.Callback;

import il.co.ilrd.collections.WaitableQueue;

public class ThreadPool {

	private int totalThreads;
	private WaitableQueue<Task<?>> taskQueue;
	private WaitableQueue<WorkerThread> threadQueue;
	private volatile boolean shutDownFlag = false;
	private Semaphore semaphore = new Semaphore(0);
	
	public ThreadPool(int totalThreads) {
		this.totalThreads = totalThreads;
		
		taskQueue = new WaitableQueue<>();
		threadQueue = new WaitableQueue<>();
		
		for (int i = 0; i < this.totalThreads; ++i) {
			new WorkerThread(taskQueue).start();
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
		
		public int getPriorityVal() {
			return priority;
		}
	}
	
	private static class WorkerThread extends Thread{
		
		private boolean keepGoingflg = true;
		private WaitableQueue<Task<?>> taskQueue;
		
		WorkerThread(WaitableQueue<Task<?>>  taskQueue){
			this.taskQueue = taskQueue;
		}
		
		@Override
		public void run() {
			
			while(keepGoingflg) {
				try {
					taskQueue.dequeue().futureTask.run();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
		
		private void stopThread() {
			keepGoingflg = false;
		}
	}
	
	private static class Task <T> implements Comparable<Task<T>>{

		private int priority;
		private FutureTask<T> futureTask;

		private Task(Callable<T> callable, int priority) {
			
			this.priority = priority;
			futureTask = new FutureTask<>(callable);
			
		}
		@Override
		public int compareTo(Task<T> otherTask) {
			return  otherTask.priority- this.priority;
		}
		
	}
	
	public Future<Object> submit(Runnable runnable, Priority priority) throws InterruptedException  {
		
		if (shutDownFlag) {
			throw new RejectedExecutionException("Cannot accept more Tasks, Shutdown In Process...");
		}

		Task<Object> t = new Task<>(Executors.callable(runnable), priority.getPriorityVal());
		taskQueue.enqueue(t);
		
		return t.futureTask;
	
	}
	
	public <T> Future<T> submit(Runnable runnable, Priority priority, T result) throws InterruptedException {
		if (shutDownFlag) {
			throw new RejectedExecutionException("Cannot accept more Tasks, Shutdown In Process...");
		}
		
		Task<T> t = new Task<>(Executors.callable(runnable, result),priority.getPriorityVal());
		taskQueue.enqueue(t);
		
		return t.futureTask;
		
	}
	
	public <T> Future<T> submit(Callable<T> callable) throws InterruptedException {
		if (shutDownFlag) {
			throw new RejectedExecutionException("Cannot accept more Tasks, Shutdown In Process...");
		}
		
		Task<T> t = new Task<>(callable, Priority.MID.getPriorityVal());
		taskQueue.enqueue(t);
			
		return t.futureTask;
	}
	
	public <T> Future<T> submit(Callable<T> callable, Priority priority) throws InterruptedException {
		if (shutDownFlag) {
			throw new RejectedExecutionException("Cannot accept more Tasks, Shutdown In Process...");
		}
		
		Task<T> t = new Task<>(callable, priority.getPriorityVal());
		taskQueue.enqueue(t);
		
		return t.futureTask;
	}
	
	public void setNumOfThreads(int num) throws InterruptedException {
		
		if(num > totalThreads) {
			for(int i = 0; i< (num - totalThreads); ++i) {
				WorkerThread t = new WorkerThread(taskQueue);
				t.start();
			}
		}
		else if(num < totalThreads) {
			Callable<Object> specificShutDownTask = new Callable<Object>() {
				
				@Override
				public Object call() throws Exception {
					((WorkerThread)Thread.currentThread()).stopThread();
					return null;
				}
			};
			
			for(int i = 0; i < totalThreads - num; ++i) {
				Task<Object> t = new Task<>(specificShutDownTask, Priority.HIGH.getPriorityVal() + 1);
				taskQueue.enqueue(t);
			}
		}
		
		totalThreads = num;

	}

	public void shutdown() throws InterruptedException {
		
		Callable<Object> shutDownTask = new Callable<Object>() {

			@Override
			public Object call() throws Exception {
				((WorkerThread)Thread.currentThread()).stopThread();
				threadQueue.enqueue((WorkerThread) Thread.currentThread());
				return null;
			}
		};
		
		shutDownFlag = true;

		for (int i = 0; i < totalThreads; ++i) {
			taskQueue.enqueue(new Task<>(shutDownTask, Priority.LOW.getPriorityVal() - 1));
		}
	}
	
	public boolean awaitTermination(long timeOut, TimeUnit unit) throws InterruptedException {
		
		for (int i = 0; i < totalThreads; ++i) {
			
			try {
				threadQueue.dequeueWithTimeot(unit.toSeconds(timeOut)).join();
			}
			catch(NullPointerException e) {
				return false;
			}
		}
		
		return true;
	}
	
	public void pause() throws InterruptedException {
		Callable<Object> pauseTask = new Callable<Object>() {
			
			@Override
			public Object call() throws Exception {
				semaphore.acquire();
				return null;
			}
		};
		
		for (int i = 0; i < totalThreads; ++i) {
			Task<Object> t = new Task<>(pauseTask, Priority.HIGH.getPriorityVal() + 1);
			taskQueue.enqueue(t);
		}
	}
	
	public void resume() {
		semaphore.release(totalThreads);;
	}

}
package il.co.ilrd.threadpool;

import java.util.concurrent.Callable;
import java.util.concurrent.CancellationException;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

import il.co.ilrd.collections.WaitableQueue;

public class ThreadPool<T> {

	private int totalThreads;
	private WaitableQueue<Task<?>> taskQueue;
	private LinkedBlockingQueue<WorkerThread> threadQueue;
	private volatile boolean shutDownFlag = false;
	private Semaphore semaphore = new Semaphore(0);
	private volatile boolean isPaused = false;
	
	public ThreadPool(int totalThreads) {
		this.totalThreads = totalThreads;
		
		taskQueue = new WaitableQueue<>();
		threadQueue = new LinkedBlockingQueue<>();
		
		for (int i = 0; i < this.totalThreads; ++i) {
			new WorkerThread(taskQueue).start();
		}
			
	}
	
	public enum Priority {
		
		LOW (1),
		MID(2),
		HIGH(3);
		
		private int pval;
		
		private Priority(int priority) {
			this.pval = priority;
		}
		
		public int getPriorityVal() {
			return pval;
		}
	}
	
	private static class WorkerThread extends Thread{
		
		private volatile boolean keepGoingflg = true;
		private WaitableQueue<Task<?>> taskQueue;
		
		WorkerThread(WaitableQueue<Task<?>> taskQueue){
			this.taskQueue = taskQueue;
		}
		
		@Override
		public void run() {
			
			while(keepGoingflg) {
				try {
					taskQueue.dequeue().execute();
				} catch (Exception e) {
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
		Callable<T> cb;
		FutureTask<T> future;
		
		private Task(Callable<T> callable, int priority) {
			
			this.priority = priority;
			cb = callable;
			future = new FutureTask<>();
			
		}
		
		@Override
		public int compareTo(Task<T> otherTask) {
			return  otherTask.priority- this.priority;
		}
		
		public void execute() throws Exception {
			if(!future.isCanceled) {
				future.setValue(cb.call());
				future.releaseSem();
			}
			else {
				future.setValue(null);
			}
		}
		
		private Future<T> getFuture() {
			return future;
		}
		
		private static class FutureTask<V> implements Future<V>{
			
			Semaphore futureSem = new Semaphore(0);
			V value = null;
			private boolean isDone = false;
			private boolean isCanceled = false;
			
			private void releaseSem() {
				futureSem.release();
				isDone = true;
			}
			
			private void setValue(V value) {
				this.value = value;
			}
			
			@Override
			public boolean cancel(boolean mayInterruptIfRunning) {
				
				if(!isCanceled && !isDone) {
					
					isCanceled = true;
					isDone = true;
					
					return true;
				}
			
				return false;
			}

			@Override
			public V get() throws InterruptedException, ExecutionException {
				
				futureSem.acquire();
				return value;
			}

			@Override
			public V get(long timeout, TimeUnit unit)
					throws InterruptedException, ExecutionException, TimeoutException {
				
				if(!isCanceled) {
					
					if(futureSem.tryAcquire(timeout, unit)) {
						return value;
					}
					
					throw new TimeoutException();
			}
				throw new CancellationException();
			}

			@Override
			public boolean isCancelled() {
				return isCanceled;
			}

			@Override
			public boolean isDone() {
				return isDone;
			}
		}
		
	}
	
	public Future<Object> submit(Runnable runnable, Priority priority) throws Exception  {
		return submit(Executors.callable(runnable, null), priority);
	
	}
	
	public <T> Future<T> submit(Runnable runnable, Priority priority, T result) throws Exception {		
		return submit(Executors.callable(runnable, result),priority);
		
	}
	
	public <T> Future<T> submit(Callable<T> callable) throws Exception {
		return submit (callable, Priority.MID);
	}
	
	public <T> Future<T> submit(Callable<T> callable, Priority priority) throws Exception {
		if (shutDownFlag) {
			throw new RejectedExecutionException("Cannot accept more Tasks, Shutdown In Process...");
		}
		
		Task<T> t = new Task<>(callable, priority.getPriorityVal());
		taskQueue.enqueue(t);
		
		return t.getFuture();
	}
	
	public void setNumOfThreads(int num) throws InterruptedException {
		
		if(!isPaused) {
			
			if(num > totalThreads) {
				for(int i = 0; i< (num - totalThreads); ++i) {
					WorkerThread t = new WorkerThread(taskQueue);
					t.start();
				}
			}
			else {
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
		throw new IllegalArgumentException();
		
	}

	public void shutdown() throws InterruptedException {
		
		Callable<Object> shutDownTask = new Callable<Object>() {

			@Override
			public Object call() throws Exception {
				((WorkerThread)Thread.currentThread()).stopThread();
				threadQueue.add((WorkerThread) Thread.currentThread());
				return null;
			}
		};
		
		shutDownFlag = true;

		for (int i = 0; i < totalThreads; ++i) {
			taskQueue.enqueue(new Task<>(shutDownTask, Priority.LOW.getPriorityVal() - 1));
		}
	}
	
	public boolean awaitTermination(long timeout, TimeUnit unit) throws InterruptedException {
		
		long endTime = System.currentTimeMillis() + unit.toMillis(timeout);
		
		for (int i = 0; i < totalThreads; ++i) {
			
			try {
				threadQueue.poll(endTime, TimeUnit.MILLISECONDS).join();
				endTime -= System.currentTimeMillis();
	
			}
			catch(NullPointerException e) {
				return false;
			}
		}
		
		return true;
	}
	
	public void pause() throws InterruptedException {
		
		isPaused = true;
		
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
		isPaused = false;
		semaphore.release(totalThreads);
	}

}
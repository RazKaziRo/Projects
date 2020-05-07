package il.co.ilrd.threadpool;

import static org.junit.jupiter.api.Assertions.*;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;

import org.junit.jupiter.api.Test;

import il.co.ilrd.threadpool.ThreadPool.Priority;
/*
class Test {
	
	 static final int MAX_T = 3;
	 
	 class RunnableTask implements Runnable{
		 
		 private String name; 
		 public RunnableTask(String s) { 
			 name = s; 
		 } 
	   
	 // Prints task name and sleeps for 1s 
	 // This Whole process is repeated 5 times 
	 public void run() 
	 { 
	     try
	     { 
	         for (int i = 0; i<=5; i++) 
	         { 
	             if (i==0) 
	             { 
	                 Date d = new Date(); 
	                 SimpleDateFormat ft = new SimpleDateFormat("hh:mm:ss"); 
	                 System.out.println("Thread ID: "+ Thread.currentThread().getId() +  " Initialization Time for"
	                         + " task name - "+ name +" = " +ft.format(d));    
	                 //prints the initialization time for every task  
	             } 
	             else
	             { 
	                 Date d = new Date(); 
	                 SimpleDateFormat ft = new SimpleDateFormat("hh:mm:ss"); 
	                 System.out.println("Executing Time for task name - "+ 
	                         name +" = " +ft.format(d));    
	                 // prints the execution time for every task  
	             } 
	             Thread.sleep(1000); 
	         } 
	         System.out.println(name+" complete"); 
	     } 
	       
	     catch(InterruptedException e) 
	     { 
	         e.printStackTrace(); 
	     } 
	 }
	 }
	 
	 class CallbleTask<V> implements Callable<V>{
		 
		 private V name; 
		 
		 public CallbleTask(V name) {
			 this.name = name;
		}
		 
		@Override
		public V call() throws Exception {
			 for (int i = 0; i<=5; i++) 
	         { 
	             if (i==0) 
	             { 
	                 Date d = new Date(); 
	                 SimpleDateFormat ft = new SimpleDateFormat("hh:mm:ss"); 
	                 System.out.println("Thread ID: "+ Thread.currentThread().getId() + " Initialization Time for"
	                         + " task name - "+ name +" = " +ft.format(d));    
	                 //prints the initialization time for every task  
	             } 
	             else
	             { 
	                 Date d = new Date(); 
	                 SimpleDateFormat ft = new SimpleDateFormat("hh:mm:ss"); 
	                 System.out.println("Executing Time for task name - "+ 
	                         name +" = " +ft.format(d));    
	                 // prints the execution time for every task  
	             } 
	             Thread.sleep(1000); 
	         } 
	         System.out.println(name+" complete");
			return name; 
		}
		 
	 
	 } 
	 */
class ThreadPoolTest {

	@Test
	void testSubmitRunnablePriority() throws InterruptedException {
		Runnable r = new Runnable() {
			
			@Override
			public void run() {
				for (int i = 0; i<=5; i++) 
		         { 
		             if (i==0) 
		             { 
		                 Date d = new Date(); 
		                 SimpleDateFormat ft = new SimpleDateFormat("hh:mm:ss"); 
		                 System.out.println("Thread ID: "+ Thread.currentThread().getId() +  " Initialization Time for"
		                        +ft.format(d));    
		                 //prints the initialization time for every task  
		             } 
		             else
		             { 
		                 Date d = new Date(); 
		                 SimpleDateFormat ft = new SimpleDateFormat("hh:mm:ss"); 
		                 System.out.println("Thread ID: "+ Thread.currentThread().getId()+ "Executing Time for task name - "
		                		+ft.format(d));    
		                 // prints the execution time for every task  
		             } 
		             try {
						Thread.sleep(1000);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					} 
		         } 
		         System.out.println(Thread.currentThread().getId()+ " complete"); 
			}
		};
	
	}

	@Test
	void testSubmitRunnablePriorityT() throws InterruptedException, ExecutionException {
		
		
	}

	@Test
	void testSubmitCallableOfT() {
		
		
	}

	@Test
	void testSubmitCallableOfTPriority() {
	}

	@Test
	void testSetNumOfThreads() {
	}

	@Test
	void testShutdown() {
	}

	@Test
	void testAwaitTermination() {
	}

	@Test
	void testPause() {
	}

	@Test
	void testResume() {
	}

}

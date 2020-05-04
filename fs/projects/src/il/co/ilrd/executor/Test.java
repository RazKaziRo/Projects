package il.co.ilrd.executor;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import il.co.ilrd.threadpool.ThreadPool;
import il.co.ilrd.threadpool.ThreadPool.Priority;

//Task class to be executed (Step 1) 
public class Test {
	
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
                 System.out.println("Thread ID: "+ Thread.currentThread().getId() + " Executing Time for task name - "+ 
                         name +" = " +ft.format(d));    
                 // prints the execution time for every task  
             } 
             Thread.sleep(1000); 
         } 
         System.out.println(name+ " complete");
		return name; 
	}
	 
 }

 // Maximum number of threads in thread pool 

 public static void main(String[] args) throws Exception { 
	 Test t = new Test();
	 
	 ThreadPool tp = new ThreadPool(MAX_T);	 
     ExecutorService pool = Executors.newFixedThreadPool(MAX_T);   

     Runnable r1 = t.new RunnableTask("RunnableTask 1"); 
     Runnable r2 = t.new RunnableTask("RunnableTask 2"); 
     Runnable r3 = t.new RunnableTask("RunnableTask 3"); 
     Runnable r4 = t.new RunnableTask("RunnableTask 4"); 
     Runnable r5 = t.new RunnableTask("RunnableTask 5"); 
     
     Callable<String> c1 = t.new CallbleTask<String>("CallbleTask 1"); 
     Callable<String> c2 = t.new CallbleTask<String>("CallbleTask 2"); 
     Callable<String> c3 = t.new CallbleTask<String>("CallbleTask 3"); 
     Callable<String> c4 = t.new CallbleTask<String>("CallbleTask 4"); 
     Callable<String> c5 = t.new CallbleTask<String>("CallbleTask 5"); 
     
   
     /*
     Future<String> futureP1 = pool.submit(c1);
     Future<String> futureP2 = pool.submit(c2);
     Future<String> futureP3 = pool.submit(c3);
     Future<String> futureP4 = pool.submit(c4);
     Future<String> futureP5 = pool.submit(c5);
     
     System.out.println(futureP5.get(1, TimeUnit.SECONDS));
     System.out.println(futureP1.get());
     System.out.println(futureP2.get());
     System.out.println(futureP3.get());
     System.out.println(futureP4.get());
     
     pool.shutdown();
     
    
     Future<String> futureR1 = tp.submit(r1,Priority.LOW, "R1 FINISH");
     Future<String> futureR2 = tp.submit(r2,Priority.HIGH, "R2 FINISH");
     Future<String> futureR3 = tp.submit(r3,Priority.HIGH, "R3 FINISH");
     Future<String> futureR4 = tp.submit(r4,Priority.HIGH,"R4 FINISH");
     Future<String> futureR5 = tp.submit(r5,Priority.HIGH,"R5 FINISH");
     
     System.out.println(futureR1.get());
     System.out.println(futureR2.get());
     System.out.println(futureR3.get());
     System.out.println(futureR4.get());
     System.out.println(futureR5.get());
  
      */
     
     Future<String> futureC1 = tp.submit(c1);
     Future<String> futureC2 = tp.submit(c2);
     Future<String> futureC3 = tp.submit(c3);
     Future<String> futureC4 = tp.submit(c4);
     Future<String> futureC5 = tp.submit(c5);
   
    
     System.out.println("Task 5 cancle " + futureC5.isCancelled());
     System.out.println("Task 5 isDone: "+ futureC5.isDone());
     futureC5.cancel(false);
     System.out.println("Task 5 cancle: " + futureC5.isCancelled());
     System.out.println("Task 5 isDone: "+ futureC5.isDone());
  
     
     //System.out.println("Future Task 5 Result: " + futureC5.get(1, TimeUnit.SECONDS));
     System.out.println("Future Task 1 Result: " + futureC1.get());
     System.out.println("Future Task 2 Result: " + futureC2.get());
     System.out.println("Future Task 3 Result: " + futureC3.get());
     System.out.println("Future Task 4 Result: " + futureC4.get());
     
	 tp.shutdown();
       
 }
}


 



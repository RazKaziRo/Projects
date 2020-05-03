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
                 System.out.println("Thread ID: "+ Thread.currentThread().getName() +  " Initialization Time for"
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
                 System.out.println("Thread ID: "+ Thread.currentThread().getName() + " Initialization Time for"
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

 // Maximum number of threads in thread pool 

 public static void main(String[] args) throws InterruptedException, ExecutionException { 
	 Test t = new Test();
	 
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
       
     // creates a thread pool with MAX_T no. of  
     // threads as the fixed pool size(Step 2) 
     
     ExecutorService singlePool = Executors.newSingleThreadExecutor();
     ExecutorService fixedPool = Executors.newFixedThreadPool(MAX_T); 
     ExecutorService cachedPool = Executors.newCachedThreadPool();
     ScheduledExecutorService scheduledPool = Executors.newScheduledThreadPool(MAX_T);
     
     /*
     scheduledPool.schedule(c1, 1, TimeUnit.SECONDS);
     scheduledPool.schedule(c2, 5, TimeUnit.SECONDS);
     scheduledPool.schedule(c3, 5, TimeUnit.SECONDS);
     scheduledPool.schedule(c4, 5, TimeUnit.SECONDS);
     scheduledPool.schedule(c5, 20, TimeUnit.SECONDS);

     scheduledPool.shutdown();
      */     
     
     /*
     cachedPool.submit(c1);
     cachedPool.submit(c2);
     Thread.sleep(8000);
     cachedPool.submit(c3);
     cachedPool.submit(c4);
     cachedPool.submit(c5);

     cachedPool.shutdown();
     */
     
     /*
     singlePool.submit(r1);
     singlePool.submit(r2);
     singlePool.submit(r3);
     singlePool.submit(r4);
     singlePool.submit(r5);
     
     singlePool.shutdown();
     */
     
     fixedPool.awaitTermination(1, TimeUnit.SECONDS);

     
     Future<String> futureR1 = fixedPool.submit(r1, "R1 FINISH");
     Future<String> futureR2 = fixedPool.submit(r2, "R2 FINISH");
     Future<String> futureR3 =fixedPool.submit(r3, "R3 FINISH");
     Future<String> futureR4 = fixedPool.submit(r4, "R4 FINISH");
     Future<String> futureR5 = fixedPool.submit(r5, "R5 FINISH");
     
    // fixedPool.shutdown();
     
     System.out.println(futureR1.get());
     System.out.println(futureR2.get());
     System.out.println(futureR3.get());
     System.out.println(futureR4.get());
     System.out.println(futureR5.get());
     
 }
}


 



package il.co.ilrd.concurrency;

import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

import il.co.ilrd.singly_linked_list.SinglyLinkedList;

public class Ex3LinkedList1SyncObj1Sem {
	
	public static final int NUM_OF_CONSUMERS = 10;
	public static final int NUM_OF_PRODUCERS = 10;
    private final Semaphore listAvailable = new Semaphore(0, true);

	private SinglyLinkedList s;
		
	public Ex3LinkedList1SyncObj1Sem(SinglyLinkedList s){
		this.s = s;
	}
		
	public class Push implements Runnable {
		
		private Object data;
			
		public Push(Object data) {
			this.data = data;
		}

		@Override
		public void run() {
				
			synchronized (s) {
				try {
					
					listAvailable.release();
					listAvailable.acquire();
					
					System.out.println(Thread.currentThread().getName() + " Pushed: " + data + " To List: " + s.hashCode());
					s.pushFront(data);
					
					listAvailable.release();
					
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

			}
				
		}
	}
			
		public class Pop implements Runnable {

			@Override
			public void run() {
					synchronized (s) {
						try {
								listAvailable.acquire();
								System.out.println(Thread.currentThread().getName() + " Poped: " + s.popFront() + " From List: " + s.hashCode());
								listAvailable.release();
												
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				}
	}
	
		public static void main(String[] args) throws InterruptedException {
			
			Thread[] consumers = new Thread[NUM_OF_CONSUMERS];
			Thread[] producers = new Thread[NUM_OF_PRODUCERS];
			
			SinglyLinkedList s = new SinglyLinkedList();
			Ex3LinkedList1SyncObj ex3 = new Ex3LinkedList1SyncObj (s);
			
			for(int j = 0; j < NUM_OF_CONSUMERS; ++j) {
				consumers[j] = new Thread(ex3.new Pop(), "Consumer No: " + j);
				consumers[j].start();
			}
			
			for(int i = 0; i < NUM_OF_PRODUCERS; ++i) {
				producers[i] = new Thread(ex3.new Push(i), "Producer No: "+ i);
				producers[i].start();
			}
			
			for(int i = 0; i < NUM_OF_PRODUCERS; ++i) {
				producers[i].join();
			}
			
			for(int j = 0; j < NUM_OF_CONSUMERS; ++j) {
				consumers[j].join();
			}
			TimeUnit.MILLISECONDS.sleep(1000);
			System.out.println("SinglyList Size: "+ s.size());
		}
}


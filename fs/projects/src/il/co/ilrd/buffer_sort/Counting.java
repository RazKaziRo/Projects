package il.co.ilrd.buffer_sort;

import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.Semaphore;

public class Counting {
	
	private final int ASCII_CHARS = 256;
	
	private int[] superHistogram = new int[ASCII_CHARS];

	public class Reader implements Runnable{
		
		private int startIdx;
		private int endIdx;
		private ArrayList<String> result;
		
		public Reader(int startIdx, int endIdx, ArrayList<String> result) {
			
			this.startIdx = startIdx;
			this.endIdx = endIdx;
			this.result = result;
		}
		
		@Override
		public void run() {
			
			int[] localHistogram = new int[ASCII_CHARS];
			String s = new String();

			System.out.println(Thread.currentThread().getName() + " Start index: " + startIdx + " End Index: " + endIdx);
			for(int i = startIdx; i < endIdx; ++i) {
				
					s = result.get(i);	
					
					for(int j = 0; j < s.length(); ++j) {
						++localHistogram[s.charAt(j)];
				}
					
			}
			
			updateSuperHistogram(localHistogram);

		}	
	}
	
	private synchronized void updateSuperHistogram(int[] localHistogram) {
		for(int i = 0; i < ASCII_CHARS; ++i) {
			superHistogram[i] += localHistogram[i];
		}
	}
	
	public int[] superHistogram() {
		return superHistogram;
	}

	
	public static void main(String[] args) throws IOException, InterruptedException {
		//MAIN NEED TO SPLIT TO DIFFERENT CLASS TAKE CARE OF FILE
		final int NUM_OF_READERS = 10;
		Counting bf = new Counting();
		ArrayList<String> result = new ArrayList<String>();
		Thread [] consumers = new Thread[NUM_OF_READERS];

		
		try (FileReader f = new FileReader("/home/student/Desktop/man.txt")) {
		    StringBuffer sb = new StringBuffer();
		    while (f.ready()) {
		        char c = (char) f.read();
		        if (c == '\n') {
		            result.add(sb.toString());
		            sb = new StringBuffer();
		        } else {
		            sb.append(c);
		        }
		    }
		    if (sb.length() > 0) {
		        result.add(sb.toString());
		    }
		}
		
			for(int k = 0, i = 0; k < NUM_OF_READERS; i += result.size()/NUM_OF_READERS, ++k) {
				System.out.println("Start: " + i);
				System.out.println("End: " + (result.size()/NUM_OF_READERS + i));
				consumers[k] = new Thread(bf.new Reader(i, (result.size()/NUM_OF_READERS + i), result), "Thread " + k);
				consumers[k].start();
			}
			
			for(int i = 0; i < NUM_OF_READERS; ++i) {
				consumers[i].join();
			}
		
		int[]ch = bf.superHistogram();

		System.out.println("l Count: " + ch[108]);
		System.out.println(result.get(0));
		//System.out.println(charHistograma[1]);
		System.out.println(result.size());
	}
	

}

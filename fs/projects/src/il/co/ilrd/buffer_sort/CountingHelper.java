package il.co.ilrd.buffer_sort;

import java.util.ArrayList;

public class CountingHelper {
	
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

			//System.out.println(Thread.currentThread().getName() + " Start index: " + startIdx + " End Index: " + endIdx);
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
	
	public int[] getSuperHistogram() {
		return superHistogram;
	}

}

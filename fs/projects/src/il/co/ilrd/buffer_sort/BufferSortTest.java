package il.co.ilrd.buffer_sort;

import static org.junit.Assert.*;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

public class BufferSortTest {

	@ParameterizedTest
	@ValueSource(ints = {1, 10, 50, 65, 130, 1430}) 
	public void testBufferSortNoShuffle(int numOfThreads) throws FileNotFoundException, IOException, InterruptedException {
		
		double endTime = 0, startTime = 0, totalTime = 0;
		FileToArrayHelper f = new FileToArrayHelper();
		CountingHelper bf = new CountingHelper();
		ArrayList<String> result = f.getResult("/home/student/Desktop/man.txt");
		
		final int NUM_OF_READERS = numOfThreads;
		System.getProperty("propert.name.here");
		Thread[] consumers = new Thread[NUM_OF_READERS];
		
		startTime = System.currentTimeMillis();
		for(int k = 0, i = 0; k < NUM_OF_READERS; i += result.size()/NUM_OF_READERS, ++k) {
			//System.out.println("Start: " + i);
			//System.out.println("End: " + (result.size()/NUM_OF_READERS + i));
			consumers[k] = new Thread(bf.new Reader(i, (result.size()/NUM_OF_READERS + i), result), "Thread " + k);
			consumers[k].start();
		}
		
		for(int i = 0; i < NUM_OF_READERS; ++i) {
			consumers[i].join();
		}
		
		endTime = System.currentTimeMillis();

	
		totalTime = endTime - startTime;
		int[]ch = bf.getSuperHistogram();
		System.out.println("No Shuffel - Num Of Threads: " + numOfThreads +" Total Exucution Time: " + totalTime/1000 + " Seconds");
		assertEquals(12403, ch[108]);
		assertEquals(7150, result.size());
	}
	
	@ParameterizedTest
	@ValueSource(ints = {1, 10, 50, 65, 130, 1430}) 	
	public void testBufferSortWithShuffle(int numOfThreads) throws FileNotFoundException, IOException, InterruptedException {
		
		double endTime = 0, startTime = 0, totalTime = 0;
		FileToArrayHelper f = new FileToArrayHelper();
		CountingHelper bf = new CountingHelper();
		final int NUM_OF_READERS = numOfThreads;
		Thread[] consumers = new Thread[NUM_OF_READERS];
		ArrayList<String> result = f.getResult("/home/student/Desktop/man.txt");
		Collections.shuffle(result);
		
		startTime = System.currentTimeMillis();
		
		for(int k = 0, i = 0; k < NUM_OF_READERS; i += result.size()/NUM_OF_READERS, ++k) {
			//System.out.println("Start: " + i);
			//System.out.println("End: " + (result.size()/NUM_OF_READERS + i));
			consumers[k] = new Thread(bf.new Reader(i, (result.size()/NUM_OF_READERS + i), result), "Thread " + k);
			consumers[k].start();
		}
		
		for(int i = 0; i < NUM_OF_READERS; ++i) {
			consumers[i].join();
		}
		endTime = System.currentTimeMillis();

		
		totalTime = endTime - startTime;
		int[]ch = bf.getSuperHistogram();
		System.out.println("Shuffel - Num Of Threads:" + numOfThreads +" Total Exucution Time: " + totalTime/1000 + " Seconds");

		assertEquals(12403, ch[108]);
		assertEquals(7150, result.size());
	}
}
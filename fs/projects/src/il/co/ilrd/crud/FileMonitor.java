package il.co.ilrd.crud;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Observable;

public class FileMonitor extends Observable{
	
	String filePath;	
	volatile boolean keepMonitoring = true;
	
	public FileMonitor(String filePath) {
		this.filePath = filePath;
	}
	
	public void startMonitor() {
		System.out.println("Start Monitoring...");
		Thread thMonitor = new Thread(startMonitoring);
		thMonitor.start();
	}
	
	private void writeLine(String newLine) {
		setChanged();
		notifyObservers(newLine);
	}
	public void stopMonitor() throws IOException {
		keepMonitoring = false;
		writeLine(null);
	}
	
	Runnable startMonitoring = new Runnable() {
		
		@Override
		public void run() {
			
			String line;
			
			try(BufferedReader lineBuffer = new BufferedReader(new FileReader(filePath))) {
				
			while(keepMonitoring) {	
								
				if((line = lineBuffer.readLine()) != null) {
					System.out.println("Read Line: " + line);
					writeLine(line);
				}
			}
			
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	};
	
}
	
	

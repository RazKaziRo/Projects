package il.co.ilrd.crud;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.ClosedWatchServiceException;
import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardWatchEventKinds;
import java.nio.file.WatchEvent;
import java.nio.file.WatchKey;
import java.nio.file.WatchService;
import java.util.Observable;

public class FileMonitor extends Observable{
	
	private String filePath;
	private String fileToMonitor;
	private WatchService watcher;
    private WatchKey key;
	private volatile boolean keepMonitoring = true;


	public FileMonitor(String filePath, String fileToMonitor) {
		this.filePath = filePath;
		this.fileToMonitor = fileToMonitor;
	}
	
	public void startMonitor() {
		new Thread(startMonitoring).start();
	}
	
	private void writeLine(String newLine) {
		setChanged();
		notifyObservers(newLine);
	}
	
	public void stopMonitor() throws IOException {
		keepMonitoring = false;
		watcher.close();
	}
	
	Runnable startMonitoring = new Runnable() {
		
		@Override
		public void run() {
			
			String line;
			Path dir = Paths.get(filePath);

			try(BufferedReader lineBuffer = new BufferedReader(new FileReader(filePath +"/"+ fileToMonitor))) {
				
			watcher = FileSystems.getDefault().newWatchService();
			
			dir.register(watcher, StandardWatchEventKinds.ENTRY_MODIFY);
		
			while(keepMonitoring) {	
				
			    key = watcher.take();

			    for (WatchEvent<?> event : key.pollEvents()) {
			    	
			        WatchEvent.Kind<?> kind = event.kind();
			        
			        WatchEvent<Path> ev = (WatchEvent<Path>)event;
			        Path fileName = ev.context();

			        if (kind == StandardWatchEventKinds.OVERFLOW) {continue;} 
			        else if (kind == StandardWatchEventKinds.ENTRY_CREATE){}  // process create event
			        else if (kind == StandardWatchEventKinds.ENTRY_DELETE) {} // process delete event
			        else if (kind == StandardWatchEventKinds.ENTRY_MODIFY && 
			        		(0 == fileName.toString().compareTo(fileToMonitor))) {
			        	
						while(keepMonitoring && (line = lineBuffer.readLine()) != null) {
							writeLine(line);
							System.out.println("Writing Line: " + line);
						}			 
			        }
			    }
			    
			    key.reset();
			}
			
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}catch (ClosedWatchServiceException e) {
				System.out.println("Monitor Closed");
			}
		}
	};
	
}
	
	

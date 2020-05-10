package il.co.ilrd.crud;

public class FileCrudTest {

	public static void main(String[] args) throws Exception {
		
		FileMonitor logMonitor = new FileMonitor("/var/log","syslog");
		FileObserver fileObserver =  new FileObserver("/home/student/Desktop/output.txt");
		
		logMonitor.addObserver(fileObserver);
		logMonitor.startMonitor();
		Thread.sleep(20000);
		System.out.println("Main finished Sleep");
		logMonitor.stopMonitor();
		fileObserver.close();
		
	}

}

package il.co.ilrd.networking;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import java.net.Socket;
import java.net.UnknownHostException;

public class TCPClient {
	
	String hostName;
	int portNumber;
	
	public TCPClient(String hostName, int portNumber) {
		this.hostName = hostName;
		this.portNumber = portNumber;
	}
	
	public void start() throws UnknownHostException, IOException, InterruptedException {
		System.out.println("Client Start...");
		String resp;
		
		try(Socket clientSocket = new Socket(hostName, portNumber);
			DataOutputStream out = new DataOutputStream(clientSocket.getOutputStream());
			DataInputStream in = new DataInputStream(clientSocket.getInputStream()))
		{
			
			int loop;
			
			while(true) {
				
				out.write("5Ping\n".getBytes());		
				loop = in.read() - 48;
				
				for(int i =0; i< loop; ++i) {
					System.out.print((char)in.read());
				}
				
				Thread.sleep(1000);
				
				}
		}
	}
		
	
	public static void main(String[] argv) throws UnknownHostException, IOException, InterruptedException {
		TCPClient client = new TCPClient("localhost", 4998);
		client.start();
	}

}

package il.co.ilrd.networking;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {
	
	private int port;
	
	public TCPServer(int port) {
		this.port = port;
	}

	public void start() throws IOException, InterruptedException {
		
		System.out.println("Server Start...");
		String msg;
		
        try(ServerSocket serverSocket = new ServerSocket(port);
        		Socket clientSocket = serverSocket.accept();
        		DataOutputStream out = new DataOutputStream(clientSocket.getOutputStream());
        		DataInputStream in = new DataInputStream(clientSocket.getInputStream());)
        {
        	int loop;
        	
        	while(true) {
        		
        		loop = in.read() - 48;
        		
        		for(int i = 0; i < loop; ++i) {
        			System.out.print((char)in.read());
        		}
        		
        		out.write("5Pong\n".getBytes());
        		Thread.sleep(1000);
        	}

        	}  	
        }
        
        
	public static void main(String [] argv) throws IOException, InterruptedException {
		TCPServer server = new TCPServer(4998);
		server.start();
	}
}

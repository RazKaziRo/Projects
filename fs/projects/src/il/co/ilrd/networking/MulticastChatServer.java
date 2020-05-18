package il.co.ilrd.networking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class MulticastChatServer {
	
	private int portNumber;
    private volatile boolean isServerOn;
    
	public MulticastChatServer(int portNumber) {
		this.portNumber = portNumber;
		this.isServerOn = true;
		establishConnection();
	}
	
	
	//make it runnable and run from threads
	private void establishConnection() {
		
		try (ServerSocket serverSocket = new ServerSocket(portNumber);
	         Socket clientSocket = serverSocket.accept();     
	         PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);                   
	         BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
	        ) {
			
			while(isServerOn) {
				String inputLine;
				
	            if((inputLine = in.readLine()) != null) {
	                out.println(inputLine);
	            }
			}
			
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
	}

	
	public void broadCastMsg() {
		        
	}
	
	
	
	
	public void stop() {
	}

	

	
	public static void main(String[] args) {
		
		MulticastChatServer server = new MulticastChatServer(Integer.parseInt(args[0]));
	}

}
	


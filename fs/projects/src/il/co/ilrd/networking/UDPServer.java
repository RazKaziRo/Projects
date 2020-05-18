package il.co.ilrd.networking;

import java.io.*;
import java.net.*;
import java.util.*;

public class UDPServer{
	
		private DatagramSocket socket;
		protected BufferedReader in;

		
		public UDPServer(int port) throws SocketException {
			socket = new DatagramSocket(port);
		}
		
		public void start() throws IOException, InterruptedException {
		
		System.out.println("Server Started.. ");
		DatagramPacket request = new DatagramPacket(new byte[1024], 1024);
	        
	       while(true) {
	    	   
	    	socket.receive(request);
	  
		    String received = new String(request.getData(), 0, request.getLength());
	        System.out.println("Server Reviced : " + received);
	        
	        sendReply(request);
	       }	
		}
		
		public void sendReply(DatagramPacket request) throws IOException, InterruptedException {
			
	         byte[] buf = "Pong".getBytes();
	         DatagramPacket reply = new DatagramPacket(buf, buf.length, request.getAddress(), request.getPort());
	         socket.send(reply);
	         Thread.sleep(1000);
		}
	
	public static void main(String[] argv) throws IOException, InterruptedException {
		
		UDPServer server = new UDPServer(4999);
		server.start();
	}
	 
}


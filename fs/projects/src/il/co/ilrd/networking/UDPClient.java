package il.co.ilrd.networking;

import java.io.*;
import java.net.*;
import java.util.*;

public class UDPClient {
	
	int port;
    InetAddress address;
    
	public UDPClient(String hostName, int port) throws UnknownHostException {
		
		this.port = port;
		address = InetAddress.getByName(hostName);
	}
	
	public void startClient() throws IOException  {
		System.out.println("Client Started... ");

		try(DatagramSocket socket = new DatagramSocket();){
			while(true) {
				
				byte[] buf = new byte[256];
				DatagramPacket packet = new DatagramPacket(buf, buf.length, address, port);
				sendReply(socket);
			
				packet = new DatagramPacket(buf, buf.length);
				socket.receive(packet);
		    
				String received = new String(packet.getData(), 0, packet.getLength());
				System.out.println("Client Reviced : " + received);
		}
		}
	
	}
	
	private void sendReply(DatagramSocket socket) throws IOException {
		
		byte[] buf = "Ping".getBytes();
		DatagramPacket packet = new DatagramPacket(buf, buf.length, address, port);
        socket.send(packet);
	}
	
	public static void main(String[] args) throws UnknownHostException, IOException{
		UDPClient client = new UDPClient("localhost", 4999);
		client.startClient();
		
	}

}


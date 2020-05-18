package il.co.ilrd.networking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class ChatClient {
	
    String hostName;
    int hostPortNumber;
    private volatile boolean isOnline;
    
    public ChatClient(String hostName, int hostPortNumber) {
    	this.hostName = hostName;
    	this.hostPortNumber = hostPortNumber;
    	isOnline = true;
    }
    
    public void start() {
    	
    	try (Socket echoSocket = new Socket(hostName, hostPortNumber);
    	     PrintWriter out = new PrintWriter(echoSocket.getOutputStream(), true);
    	     BufferedReader in = new BufferedReader(new InputStreamReader(echoSocket.getInputStream()));
    	     BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in))) {
    		
    			while(isOnline) {
    				
    				String userInput;
    				while ((userInput = stdIn.readLine()) != null) {
    					out.println(userInput);
    					System.out.println("echo: " + in.readLine());
    				}
    	        
    		}
    			
    	    } catch (UnknownHostException e) {
    	        System.err.println("Don't know about host " + hostName);
    	        System.exit(1);
    	    } catch (IOException e) {
    	        System.err.println("Couldn't get I/O for the connection to " +
    	            hostName);
    	        System.exit(1);
    	    } 
    }
    
    public void stop() {
    	isOnline = false;
    }

    

	public static void main(String[] args) {

			ChatClient client = new ChatClient(args[0], Integer.parseInt(args[1]));
			client.start();
	}

}

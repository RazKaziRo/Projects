package il.co.ilrd.chat;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class ChatClient {
	
	InetSocketAddress inetAddress;
	String host;
	int port;
	boolean isOnline;
	SocketChannel socketChannle;
	Thread r, w;
	
	public ChatClient(String host, int port) throws IOException {
		this.host = host;
		this.port = port;
		inetAddress = new InetSocketAddress(host, port);
		isOnline = true;
		socketChannle = SocketChannel.open(inetAddress);
	}
	
	public void start() {
		//r = new Thread(read);
		w = new Thread(write);
		
		w.start();
		//r.start();
	}
			
	Runnable read = new Runnable() {
			
			@Override
			public void run() {
				System.out.println("Connectin to " + host + ":" + port);
				System.out.println("Client Start Reading...");
				while(isOnline) {
				ByteBuffer inputBuffer = ByteBuffer.allocate(1024);
				try {
					socketChannle.read(inputBuffer);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

				String inMsg = new String(inputBuffer.array()).trim();
				System.out.println("Input Msg In client: "+ inMsg);
				inputBuffer.clear();
				try {
					Thread.sleep(10000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				}
			}
		};
		
		Runnable write = new Runnable() {
			
			@Override
			public void run() {
				System.out.println("Client Start Writing...");

				while(isOnline) {
				System.out.println("Connectin to" + host + ":" + port);
				ObjectOutputStream oos = null;
				
				while(isOnline) {
					Scanner sc = new Scanner(System.in);
					System.out.println("Enter Request: ");
					String op = sc.next();

					Msg m = RequestHandler.valueOf(op).requestHandler();
				
					try {
						
						oos = new ObjectOutputStream(socketChannle.socket().getOutputStream());
						oos.writeObject(r);

					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					
				}
				}
			}
		};
		
	 enum RequestHandler {

			LOGIN(0) {
				@Override
				public Msg requestHandler() {
					String email;
					String name;
					
					System.out.println("Enter Email: ");
					email = sc.next();
					
					System.out.println("Enter Name: ");
					name = sc.next();
					
					RequestLogin m = new RequestLogin(RequestHandler.LOGIN, email, name);
					
					return m;
				}
			},
			CREATE_GROUP(1) {
				@Override
				public Msg requestHandler() {
					return null;
				}
			},
			JOIN_GROUP(2) {
				@Override
				public Msg requestHandler() {
					return null;
				}
			},
			LEAVE_GROUP(3) {
				@Override
				public Msg requestHandler() {
					return null;
				}
			},
			SEND_MSG(4) {
				@Override
				public Msg requestHandler() {
					return null;
				}
			},

			LOGOUT(5) {
				@Override
				public Msg requestHandler() {
					return null;
					
				}
			};

			public abstract Msg requestHandler();
			
			int value;
			Scanner sc;
			
			RequestHandler(int value){
				this.value = value;
				sc = new Scanner(System.in);
			}

			public int getValue() {
				return value;
			}
			
	 
		
	 }
	 
	public static void main(String[] args) throws IOException, InterruptedException {
		
		ChatClient client = new ChatClient("localhost", 4999);
		client.start();
	}

	 }

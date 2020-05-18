package il.co.ilrd.chat;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.Set;


public class TCPCommunication implements Communication {
		
		private ChatServer server;
		int port;
		Selector selector;
		boolean isOnline;
		
		public TCPCommunication(ChatServer server, int port) throws IOException {
			this.server = server;
			selector = Selector.open();
			this.port = port;
		}
		
		private ChatServer getServer() {
			return server;
		}

		@Override
		public void Init() {
			isOnline = true;
			
			try (ServerSocketChannel serverSocketChannel = ServerSocketChannel.open();){
				
				InetSocketAddress comAddress = new InetSocketAddress(port);
				serverSocketChannel.bind(comAddress);
				serverSocketChannel.configureBlocking(false);
				ObjectInputStream ois;
				
				SelectionKey selectKey = serverSocketChannel.register(selector, SelectionKey.OP_ACCEPT);
				System.out.println("Server Is wating for connection...");
				while(isOnline) {
					
					selector.select();
					
					Set<SelectionKey> clientsKeys = selector.selectedKeys();
					Iterator<SelectionKey> clientsKeyIterator = clientsKeys.iterator();
					
					while(clientsKeyIterator.hasNext()) {
						SelectionKey key = clientsKeyIterator.next();
						
						if(key.isAcceptable()) {
							
							SocketChannel clientSocketChannel = serverSocketChannel.accept();
							clientSocketChannel.configureBlocking(false);
							clientSocketChannel.register(selector, SelectionKey.OP_READ);
							System.out.println("Connection Accepted: " + clientSocketChannel.getLocalAddress() + "\n");
							
						}
						else if(key.isReadable()) {
							
							SocketChannel clientSocketChannel = (SocketChannel)key.channel();
							ois = new ObjectInputStream(clientSocketChannel.socket().getInputStream());
							try {
								
								Request r = (Request)ois.readObject();
								
								ResponseHanlder.valueOf(r.getOpID().toString()).responseHandler(clientSocketChannel, this);
								
							} catch (ClassNotFoundException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
							}
						
						}
						else if(key.isConnectable()) {
							System.out.println("Client stop");
							isOnline = false;
						}
						Thread.sleep(2000);
						clientsKeyIterator.remove();
					}
					
				}
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
				
		}
		
		private static class SocketPeer implements Peer {
			private SocketChannel clientSocket;
			
			ByteBuffer clientOutBuf;
		

			public SocketPeer(SocketChannel clientSocket) {
				this.clientSocket = clientSocket;
				clientOutBuf = ByteBuffer.allocate(1024);
			}


			@Override
			public void responseMessage(int msgID, int userID, String userName, String groupName, UserProperties prop,
					String message, ChatResponsStatus status) {
				// TODO Auto-generated method stub
				
			}


			@Override
			public void responseJoinGroup(int msgID, int userID, String userName, String groupName,
					ChatResponsStatus status) {
				// TODO Auto-generated method stub
				
			}


			@Override
			public void responseLogin(int msgID, int userID, Set<String> groupNames, ChatResponsStatus status) {
				// TODO Auto-generated method stub
				
			}


			@Override
			public void responseCreateGroup(int msgID, String groupName, ChatResponsStatus status) {
				// TODO Auto-generated method stub
				
			}


			@Override
			public void responseLeaveGroup(int msgID, int userID, String userName, String groupName,
					ChatResponsStatus status) {
				// TODO Auto-generated method stub
				
			}
		}
			
	enum ResponseHanlder {
				
				LOGIN(0) {
					@Override
					public void responseHandler(SocketChannel clientSocket, TCPCommunication commun) {
						System.out.println("Inside Response Handler Login");
					}
				},
				CREATE_GROUP(1) {
					@Override
					public void responseHandler(SocketChannel clientSocket, TCPCommunication commun) {
					}
				},
				JOIN_GROUP(2) {
					@Override
					public void responseHandler(SocketChannel clientSocket, TCPCommunication commun) {
					}
				},
				LEAVE_GROUP(3) {
					@Override
					public void responseHandler(SocketChannel clientSocket, TCPCommunication commun) {
					}
				},
				SEND_MSG(4) {
					@Override
					public void responseHandler(SocketChannel clientSocket, TCPCommunication commun) {
					}
				},

				LOGOUT(5) {
					@Override
					public void responseHandler(SocketChannel clientSocket, TCPCommunication commun) {
						
					}
				};

				
				public abstract void responseHandler(SocketChannel clientSocket, TCPCommunication commun);
				int value;
				
				ResponseHanlder(int value){
					this.value = value;
				}

				public int getValue() {
					return value;
				}
		

	}
	
	public static void main(String[] args) throws IOException {
		
		TCPCommunication t = new TCPCommunication(new ChatServerHub(), 4999);
		t.Init();
		
	}

}

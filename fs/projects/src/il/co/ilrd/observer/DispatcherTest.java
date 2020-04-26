package il.co.ilrd.observer;

import org.junit.jupiter.api.Test;

import il.co.ilrd.observer.Dispatcher.Callback;

class DispatcherTest {
	
	@Test
	void DispatcherTestUnit(){
		
		class Observer{
			
			private int msgCount;
			private String userName;
			private Callback<String> cb = new Callback<String>(this::recivedMail,this::logOff);
					
			public Observer(String userName){
				this.userName = userName;
				
			}
			
			public void recivedMail(String from) {
				System.out.println("Hey There " + userName+ " Just Recived New Messege");
				++msgCount;
				System.out.println(userName + " Unread Messeges:  " + msgCount +"\n");
			}
			
			private void logOff() {
				System.out.println("Bye Bye " + userName +" See You Next Time :)");
		
			}
		}
		
		class Subject{
			
			private Callback<String> cb = new Callback<String>(this::sendMail,this::logOut);
			
			public void sendMail(String from) {
				System.out.println("Sending Messeges... \n");
			}
			
			public void logOut() {
				System.out.println("Loggin Out...");
			}
	
		}
		
		Subject gmailClient = new Subject();
		Observer reciverA = new Observer("ReciverA");
		Observer reciverB = new Observer("ReciverB");
		Observer reciverC = new Observer("ReciverB");

		Dispatcher<String> d = new Dispatcher<>();
		
		d.register(gmailClient.cb);
		d.register(reciverA.cb);
		d.register(reciverB.cb);
		
		d.updateAll("New Gmail Alert(1)");
		reciverA.cb.stopService();
		d.updateAll("New Gmail Alert(2)");
		d.register(reciverA.cb);
		d.updateAll("New Gmail Alert(3)");

		d.stopAll();

	}
	
}

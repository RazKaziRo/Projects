package il.co.ilrd.observer;

import org.junit.jupiter.api.Test;

import il.co.ilrd.observer.Dispatcher.Callback;

class DispatcherTest {
	
	@Test
	void DispatcherTest(){
		
		class Observer{
			
			private int msgCount;
			private String userName;
			Callback<String> cb = new Callback<String>(this::recivedMail,this::logOff);
					
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
			
			Callback<String> cb = new Callback<String>(this::sendMail,this::logOut);
			
			public void sendMail(String from) {
				System.out.println("Sending Messeges... \n");
			}
			
			public void logOut() {
				System.out.println("Loggin Out...");
			}

			
		}
		
		Subject gmailClient = new Subject();
		Observer revicerA = new Observer("ReciverA");
		Observer revicerB = new Observer("ReciverB");

		Dispatcher<String> d = new Dispatcher<>();
		
		d.register(gmailClient.cb);
		d.register(revicerA.cb);
		d.register(revicerB.cb);
		
		d.updateAll("New Gmail Alert(1)");
		revicerA.cb.stopService();
		d.updateAll("New Gmail Alert(2)");
		d.register(revicerA.cb);
		d.updateAll("New Gmail Alert(3)");
		d.stopAll();



	}
	
}

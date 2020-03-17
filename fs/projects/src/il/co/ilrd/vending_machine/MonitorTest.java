package il.co.ilrd.vending_machine;


public class MonitorTest implements Monitor {

	@Override
	public void write(Notifications msg, Object param) {
		if(param != null)
		System.out.println(msg + param.toString());
		else {
			System.out.println(msg);
		}
		
	}

}

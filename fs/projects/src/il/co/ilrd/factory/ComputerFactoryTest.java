package il.co.ilrd.factory;

public class ComputerFactoryTest {

	public static void main(String[]argv) {
		
		ComputerFactory<String, String,String, String, Computer> factory = new ComputerFactory<String, String, String, String, Computer>();
		factory.add("PC Ctor", PC::new);
		factory.add("Server Ctor", Server::new);
		Computer pcCtor = factory.create("PC Ctor", "8GB RAM", "256GM HDD", "I7 CPU");
		Computer serverCtor = factory.create("Server Ctor", "32GB RAM", "1024GM HDD", "I9 CPU");
		
		factory.add("PC Static", PC::pcFactory);
		Computer pcStatic = factory.create("PC Static", "4GM RAM", "128GB HDD", "I5 CPU");
		
		PC pcInstance = new PC("2GB RAM", "32GB HDD", "I3 CPU");
		
		factory.add("PC Instance", pcInstance::changeSpec);
		Computer computerInstance = factory.create("PC Instance", "1GB RAM", "1GB HDD", "I3 CPU");
		
		factory.add("Server Lambda", (String ram, String hdd, String cpu)->new Server("1","2","3"));
		Computer serverLambda = factory.create("Server Lambda", null, null, null);
		System.out.println(pcCtor);
		System.out.println(serverCtor);
		System.out.println(pcStatic);
		System.out.println(computerInstance);
		System.out.println(serverLambda);


	}
}


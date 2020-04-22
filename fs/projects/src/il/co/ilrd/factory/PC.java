package il.co.ilrd.factory;

public class PC extends Computer {

	private String ram;
	private String hdd;
	private String cpu;
	
	public PC(String ram, String hdd, String cpu){
		this.ram=ram;
		this.hdd=hdd;
		this.cpu=cpu;
	}
	@Override
	public String getRAM() {
		return this.ram;
	}

	@Override
	public String getHDD() {
		return this.hdd;
	}

	@Override
	public String getCPU() {
		return this.cpu;
	}
	
	public static Computer pcFactory(String ram, String hdd, String cpu) {
		return new PC (ram, hdd, cpu);
	}
	
	public Computer changeSpec(String ram, String hdd, String cpu) {
		this.ram = ram;
		this.hdd = hdd;
		this.cpu = cpu;
		
		return this;
	}


}

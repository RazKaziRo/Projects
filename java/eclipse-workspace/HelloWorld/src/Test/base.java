package Test;

public class base {
	
	int x = 5;

	public static void main(String[] args) {
	
		base myObj1 = new base();
		Other myObj2 = new Other();
		Other myObj3 = new Other();
		
		System.out.println(myObj1.x);
		System.out.println(myObj2.y);
		System.out.println(Other.i);
		
	    {
	        System.out.println("base Inside instance initializer block");
	    }
	}

}

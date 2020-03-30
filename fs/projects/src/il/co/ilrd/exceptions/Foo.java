package il.co.ilrd.exceptions;

import java.io.IOException;

public class Foo {
	byte[] b = new byte[100];
	
	public void func1() throws IOException {
		
		throw new IOException("IOException From func1()");
	}
	
	public void func2() {
		
		throw new NullPointerException("NullPointerException From func2()");	
	}
	
	public void func3() {
		throw new MyException1();
	}
	
	public void func4() throws MyException2 {
		throw new MyException2();
	}
	
	public static void main(String[] argv) throws IOException {
		Foo f = new Foo();
		
		//f.func1();
		//f.func2();
		//f.func3();
		//f.func4();
		
		
		//f.b[101] = 1;
	}
}

package il.co.ilrd.exceptions;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import javax.naming.NameAlreadyBoundException;

public class Foo implements AutoCloseable{
	byte[] b = new byte[100];
	
	public Foo() throws NameAlreadyBoundException {
		throw new NameAlreadyBoundException();
	}
	public void func1() throws IOException {
		
		throw new IOException("IOException From func1()");
	}
	
	public void func2() {
		
		throw new NullPointerException("NullPointerException From func2()");	
	}
	
	public void func3() {
		throw new MyException1();
	}
	
	public void func4() throws MyException2  {
		throw new MyException2();
	}
	
	static String readFirstLineFromFile(String path) throws FileNotFoundException, IOException {
	    try (BufferedReader br =
	                   new BufferedReader(new FileReader(path))) {
	        return br.readLine();
	    }
	}
	
	public static void main(String[] argv) throws Exception {
		//Foo f = new Foo();
		
		try(Foo f1 = new Foo()){
			
		}
		finally {
			throw new NullPointerException();
		}
		//f.func1();
		//f.func2();
		//f.func3();
		//f.func4();
		
		
		//f.b[101] = 1;
	}
	@Override
	public void close() throws Exception {
		// TODO Auto-generated method stub
		
	}



}

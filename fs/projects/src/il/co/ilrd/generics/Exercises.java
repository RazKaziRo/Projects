package il.co.ilrd.generics;

import java.util.ArrayList;
import java.util.List;

public class Exercises {
	
	public class FooReference<T> {
		
		private T t;
		 
		public FooReference(T t) {
			this.t = t;
			
		}
			
		public T getT() {
			return t;
		}

		public void setT(T t) {
			this.t = t;
		}
	
		
		public Class<?> getClassAtRunTime() {
			return t.getClass();
		}
		
	}
	
	public static <T> void printArray(T[] array) {
		
		for(T element : array) {
			System.out.println(element);
		}
		System.out.println();
	}
	
	
	public static void main(String[] argv) {
		
		
		
		Exercises ex = new Exercises();
		Integer [] ints = {1,2,3,4,5};
		Character [] chars = {'a','b', 'c', 'd', 'e'};
		Boolean [] bools = {true, false, true, false, false};
		
		printArray(ints);
		printArray(chars);
		printArray(bools);
		
		FooReference<Integer> intRef = ex.new FooReference<Integer>(1);
		FooReference<String> strRef = ex.new FooReference<String>("Hello");
		
		System.out.println("intRef.getT() " + intRef.getT());
		System.out.println(intRef.getClassAtRunTime());
		intRef.setT(6);
		System.out.println("intRef.getT() " + intRef.getT());
		
		System.out.println("strRef.getT() " + strRef.getT());
		System.out.println(strRef.getClassAtRunTime());
		strRef.setT("World");
		System.out.println("f.getT() " + strRef.getT());
		
		
		List rawList;
		List<?> listOfAnyType = null;
		List<Object> listOfObject = new ArrayList<Object>();
		List<String> listOfString = new ArrayList<String>();
		List<Integer> listOfInteger = new ArrayList<Integer>();
		
		rawList = listOfAnyType;
		rawList = listOfString;
		rawList = listOfInteger;
		listOfAnyType = listOfString;
		listOfAnyType = listOfInteger;
		//listOfObject = (List<Object>)listOfString;

}
	
}

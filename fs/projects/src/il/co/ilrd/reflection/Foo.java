package il.co.ilrd.reflection;

import java.io.Serializable;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;

public class Foo implements Serializable, Cloneable, Runnable{

	private int a;
	public String b;
	
	public void f1() {
		System.out.println("Inside f1");
	}
	
	private void f2() {
		System.out.println("Inside f2");
	}
	
	public static void main(String[] argv) throws InstantiationException, IllegalAccessException {
		
		Foo foo = new Foo();
		Class classObj = foo.getClass();
		
		System.out.println("Foo Class Name: "+ classObj.getName());
		System.out.println("Foo SuperClass Name: " + classObj.getSuperclass().getName());
		
		Class[] InterfaceList = classObj.getInterfaces();
		
		System.out.print("Implemented interfaces are : ");
		for (Class class1 : InterfaceList)	{
			System.out.println(class1.getName() + " ");
		}
		
		int accessModifier= classObj.getModifiers(); 
		System.out.println("Access modifiers of the class are : " + Modifier.toString(accessModifier));
		
		Field[] field = classObj.getDeclaredFields();
		
		for(Field fieldVar : field) {

			System.out.println("Variable name : "+fieldVar.getName());
			System.out.println("Datatypes of the variable :"+fieldVar.getType());
		}
		
		Foo obj = (Foo) classObj.newInstance();
		obj.f1();
		obj.f2();
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		
	}
}

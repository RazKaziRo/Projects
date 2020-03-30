package il.co.ilrd.reflection;

import java.io.Console;
import java.lang.reflect.Modifier;

public class GetClassMetaData {

	public static void main (String [] args) throws ClassNotFoundException { 
		
	Class ClassObj = Base.class;
	
	System.out.println("Name of the class is : " +ClassObj.getName());
	
	System.out.println("Name of the super class is : " +ClassObj.getSuperclass().getName());
	
	Class[] InterfaceList = ClassObj.getInterfaces();
	
	System.out.print("Implemented interfaces are : ");
	for (Class class1 : InterfaceList)	{
		System.out.println(class1.getName() + " ");
	}
	System.out.println();
	
	int accessModifier= ClassObj.getModifiers(); 
	System.out.println("Access modifiers of the class are : " +Modifier.toString(accessModifier));
	
	}
}
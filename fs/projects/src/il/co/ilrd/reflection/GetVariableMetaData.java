package il.co.ilrd.reflection;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;

public class GetVariableMetaData {
	public static void main(String[] args) throws IllegalArgumentException, IllegalAccessException { 
		
	VariableMetaData classVar = new VariableMetaData(); 
	Class classObjVar = classVar.getClass();
	
	Field[] field = classObjVar.getDeclaredFields();
	
	for(Field fieldVar : field) { 
	System.out.println("Variable name : "+fieldVar.getName());
	System.out.println("Datatypes of the variable :"+fieldVar.getType());
	
	int accessModifiers = fieldVar.getModifiers();
	System.out.println("Access Modifiers of the variable : "+ Modifier.toString(accessModifiers));
	System.out.println("Value of the variable : "+fieldVar.get(classVar));
	System.out.println();
	System.out.println("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *") ;
	}
	}
}
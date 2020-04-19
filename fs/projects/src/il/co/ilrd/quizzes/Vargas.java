package il.co.ilrd.quizzes;

public class Vargas {

		/* - Known also as Variable Arguments
		 * 
		 * The varags allows the method to accept zero or muliple arguments. 
		 * Before varargs either we use overloaded method or take an array as the method parameter 
		 * 
		 * public void foo() { }
		 * public void foo(int a1) { }
		 * public void foo(int a1, int a2) { }
		 * public void foo(int a1, int a2, int a3) { }
		 * public void foo(int a1, int a2, int a3, int... rest) { }
		 * 
		 * Cons:
		 * leads to the maintenance problem.
		 *  
		 * Pros:
		 * we dont have to provide oveloaded methods for each combination = less code
		 * 
		 * If we don't know how many argument we will have to pass in the method use varargs!
		 * 
		 * Syntax:
		 * return_type method_name(data_type... variableName){}  
		 *
	
		 * Rules for varargs:
		 * 	- There can be only one variable argument in the method.
		 *  - Variable argument (varargs) must be the last argument.
		 *  
		 *  BAD!-
		 *  void method(String... a, int... b){}//Compile time error  
		 *  void method(int... a, String b){}//Compile time error  
		 *
		 */
		 
	
		//The WRONG way to use varargs to pass one or more arguments!
		static int min(int... args) {
			
			if (args.length == 0)
				throw new IllegalArgumentException("Too few arguments");
			
			int min = args[0];
			for (int i = 1; i < args.length; i++)
				if (args[i] < min)
					min = args[i];
			
			return min;
			}
		
		//invoked with no arguments will fail at run time + its ugly :)
		
		// The right way to use varargs to pass one or more arguments
		static int min(int firstArg, int... remainingArgs) {
			
			int min = firstArg;
			
			for (int arg : remainingArgs)
				if (arg < min)
					min = arg;
			return min;
			}
	
	 	static void display(String... values){  
	 		
	 		System.out.println("display method invoked "); 
	 		
	 		for(String s:values){ 
	 			System.out.println(s);  
	 		}  
	 	}
		
	 	public static void main(String[] argv) {
	 		
	 		 display();	//zero argument   
	 		 display("my","name","is","varargs");//four arguments  
	 	}
		
}

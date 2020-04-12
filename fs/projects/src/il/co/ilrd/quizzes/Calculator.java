package il.co.ilrd.quizzes;

public class Calculator {
	
	interface Operator{
		int operate(int a, int b);
	}

	
	public int operation(int a, int b, Operator op) {
		return op.operate(a, b);
	}
	
	static Operator subtraction = new Operator() {

		@Override
		public int operate(int a, int b) {
			return a-b;
		}

	};
	
	static Operator addition = (int a, int b)-> a + b;
	
	static class Multiplication implements Operator{

		@Override
		public int operate(int a, int b) {

			return a * b;
		}
		
	}
	
	class Division implements Operator{

		@Override
		public int operate(int a, int b) {
			return a/b;
		}
		
	}
	

	public static void main(String [] argv) {
		Calculator calc = new Calculator();
		Calculator.Multiplication multi = new Calculator.Multiplication();
		
		System.out.println(calc.operation(10, 20, addition));
		System.out.println(Calculator.subtraction.operate(100, 10));
		System.out.println(multi.operate(5, 5));
		System.out.println(calc.new Division().operate(100, 10));

		
		
	}

}

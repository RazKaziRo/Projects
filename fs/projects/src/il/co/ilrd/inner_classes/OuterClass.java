package il.co.ilrd.inner_classes;

public class OuterClass {
	
	private int j = 1;
	InnerClass inner = new InnerClass(this);
	
	private void printK() {
		System.out.println("outer k");
	}
	private void printM() {
		System.out.println(inner.m);
	}
	
	 public static class InnerClass{
		 
		public int j = 0;
		private String m = "inner m";
		OuterClass outer;
		
		public InnerClass(OuterClass outer) {
			this.outer = outer;
		}
		
		void printJ(int j) {
			outer.printK();
			System.out.println("inner j");
			System.out.println(outer.j);
			System.out.println(this.j);
			
		}
	}

	public static void main(String [] argv) {
			
		OuterClass outer = new OuterClass();
		OuterClass.InnerClass inner = new InnerClass(outer);
		
		outer.printK();
		outer.printM();
		inner.printJ(22);
	}
}

package il.co.ilrd.quizzes;

import static java.lang.Math.sqrt;

public class April23_Quizz {
	
	class Point{
		
		private int x = 0,y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public Point() {
			super();
		}

	}
	
	
	public static void main(String[] argv) {
	StringBuffer strBuffer = new StringBuffer("This, that, etc.!");
	System.out.println(strBuffer.replace(12, 15, "etcetera"));
	System.out.println(sqrt(4));
	
	}
}

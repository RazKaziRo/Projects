package il.co.ilrd.quizzes;

public class April12_Quizz {

	
	enum NUM_OF_DAYS{
		SUNDAY;
	};
	
		static int outer_static;
		static private int outer_int;
		String outer_str;
		private char outer_char;
		
		private class Inner{
			
			int foo(Nested c) {
				return c.a = 3;
			}
			
			private int inner_private;
			static final int c = 3;

		
		void bar(){
			
				System.out.println(outer_int);
				System.out.println(outer_static);
				System.out.println(outer_str);
				System.out.println(outer_char);
				System.out.println(April12_Quizz.this);
				System.out.println();

			}
		}
		private static class Nested{
			private int a;
			
			
			void bar(){
				
				System.out.println(outer_int);
				System.out.println(outer_static);
				
				}
			}
		void foo() {
			class Local{
				int local_int;
				
				void bar(){
					System.out.println(outer_int);
					System.out.println(outer_static);
					System.out.println(outer_str);
					System.out.println(outer_char);
					System.out.println(April12_Quizz.this);

				}
			}
			
		}
}



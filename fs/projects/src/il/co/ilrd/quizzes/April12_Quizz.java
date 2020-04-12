package il.co.ilrd.quizzes;

public class April12_Quizz {

		static int outer_static;
		static private int outer_int;
		String outer_str;
		private char outer_char;
		
		private class Inner{
			
			private int inner_private;
			int inner_int;
			
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
			
			static int nested_static;
			
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
					System.out.println(Nested.nested_static);


				}
			}
			
		}
}



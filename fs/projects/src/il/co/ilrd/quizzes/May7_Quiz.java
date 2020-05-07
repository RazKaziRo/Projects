package il.co.ilrd.quizzes;

public class May7_Quiz {

	static String encodeStr(String str) {
		
		
		char charHolder;
		char[] charArray = new char[str.length()];
		
		for(int i = 0, k = 0; i < str.length() - 1; ++i) {
			char counter = '0';
			
			charHolder = str.charAt(i);
			++counter;
			
			while( i  < str.length() - 1 && charHolder == str.charAt(i + 1)) {
				++counter;
				++i;
			}
			
			charArray[k] = charHolder;
			charArray[k+1] = counter;
			k += 2;
				
		}
		
		return new String(charArray);
	}
	
	public static void main(String [] argv) {
		
		 String str = "aaabbacccc";
		 System.out.println(encodeStr(str));
	}

}

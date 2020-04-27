package il.co.ilrd.quizzes;

import java.lang.reflect.Array;
import java.util.Arrays;

public class April26_Quiz {
	
	public static boolean isPermutation(String s, String t) {
		
		if(s.length() != t.length()) {
			return false;
		}
		
		char[] sArr = s.toCharArray();
		Arrays.sort(sArr);
		
		char[] tArr = t.toCharArray();
		Arrays.sort(tArr);
	
		return Arrays.equals(sArr, tArr);
						
	}
	
	public static boolean isRotation(String s1, String s2) {
		
		if(s1.length() != s2.length()) {
			return false;
		}
		
		return s1.contains(s2);
	}
	
	public static void main(String [] argv) {
		System.out.println(isPermutation("HARRY","YRAHR"));
		System.out.println(isPermutation("HARRY","YLAHR"));

	}

}

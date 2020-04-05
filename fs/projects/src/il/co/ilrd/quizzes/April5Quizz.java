package il.co.ilrd.quizzes;

import java.util.ArrayList;
import java.util.List;

public class April5Quizz {
	
	public <Object> void printfall(List<Object> list){
		System.out.println(list.toString());
	}
	
	public static void main(String[] argv) {
		
		April5Quizz ap = new April5Quizz();
		List<String> strings = new ArrayList<String>();
		strings.add("a");
		strings.add("e");
		
		List<Integer> ints = new ArrayList<Integer>();
		ints.add(1);
		ints.add(2);
		
		ap.printfall(strings);
		ap.printfall(ints);

		
	}
	

}


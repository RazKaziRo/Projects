import java.util.HashSet;

public class Quizz {

	public static boolean isSumFound(Integer[] arr, Integer sum) {
		
		HashSet<Integer> set = new HashSet<Integer>();
		
		for(Integer existNum : arr) {
			if(set.contains(sum - existNum)) {
				
				return true;
			}
			else {
				set.add(existNum);
			}
		}
		return false;
		
	}
	
	public static void main(String[] args) {
		
		Integer arr[] = {2,5,7,4,3,8};
		Integer sum = 11;
		
		System.out.println(isSumFound(arr,sum));
	}

}

package il.co.ilrd.quizzes;

public class May13_Quiz {

	public static void sortArray(int[] arr) {
		
		if(arr.length <= 1) {
			return;
		}
		
		for(int i = 0; i < arr.length; ++i) {
			
			int numA;
			int numB;
			
			if(arr[i]%2 != 0) {
				numA = arr[i];
				
				for(int j = i + 1; j < arr.length; ++j) {
					
					numB = arr[j];
					
					if(arr[i] > arr[j] && arr[j] % 2 != 0) {
						
						arr[i] = numB;
						arr[j] = numA;
						numA = numB;
					}

				}
			}
		}
	}
	
	public static void main(String[] args) {
		int[] arr = {9, 3, 2, 8, 1, 4, 7, 5};
		sortArray(arr);
		
		for(int i = 0; i < arr.length; ++i) {
			System.out.print(arr[i] + ",");
		}
		
	}

}

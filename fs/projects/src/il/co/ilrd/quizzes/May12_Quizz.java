package il.co.ilrd.quizzes;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;


public class May12_Quizz {
		
	public static int findSubarrayMaxSum(int[] arr) {
		
		int maxSum = Integer.MAX_VALUE;
		int tempSum = Integer.MIN_VALUE;
		
		for(int i = 0; i < arr.length; ++i) {
			
			maxSum += arr[i];
			
			if(maxSum < 0) {
				maxSum = 0;
			}
			else if(tempSum < maxSum) {
				tempSum = maxSum;
			}
		}
		
		return tempSum;
	}

	public static void main(String[] args) {
		
		int[] arr = {-2, -1,-3, -3, -1, 2, 1, -5, 4};
		System.out.println(findSubarrayMaxSum(arr));

	}

}

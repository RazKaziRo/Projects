package il.co.ilrd.collection;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.stream.Collectors;

public class Exercise {

		public static class DataObject{
			
			private String code;
			private int value;
			
			public DataObject(String code, int value) {
				this.code = code;
				this.value = value;
			}
			
			public String getCode() {
				return code;
			}

			public int getValue() {
				return value;
			}

		}
		
		public static void main(String[] argv) {
			
			Exercise ex = new Exercise();
			
			int [] intArray = {3,2,6,1,9};
			for(int element : intArray) {
				System.out.println(element);
			}
			
			List<Integer> integerArr = 
					Arrays.stream(intArray).boxed().collect(Collectors.toList());
			
			Collections.sort(integerArr);
			
			for(Integer element : integerArr) {
				System.out.print(element + ", ");
			}
			System.out.println("\n");
			
			HashMap<String, Integer> daysOfWeek = new HashMap<String, Integer>();
			
			daysOfWeek.put("Sunday", 1);
			daysOfWeek.put("Monday", 2);
			daysOfWeek.put("Tuesday", 3);
			daysOfWeek.put("Wednesday", 4);
			daysOfWeek.put("Thursday", 5);
			daysOfWeek.put("Friday", 6);
			daysOfWeek.put("Saturday", 7);
			
			for(Entry<String, Integer> element : daysOfWeek.entrySet()) {
				System.out.println("Key: " + element.getKey() + "| Value: " + element.getValue());
			}
			
			Integer sum = 0;
			Exercise.DataObject[] array = new DataObject[5];
			
			array[0] = new DataObject("A", 1);
			array[1] = new DataObject("B", 2);
			array[2] = new DataObject("C", 3);
			array[3] = new DataObject("D", 4);
			array[4] = new DataObject("E", 5);
			
			HashMap<String, Integer> hashDataObject = new HashMap<String, Integer>();
			for(int i = 0 ; i < array.length; ++i) {
				hashDataObject.put(array[i].getCode(), array[i].value);
			}
			
			for(Integer element : hashDataObject.values()) {
				
				sum+=element;
			}
			
			System.out.println(sum);
			
			
		}
}

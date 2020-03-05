import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Arraylist { 

    public static void main(String[] args) 
    { 
      int num_of_ints = 100000; 
      int num_of_arrays = 1000;

     	Runtime r = Runtime.getRuntime();  
 	
		  ArrayList<int[]> list = new ArrayList<int[]>();

 		 for(int i = 0; i < num_of_arrays; ++i)
 		 {
 			  list.add(new int[num_of_ints]);

 			System.out.println("Free Memory1: " + r.freeMemory()); 
  			System.out.println("Total Memory: " + r.totalMemory());
     	}

     	while(true)
     	{
     		System.out.println("Free Memory1: " + r.freeMemory()); 
     	}

   }
}

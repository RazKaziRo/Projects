import java.util.Arrays; 

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Integer one = new Integer(1);
		Integer anotherOne = new Integer(1);
		
		if(0 == one.compareTo(anotherOne)) {
			System.out.println("both one are equal");
		}
		else {
			System.out.println("both one are not equal");
		}
		
        char[] copyFromA = { 'd', 'e', 'c', 'a', 'f', 'f', 'e','i', 'n', 'a', 't', 'e', 'd' };
        char[] copyToA = new char[7];
        
        /* public static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)*/
        System.arraycopy(copyFromA, 2, copyToA, 0, 7); 
        System.out.println(new String(copyToA));
        
        char[] copyFromB = {'d', 'e', 'c', 'a', 'f', 'f', 'e', 'i', 'n', 'a', 't', 'e', 'd'};     
        char[] copyToB = Arrays.copyOfRange(copyFromB, 2, 9);
            
         System.out.println(new String(copyToB));
         
         int[] arrC = {13, 7, 6, 45, 21, 9, 101, 102}; 
         Arrays.parallelSort(arrC);
         
        for (int i = 0; i < arrC.length; ++i) {
        	System.out.print(arrC[i] + ",");
        }
        System.out.println();
        
        int searchVal = 45;
        int retVal = Arrays.binarySearch(arrC,searchVal);
        System.out.println("The index of element 45 is : " + retVal);
        	
        
        Arrays.fill(arrC, 18);
        System.out.println("After Fill 18:");
        for (int value : arrC) {
            System.out.print(value + ",");
         }
        System.out.println();
        
        
    	String str1 = "Hello";
    	String str2 = "Hello";
    	String str3 = new String("Hello");
    	
    	System.out.println("str1 == st2" + str1 == str2);
    	System.out.println("str1 == str3" + str1 == str3);
    	
    	int i = 10;
    	int j = 11;
    	int k = 11;
    	
    	System.out.println("k == j" + " " +(k == j));
    	
    	int [] arrA = {1,2,3};
    	int [] arrB = {1,2,3};
    	
    	System.out.println("arrA == arrB" +  " " + (arrA ==  arrB));
    	System.out.println("arrA.equals(arrB)" + " " + (arrA.equals(arrB)));
    	
    	StringBuffer strBuffer = new StringBuffer("This, that, etc.!");
    	System.out.println(strBuffer.replace(12, 15, "etcetera"));
    	
    	Boolean b = null;
    	System.out.println(b ? true : false);
	}

}

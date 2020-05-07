package il.co.ilrd.quizzes;

public class May5_Quizz {
	
	static int fibRec(int n) {
		
		if(n == 0 || n == 1) {
			return n;
		}
		else {
			
			return fibRec(n -1) + fibRec (n - 2);
		}
				
	}
	
		static int fibIter(int n){
			
			int res = 0;
			int n1 = 0 , n2 = 1;
			
		    for(int i = 1; i < n; ++i){
		    	res = n1 + n2;
		    	n1 = n2;
		    	n2 = res;
		    }
		    
		    return res;
		}
		
	static int fibDynamic(int n) 
	{ 
		int f[] = new int[n+2];
		int i; 
		       
		f[0] = 0; 
		f[1] = 1; 
		      
		    for (i = 2; i <= n; i++) 
		    { 
		        f[i] = f[i-1] + f[i-2]; 
		    } 
		       
		    return f[n]; 
		    }



	public static void main (String[] argv) {
	}
}

class Ex5{ 

public static void main(String[] args) { 

  int k = 0;
  RecFunction(k);

} 

public static void RecFunction(int num){

    if(num < 1000)
    {

      System.out.println(num);
      RecFunction(++num);

    }
}

}
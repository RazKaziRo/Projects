
/**
 * @author      Raz KaziRo 	<razkaziro@gmail.com>
 * @version     1.0                 (current version number of program)
 * @since       0.0         (the version of the package this class was first added to)
 */


class HelloWorldApp
{
    public static void main(String[] args)
    {
    	MySecondClass object = new MySecondClass();

        System.out.println("Hello World!"); 
        MySecondClass.foo1();
        object.foo2();
    }
}
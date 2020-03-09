import static org.junit.Assert.*;

import org.junit.Test;

public class ComplexTests {

	@Test
	public void testAddition() {
		
		ComplexNumber c1 = new ComplexNumber (5.5, 4);
		ComplexNumber c2 = new ComplexNumber(1.2, 3.5);
		
		ComplexNumber result = new ComplexNumber(6.7, 7.5);
		
		System.out.println("add " + c1.addition(c2));
		assertEquals("FAIL: FAIL ADD ",  c1.addition(c2), result);

	}

	/*@Test
	public void testSubtraction() {
		fail("Not yet implemented");
	}

	@Test
	public void testMultiplyBy() {
		fail("Not yet implemented");
	}

	@Test
	public void testDivideBy() {
		fail("Not yet implemented");
	}

	@Test
	public void testParse() {
		fail("Not yet implemented");
	}*/

}

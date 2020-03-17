package il.co.ilrd.complex_number;

import static org.junit.Assert.*;

import org.junit.Test;

public class ComplexTest {

	ComplexNumber c1 = new ComplexNumber();
	ComplexNumber c2 = new ComplexNumber();
	ComplexNumber result = new ComplexNumber();
	ComplexNumber expected = null;
	
	@Test
	public void testAddition() {
		
		c1 = new ComplexNumber(5, 2);
		c2 = new ComplexNumber(7, 12);
		result = new ComplexNumber(12, 14);
		expected = c1.addition(c2);
		
		assertEquals(expected, result);
		
		c1 = new ComplexNumber(-2, -15);
		c2 = new ComplexNumber(-12, 13);
		result = new ComplexNumber(-14, -2);
		expected = c1.addition(c2);
		 
		assertEquals(expected, result);

	}
	
	@Test
	public void testSubtraction() {
		
		 c1 = new ComplexNumber(8, 6);
		 c2 = new ComplexNumber(5, 2);
		 result = new ComplexNumber(3, 4);
		 expected = c1.subtraction(c2);
		
		assertEquals(expected, result);
		
		c1 = new ComplexNumber(12, 14);
		c2 = new ComplexNumber(3, -2);
		result = new ComplexNumber(9, 16);
		expected = c1.subtraction(c2);
		 
		assertEquals(expected, result);
	}
	
	@Test
	public void testMultiplyBy() {
		
		c1 = new ComplexNumber(3, 4);
		c2 = new ComplexNumber(3, 4);
		result = new ComplexNumber(-7, 24);
		expected = c1.multiplyBy(c2);
		
		assertEquals(expected, result);
		
		c1 = new ComplexNumber(1, 3);
		c2 = new ComplexNumber(2, 1);
		result = new ComplexNumber(-1, 7);
		expected = c1.multiplyBy(c2);
		assertEquals(expected, result);
		
	}
	
	
	@Test
	public void testDivideBy() {
		
		c1 = new ComplexNumber(3, -1);
		c2 = new ComplexNumber(2, -2);
		
		result = new ComplexNumber(1, 0.5);
		expected = c1.divideBy(c2);
		
		assertEquals(expected, result);
	}
	
	
	@Test
	public void testParseComplex() {
		
		ComplexNumber parsedC1 = ComplexNumber.parseComplex("5.3 + 3.1i");
		ComplexNumber parsedC2 = ComplexNumber.parseComplex("11.3 + 2.2i");

		c1 = new ComplexNumber(5.3, 3.1);
		c2 = new ComplexNumber(11.3, 2.2);

		assertEquals(parsedC1, c1);
		assertEquals(parsedC2, c2);
		
		 parsedC1 = ComplexNumber.parseComplex("0 + 3.1i");
		 parsedC2 = ComplexNumber.parseComplex("11.3 + 0i");
		
		c1 = new ComplexNumber(0, 3.1);
		c2 = new ComplexNumber(11.3, 0);
		
		assertEquals(parsedC1, c1);
		assertEquals(parsedC2, c2);
		
		parsedC1 = ComplexNumber.parseComplex("1");
		parsedC2 = ComplexNumber.parseComplex("1i");
		
		c1 = new ComplexNumber(1, 0);
		c2 = new ComplexNumber(0, 1);
		
		assertEquals(parsedC1, c1);
		assertEquals(parsedC2, c2);
		
		parsedC1 = ComplexNumber.parseComplex("+11.7 - 5.3i");
		parsedC2 = ComplexNumber.parseComplex("-3.6 + 1i");
		
		c1 = new ComplexNumber(11.7, -5.3);
		c2 = new ComplexNumber(-3.6, 1);
		
		assertEquals(parsedC1, c1);
		assertEquals(parsedC2, c2);
		
		parsedC1 = ComplexNumber.parseComplex("0");
		parsedC2 = ComplexNumber.parseComplex("-i");
		
		c1 = new ComplexNumber(0, 0);
		c2 = new ComplexNumber(0, -1);
		
		assertEquals(parsedC1, c1);
		assertEquals(parsedC2, c2);

	}
	
	@Test
	public void testIsReal() {
		
		c1 = new ComplexNumber(3.3, 6);
		c2 = new ComplexNumber(1.9, 0);
		
		assertEquals(c1.isReal(), false);
		assertEquals(c2.isReal(), true);
		
		c1 = new ComplexNumber(-3.3, 6);
		c2 = new ComplexNumber(0, 0);
		
		assertEquals(c1.isReal(), false);
		assertEquals(c2.isReal(), true);
	}
	
	@Test
	public void testIsImg() {
		
		c1 = new ComplexNumber(3.3, 6);
		c2 = new ComplexNumber(0, 6.9);
		
		assertEquals(c1.isImg(), false);
		assertEquals(c2.isImg(), true);
		
		c1 = new ComplexNumber(-3.3, 6);
		c2 = new ComplexNumber(0, 0);
		
		assertEquals(c1.isImg(), false);
		assertEquals(c2.isImg(), true);
	}
}

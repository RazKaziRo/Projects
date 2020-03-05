package shapes;
//import static java. lang. Math. *;

public class Circle extends Shape{

	double radius;
	
	Circle() {	
		
		this.radius = 1.0;
	}
	
	Circle(double radius) {
		
		this.radius = radius;
	}
	
	Circle(double radius, String color, Boolean filled) {
		
		super(color, filled);
		this.radius = radius;
	}
	
	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		
		this.radius = radius;
	}
	
	public double getArea() { 
		
		return Math.PI * (Math.pow(this.radius, 2));
	}
	
	public double getPerimeter() {
		
		return (2 * Math.PI * this.radius);
	}

	@Override
	public String toString() {

		return "A Circle with radius " + this.radius + " ,which is a subclass of " + super.toString();
	}
}

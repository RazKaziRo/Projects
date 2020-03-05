package shapes;
public abstract class Shape {
	
	String color;
	boolean filled;

	Shape(){
		this.color = "Green";
		this.filled = true;
	}
	
	Shape(String color, boolean filled){
		this.color = color;
		this.filled = filled;
	}
	
	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public boolean isFilled() {
		return filled;
	}

	public void setFilled(boolean filled) {
		this.filled = filled;
	}

	abstract public double getArea();
	abstract public double getPerimeter();
	
	@Override
	public String toString() {
		
		return "A Shape With Color of " + color + " And " + (isFilled() ? "Filled" : "Not Filled");
	}

}



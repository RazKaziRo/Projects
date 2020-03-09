import static java.lang.Math.*;

public class ComplexNumber implements Comparable <ComplexNumber> {
	
		private double real, img;
		
		ComplexNumber(){
			
			real = 0;
			img = 0;
		}
		
		ComplexNumber(double real, double img){
			
			this.real = real;
			this.img = img;
		}
		
		public ComplexNumber addition(ComplexNumber c){
			
			return new ComplexNumber((this.real + c.real), (this.img + c.img));
		}
		
		public ComplexNumber subtraction(ComplexNumber c){
			
			return new ComplexNumber((this.real - c.real), (this.img - c.img));
		}
		
		public ComplexNumber multiplyBy(ComplexNumber c){
			
			return new ComplexNumber(((this.real * c.real) - (this.img * c .img)), 
					((this.real * c.img) + (c.real * this.img)));
		}
		
		public ComplexNumber divideBy(ComplexNumber c){
			
			return new ComplexNumber((this.real * c.real) + (this.img * c.img) / (pow(c.real, 2) + pow(c.img, 2)), 
					((this.img * c.real) - (this.real * c.img)) / (pow(c.real, 2) + pow(c.img, 2)));
		}

		public double getReal() {
			return real;
		}

		public void setReal(double real) {
			this.real = real;
		}

		public double getImg() {
			return img;
		}

		public void setImg(double img) {
			this.img = img;
		}
		
		public void setValue(double real, double img) {
			
		}
		/*
		public boolean isReal() {
			
		}
		
		public boolean isImg() {
			
		}
		
		public static ComplexNumber parse(String str) {
			
		}
		
		*/
		
		@Override
		public int compareTo(ComplexNumber c) {
			
			Double thisHolder = this.real;
			Double cHolder = c.real;
				
			int result = thisHolder.compareTo(cHolder);
			
			if (result == 0) {
				
				thisHolder = this.img;
				cHolder = c.img;
				
				return thisHolder.compareTo(cHolder);
			}
			
		return result;
		
		}

		
		@Override
		public String toString() { 
			return (this.real + " + " + this.img +  "i");
		}
		
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			ComplexNumber other = (ComplexNumber) obj;
			if (Double.doubleToLongBits(img) != Double.doubleToLongBits(other.img))
				return false;
			if (Double.doubleToLongBits(real) != Double.doubleToLongBits(other.real))
				return false;
			return true;
		}
		
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			long temp;
			temp = Double.doubleToLongBits(img);
			result = prime * result + (int) (temp ^ (temp >>> 32));
			temp = Double.doubleToLongBits(real);
			result = prime * result + (int) (temp ^ (temp >>> 32));
			return result;
		}
}

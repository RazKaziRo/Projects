public class EmployeeList {

    public static void main(String[] args) {

        System.out.println("First Avilable ID: " + Employee.getNextID());

        Employee a = new Employee("John Doe");
        Employee b = new Employee("Jane Smith");
        Employee c = new Employee("Sally Brown");

        System.out.println("Next Avilable ID: " + Employee.getNextID());
        System.out.println("a instanceof Employee" + " " + (a instanceof Object));
        
        System.out.println(a.getID() + ": " + a.getName());
        System.out.println(b.getID() + ": " + b.getName());
        System.out.println(c.getID() + ": " + c.getName());

    }

}
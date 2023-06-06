class EmployeeDemo{
    public static void main(String[] args){
	Employee a = new Employee("a", 50000, 2013, "1233344");
	Employee b = new Employee("a", 50000, 2013, "1233344");
	Employee c = new Employee(50000, "1233344");
	System.out.println(a.equals(b));
	
    }
}

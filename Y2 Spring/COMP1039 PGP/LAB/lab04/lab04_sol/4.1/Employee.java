class Employee extends Person{
    private double salary;
    private int year;
    private String nin;

    public Employee(String m, double s, int y, String id){
	super(m);
	salary = s;
	year = y;
	nin = id;
    }

    //
    public Employee(double s, int y, String id){
	super();
	salary = s;
	year = y;
	nin = id;
    }

    public Employee(String n, int y, String id){
	this(n, 0, y, id);
    }

    public Employee(String n, double s, String id){
	this(n, s, 0, id);
    }

    public Employee(String n, double s, int y){
	this(n, s, y, "");
    }
    //
    
    public Employee(String n, double s){
	this(n, s, 0, "");
    }

    public Employee(String n, int y){
	this(n, 0, y, "");
    }

    public Employee(String n, String id){
	this(n, 0, 0, id);
    }

    public Employee(double s, int y){
	this(s, y, "");
    }

    public Employee(double s, String id){
	this(s, 0, id);
    }

    public Employee(int y, String id){
	this(0, y, id);
    }
    //
    public Employee(String n){
	super(n);
    }

    public Employee(double s){
	this(s, "");
    }

    public Employee(int y){
	this(y, "");
    }

    public Employee(){
	this(0, 0, "");
    }

    public double getSalary(){
	return salary;
    }

    public int getYear(){
	return year;
    }

    public String getNIN(){
	return nin;
    }
   
     
    public boolean equals(Object o)
    {
	if(o == null)
	    return false;
	if(this == o)
	    return true;
	if(o instanceof Employee){
	    Employee e = (Employee) o;
	    if(!this.getName().equals(e.getName()))
		return false;
	    if(salary != e.getSalary())
		return false;
	    if(year != e.getYear())
		return false;
	    if(!this.getNIN().equals(e.getNIN()))
		return false;
	    return true; 
	}
	
	return false;
    }
 
}




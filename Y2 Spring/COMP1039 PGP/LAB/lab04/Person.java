public class Person
{
	private String name;

	public Person()
	{
		name = "No name yet.";
	}
	public Person(String n)
	{
		name = n;
	}
	public void setName(String newName)
	{
		name = newName;
	}
	public String getName()
	{
		return name;
	}
	public void print()
	{
		System.out.println("Name: " + name);
	}
	public boolean equals(Object p)
	{
	    if(p instanceof Person){
		return this.name.equals(((Person)p).getName());
	    }
	    return false;
	}
}

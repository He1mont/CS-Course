public class CounterDemo{
	public static void main(String[] args){
		for(int i = 0; i < 3; i++){
			MyClass obj = new MyClass();
			System.out.println("Class " + MyClass.count);
			// count presents # objects
		}
	}
}

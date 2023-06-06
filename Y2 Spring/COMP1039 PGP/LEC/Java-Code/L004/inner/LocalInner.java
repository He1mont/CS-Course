public class LocalInner{

    void aMethod(){
		class Inner{
			void print(){
				System.out.println("This is a method inner class");
			}
		}
		Inner inner = new Inner();
		inner.print();
    }


    public static void main(String[] args){
		LocalInner local = new LocalInner();
		local.aMethod();
    }
}

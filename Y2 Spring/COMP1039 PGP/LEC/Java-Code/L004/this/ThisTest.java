public class ThisTest{
    int a;
    int b;

    // Here setData is a method, not a Constructor
    public void setData(int a, int b){
        this.a = a;
        this.b = b; 
    }
    // the value of a local variable is assigned to 
    // an instance varaible of the same name

    public void showData(){
        System.out.println("a = " + a);
        System.out.println("b = " + b);
    }

    public static void main(String[] args){
	
        ThisTest tt = new ThisTest();

        tt.setData(10, 20);
        tt.showData();
    }
}

public class SDemo{
    public static void main(String[] args){
	StaticDemo ob1 = new StaticDemo();
	StaticDemo ob2 = new StaticDemo();

	ob1.x = 10;				// 通过对象调用
	ob2.x = 20;
	StaticDemo.y = 19;		// 直接通过类名调用
	System.out.println("sum ob1: " + ob1.sum());
	System.out.println("sum ob2: " + ob2.sum());

	StaticDemo.y = 100;
	System.out.println("sum ob1: " + ob1.sum());
	System.out.println("sum ob2: " + ob2.sum());
    }
}

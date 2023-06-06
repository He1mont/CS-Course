class MyClass{
	int x;
	MyClass(){
		System.out.println(x);
	}
	MyClass(int i){
		x = i;
		System.out.println(x);
	}
	MyClass(int i, int j){
		x = i + j;
		System.out.println(x);
	}
}

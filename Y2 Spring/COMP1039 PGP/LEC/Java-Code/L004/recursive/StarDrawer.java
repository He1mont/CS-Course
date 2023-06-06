class StarDrawer{
    void drawStars(int n){
		if(n == 1)
			System.out.println("*");
		else{
			System.out.print("*");
			drawStars(n-1);
		}
    }
}

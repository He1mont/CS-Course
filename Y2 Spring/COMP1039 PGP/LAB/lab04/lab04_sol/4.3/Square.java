class Square extends Rectangle{
    double side;

    public Square(double s){
	super();
	side = s;
    }

    public Square(double s, String c, boolean f){
	super(c, f);
	side = s;
    }

    public double getArea(){
	return side * side;
    }

    public double getPerimeter(){
	return 4 * side;
    }
}

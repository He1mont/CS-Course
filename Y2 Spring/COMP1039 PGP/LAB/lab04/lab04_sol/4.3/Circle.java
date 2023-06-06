class Circle extends TwoDShape{
    double radius;

    public Circle(double r){
	super();
	radius = r;
    }

    public Circle(double r, String c, boolean f){
	super(c, f);
	radius = r;
    }

    public double getArea(){
	return Math.PI * radius * radius;
    }

    public double getPerimeter(){
	return 2 * Math.PI * radius;
    }
}

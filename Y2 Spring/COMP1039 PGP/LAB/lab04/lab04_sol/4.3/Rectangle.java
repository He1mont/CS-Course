class Rectangle extends TwoDShape{
    double width;
    double height;

    public Rectangle(String c, boolean f){
	super(c, f);
    }

    public Rectangle(){
	super();
    }
    
    public Rectangle(double w, double h){
	super();
	width = w;
	height = h;
    }

    public Rectangle(double w, double h, String c, boolean f){
	super(c, f);
	width = w;
	height = h;
    }

    public double getArea(){
	return width * height;
    }

    public double getPerimeter(){
	return 2 * (width + height);
    }
}

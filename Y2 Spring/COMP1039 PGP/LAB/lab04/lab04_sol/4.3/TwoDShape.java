abstract class TwoDShape{
    protected String color;
    protected boolean filled;

    public TwoDShape(String c, boolean f){
	color = c;
	filled = f;
    }

    public TwoDShape(){
	this("white", false);
    }

    String getColor(){
	return color;
    }

    void setColor(String s){
	color = s;
    }

    boolean isFilled(){
	return filled;
    }

    void setFilled(boolean b){
	filled = b;
    }

    abstract double getArea();

    abstract double getPerimeter();
}

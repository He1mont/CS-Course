/**
 *
 */
public class Position{
    // value of x-axis
    private int x;
    // value of y-axis
    private int y;
    
    // constructor
    public Position(int x, int y){
	this.x = x;
	this.y = y;
    }
    // get the x value
    public int getX(){
	return this.x;
    }
    // get the y value
    public int getY(){
	return this.y;
    }

    // check if this position is the same with the given position
    public boolean equals(Object obj){
	if(this == obj)
	    return true;
	if(obj == null)
	    return false;
	if(obj instanceof Position){
	    Position p = (Position)obj;
	    if(p.getX() == x && p.getY() == y)
		return true;
	}
	return false;
    }

    // generate the position above
    public Position upPosition(){
	return new Position(x, y-1);
    }

    // generate the position below
    public Position downPosition(){
	return new Position(x, y+1);
    }

    // generate the position on the left of the current one
    public Position leftPosition(){
	return new Position(x-1, y);
    }

    // generate the position on the right of the current one
    public Position rightPosition(){
	return new Position(x+1, y);
    }

    // translate the current position to a string
    public String toString(){
	return "(" + x + "," + y + ")";
    }
    

}

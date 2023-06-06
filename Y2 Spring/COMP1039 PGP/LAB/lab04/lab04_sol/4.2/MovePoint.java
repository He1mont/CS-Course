class MovePoint implements Moveable{
    // variables
    private int x;
    private int y;

    public MovePoint(){
	x = 0;
	y = 0;
    }

    public MovePoint(int x, int y){
	this.x = x;
	this.y = y;
    }

    public void MoveUp(){
	this.y++;
    }

    public void MoveDown(){
	this.y--;
    }

    public void MoveLeft(){
	this.x--;
    }

    public void MoveRight(){
	this.x++;
    }

    public void print(){
	System.out.println("(" + x + "," + y + ")");
    }
}

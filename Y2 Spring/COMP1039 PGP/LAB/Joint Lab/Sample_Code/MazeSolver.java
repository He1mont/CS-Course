import java.util.ArrayList;

public class MazeSolver{

    // the maze we are goint to solve
    private String[] maze;
    // the current position of the agent
    private Position current;
    // the destination point
    private Position des;

    // set up an open list, i.e., what we are going to check next
    ArrayList<Position> open = new ArrayList<Position>();
    // set up a closed list, i.e., where we have already visited
    ArrayList<Position> closed = new ArrayList<Position>();
    // solution
    private String[] solution;

    // constructor
    public MazeSolver(String[] m){
	initMaze(m);
    }

    // TODO: a method to initialise the maze 
    public void initMaze(String[] m){
	this.maze = m;
	solution = null;
    }

    // a method to show the maze
    public void showMaze(){
	showString(maze);
    }

    // a method to show the solution
    public void showSolution(){
	showString(solution);
    }
    // a method to show an array of Strings
    private void showString(String[] s){
	if(s == null)
	    return;
	for(int i = 0; i < s.length; i++){
	    for(int j = 0; j < s[i].length(); j++){
		System.out.print(s[i].charAt(j));
	    }
	    System.out.println();
	}
    }

    // draw * at a specified location in a given maze
    private String[] drawStarAt(String[] ss, Position p){
	if(ss == null){
	    System.out.println("The given maze cannot be null");
	    return null;
	}
      
	// copy the array
	String[] sbs = new String[ss.length];
	System.arraycopy(ss, 0, sbs, 0, ss.length);

	if(p != null){
	    // get x and y value of the given position
	    int x = p.getX();
	    int y = p.getY();
	    // ensure the position is valid, given the maze
	    if(sbs.length > y && y >= 0 && sbs[y].length() > x && x >= 0){
		// use string builder
		StringBuilder sb = new StringBuilder(sbs[y]);
		sb.setCharAt(x, '*');
		sbs[y] = sb.toString();
	    }
	}
	return sbs;
    }


    

    // TODO: a method to find the first occurrence of a given character, row by row, from left to right
    private Position mazeFind(char c){
	// ...
	return null;
    }


    // TODO: get a character at a specified point
    private char mazeAt(Position p){
	// ...
	return '';
    }

    // TODO: return true if the given position is within the bounds of the maze, false, otherwise
    private boolean mazeInBounds(Position p){
	// ...
	return false;
    }


    // solve the maze using depth-first search
    /*
    public void solveDFS(){
	// initialise the open list
	open.clear(); // remove all elements
	open.add(current); // add the current location
	// initialise the closed list
	closed.clear();
	// initialise the state list
	ArrayList<String[]> paths = new ArrayList<String[]>();
	paths.add(maze);


	// search until there is no valid step
	while(open.size() > 0){
	    // get the first element in the openList
	    Position target = open.remove(0);
	    // and its corresponding path
	    String[] path = paths.remove(0);
	    // check the value of the target location
	    char value = mazeAt(target);

	    if(value == 'B'){ // goal
		solution = path;
		return;
	    }else if(value == '.' || value == 'A'){ // try adjacent points
		// update the current location
		String[] np = drawStarAt(path, target);
		// up
		Position up = target.upPosition();
		if(mazeInBounds(up) && !closed.contains(up)){ // if this point is valid and is not included in the closed list
		    open.add(0, up); // add it to the head of the list
		    paths.add(0, np); // add the updated path to the list of paths
		}
		// down
		Position down = target.downPosition();
		if(mazeInBounds(down) && !closed.contains(down)){ // if this point is valid and is not included in the closed list
		    open.add(0, down); // add it to the head of the list
		    paths.add(0, np); // add the updated path to the list of paths
		}
		Position left = target.leftPosition();
		if(mazeInBounds(left) && !closed.contains(left)){ // if this point is valid and is not included in the closed list
		    open.add(0, left); // add it to the head of the list
		    paths.add(0, np); // add the updated path to the list of paths
		}
		Position right = target.rightPosition();
		if(mazeInBounds(right) && !closed.contains(right)){ // if this point is valid and is not included in the closed list
		    open.add(0, right); // add it to the head of the list
		    paths.add(0, np); // add the updated path to the list of paths
		}
	    }
	    // update closed list
	    closed.add(target);
	    
	}
    }*/


    // TODO: search the maze using breath-first search
    public void solveBFS(){
	// ...
    }
   
}

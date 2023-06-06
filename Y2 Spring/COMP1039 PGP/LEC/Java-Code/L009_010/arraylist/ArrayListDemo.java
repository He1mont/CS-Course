import java.util.ArrayList;

class ArrayListDemo{
    public static void main(String[] args){
		// create a new array of characters
		ArrayList<Character> a1 = new ArrayList<>();
		// get its size
		System.out.println("Initial size: " + a1.size());

		// add elements
		a1.add('A');
		a1.add('B');
		a1.add('C');

		// get its size
		System.out.println("Size after additions: " + a1.size());
		// display the arraylist
		System.out.println("Contents: " + a1);
		// iteration on each element
		for(int i = 0; i < a1.size(); i++){
			System.out.print(a1.get(i)+";");
		}
		System.out.println();

		// add an element at a specified position
		a1.add(1, 'X');
		// get its size
		System.out.println("Size after additions: " + a1.size());
		// display the arraylist
		System.out.println("Contents: " + a1);

		// delete the element just added
		a1.remove(1);
		// get its size
		System.out.println("Size after deletions: " + a1.size());
		// display the arraylist
		System.out.println("Contents: " + a1);

		// set values
		a1.set(1, 'D');
		// display the arraylist
		System.out.println("Contents: " + a1);

		// find the index of particular element and then remove
		int index = a1.indexOf('D');
		a1.remove(index);
		// display the arraylist
		System.out.println("Contents: " + a1);
		// directly delete an object
		a1.remove((Character)'A');
		// display the arraylist
		System.out.println("Contents: " + a1);

		// clear
		a1.clear(); 
		System.out.println("size after clearance: " + a1.size());
		// display the arraylist
		System.out.println("Contents: " + a1);
	
    }
}

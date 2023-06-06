// a class declaration
public class Die{
    // a method to randomly generate an integer number within the range [1, 6]
    public int roll(){
	// Math.random * 6 give us an double number, we need to cast it to an integer number first.
	// This step of integer conversion give us an integer within the range [0, 5], so we need to add 1 to the final result
	return 1 + (int) (Math.random()*6);
    }
}

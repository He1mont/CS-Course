
class ThrowIODemo{
    public static char prompt(String str){
	    System.out.println(str + ": ");
	    return (char) System.in.read();
    }

    public static void main(String[] args) {
	char ch = 'X';
	//try{
	ch = prompt("Enter a letter");
	    //}catch(java.io.IOException exc){
	    //System.out.println("I/O exception occurred.");
	    //}
	System.out.println("You pressed " + ch);	
}
}

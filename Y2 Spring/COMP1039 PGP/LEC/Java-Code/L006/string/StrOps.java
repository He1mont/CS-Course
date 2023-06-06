public class StrOps{
    public static void main(String[] args){
	String str1 = "Find string methods here.";   // Create str1
	String str2 = new String(str1); // Create another string based on str1
	String str3 = "Java strings are powerful."; // Create our third string
	int result, idx; // Declare two integer number
	char ch; // and a character

	// output the length of the string
	System.out.println("Length of str1: " + str1.length());

	// interatively print each character in str1
	for(int i = 0; i < str1.length(); i++){
	    System.out.print(str1.charAt(i)+"|");
	}
	System.out.println();

	// ==
	if(str1 == str2)
	    System.out.println("str1 == str2");
	else
	    System.out.println("str1 != str2");

	if(str1.equals(str2))
	    System.out.println("str1 equals to str2");
	else
	    System.out.println("str1 does not equal to str2");

	// compare to
	result = str1.compareTo(str3);
	if(result == 0)
	    System.out.println("str1 and str3 are equal");
	else if(result < 0)
	    System.out.println("str1 is less than str3");
	else
	    System.out.println("str1 is larger than str3");

	// assign a new string to str2
	str2 = "One Two Three One";
	// get the index of one
	idx = str2.indexOf("One");
	System.out.println("Index of first occurance of One: " + idx);
	// for a character
	idx = str2.indexOf('e');
	System.out.println("Index of first occurance of e: " + idx);
	// case sensitive
	idx = str2.indexOf('o');
	System.out.println("Index of first occurance of o: " + idx);
	// last index
	idx = str2.lastIndexOf("One");
	System.out.println("Index of last occurance of One: " + idx);
    }
}

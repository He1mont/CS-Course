class Palindrome{
    public static void main(String[] args){
	String a = args[0]; 
	for(int i = 0; i < a.length() / 2; i++){
            // compare 
            if(a.charAt(i) != a.charAt(a.length()-1-i)){
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}

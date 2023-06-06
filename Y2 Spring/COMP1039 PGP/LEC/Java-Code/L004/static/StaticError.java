public class StaticError{
    int x;		
    static int y = 1024;

    // Constructor
    public StaticError(int val){
        this.x = val;
    }

    public static void main(String[] args){
        StaticError se = new StaticError(5);
        int z = y / se.x;
        System.out.println(z);
    }
}

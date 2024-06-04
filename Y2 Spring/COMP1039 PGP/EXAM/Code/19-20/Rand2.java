public class Rand2{
    public static void main(String[] args){
        double x, ratio;
        int plus = 0;
        int minus = 0;
        for (int i=0; i<19; i++){
            x = Math.random();
            if (x > 0.5)
                plus++;
            else 
                minus++;
        }
        ratio = (double)plus / minus;
        System.out.println("plus : "+plus);
        System.out.println("minus: "+minus);
        System.out.println("ratio: "+ ratio);
    }
}
class Summation {
    private int sum;

    <T extends Number> Summation(T arg) {
        for (int i = 0; i < arg.intValue(); i++) {
            sum += i;
        }
    }

    public int getSum() {
        return this.sum;
    }

    public static void main(String[] args) {
        Summation s = new Summation(4.2);
        System.out.println(s.getSum());
    }
}

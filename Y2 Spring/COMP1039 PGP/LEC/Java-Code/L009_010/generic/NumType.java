class NumType<T extends Number> {
    T num;

    NumType(T t) {
        num = t;
    }

    double multiply(double x) {
        return num.doubleValue() * x;
    }

    /*
     * boolean absEquals(NumType<?> ob){
     * return Math.abs(num.doubleValue()) == Math.abs(ob.num.doubleValue());
     * }
     */

    public static void main(String args[]) {
        NumType<Integer> it = new NumType<Integer>(2);
        NumType<Double> dt = new NumType<Double>(2.0);
        System.out.println(it.multiply(3));
        // System.out.println(it.absEquals(dt));
    }
}

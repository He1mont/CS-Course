abstract class TwoDShape {
    double width;
    double height;

    abstract double area();

    void showDim() {
        System.out.println("Width and height are " + width + " and " + height);
    }
}

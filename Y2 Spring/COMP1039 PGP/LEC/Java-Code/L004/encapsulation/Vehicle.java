public class Vehicle {
    private int passengers, fuelCap, mpg;

    Vehicle(int p, int f, int m){
        passengers = p;
        fuelCap = f;
        mpg = m;
    }
    
    // 需要用getMpg函数来调用mpg的值
    public int getMpg(){
        return mpg;
    }
    private int range(){
        return mpg * fuelCap;
    }
}

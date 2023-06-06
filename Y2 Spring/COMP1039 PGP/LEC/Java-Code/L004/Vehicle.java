public class Vehicle {

    int passengers; // number of passages
    int fuelCap;    // fuel capacity in gallons
    int mpg;        // consumption in miles per gallon


    // here are three methods
    void range(){
    	System.out.println("range: " + (fuelCap * mpg));
    }
    
    int ret_range(){
        return fuelCap * mpg;
    }

    double fuelNeeded(int distance){
        return (double) distance / mpg;
    }

    // Constructor
    Vehicle(int p, int f, int m){
        passengers = p;
        fuelCap = f;
        mpg = m;
    }

}








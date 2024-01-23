package com.theBestBikeShop;

public class BikeApp {
    public static void main(String[]args){
        Bicycle b = new Bicycle(20, 300);
        b.switchLightStatus();
        b.currentState();

        MountainBike mb1 = new MountainBike(20, 30, true, true);
        MountainBike mb2 = new MountainBike(20, 30, true, false);

        mb1.switchLightStatus();
        mb1.currentState();
    }
}




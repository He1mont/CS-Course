package com.theBestBikeShop;

public class MountainBike extends Bicycle {
    private boolean frontSus;
    private boolean rearSus;
    MountainBike(int gear, int speed, boolean front, boolean rear) {
        super(gear, speed);
        frontSus = front;
        rearSus = rear;
    }
    public boolean isFullSuspension() {
        return frontSus && rearSus;
    }
    @Override
    public void currentState() {
        super.currentState();
        if (frontSus)
            System.out.println("It has a front suspension.");
        else
            System.out.println("It has no front suspension.");
        if (rearSus)
            System.out.println("It has a rear suspension.");
        else
            System.out.println("It has no rear suspension.");
    }
}

class ByThree implements Series {
    int start; // start value for this series
    int val; // current value
    // constructor

    ByThree() {
        start = 0; // set the start value
    }

    // implement the methods specified by Series.
    public int getNext() {
        val += 3;
        return val;
    }

    // implement the reset methods
    public void reset() {
        val = start;
    }

    public void unique() {

    }
}

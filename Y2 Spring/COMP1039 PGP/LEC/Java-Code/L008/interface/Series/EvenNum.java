class EvenNum implements Series {
    int start; // start value for this series
    int val; // current value
    // constructor

    EvenNum() {
        start = 0; // set the start value
    }

    // implement the methods specified by Series.
    public int getNext() {
        val += 2;
        return val;
    }

    // implement the reset methods
    public void reset() {
        val = start;
    }

}

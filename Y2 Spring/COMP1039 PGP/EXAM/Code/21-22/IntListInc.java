public class IntListInc extends IntList {
    
    // attributes
    int inc;

    // constructor
    IntListInc (int value, int inc){
        super(value);       // call the constructor of the super class
        this.inc = inc;
    }

    // Override
    public IntList next(){
        if (super.next == null){
            IntListInc nextInc = new IntListInc(value+inc, inc);
            super.next = nextInc;
            super.next.prev = this;
        }

        return next;
    }


}

public class IntList {

    // attributes
    protected IntList next;
    protected IntList prev;
    protected int value;

    // constructors
    public IntList(int value) {
        prev = null;
        this.value = value;
    }

    // methods
    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public IntList next() {
        if (next == null) {
            next = new IntList(value);
            next.prev = this;
        }
        return next;
    }

    public IntList previous() {
        return prev;
    }

    public String toString(int n) {
        String sv = String.valueOf(value);
        if (n > 1) {
            sv = sv + ", " + next().toString(n - 1);
        }
        return sv;
    }

    // Overload Qc
    public String toString() {
        String sv = String.valueOf(value);
        if (next() != null){
            sv = sv + ", " + next().toString();
        }
        return sv;
    }

}
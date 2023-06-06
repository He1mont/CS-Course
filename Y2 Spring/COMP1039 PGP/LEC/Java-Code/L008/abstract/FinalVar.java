class FinalVar {

    final int VALUE;

    void changeValue() {
        VALUE = 3;
    }

    int getValue() {
        return VALUE;
    }

    FinalVar(int v) {
        VALUE = v;
    }
}

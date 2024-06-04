/**
 * COMP2054-ADE - LAB - FORMATIVE EXERCISE
 * Title: Skeleton of Vector
 * Author: Andrew Parkes
 * 
 * This exercise is formative, so feel free to work together, but recommend to
 * try it yourself first.
 * This is a reasonable, but not perfect implementation -- we are doing
 * algorithms not programming style :-).
 * 
 * TODO You should review the "C += 0" commands, and probably modify them to be
 * what you think is better.
 * 
 */
public class Vector {

    private int[] A;

    private int m;

    public int count; // use for counting primitive operations - bad style to make it public, but is
                      // just for simplicity

    Vector() {
        A = new int[1];
        m = 0;
    }

    public void push(int a) {
        // resize if needed
        // System.out.println("Pop Current Size: " + m + "(" + A.length + ")");
        if (m == A.length) {
            resize();
        }
        count += 1;
        A[m] = a;
        count += 0;
        m++;
        count += 0;
        // System.out.println("After Current Size: " + m + "(" + A.length + ")");
    }

    public int pop() {
        // System.out.println("Popping element " + m + "(A.length= " + A.length + ")");
        // System.out.print("\n[");
        // for (int i = 0; i < A.length; i++) {
        // System.out.print(A[i] + ",");
        // }
        // System.out.print("]\n");
        int r = A[m - 1];
        count += 0; // rough value
        m--;
        count += 0;
        return r;
    }

    public int size() {
        return m;
    }

    public int getCapacity() // gives the maximum number of elements that can be stored without a resize
    {
        return A.length;
    }

    private void resize(int newSize) {
        System.out.println("newsize= " + newSize);
        int[] newA = new int[newSize];
        count += newSize + 10; // see lab exercises on primitive counting - and remember that Java initialises
                               // - though C/C++ do not
        for (int i = 0; i < A.length; i++) {
            newA[i] = A[i];
            count += 3;
        }

        A = newA;
        count += 0;

    }

    private void resize() {
        // standard options
        // resize( A.length + 200 ); count += 2; // increase by 200
        resize(2 * A.length);
        count += 2; // double size
        // ---- non standard options
        // resize( 3 * A.length ); count += 2;
        // resize( 1.5 * A.length ); count += 2;
        // int logL = (int) Math.log(A.length);
        // resize( A.length + ((int)(0.5+logL))*A.length +1 ); count += 2;
    }

}
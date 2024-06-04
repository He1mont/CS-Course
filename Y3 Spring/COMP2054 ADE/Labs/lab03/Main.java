/**
 * COMP2054 - LAB - FORMATIVE EXERCISE
 * Title: Vector implementation and analysis - "solution"
 * Author: Andrew Parkes
 * 
 * This exercise is formative, so feel free to work together, but recommend to
 * try it yourself first.
 */

public class Main {

    /// used for counting primitive operations
    static int c;

    /*
     * Main method: runs the experiments and prints results.
     * You can (and should) change this as needed.
     * 
     */
    public static void main(String[] a) {

        int maxN = 10000; // CHANGE AS NEEDED

        Vector v = new Vector();

        v.count = 0;
        for (int n = 1; n <= maxN; n += 1) {
            v.push(n);
            System.out.println(n + " " + v.count);
        }
    }
}
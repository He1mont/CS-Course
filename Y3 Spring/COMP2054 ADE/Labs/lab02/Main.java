/** COMP2054-ADE WEEK 3 - LAB - FORMATIVE EXERRCISE
    Title:  Analysis of Algorithms
	Author: Andrew Parkes
	
	This exercise is formative, so feel free to work together, but recommend to try it yourself first.
*/
import java.util.Random;

public class Main {

    // used for counting primitive operations
    static int c;
    static Random rnd;

    /*
     * Main method: runs the experiments and prints results.
     * 
     * You can (and should) change this as needed.
     * 
     * E.g. You should change the maxN and maxRuns to values of your choice.
     * You may well also want to do more than just report the n,c from each run.
     * e.g. to collect and print more 'statistics' such as worst, best, average at
     * each value of n.
     */
    public static void main(String[] a) {

        int maxN = 10; // CHANGE AS NEEDED
        int numRuns = 5; // CHANGE AS NEEDED

        rnd = new Random();

        System.out.println("n,worst_case,best_case,avg_case");
        for (int n = 1; n <= maxN; n += 1) {
            int[] A = new int[n];
            double worst_case = 0.0, best_case = Integer.MAX_VALUE, sum = 0.0;
            for (int run = 0; run < numRuns; run++) {
                // initialise A with randomised values
                randInit(A);
                // printList(A);
                // reset the counter, c, run f, and report the count
                c = 0;
                int out = p(A);
                // System.out.println(n + " " + c);
                // KEEP EXTRA STATISTICS AS NEEDED
                if (c > worst_case)
                    worst_case = c;
                if (c < best_case)
                    best_case = c;
                sum += c;

            }
            System.out.println(n + "," + worst_case + "," + best_case + "," + sum / numRuns);
            // System.out.println("------------------");
        }
        // PROCESS/PRINT EXTRA STATISTICS AS NEEDED
    }

    /*
     * This is the function 'p' that needs to be analysed.
     * It works on an integer array, 'A' with n elements.
     * You can think of it as a piece of 'legacy code' you are given and it is
     * suspected to
     * be causing trouble, such as making the application program to be going slow.
     * You need to analyse its scaling behaviour and make other comments.
     * The "c += " fragments have been added to help, but are not intnded as part of
     * the "p()" methof itself. However, they are part of the annotated code and do
     * run.
     * 
     * Note in particular if the increment is in the body of the loop then it will
     * run each time the body runs, and so you should not then directly include
     * terms to account for the "Number of passes". Hence, it is a bit differnt from
     * the lectures.
     * 
     * NOTE: Do _NOT_ take this as an example of how to write good code!
     * Parts of it may be deliberately poor to illustrate useful points.
     * 
     * SUGGEST TO NOT CHANGE THIS FUNCTION EXCEPT THE increments to the counter on
     * the r.h.s. !!!
     * 
     * 
     */
    static int p(int[] A) {
        int n = A.length;           c += 2;
        int[] B = new int[n];       c += 2;

        int sum = 0;                c += 1;
        int max = 0;                c += 1;

        c += 1;     // int p = 0
        for (int p = 0; p < n; p++) {
            int k = A[p];           c += 4;
            sum += k;               c += 3;
            B[p] = sum;             c += 3;
            int m = 0;              c += 1;
            int s;                  c += 1;
            s = (n % 2 == 0 ? sum : k);     c += 5;
            while (s >= 2) {        c += 3;
                s /= 2;             c += 3;
                m++;                c += 3;
            }
            if (m > max) {          c += 3;
                max = m;            c += 3;
            }
            c += 3;     // p < n
            c += 3;     // p++
        }
        A = B;                      c += 2;
        c += 1;
        return max;
    }

    /*
     * Used to initialise the array A.
     * You are expected to first do experiments using version exactly as below.
     */
    static void randInit(int[] A) {
        int n = A.length;
        for (int i = 0; i < n; i++) {
            A[i] = 10 * n + rnd.nextInt(n);
        }
    }

    /*
     * OPTIONAL: use these other versions in order to initialise the array, and get
     * graphs that are more interesting.
     * 
     * Used to initialise the array A.
     * You are expected to first do experiments using version exactly as below.
     */
    static void randInit_v2(int[] A) {
        int n = A.length;
        if (n % 3 == 0) {
            for (int i = 0; i < n; i++) {
                A[i] = 10 * n + rnd.nextInt(n);
            }
        }
    }

    /*
     * Used to initialise the array A.
     * You are expected to report results using version exactly as below.
     * (Unless you know what you are doing, e.g. for some "side experiments"
     * used to help you understand.)
     */
    static void randInit_v3(int[] A) {
        int n = A.length;

        if (n % 3 == 0) {
            for (int i = 0; i < n; i++) {
                A[i] = 10 * n + rnd.nextInt(n);
            }
        } else {
            for (int i = 0; i < n; i++) {
                A[i] = 10 + rnd.nextInt(Math.min(n, 100));
            }
        }
    }

    static void printList(int[] ls) {
        for (int i = 0; i < ls.length; i++) {
            System.out.print(ls[i] + " ");
        }
        System.out.println("");
    }

}
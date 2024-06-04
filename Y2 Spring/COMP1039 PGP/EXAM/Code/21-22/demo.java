public class demo{
    public static void main (String[] args){
        
        // (a)
        System.out.println("------------------------------------------");
        System.out.println("Here is Question a!");

        // (i)
        System.out.print("  (i): ");
        IntList x1 = new IntList(4); 
        System.out.println(String.valueOf(x1.getValue() * x1.next().getValue()));

        // (ii)
        System.out.print(" (ii): ");
        System.out.println(x1.toString(10));

        // (iii)
        System.out.print("(iii): ");
        IntList x2 = new IntList(0);
        IntList x3 = x2.next().next().next();
        x3.setValue(5);
        x3.next().next().setValue(8);
        System.out.println(x2.toString(8));

        // (iv)
        System.out.print(" (iv): ");
        System.out.println(x3.previous().toString(2));

        // (b)
        System.out.println("------------------------------------------");
        System.out.println("Here is Question b!");

        IntList x4 = new IntListInc(0, 3);
        System.out.println(x4.toString(5));

        // (c)
        System.out.println("------------------------------------------");
        System.out.println("Here is Question c!");
        // System.out.println(x1.toString());      // infinite loop

        // (d)
        System.out.println("------------------------------------------");
        System.out.println("Here is Question d!");

        int[] ns = {5,2,6,7};
        IntList x5 = linked(ns);
        System.out.println(x5.toString(6));

    }

    // (d)
    public static IntList linked(int[] ns){

        // empty array
        if (ns.length == 0){
            IntList head = new IntList(0);
            return head;
        }
        
        IntList head = new IntList(ns[0]);
        IntList tmp = head;
        for (int i=1; i<ns.length; i++){
            IntList node = new IntList(ns[i]);  // create node
            tmp.next = node;                    // create link
            node.prev = tmp;
            tmp = tmp.next;                     // move onto next node
        }
        // use zero to fill the rest of the lists
        tmp.next = new IntList(0);

        return head;
    }

}
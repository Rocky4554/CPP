import java.util.*;

public class A_P {

    public void find(int a, int b, int k) {

        int diff = b - a;

        while (k > 0) {
            b = b + diff;
            System.out.print(b + " ");
            k--;
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();

        int k = in.nextInt();

        A_P ob = new A_P();

        System.out.println("the next" + k + "term of Ap are :");
        ob.find(a, b, k);
    }
}
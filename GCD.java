import java.util.*;

public class GCD {

    static int gcd(int a, int b) {

        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }

        if (a == b) {
            return a;
        }

        if (a > b)

            return gcd(a - b, b);

        return gcd(a, b - a);

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();

        GCD ob = new GCD();

        System.out.println(ob.gcd(a, b));

    }
}
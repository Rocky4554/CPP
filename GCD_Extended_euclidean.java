import java.util.*;

public class GCD_Extended_euclidean {

    int ext_gcd(int a, int b, int x, int y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1 = 1, y1 = 1;
        int d = ext_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;

        return d;

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        GCD_Extended_euclidean ob = new GCD_Extended_euclidean();

        int a = in.nextInt();
        int b = in.nextInt();
        int x = 1, y = 1;// asumming value of x and y to be 1;

        System.out.println(ob.ext_gcd(a, b, x, y));
    }

}

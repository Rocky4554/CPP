import java.util.*;

public class GCD_memoization {

    static int dp[][] = new int[1001][1001];

    int gcd(int a, int b) {

        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }

        if (a == b) {// if both values are equal
            return a;
        }

        if (dp[a][b] != -1) {// checking if it already present
            return dp[a][b];
        }

        if (a > b) {//
            dp[a][b] = gcd(a - b, b);// filling value in table
        } else {

            dp[a][b] = gcd(a, b - a);// filling value in table
        }
        return dp[a][b];

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();

        for (int i = 0; i < 1001; i++) {
            for (int j = 0; i < 1001; i++) {
                dp[i][j] = -1;
            }
        }

        GCD ob = new GCD();

        System.out.println(ob.gcd(a, b));

    }

}

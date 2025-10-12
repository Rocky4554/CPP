import java.util.*;

public class DP_Integerbreak {

    int find(int n) {

        int dp[] = new int[n + 1];// creating a dp
        if (n == 1) {
            return 1;
        }
        if (dp[n] != 0) {// memoization
            return dp[n];
        }
        int maxi = 0;
        for (int i = 1; i < n; i++) {
            int y = n - i;// dividing the no in two parts (i is the first part and y is the second part);

            int p1 = find(i);
            int p2 = find(y);

            maxi = Math.max(maxi, Math.max(i, p1) * Math.max(y, p2));// her we are storing the maximum product
            dp[n] = maxi;//memoization
        }
        return dp[n];// returning the last index of dp;
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("enter a no");
        int n = in.nextInt();  

        DP_Integerbreak ob = new DP_Integerbreak();

        System.out.println(ob.find(n));
    }
}

import java.util.Scanner;

public class ARRAY_IncresasingSubarray {

    public static int solve(int n, int ar[]) {
        int ar1[] = new int[n];
        int j = 0;
        ar1[j] = ar[0];
        for (int i = 1; i < ar.length; i++) {
            if (ar1[j] < ar[i]) {
                j++;
                ar1[j] = ar[i];
            } else {
                ar1[j] = ar[i];

            }
        }
        return j + 1;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ar[] = new int[n];
        for (int i = 0; i < n; i++) {
            ar[i] = sc.nextInt();
        }
        System.out.println(solve(n, ar));

    }

}

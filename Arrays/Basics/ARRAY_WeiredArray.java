import java.util.Arrays;

public class ARRAY_WeiredArray {
    public static void main(String[] args) {
        int a[] = { 3, 3, 1, 3, 3 };
        System.out.println(weiredArray(a));
    }

    public static int weiredArray(int[] a) {
        if (a.length < 2) {
            return 0;
        }
        int[] li = new int[a.length];
        int cnt = 0;
        int maxm = 0;

        for (int i = 0; i < a.length; i++) {
            for (int j = i; j < a.length; j++) {
                if (a[i] == a[j]) {
                    cnt++;
                } else {
                    li[i] = cnt;
                    cnt = 0;
                    break;
                }
            }

        }

        maxm = Arrays.stream(li).max().getAsInt();
        return maxm;
    }
}
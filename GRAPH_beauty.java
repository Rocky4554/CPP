import java.util.*;

public class GRAPH_beauty {
    static ArrayList<Integer>[] graph;
    static int[] letter;
    static int[] vis;
    static int[][] mem;

    public static boolean dfs(int vertex) {
        vis[vertex] = 1;
        for (int to : graph[vertex]) {
            if (vis[to] == 1) {
                return true;
            }
            if (vis[to] == 0 && dfs(to)) {
                return true;
            }
            for (int i = 0; i < 26; i++) {
                mem[vertex][i] = Math.max(mem[vertex][i], mem[to][i]);
            }

        }
        mem[vertex][letter[vertex]]++;
        vis[vertex] = 2;
        return false;

    }

    public static int beauty(int n, int m, String s, int x[], int y[]) {
        graph = new ArrayList[n + 1];

        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<Integer>();

        }
        for (int i = 0; i < m; i++) {
            int from = x[i];
            int to = y[i];

            graph[from].add(to);

        }
        letter = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            letter[i] = s.charAt(i - 1) - 'a';

        }
        vis = new int[n + 1];
        mem = new int[n + 1][26];
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0 && dfs(i)) {
                return -1;
            }
        }
        int ans = 0;

        for (int k = 0; k <= n; k++) {
            for (int j = 0; j < 26; j++) {
                ans = Math.max(ans, mem[k][j]);
            }
        }

        return ans;
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        String s = in.next();

        int x[] = new int[m];
        int y[] = new int[m];

        for (int i = 0; i < m; i++) {
            x[i] = in.nextInt();
        }

        for (int i = 0; i < m; i++) {
            y[i] = in.nextInt();
        }
        System.out.println(beauty(n, m, s, x, y));

    }

}

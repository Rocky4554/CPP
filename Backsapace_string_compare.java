import java.util.*;

public class Backsapace_string_comapre {

    public static boolean check(String s, String t) {
        Stack<Character> st = new Stack<Character>();
        for (char c : s.toCharArray()) {
            if (c != '#') {
                st.push(c);
            } else if (!st.isEmpty()) {
                st.pop();
            }
        }

        Stack<Character> tt = new Stack<Character>();
        for (char c : t.toCharArray()) {
            if (c != '#') {
                tt.push(c);
            } else if (!tt.isEmpty()) {
                tt.pop();
            }
        }

        while (!st.isEmpty()) {
            char curr = st.pop();
            if (tt.isEmpty() || tt.pop() != curr) {
                return false;
            }
        }

        return st.isEmpty() && tt.isEmpty();

    }

    public static void main(String[] args) {

        String s = "ab#c", t = "ad#b#c";

        Backsapace_string_comapre ob = new Backsapace_string_comapre();

        System.out.println(ob.check(s, t));
    }

}
import java.io.*;
import java.util.*;

/**
 * Created by qf on 22.10.2016.
 */
public class B {
    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) {
        new B().run();
    }
    public static final String NO = "Impossible";


    String getBoys(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append('B');
        }
        return sb.toString();
    }

    String getGirls(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append('G');
        }
        return sb.toString();
    }

    public char[] merge(Deque<Character> d) {
        int cur = 0;
        int size = d.size();
        char[] ans = new char[size];
        for (char c : d) {
            ans[cur] = c;
            cur += 2;
            cur %= size;
        }
        return ans;
    }

    public char[] merge(Deque<Character> d1, Deque<Character> d2) {
        int cur = 0;
        int size = d1.size() + d2.size();
        char[] ans = new char[size];
        for (char c : d1) {
            ans[cur] = c;
            cur += 2;
            cur %= size;
        }
        cur = 1;
        for (char c : d2) {
            ans[cur] = c;
            cur += 2;
            cur %= size;
        }
        return ans;
    }

    void ass(boolean flag) {
        if (!flag) {
            throw new AssertionError("here");
        }
    }

    void solve() throws IOException {
        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        if (x > n || y > n) {
            out.println(NO);
            return;
        }
        if (n == x && y == 0) {
            out.println(getBoys(n));
            return;
        }
        if (n == y && x == 0) {
            out.println(getGirls(n));
            return;
        }

        if (n % 2 == 0) {
            int n1 = n / 2;
            int a = x + y - n;
            if (a % 2 != 0) {
                out.println(NO);
                return;
            }
            a /= 2;
            Deque<Character> deque1 = new ArrayDeque<>();
            Deque<Character> deque2 = new ArrayDeque<>();
            int in1 = Math.min(a, n1 / 2);
            for (int i = 0; i < in1; i++) {
                deque1.add('B');
                deque1.add('G');
            }
            int in2 = a - in1;
            if (in2 * 2 > n1) {
                out.println(NO);
                return;
            }
            for (int i = 0; i < in2; i++) {
                deque2.add('B');
                deque2.add('G');
            }
            x -= 2 * a;
            y -= 2 * a;
            while (deque1.size() != n1) {
                if (x > 0) {
                    deque1.addFirst('B');
                    x--;
                } else if (y > 0) {
                    deque1.addLast('G');
                    y--;
                }
            }
            while (deque2.size() != n1) {
                if (x > 0) {
                    deque2.addFirst('B');
                    x--;
                } else if (y > 0) {
                    deque2.addLast('G');
                    y--;
                }
            }
            out.println(merge(deque1, deque2));
        } else {
            int a = x + y - n;
            if (a % 2 != 0) {
                out.println(NO);
                return;
            }
            a /= 2;
            Deque<Character> list = new ArrayDeque<>();
            for (int i = 0; i < a; i++) {
                list.add('B');
                list.add('G');
            }
            x -= 2 * a;
            y -= 2 * a;
            for (int i = 0; i < x; i++) {
                list.addFirst('B');
            }
            for (int i = 0; i < y; i++) {
                list.addLast('G');
            }
            ass(list.size() == n);
            out.println(merge(list));
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("boysgirls.in"));
            out = new PrintWriter(new File("boysgirls.out"));

            Locale.setDefault(Locale.US);
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}

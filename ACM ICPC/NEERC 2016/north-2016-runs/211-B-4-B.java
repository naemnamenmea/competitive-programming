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

    String solveTest(int n, int x, int y) {
        if (x > n || y > n) {
            return NO;
        }
        if (n == x && y == 0) {
            return getBoys(n);
        }
        if (n == y && x == 0) {
            return getGirls(n);
        }
        if (x + y < n) {
            return NO;
        }

        if (n % 2 == 0) {
            int n1 = n / 2;
            int a = x + y - n;
            if (a % 2 != 0) {
                return NO;
            }
            a /= 2;
            Deque<Character> deque1 = new ArrayDeque<>();
            Deque<Character> deque2 = new ArrayDeque<>();
            int in1 = Math.min(a, n1 / 2);
            int in2 = a - in1;
            if (in2 * 2 > n1) {
                return NO;
            }
            if (in2 == 0 && in1 >= 2) {
                in1--;
                in2++;
            }
            for (int i = 0; i < in1; i++) {
                deque1.add('B');
                deque1.add('G');
            }
            for (int i = 0; i < in2; i++) {
                deque2.add('B');
                deque2.add('G');
            }
            x -= 2 * a;
            y -= 2 * a;
            while (deque1.size() != n1) {
                if (x < y) {
                    if (x > 0) {
                        deque1.addFirst('B');
                        x--;
                    } else if (y > 0) {
                        deque1.addLast('G');
                        y--;
                    }
                } else {
                    if (y > 0) {
                        deque1.addLast('G');
                        y--;
                    } else if (x > 0) {
                        deque1.addFirst('B');
                        x--;
                    }
                }
            }
            while (deque2.size() != n1) {
                if (x < y) {
                    if (x > 0) {
                        deque2.addFirst('B');
                        x--;
                    } else if (y > 0) {
                        deque2.addLast('G');
                        y--;
                    }
                } else {
                    if (y > 0) {
                        deque2.addLast('G');
                        y--;
                    } else if (x > 0) {
                        deque2.addFirst('B');
                        x--;
                    }
                }
            }
            return String.valueOf(merge(deque1, deque2));
        } else {
            int a = x + y - n;
            if (a % 2 != 0) {
                return NO;
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
            return String.valueOf(merge(list));
        }
    }

    boolean check(int n, int x, int y, String ans) {
        if (ans.equals(NO)) {
            return true;
        }
        char[] s = ans.toCharArray();
        if (n != s.length) {
            return false;
        }
        int cx = 0;
        int cy = 0;
        for (int i = 0; i < n; i++) {
            char prev = s[(i - 1 + n) % n];
            char next = s[(i + 1) % n];
            if (prev == 'B' || next == 'B') {
                cx++;
            }
            if (prev == 'G' || next == 'G') {
                cy++;
            }
        }
        return cx == x && cy == y;
    }

    void solve() throws IOException {
        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();

        String ans = solveTest(n, x, y);
        //System.out.println(ans);
        if (check(n, x, y, ans)) {
            out.println(ans);
        } else {
            out.println(NO);
        }
        /*Random rnd = new Random(15082005);
        int tests = 100;
        for (int test = 0; test < tests; test++) {
            int n = rnd.nextInt(10);
            int x = rnd.nextInt(n + 1);
            int y = rnd.nextInt(n + 1 - (n - x)) + n - x;
            String ans = solveTest(n, x, y);
            if (check(n, x, y, ans)) {
                System.out.println("OK " + rnd.nextInt());
            } else {
                System.out.println("WA ");
                System.out.println(n + " " + x + " " + y);
            }
        }*/
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

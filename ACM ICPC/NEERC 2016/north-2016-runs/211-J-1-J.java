import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * Created by qf on 22.10.2016.
 */
public class J {
    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) {
        new J().run();
    }

    void solve() throws IOException {
        int n = in.nextInt();
        if (n == 0) {
            out.println("? / ? / ?");
            return;
        }
        out.println("a = ? max ?");
        int max = 18;
        for (int i = 0; i < max - 1; i++) {
            char prev = (char) (i + 'a');
            char cur = (char) (i + 1 + 'a');
            out.printf("%c = %c max %c\n", cur, prev, prev);
        }
        out.println("s = r / r");
        for (int i = max, j = 1; j < 8; i++, j++) {
            char prev = (char) (i + 'a');
            char cur = (char) (i + 1 + 'a');
            out.printf("%c = %c + %c\n", cur, prev, prev);
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 16; i++) {
            if (((n >> i) & 1) != 0) {
                ans.add(i + max);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i == 0) {
                out.print(((char)('a' + ans.get(i))));
            } else {
                out.print(" + " + ((char)('a' + ans.get(i))));
            }
        }
        out.println();
    }

    void run() {
        try {
            in = new FastScanner(new File("java2016.in"));
            out = new PrintWriter(new File("java2016.out"));

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

import javafx.collections.transformation.SortedList;

import java.io.*;
import java.util.*;

/**
 * Created by qf on 22.10.2016.
 */
public class Main {
    FastScanner in;
    PrintWriter out;

    int W;
    int H;

    int w;
    int h;

    int count = 0;

    void solve() {
        W = in.nextInt();
        H = in.nextInt();

        w = in.nextInt();
        h = in.nextInt();
        if (W < w || H < h) {
            rotate();
        }
        if ((w > W && w > H) || (h > H && h > W)) {
            out.println(-1);
            return;
        }
        doW();
        doH();
        out.println(count);
    }

    void rotate() {
        int temp = W;
        W = H;
        H = temp;
    }

    void doW() {
        while(W > w) {
            int temp;
            if (W % 2 == 0) {
                temp = W / 2;
            } else {
                temp = W / 2 + 1;
            }
            W = max(w, temp);
            count++;
        }
    }

    void doH() {
        while(H > h) {
            int temp;
            if (H % 2 == 0) {
                temp = H / 2;
            } else {
                temp = H / 2 + 1;
            }
            H = max(h, temp);
            count++;
        }
    }

    int max(int i1, int i2) {
        if (i1 > i2) {
            return i1;
        } else {
            return i2;
        }
    }

    void run() throws FileNotFoundException {
        in = new FastScanner(new File("folding.in"));
        out = new PrintWriter(new File("folding.out"));
        solve();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new Main().run();
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    FastScanner(File f) throws FileNotFoundException {
        br = new BufferedReader(new FileReader(f));
    }
    String next() {
        while(st == null || !st.hasMoreTokens()) {
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
}

class cl {
    Calendar cal;
    Integer n;
    cl(Calendar cal, Integer n) {
        this.cal = cal;
        this.n = n;
    }

    int compareTo(cl t) {
        return this.cal.compareTo(t.cal);
    }
}

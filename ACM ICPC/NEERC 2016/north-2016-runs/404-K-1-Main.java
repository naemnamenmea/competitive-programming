import javafx.collections.transformation.SortedList;

import java.io.*;
import java.util.*;

/**
 * Created by qf on 22.10.2016.
 */
public class Main {
    FastScanner in;
    PrintWriter out;

    void solve() {
        ArrayList<cl> list = new ArrayList<>();
        int day = in.nextInt();
        int month = in.nextInt();
        int year = in.nextInt();
        Calendar init = new GregorianCalendar(year, month, day);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int d = in.nextInt();
            int m = in.nextInt();
            int y = in.nextInt();
            Calendar cal = new GregorianCalendar(y, m, d);
            list.add(new cl(cal, i + 1));
        }
        Collections.sort(list, new Comparator<cl>() {
            @Override
            public int compare(cl o1, cl o2) {
                return o1.compareTo(o2) * (-1);
            }
        });
        for (cl c: list) {
            c.cal.add(1, 18);
            if (c.cal.before(init)) {
                out.println(c.n);
                return;
            }
        }
        out.println(-1);
    }

    void run() throws FileNotFoundException {
        in = new FastScanner(new File("king.in"));
        out = new PrintWriter(new File("king.out"));
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

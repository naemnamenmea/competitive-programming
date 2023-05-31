import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;

/**
 * Created by qf on 22.10.2016.
 */
public class K {
    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) {
        new K().run();
    }

    class Date implements Comparable<Date>{
        int d, m, y, i;

        public Date(int d, int m, int y, int i) {
            this.d = d;
            this.m = m;
            this.y = y;
            this.i = i;
        }
        boolean good(Date dateFather) {
            if (dateFather.y < y + 18) {
                return false;
            } else if (dateFather.y > y + 18) {
                return true;
            } else {
                return dateFather.m > m || (dateFather.m == m && dateFather.d >= d);
            }
        }


        @Override
        public int compareTo(Date o) {
            if (y != o.y) {
                return Integer.compare(y, o.y);
            } else if (m != o.m) {
                return Integer.compare(m, o.m);
            } else {
                return Integer.compare(d, o.d);
            }
        }
    }

    void solve() throws IOException {
        Date dateFather = new Date(in.nextInt(), in.nextInt(), in.nextInt(), -1);
        int n = in.nextInt();
        Date[] d = new Date[n];
        Arrays.setAll(d, i -> new Date(in.nextInt(), in.nextInt(), in.nextInt(), i));
        Optional<Date> min = Arrays.stream(d).filter(i -> i.good(dateFather)).maxx(Date::compareTo);
        if (min.isPresent()) {
            out.println(min.get().i + 1);
        } else {
            out.println(-1);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("king.in"));
            out = new PrintWriter(new File("king.out"));

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

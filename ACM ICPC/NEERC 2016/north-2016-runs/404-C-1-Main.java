import javafx.collections.transformation.SortedList;

import java.io.*;
import java.util.*;

/**
 * Created by qf on 22.10.2016.
 */
public class Main {
    FastScanner in;
    PrintWriter out;

    int n;
    int N;
    ArrayList<cl> list1;
    ArrayList<cl> list2;
    ArrayList<cl> NumList;

    void solve() {
        n = in.nextInt();
        N = n;
        list1 = new ArrayList<>(n);
        list2 = new ArrayList<>(n);
        NumList = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            cl my = new cl(in.nextInt(), in.nextInt(), i);
            list1.add(my);
            list2.add(my);
            NumList.add(my);
        }
        Collections.sort(list1, new Comparator<cl>() {
            @Override
            public int compare(cl o1, cl o2) {
                if (o1.r1 > o2.r1) {
                    return -1;
                }
                if (o1.r1 < o2.r1) {
                    return 1;
                }
                return 0;
            }
        });
        Collections.sort(list2, new Comparator<cl>() {
            @Override
            public int compare(cl o1, cl o2) {
                if (o1.r2 > o2.r2) {
                    return -1;
                }
                if (o1.r2 < o2.r2) {
                    return 1;
                }
                return 0;
            }
        });
        while(N > 0) {
            cut();
        }
        for (int i = 0; i < n; i++) {
            out.println(NumList.get(i).kill);
        }
//        for (int i = 0; i < n; i++) {
//            System.out.println(list1.get(i).r1 + " " + list2.get(i).r2);
//        }

    }

    void cut() {
        cl root = list1.get(n - N);
        root.kill = N - 1;
        int initialState = list1.indexOf(root);
        int index = initialState;
        do {
            initialState = list1.indexOf(root);
            index = list2.indexOf(root);
            Set<cl> tempSet = new HashSet<>();
            for (cl temp : list2.subList(0, index)) {
                tempSet.add(temp);
                if (temp.kill == 0) {
                    temp.kill = N - 1;
                }
            }
            int min = N;
            for (cl temp : tempSet) {
                if (temp.r1 < min) {
                    min = temp.r1;
                    root = temp;
                }
            }
            index = list1.indexOf(root);
            tempSet = new HashSet<>();
            for (cl temp : list1.subList(0, index)) {
                tempSet.add(temp);
                if (temp.kill == 0) {
                    temp.kill = N - 1;
                }
            }
            min = N;
            for (cl temp : tempSet) {
                if (temp.r2 < min) {
                    min = temp.r2;
                    root = temp;
                }
            }
        } while(list1.indexOf(root) > initialState);
        N = n - index - 1;
    }


    long max(long i1, long i2) {
        if (i1 > i2) {
            return i1;
        } else {
            return i2;
        }
    }

    void run() throws FileNotFoundException {
        in = new FastScanner(new File("codecoder.in"));
        out = new PrintWriter(new File("codecoder.out"));
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
    int r1;
    int r2;
    int num;
    int kill;

    public cl(int r1, int r2, int num) {
        this.r1 = r1;
        this.r2 = r2;
        this.num = num;
    }
}

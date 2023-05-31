import java.io.*;
import java.util.ArrayList;

public class C {

//    static String inputName = "C:\\work\\Olimp\\src\\input.txt";
//    static String outputName = "C:\\work\\Olimp\\src\\output.txt";
    static String inputName = "codecoder.in";
    static String outputName = "codecoder.out";
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(inputName));
        PrintWriter writer = new PrintWriter(new File(outputName));
        C.solve(reader, writer);
        reader.close();
        writer.close();
    }

    public static void solve(BufferedReader r, PrintWriter w) throws IOException {
        int q = Integer.parseInt(r.readLine());
        ArrayList<Pair> pairs = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            String line = r.readLine();
            String[] words = line.split(" ");
            int a = Integer.parseInt(words[0]);
            int b = Integer.parseInt(words[1]);
            pairs.add(new Pair(a, b));
        }

        for (int i = 0; i < q; i++) {
            int s = 0;
            for (int j = 0; j < q; j++) {
                s+=pairs.get(i).compare(pairs.get(j));
            }
            w.write(s + "\n");
        }
    }

    public static class Pair {
        int a, b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        public int compare(Pair pair) {
            if (this.a > pair.a || this.b > pair.b) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

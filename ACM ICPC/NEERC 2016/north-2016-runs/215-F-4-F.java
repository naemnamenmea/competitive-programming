import java.io.*;
public class F {

//    static String inputName = "C:\\work\\Olimp\\src\\input.txt";
//    static String outputName = "C:\\work\\Olimp\\src\\output.txt";
    static String outputName = "folding.out";
    static String inputName = "folding.in";
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(inputName));
        PrintWriter writer = new PrintWriter(new File(outputName));
        F.solve(reader, writer);
        reader.close();
        writer.close();
    }

    public static void solve(BufferedReader r, PrintWriter w) throws IOException {
        String line = r.readLine();
        String[] words = line.split(" ");
        int x1 = Integer.parseInt(words[0]);
        int y1 = Integer.parseInt(words[1]);

        line = r.readLine();
        words = line.split(" ");
        int x2 = Integer.parseInt(words[0]);
        int y2 = Integer.parseInt(words[1]);

        double p1 = Math.max(x1,  y1);
        double q1 = Math.max(x2,  y2);
        double p2 = Math.min(x1,  y1);
        double q2 = Math.min(x2,  y2);
        if (p1 < q1 || p2 < q2) {
            w.write(-1 + "");
            return;
        }

        double pq1 = Math.log(p1/q1)/Math.log(2);
        double pq2 = Math.log(p2/q2)/Math.log(2);

        int a1 = (int) Math.ceil(pq1);
        int a2 = (int) Math.ceil(pq2);

        w.write((a1+a2) + "");

    }
}

import java.io.*;
public class F {

//    static String inputName = "C:\\work\\Olimp\\src\\input.txt";
//    static String outputName = "C:\\work\\Olimp\\src\\output.txt";
    static String inputName = "folding.in";
    static String outputName = "folding.out";
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

        double p1 = (double) Math.max(x1,  y1) / (double) Math.max(x2,  y2);
        double p2 = (double) Math.min(x1,  y1) / (double) Math.min(x2,  y2);
        if (p2 < 1 || p1 < 1) {
            w.write(-1 + "");
            return;
        }
        double l1 = Math.log(p1) / Math.log(2);
        int res1 = (int) Math.ceil(l1);
        double l2 = Math.log(p2) / Math.log(2);
        int res2 = (int) Math.ceil(l2);
        w.write((res1 + res2) + "");

    }
}

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

        double p1 = Math.max(x1,  y1);
        double q1 = Math.max(x2,  y2);
        double p2 = Math.min(x1,  y1);
        double q2 = Math.min(x2,  y2);
        if (p1 < q1 || p2 < q2) {
            w.write(-1 + "");
            return;
        }

        p1 = Math.log(p1) / Math.log(2);
        q1 = Math.log(q1) / Math.log(2);
        p2 = Math.log(p2) / Math.log(2);
        q2 = Math.log(q2) / Math.log(2);

        int a1 = (int) Math.ceil(p1);
        int a2 = (int) Math.ceil(p2);
        int b1 = (int) q1;
        int b2 = (int) q2;

        if (p1 == q1) {
            a1 = 0;
            b1 = 0;
        } else if (p2 == q2) {
            a2 = 0;
            b2 = 0;
        }


        w.write((a1+a2-b2-b1) + "");

    }
}

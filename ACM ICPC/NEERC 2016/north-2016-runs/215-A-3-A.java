import java.io.*;

public class A {

//    static String inputName = "C:\\work\\Olimp\\src\\input.txt";
//    static String outputName = "C:\\work\\Olimp\\src\\output.txt";
    static String inputName = "anniversary.in";
    static String outputName = "anniversary.out";
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(inputName));
        PrintWriter writer = new PrintWriter(new File(outputName));
        A.solve(reader, writer);
        reader.close();
        writer.close();
    }

    public static void solve(BufferedReader r, PrintWriter w) throws IOException {
        String line = r.readLine();
        String[] words = line.split(" ");
        int x = Integer.parseInt(words[0]);
        int y = Integer.parseInt(words[1]);
        int x1 = Integer.parseInt(words[2]);
        int y1 = Integer.parseInt(words[3]);
        int x2 = Integer.parseInt(words[4]);
        int y2 = Integer.parseInt(words[5]);

        if (x1 == x2) {
            w.write("0 " + y1 + " " + x + " " +  y2 + " ");
        } else {
            w.write(x1 + " 0 " + x2 + " " + y + " ");
        }
    }
}
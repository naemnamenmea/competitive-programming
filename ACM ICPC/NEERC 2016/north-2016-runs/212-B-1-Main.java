import java.io.*;
import java.util.StringTokenizer;
import java.util.stream.Stream;

/**
 * Created by qf on 22.10.2016.
 */
public class Main {
    public static void main(String[] args) throws IOException {
//        testString("10 5 7");
//        testString("10 3 8");
//        testString("100 52 50");
        testFile("boysgirls.in", "boysgirls.out");
    }

    public static void test(InputStream in, OutputStream out) throws IOException {

        BufferedReader brIn = new BufferedReader(new InputStreamReader(in));
        OutputStreamWriter wrOut = new OutputStreamWriter(out);

        // код проги

        //String s = brIn.readLine();
        StringTokenizer st = new StringTokenizer(brIn.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        wrOut.write(generate(n,x,y) + "\n");
        wrOut.close();

    }

    public static String generate(int n, int x, int y) {

        x--; y--;
        String res = "";
        for (; x>0 && y>0; x--, y--) {
            res += "BG";
        }

        if (x>0) {
            for (;x>0; x--) {
                res += "B";
            }
        } else if (y>0) {
            for (;y>0; y--) {
                res += "G";
            }
        }

        if (res.length() == n) {
            return res;
        } else {
            return "Impossible";
        }

    }

    public static boolean isValid (String a, int n, int x, int y) {

        char b = 'b';
        char g = 'g';

        int boy = 0;
        int girl = 0;

        if (a.length() != n) return false;

        for (int i = 0; i < n; i++) {
            if (isNextTo(a,i,b)) {
                boy++;
            }
            if (isNextTo(a,i,g)) {
                girl++;
            }
        }

        if (boy == x && girl == y)
            return true;
        else return false;

    }

    public static boolean isNextTo(String s, int i, char g) { // fasle after girl
        if (i == 0) {
            return s.charAt(s.length()-1) == g || s.charAt(1) == g;
        } else if (i == s.length() - 1) {
            return s.charAt(s.length()-2) == g || s.charAt(0) == g;
        } else {
            return s.charAt(i-1) == g || s.charAt(i+1) == g;
        }
    }

    public static void testFile(String inName, String outName) throws IOException {
        File inFile = new File(inName);
        File outFile = new File(outName);

        InputStream inStream = new FileInputStream(inFile);
        OutputStream outputStream = new FileOutputStream(outFile);

        test(inStream, outputStream);

//        outputStream.flush();
//        outputStream.close();
    }

    public static void testString(String in) throws IOException {
        InputStream inStream = new ByteArrayInputStream(in.getBytes());
        test(inStream, System.out);
    }
}

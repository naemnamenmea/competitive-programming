import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by qf on 22.10.2016.
 */
public class F {

    public static void main(String[] args) throws IOException {
        File inFile = new File("folding.in");
        File outFile = new File("folding.out");

        BufferedReader brIn = new BufferedReader(new InputStreamReader(new FileInputStream(inFile)));
        OutputStreamWriter wrOut = new OutputStreamWriter(new FileOutputStream(outFile));

        String s = brIn.readLine();
        StringTokenizer st = new StringTokenizer(s," ");
        int W = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());
        s = brIn.readLine();
        st = new StringTokenizer(s," ");
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        if ((w>W && w>H) || (h>W && h>H)) {
            wrOut.write("-1\n");
            wrOut.close();
            return;
        } else {
            int ww = getNumFolds(W,w);
            int wh = getNumFolds(W,h);
            int hw = getNumFolds(H,w);
            int hh = getNumFolds(H,h);

            if (ww+hh < wh+hw) {
                wrOut.write((ww+hh)+"\n");
            } else {
                wrOut.write((wh+hw)+"\n");
            }
            wrOut.close();
        }

    }

    private static int getNumFolds(int n, int k) {
        int c = 0;
        while (k<n) {
            n = myDiv2(n);
            c++;
        }
        return c;
    }

    private static int myDiv2(int n) {
        return n % 2 == 0 ? n/2 : n/2 + 1;
    }

}

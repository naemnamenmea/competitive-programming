import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * Created by qf on 22.10.2016.
 */


class MyDate {

    int d;
    int id;

    public static MyDate fromString(String date, int id) {
        StringTokenizer st = new StringTokenizer(date, " ");
        return new MyDate(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),id);
    }

    public MyDate(int d, int m, int y, int id) {
        this.d = y*365+d;
        for (int i=0; i < m-1; i++) {
            this.d += K.DAYSINMONTH[i];
        }
        this.id = id;
    }

    public int diff(MyDate d) {
        return d.d - this.d;
    }

    public int getD() {
        return this.d;
    }

    public int getId() {
        return this.id;
    }

}
public class K {

    public static final int[] DAYSINMONTH = new int[]{
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    public static final int DAYSINYEAR = 365;
    public static final int AGE = 18;



    public static void main(String[] args) throws IOException {
        File inFile = new File("king.in");
        File outFile = new File("king.out");

        BufferedReader brIn = new BufferedReader(new InputStreamReader(new FileInputStream(inFile)));
        OutputStreamWriter wrOut = new OutputStreamWriter(new FileOutputStream(outFile));

        String kingDeath = brIn.readLine();
        MyDate kd = MyDate.fromString(kingDeath,-1);

        int n = Integer.parseInt(brIn.readLine());
        ArrayList<MyDate> sons = new ArrayList<>();
        for (int i = 0; i<n; i++) {
            String date = brIn.readLine();
            sons.add(MyDate.fromString(date,i+1));
        }

        sons.sort(new Comparator<MyDate>() {
            @Override
            public int compare(MyDate o1, MyDate o2) {
                return o2.getD()-o1.getD();
            }
        });
        MyDate sn = null;
        for (MyDate son : sons) {
            if (son.diff(kd)>=DAYSINYEAR*AGE) {
                sn = son;
                break;
            }
        }

        if (sn == null) {
            wrOut.write("-1\n");
        } else {
            int snID = sn.getId();
            wrOut.write(snID + "\n");
        }

        wrOut.close();
    }

}

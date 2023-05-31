
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Created by qf on 22.10.2016.
 */
public class KingHeir {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(new File("king.in")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int d = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<ArrayList<Integer>> sons = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> son = new ArrayList<>();
            st = new StringTokenizer(in.readLine());
            int day = Integer.parseInt(st.nextToken());
            int month = Integer.parseInt(st.nextToken());
            int year = Integer.parseInt(st.nextToken());
            son.add(day);
            son.add(month);
            son.add(year);
            sons.add(son);
        }
        int bestSonPos = -2;
        int y_min = 0;
        int m_min = 0;
        int d_min = 0;
        for (int i = 0; i < n; i++) {
            int year = sons.get(i).get(2);
            int month = sons.get(i).get(1);
            int day = sons.get(i).get(0);
            if(isAdult(y, m, d, year, month, day)){
                if(isYounger(year, month, day, y_min, m_min, d_min)){
                    y_min = year;
                    m_min = month;
                    d_min = day;
                    bestSonPos = i;
                }
            }
        }
        in.close();
        PrintWriter writer = new PrintWriter(new FileWriter(new File("king.out")));
        writer.print(bestSonPos + 1);
        writer.close();
    }

    private static boolean isYounger(int year, int month, int day, int y_min, int m_min, int d_min) {
        if( year > y_min) return true;
        if( year == y_min){
            if(month > m_min) return true;
            if (month == m_min){
                if( day >= d_min) return true;
            }
        }
        return false;
    }

    private static boolean isAdult(int y, int m, int d, int year, int month, int day){
        if( (y - year) > 18) return true;
        if ((y - year) == 18){
            if(m > month) return true;
            if(m == month){
                if(d >= day) return true;
            }
        }
        return false;
    }
}

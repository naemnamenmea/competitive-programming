import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Map;
import java.util.Scanner;

public class TaskH {

    static int x = 60;
    static int l = x + 1;
    static int[][] ar = new int[l][l];
    static Square[][][] asq = new Square[l][l][1000];

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("hard.in"));
        PrintWriter pw = new PrintWriter(new File("hard.out"));


        for (int i = 1; i < l; i++){
            ar[i][i] = 1; //заполнение диагонали
            asq[i][i][0] = new Square(0, 0, i);
        }
        for (int i = 1; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                int min = Integer.MAX_VALUE;
                int t1, t2;
                for (int k = 1; k <= i; k++) {
                    t1 = ar[Math.min(j-k, i)][Math.max(j-k,i)] + ar[Math.min(i-k, k)][Math.max(i-k,k)] + 1;
                    t2 = ar[Math.min(i-k, j)][Math.max(i-k,j)] + ar[Math.min(j-k, k)][Math.max(j-k,k)] + 1;
                    if (Math.min(t1, t2) < min){
                        if(t1 < t2){
                            min = t1;
                            admas2(i, j, k);
                        }else{
                            min = t2;
                            admas1(i, j, k);
                        }
                    }
                }
                ar[i][j] = min;
            }
            for (int j = i+1; j < l; j++) {
                ar[j][i] = ar[i][j];
                for (int k = 0; k < ar[i][j]; k++) {
                    asq[j][i][k] = new Square(asq[i][j][k].y, asq[i][j][k].x, asq[i][j][k].r);
                };
            }
        }

        /*
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                System.out.println(i + "x" + j + " _ " + ar[i][j]);
            }
        }
        */

        int num = sc.nextInt();
        for (int z = 0; z < num; z++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            pw.println(ar[a][b]);
            for (int i = 0; i < ar[a][b]; i++) {
                pw.println(asq[a][b][i].x + " " + asq[a][b][i].y + " " + asq[a][b][i].r);
            }
        }
        sc.close();
        pw.close();
    }

    static void admas2(int i, int j, int k){
        int m;
        for ( m = 0; m < ar[i][j-k]; m++) {
            asq[i][j][m] = asq[i][j-k][m];
        }
        Square temp;
        for (int n = 0; n < ar[i-k][k]; n++) {
            asq[i][j][n + m] = new Square(asq[i-k][k][n].x, asq[i-k][k][n].y + j - k, asq[i-k][k][n].r);
        }
        asq[i][j][m+ar[i-k][k]] = new Square(i-k, j-k, k);
    }

    static void admas1(int i, int j, int k){
        int m;
        for ( m = 0; m < ar[i-k][j]; m++) {
            asq[i][j][m] = asq[i-k][j][m];
        }
        Square temp;
        for (int n = 0; n < ar[k][j-k]; n++) {
            asq[i][j][n + m] = new Square(asq[k][j-k][n].x + i - k, asq[k][j-k][n].y, asq[k][j-k][n].r);
        }
        asq[i][j][m+ar[k][j-k]] = new Square(i-k, j-k, k);
    }

    /*
    static int cuts(int a, int b){
        int temp = a;
        a = Math.min(a, b);
        b = Math.max(temp, b);
        if(a == 0 || b == 0) return 0;
        if(a == b){ //a-min b-max
            return 1;
        }
        int min = 100000;
        for (int i = 0; i < a; i++) {
            int t1 = cuts(a, b - (i+1)) + cuts(a - (i + 1), (i + 1));
            int t2 = cuts(b, a - (i+1)) + cuts(b - (i + 1), (i + 1));
            if (Math.min(t1, t2) < min){
                min = Math.min(t1, t2);
            }
        }
        return min + 1;
    }
    */

    static class Square{
        int x, y, r;

        Square(int a,int b,int c){
            x = a;
            y = b;
            r = c;
        }

    }

}

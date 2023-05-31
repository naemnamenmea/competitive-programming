package com.company.test;

import java.io.FileReader;
import java.io.FileWriter;

public class Main {

    static long w = 0;
    static long h = 0;
    static long px1 = 0;
    static long py1 = 0;
    static long px2 = 0;
    static long py2 = 0;
    static int i, j = 0;

    public static void main(String[] args) throws Exception{
        FileReader red = new FileReader("anniversary.in");
        int simvol ;
        while ((simvol = red.read()) != 32){
            byte[] b = new byte[1];
            b[0] = (byte) simvol;
            w = (w*10) + new Integer(new String(b));
        }
        while ((simvol = red.read()) != 32){
            byte[] b = new byte[1];
            b[0] = (byte) simvol;
            h = (h*10) + new Integer(new String(b));
        }

        while ((simvol = red.read()) != 32){
            byte[] b = new byte[1];
            b[0] = (byte) simvol;
            px1 = (px1*10) + new Integer(new String(b));
        }

        while ((simvol = red.read()) != 32){
            byte[] b = new byte[1];
            b[0] = (byte) simvol;
            py1 = (py1*10) + new Integer(new String(b));
        }

        while ((simvol = red.read()) != 32){
            byte[] b = new byte[1];
            b[0] = (byte) simvol;
            px2 = (px2*10) + new Integer(new String(b));
        }

        while ((simvol = red.read()) != -1){
            byte[] b = new byte[1];
            b[0] = (byte) simvol;
            py2 = (py2*10) + new Integer(new String(b));
        }
        red.close();
        //System.out.print(w + " " + h + " " + px1 + " " + py2 + " " +px2 +  " " + py2);
        if (w >= 3 && h >=3)
        if (px1 != px2 || py1 != py2) {

            aVoid();
           // System.out.println("x1 = " + i + " x2 = " + j);
            FileWriter fw = new FileWriter("anniversary.out");
            fw.write(i + " " + 0 + " " + j + " " + h);
            fw.close();
        }
    }
    static float funY (float x1, float y1, float x2, float y2, float value){
        return (((value - x1) * (y2 - y1))/ (x2-x1)) + y1;
    }

    static int  aVoid(){
        for (i = 0; i <= w; i++) {
            for (j = 0; j <= w; j++) {
                //System.out.println("i="+i + " j="+j+" fun=" + (funY(i, 0, j, h, px1) + " py1=" +py1 + " py2=" + py2) + "  |" + (funY(i, 0, j, h, px1) < py1) +  "  |" + (funY(i, 0, j, h, px1) < py2));
                if ((funY(i, 0, j, h, px1) > py1) && (funY(i, 0, j, h, px2) < py2))
                    return 0;
                if ((funY(i, 0, j, h, px1) < py1) && (funY(i, 0, j, h, px2) > py2))
                    return 0;
            }
        }
        return 0;
    }
}

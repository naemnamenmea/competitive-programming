package com.company.test;

import java.io.*;

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
        String stroca = "";
        while ((simvol = red.read()) != 32){
            stroca += (char)simvol;
        }
        w = Integer.parseInt(stroca);
        stroca = "";

        while ((simvol = red.read()) != 32){
            stroca += (char)simvol;
        }
        h = Integer.parseInt(stroca);
        stroca = "";
        while ((simvol = red.read()) != 32){
            stroca += (char)simvol;
        }
        px1 = Integer.parseInt(stroca);
        stroca = "";

        while ((simvol = red.read()) != 32){
            stroca += (char)simvol;
        }
        py1 = Integer.parseInt(stroca);
        stroca = "";

        while ((simvol = red.read()) != 32){
            stroca += (char)simvol;
        }
        px2 = Integer.parseInt(stroca);
        stroca = "";

        while ((simvol = red.read()) != -1  ){
            stroca += (char)simvol;
        }
        py2 = Integer.parseInt(stroca);

        red.close();

        System.out.print(w + " " + h + " " + px1 + " " + py1 + " " +px2 +  " " + py2);
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

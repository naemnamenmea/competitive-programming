package com.company.king;

import java.io.FileReader;
import java.io.FileWriter;

public class Main {

    public static void main(String[] args) throws Exception{
        date Smert;
        int count ;
        date[] dates ;

        FileReader red = new FileReader("king.in");

        int simvol;
        String stroca = "";

        while ((simvol = red.read()) != 13){
                stroca += (char)simvol;
        }
        Smert =  date.newDate(stroca);

        red.read(); stroca="";
        while ((simvol = red.read()) != 13){
            stroca += (char)simvol;
        }
        count = new Integer(stroca);
        dates = new date[count];

        for (int i = 0; i < count; i++){
            red.read(); stroca="";
            while ((simvol = red.read())!= 13 && simvol!=-1 ) {
                stroca += (char) simvol;
            }
                dates[i] = date.newDate(stroca);
        }
        red.close();
        FileWriter fr = new FileWriter("king.out");
        System.out.print(date.rezolt(dates,Smert));
        fr.write(date.rezolt(dates,Smert)+"");
        fr.close();

    }
}

class date{
    public int day;
    public int month;
    public int age;

    date(int day, int month, int age){
        this.day = day;
        this.month = month;
        this.age = age;

    }

    static date newDate  (String stroca){
        return new date(
                new Integer(stroca.substring(0, stroca.indexOf(" "))),
                new Integer(stroca.substring( stroca.indexOf(" ")+1, stroca.lastIndexOf(" "))),
                new Integer(stroca.substring(stroca.lastIndexOf(" ")+1,stroca.length()))
        );
    }
    static int rezolt (date[] dates, date smert){
        int i = 0;
        for(date d : dates){
            if (smert.age - d.age > 18 ){
                i++;
            }
            else if (smert.age - d.age  == 18){
                if (smert.month - d.month > 0){
                    i++;
                }
                else if (smert.month - d.month == 0){
                    if (smert.day+1 - d.day >= 0){
                        i++;
                    }
                }
            }
        }
        if (i == 0){
            return -1;
        }
        else return i;
    }
}
package com.company.king;

import java.awt.*;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import static java.awt.Color.red;

public class Main {

    public static void main(String[] args) {

        date Smert;
        int count ;
        date[] dates ;

        try (FileReader red = new FileReader("king.in")){

        int simvol;
        String stroca = "";

        while ((simvol = red.read()) != 13){
                stroca += (char)simvol;
        }
        Smert =  date.newDate(stroca);

        if (Smert.age == 10000){
            red.close();
            FileWriter fr = new FileWriter("king.out");
            fr.write("-1");
            fr.close();
        }
        else {
            red.read();
            stroca = "";
            while ((simvol = red.read()) != 13) {
                stroca += (char) simvol;
            }
            count = new Integer(stroca);
            if (count > 100) count = 100;
            if (count < 0) count = 0;
            dates = new date[count];
            for (int i = 0; i < count; i++) {
                red.read();
                stroca = "";
                while ((simvol = red.read()) != 13 && simvol != -1) {
                    stroca += (char) simvol;
                }
                dates[i] = date.newDate(stroca);
            }
            red.close();
            FileWriter fr = new FileWriter("king.out");
            fr.write(date.rezolt(dates, Smert) + "");
            fr.close();
        }

        }
        catch (IOException e) {
            e.printStackTrace();
        }

    }
}

class date {
    public int day;
    public int month;
    public int age;

    date(int day, int month, int age){
        if (month < 1 || month > 12){
            this.age = 10000;
        }
        this.month = month;
        if (day < 1 || day > 31){
            this.age = 10000;
        }
        else if (month == 2 && day > 28){
            this.age = 10000;
        }
        this.day = day;

        if (this.age != 10000){
            if (age < 1 || age > 9999){
                this.age = 10000;
            }
            else {
                this.age = age;
            }
        }

    }

    static date newDate  (String stroca){
        return new date(
                new Integer(stroca.substring(0, stroca.indexOf(" "))),
                new Integer(stroca.substring( stroca.indexOf(" ")+1, stroca.lastIndexOf(" "))),
                new Integer(stroca.substring(stroca.lastIndexOf(" ")+1,stroca.length()))
        );
    }

    static boolean pro (ArrayList<date> dates, date value){
        for (date d : dates){
            if (d.day == value.day && d.month == value.month && d.age == value.age){
                return false;
            }
        }
        return true;
    }
    static int rezolt (date[] dates, date smert){
        int i = 0;
        ArrayList<date> pow = new ArrayList<>();

        for(date d : dates){
            if (smert.age - d.age > 18 ){
                if (date.pro(pow,d )){
                    i++;
                    pow.add(d);
                }
                else {i--;}
            }
            else if (smert.age - d.age  == 18){
                if (smert.month - d.month > 0){
                    if (date.pro(pow,d )){
                        i++;
                        pow.add(d);
                    }
                    else {i--;}
                }
                else if (smert.month - d.month == 0){
                    if (smert.day+1 - d.day >= 0){
                        if (date.pro(pow,d )){
                            i++;
                            pow.add(d);
                        }
                        else {i--;}
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
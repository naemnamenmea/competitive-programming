import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(new File("king.in"));		
		Son dayDeath = new Son();
		dayDeath.day = sc.nextInt(); dayDeath.month = sc.nextInt(); dayDeath.year = sc.nextInt()-18;
		
		int numSons = sc.nextInt();
		Son[] sons = new Son[numSons];
		for(int i = 0; i<numSons; i++){
			sons[i] = new Son();
			sons[i].day = sc.nextInt();
			sons[i].month = sc.nextInt();
			sons[i].year = sc.nextInt();
		}		
		sc.close();
		
		Son bestSon = new Son();
		bestSon.year = 0; bestSon.month = 0; bestSon.day = 0;
		int numBestSon = -1;
		
		for(int i = 0; i<numSons; i++){
			if(sons[i].year<dayDeath.year){
				if(sonCompare(sons[i], bestSon)==true){
					bestSon = sons[i];
					numBestSon = i+1;
				}
			}else if(sons[i].month<dayDeath.month && sons[i].year==dayDeath.year){
				if(sonCompare(sons[i], bestSon)==true){
					bestSon = sons[i];
					numBestSon = i+1;
				}
			}else if(sons[i].day<=dayDeath.day && sons[i].month==dayDeath.month && sons[i].year==dayDeath.year){
				if(sonCompare(sons[i], bestSon)==true){
					bestSon = sons[i];
					numBestSon = i+1;
				}
			}
		}
		
		System.out.print(numBestSon);
		
	}
	
	public static class Son{
		public int day, month, year;
		
	}
	
	public static boolean sonCompare(Son son, Son bestSon){
		if(son.year>bestSon.year){
			return true;
		}else if(son.month>bestSon.month && son.year==bestSon.year){
			return true;
		}else if(son.day>bestSon.day && son.month==bestSon.month && son.year==bestSon.year){
			return true;
		}
		return false;
	}

}
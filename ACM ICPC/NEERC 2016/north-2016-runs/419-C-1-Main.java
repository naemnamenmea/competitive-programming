import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(new File("codecoder.in"));
		PrintWriter pw = new PrintWriter(new File("codecoder.out"));
		
		int numMans = sc.nextInt();
		Man[] man = new Man[numMans];
		
		for(int i=0; i<numMans; i++){
			man[i] = new Man();
			man[i].cc = sc.nextInt();
			man[i].tf = sc.nextInt();
			man[i].num = 0;
		}
		
		sc.close();
		
		
		for(int i=0; i<numMans; i++){
			for(int j=i+1; j<numMans; j++){
				if(man[i].cc>man[j].cc || man[i].tf>man[j].tf) man[i].num++;
				if(man[j].cc>man[i].cc || man[j].tf>man[i].tf) man[j].num++;
			}
			pw.println(man[i].num);
		}
		pw.close();
		
	}
	
	public static class Man{
		int cc, tf, num;
	}

}

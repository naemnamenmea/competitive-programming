import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Task{
	public static void main(String args[]) throws FileNotFoundException {
		
		Scanner sc = new Scanner(new BufferedReader(new FileReader("king.in")));
		PrintWriter writer = new PrintWriter("king.out");
		
		int d = sc.nextInt(), m = sc.nextInt(), y = sc.nextInt(), n = sc.nextInt();
		
		long maxdate = (y-18) * 10000 + m * 100 + d; 
		long maxfounddate = 0;
		int count = -1;
		
		for (int i = 1; i < n + 1; i++) {
			int di = sc.nextInt(), mi = sc.nextInt(), yi = sc.nextInt();
			long datei = yi * 10000 + mi * 100 + di;
			if (datei <= maxdate && datei > maxfounddate) {
				maxfounddate = datei;
				count = i;
			}
			
		}
		
		writer.println(count);
		writer.close();
	}
	
	//public static boolean elder(int y1, int m1, int d1, int y2, int m2, int d2) {
		// первая дата меньше, возраст больше
//		if (y1 < y2) return false;
//		else if (m1 < m2) return false;
//		else if (d1 < d2) return false;
//		else return true;
	//}
}
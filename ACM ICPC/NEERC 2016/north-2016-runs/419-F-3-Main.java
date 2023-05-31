import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(new File("folding.in"));
		
		double firstW = sc.nextInt(), firstH = sc.nextInt(), lastW = sc.nextInt(), lastH = sc.nextInt();
		
		sc.close();
		
		int numFold = -1;
		
		if((lastW<=firstW && lastH<=firstH) || (lastW<=firstH && lastH<=firstW)){
			if(lastW>firstW || lastH>firstH){
				double buffer = firstW;
				firstW = firstH;
				firstH = buffer;
			}
			
			numFold = 0;
			
			if(lastW<firstW){
				while(lastW<firstW){					
					/*if(firstW % 2 == 0){
						firstW = firstW / 2;
					}else{
						firstW = firstW / 2 + 1;
					}*/
					firstW /= 2;
					numFold++;
				}
				
			}
			if(lastH<firstH){
				while(lastH<firstH){
					/*if(firstH % 2 == 0){
						firstH = firstH / 2;
					}else{
						firstH = firstH / 2 + 1;
					}*/
					firstH /= 2;
					numFold++;
				}
			}
		}
		
		if(numFold==0){numFold = -1;};
		
		PrintWriter pw = new PrintWriter(new File("folding.out"));
		
		pw.write(numFold+"");
		pw.close();
	}

}

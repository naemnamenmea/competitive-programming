import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		
		//BufferedReader br = new BufferedReader(new FileReader("anniversary.in"));
		
		//String buffer = br.readLine();
		
		//String[] inputInfo;
		//int indexInfo = 0;
		
		//while(buffer != null){
			//inputInfo[indexInfo] = buffer;
			//buffer = br.readLine();
		//}
		//br.close();
		
		Scanner sc = new Scanner(new File("anniversary.in"));		
		
		int cakeW = sc.nextInt(), cakeH = sc.nextInt(), Ax = sc.nextInt(), Ay = sc.nextInt(), Bx = sc.nextInt(), By = sc.nextInt();
		
		sc.close();
		
		int Mx, My, Nx, Ny;
		
		if(Ax == Bx){
			Mx = 0; My = Ay; Nx = cakeW; Ny = By;
		}else{
			Mx = Ax; My = 0; Nx = Bx; Ny = cakeH;
		}
		
		PrintWriter pw = new PrintWriter(new File("anniversary.out"));
		
		pw.write(Mx+" "+My+" "+Nx+" "+Ny);
		pw.close();
		
		
		// space - 32
		
	}
	
	/*public long[] getArr(String str){
		
		long[] arr = new long[6];
		int intArr = 0;
		String buffer = "";
		
		for(int i=0; i<str.length(); i++){
			if(str.charAt(i) == ' '){
				arr[intArr] = Long.parseLong(buffer);
				intArr++;
				buffer = "";
			}else{ buffer += str.charAt(i); }
			
		}
		
		return arr;
	}*/
}

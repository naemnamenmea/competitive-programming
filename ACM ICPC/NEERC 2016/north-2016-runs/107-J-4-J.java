import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class J {

	public static void main(String[] args) throws IOException {
		try (Scanner scanner = new Scanner(new File("java2016.in"))) {
			try (PrintWriter out = new PrintWriter(new File("java2016.out"))) {
				int n = scanner.nextInt();

				List<String> ans = new ArrayList<>();

				if (n == 0) {
					ans.add("? /?/ ?");
				} else {
					if (n == 1) {
						ans.add("a = ? max ?");
						ans.add("((a max a) / a");
					} else {
						ans.add("z = ? /?/ ?");						
						ans.add("a = ? max (? max (? max (? max (? max (? max (? max (? max ?)))))))");
						ans.add("b = (a max a) / a");
						
						int x = 'b', y = 'z';

						while (true) {
							if (n % 2 == 1) {
								ans.add(((char) (y - 1)) + " = " + ((char) (y)) + " + " + ((char) (x)));
								--y;
							}

							n /= 2;
							if (n == 0) {
								ans.add("" + ((char) (y)));
								break;
							} else {
								ans.add(((char) (x + 1)) + " = " + ((char) (x)) + " + " + ((char) (x)));
								++x;
							}
						}

					}
				}

				int len = 0;
				for (String line : ans) {
					len += line.length() + 1;
					out.println(line);
				}

				System.out.println(len);

			}
		}
	}

}



//z = ? /?/ ?
//a = ? max ?
//b = (a max a) / a
//y = z + b
//c = b + b
//x = y + c
//d = c + c
//e = d + d
//w = x + e
//f = e + e
//v = w + f
//g = f + f
//u = v + g
//h = g + g
//t = u + h
//t


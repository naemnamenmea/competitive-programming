import java.io.*;

public class K {

    static String inputName = "king.in";
    static String outputName = "king.out";
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(inputName));
        PrintWriter writer = new PrintWriter(new File(outputName));
        K.solve(reader, writer);
        reader.close();
        writer.close();
    }

    public static void solve(BufferedReader r, PrintWriter w) throws IOException {
        int perfectDay, perfectMonth, perfectYear;
        int quanityOfTheSons;
        int[] months = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        String line = r.readLine();
        String[] words = line.split(" ");
        perfectDay = Integer.parseInt(words[0]);
        perfectMonth = Integer.parseInt(words[1]);
        perfectYear = Integer.parseInt(words[2]) - 18;

        line = r.readLine();
        quanityOfTheSons = Integer.parseInt(line);

        int bestDay = 999, bestMonth = 999, bestYear = 999, bestId = -1;

        for (int i = 1; i <= quanityOfTheSons; i++) {
            line = r.readLine();
            words = line.split(" ");
            int dayOfSon = Integer.parseInt(words[0]);
            int monthOfSon = Integer.parseInt(words[1]);
            int yearOfSon = Integer.parseInt(words[2]);

            if (yearOfSon <= perfectYear) {
                int diffD, diffM = 0, diffY = 0;
                if (perfectDay < dayOfSon) {
                    diffD = perfectDay - dayOfSon + months[perfectMonth - 1];
                    diffM = -1;
                } else {
                    diffD = perfectDay - dayOfSon;
                }
                diffM += perfectMonth;

                if (diffM < monthOfSon) {
                    diffM = diffM - monthOfSon + 12;
                    diffY = -1;
                }

                diffY += perfectYear;

                if (diffY < yearOfSon) {
                    continue;
                } else {
                    diffY -= yearOfSon;
                }

                if (diffY < bestYear) {
                    bestYear = diffY;
                    bestMonth = diffM;
                    bestDay = diffD;
                    bestId = i;
                } else if (diffY == bestYear) {
                    if (diffM < bestMonth) {
                        bestYear = diffY;
                        bestMonth = diffM;
                        bestDay = diffD;
                        bestId = i;
                    } else if (diffM == bestMonth) {
                        if (diffD < bestDay) {
                            bestYear = diffY;
                            bestMonth = diffM;
                            bestDay = diffD;
                            bestId = i;
                        }
                    }
                }
            }





        }
        w.write(bestId + "");

    }
}

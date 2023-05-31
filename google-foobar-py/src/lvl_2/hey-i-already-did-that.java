public class Solution {
    public static int solution(String n, int b) {
        int k = n.length();
        int count = 0;
        Map<String, Integer> map = new HashMap<>();

        while (!map.containsKey(n)) {
            map.put(n, count);

            char[] chars = n.toCharArray();
            Arrays.sort(chars);
            String y = new String(chars);
            String x = new StringBuilder(y).reverse().toString();
            String z = Integer.toString(Integer.parseInt(x, b) - Integer.parseInt(y, b), b);
            //n = String.format("%1$" + k + "s", z).replace(' ', '0');
            char[] repeat = new char[k - z.length()];
            Arrays.fill(repeat, '0');
            n = new String(repeat) + z;
            count++;
        }

        int from = map.get(n);

        return count - from;
    }
}

assert (solution("1211", 10) == 1);
assert (solution("81", 10) == 5);
assert (solution("09", 10) == 5);
assert (solution("9", 10) == 1);
assert (solution("210022", 3) == 3);
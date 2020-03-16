import java.util.ArrayList;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        ArrayList<String> part1 = new ArrayList<String>();
        ArrayList<String> part2 = new ArrayList<String>();
        for (int i = 0; i < str1.length() - 1; ++i) {
            String pres = str1.substring(i, i + 2);
            if (Character.isLetter(pres.charAt(0)) && Character.isLetter(pres.charAt(1)))
                part1.add(pres.toLowerCase());
        }
        for (int i = 0; i < str2.length() - 1; ++i) {
            String pres = str2.substring(i, i + 2);
            if (Character.isLetter(pres.charAt(0)) && Character.isLetter(pres.charAt(1)))
                part2.add(pres.toLowerCase());
        }
        int sum = part1.size() + part2.size();
        int inters = 0;
        for (int i = 0; i < part1.size(); ++i) {
            for (int j = 0; j < part2.size(); ++j) {
                if (part1.get(i).equals(part2.get(j))) {
                    inters++;
                    part2.remove(j);
                    break;
                }
            }
        }
        sum -= inters;
        if (sum == 0)
            answer = 65536;
        else
            answer = inters * 65536 / sum;
        return answer;
    }
}
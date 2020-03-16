class Solution {
    public int solution(String s) {
        int answer = s.length();
        int slen = s.length();
        for (int i = 1; i < slen; ++i) {
            int count = 1;
            String prev = s.substring(0, i);
            String after = "";
            for (int j = i; j < slen; j += i) {
                String pres;
                if (slen - j < i)
                    pres = s.substring(j);
                else
                    pres = s.substring(j, j + i);
                if (prev.equals(pres))
                    count++;
                else {
                    if (count == 1)
                        after += prev;
                    else
                        after += (Integer.toString(count) + prev);
                    prev = pres;
                    count = 1;
                }
            }
            if (count == 1)
                after += prev;
            else
                after += (Integer.toString(count) + prev);
            if (answer > after.length())
                answer = after.length();
        }
        return answer;
    }
}
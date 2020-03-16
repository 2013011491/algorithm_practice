class Solution {
    public int solution(String[] lines) {
        int answer = 0;
        int start[] = new int[2001];
        int end[] = new int[2001];

        for (int i = 0; i < lines.length; ++i) {
            end[i] = (lines[i].charAt(11) - '0') * 36000 + (lines[i].charAt(12) - '0') * 3600
                    + (lines[i].charAt(14) - '0') * 600 + (lines[i].charAt(15) - '0') * 60
                    + (lines[i].charAt(17) - '0') * 10 + (lines[i].charAt(18) - '0');
            end[i] *= 1000;
            end[i] += Integer.parseInt(lines[i].substring(20, 23));
            int temp = 1000;
            int minus = 0;
            for (int j = 24; j < lines[i].length(); ++j) {
                if (lines[i].charAt(j) == '.')
                    continue;
                else if (lines[i].charAt(j) == 's')
                    break;
                minus += (lines[i].charAt(j) - '0') * temp;
                temp /= 10;
            }
            start[i] = end[i] - minus + 1;
        }
        for (int i = 0; i < lines.length; ++i) {
            int st = end[i];
            int fi = st + 999;
            int max = 0;
            for (int j = 0; j < lines.length; ++j) {
                if (start[j] <= fi && end[j] >= st)
                    max++;
            }
            if (max > answer)
                answer = max;
        }

        return answer;
    }
}
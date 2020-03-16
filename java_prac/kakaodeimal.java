class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        String trans = "0123456789ABCDEF";
        String bitstr = "0";
        int count = 1;
        int limit = p - 1 + ((t - 1) * m);
        int num = 0;
        while (count <= limit) {
            num++;
            int cpnum = num;
            String pres = "";
            while (cpnum != 0) {
                pres = trans.charAt(cpnum % n) + pres;
                cpnum /= n;
            }
            count += pres.length();
            bitstr += pres;
        }
        for (int i = p - 1; i <= limit; i += m) {
            answer += bitstr.charAt(i);
        }

        return answer;
    }
}
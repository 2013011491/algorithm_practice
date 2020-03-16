class Solution {
    public String solution(String p) {
        if (p == "")
            return "";
        String answer = "";
        String u = "";
        String v = "";
        int count;
        boolean isright = true;
        if (p.charAt(0) == '(')
            count = 1;
        else
            count = -1;
        for (int i = 1; i < p.length(); ++i) {
            if (count < 0)
                isright = false;
            if (p.charAt(i) == '(')
                count++;
            else
                count--;
            if (count == 0) {
                u = p.substring(0, i + 1);
                if (i != p.length() - 1)
                    v = p.substring(i + 1);
                break;
            }
        }
        if (isright)
            return u + solution(v);
        answer = "(" + solution(v) + ")";
        for (int i = 1; i < u.length() - 1; ++i) {
            if (u.charAt(i) == '(')
                answer += ")";
            else
                answer += "(";
        }
        return answer;
    }
}
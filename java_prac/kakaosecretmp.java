class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for (int i = 0; i < n; ++i) {
            int num = arr1[i] | arr2[i];
            char pres[] = new char[n];
            int index = n - 1;
            while (num != 0) {
                if (num % 2 == 1)
                    pres[index--] = '#';
                else
                    pres[index--] = ' ';
                num /= 2;
            }
            for (int k = index; k >= 0; --k) {
                pres[k] = ' ';
            }
            answer[i] = String.valueOf(pres);
        }
        return answer;
    }
}
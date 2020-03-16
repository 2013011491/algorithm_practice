import java.util.ArrayList;

class Solution {
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        ArrayList<int[]> stp = new ArrayList<int[]>();
        char nboard[][] = new char[m][n];
        for (int i = 0; i < m; ++i) {
            nboard[i] = board[i].toCharArray();
        }
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                char stc = nboard[i][j];
                if (nboard[i][j + 1] == stc && nboard[i + 1][j + 1] == stc && nboard[i + 1][j] == stc)
                    stp.add(new int[] { i, j });
            }
        }
        while (!stp.isEmpty()) {
            // numbering block and change
            for (int i = 0; i < stp.size(); ++i) {
                int st[] = new int[] { stp.get(i)[0], stp.get(i)[1] };
                if (nboard[st[0]][st[1]] != '0') {
                    answer++;
                    nboard[st[0]][st[1]] = '0';
                }
                if (nboard[st[0]][st[1] + 1] != '0') {
                    answer++;
                    nboard[st[0]][st[1] + 1] = '0';
                }
                if (nboard[st[0] + 1][st[1]] != '0') {
                    answer++;
                    nboard[st[0] + 1][st[1]] = '0';
                }
                if (nboard[st[0] + 1][st[1] + 1] != '0') {
                    answer++;
                    nboard[st[0] + 1][st[1] + 1] = '0';
                }
            }
            stp.clear();
            // remove zero value
            for (int i = 0; i < n; ++i) {
                char temp[] = new char[m];
                for (int k = 0; k < m; ++k) {
                    temp[k] = '0';
                }
                int index = m - 1;
                for (int j = m - 1; j >= 0; --j) {
                    if (nboard[j][i] != '0')
                        temp[index--] = nboard[j][i];
                }
                for (int j = 0; j < m; ++j) {
                    nboard[j][i] = temp[j];
                }
            }
            // re-search square
            for (int i = 0; i < m - 1; ++i) {
                for (int j = 0; j < n - 1; ++j) {
                    if (nboard[i][j] == '0')
                        continue;
                    char stc = nboard[i][j];
                    if (nboard[i][j + 1] == stc && nboard[i + 1][j + 1] == stc && nboard[i + 1][j] == stc)
                        stp.add(new int[] { i, j });
                }
            }
        }
        return answer;
    }
}
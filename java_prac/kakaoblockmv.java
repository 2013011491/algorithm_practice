import java.util.ArrayList;

class Solution {
    public int solution(int[][] board) {
        int answer = 0;
        int n = board.length;
        int visit[][][][] = new int[101][101][101][101];
        ArrayList<int[]> points = new ArrayList<int[]>();
        points.add(new int[] { 0, 0, 0, 1, 0, 0 }); // first point,2nd point,way,len
        while (!points.isEmpty()) {
            int pres[] = new int[6];
            pres = points.get(0);
            if (visit[pres[0]][pres[1]][pres[2]][pres[3]] == 1) {
                points.remove(0);
                continue;
            }
            if ((pres[0] == n - 1 && pres[1] == n - 1) || (pres[2] == n - 1 && pres[3] == n - 1)) {
                answer = pres[5];
                break;
            }
            visit[pres[0]][pres[1]][pres[2]][pres[3]] = 1;
            if (pres[4] == 0) // row case
            {
                if (pres[3] < n - 1 && board[pres[2]][pres[3] + 1] == 0)
                    points.add(new int[] { pres[2], pres[3], pres[2], pres[3] + 1, 0, pres[5] + 1 });
                if (pres[1] > 0 && board[pres[0]][pres[1] - 1] == 0)
                    points.add(new int[] { pres[0], pres[1] - 1, pres[0], pres[1], 0, pres[5] + 1 });
                if (pres[0] < n - 1 && board[pres[0] + 1][pres[1]] == 0 && board[pres[2] + 1][pres[3]] == 0) {
                    points.add(new int[] { pres[0] + 1, pres[1], pres[2] + 1, pres[3], 0, pres[5] + 1 });
                    points.add(new int[] { pres[0], pres[1], pres[0] + 1, pres[1], 1, pres[5] + 1 });
                    points.add(new int[] { pres[2], pres[3], pres[2] + 1, pres[3], 1, pres[5] + 1 });
                }
                if (pres[0] > 0 && board[pres[0] - 1][pres[1]] == 0 && board[pres[2] - 1][pres[3]] == 0) {
                    points.add(new int[] { pres[0] - 1, pres[1], pres[2] - 1, pres[3], 0, pres[5] + 1 });
                    points.add(new int[] { pres[0] - 1, pres[1], pres[0], pres[1], 1, pres[5] + 1 });
                    points.add(new int[] { pres[2] - 1, pres[3], pres[2], pres[3], 1, pres[5] + 1 });
                }
            } else {
                if (pres[2] < n - 1 && board[pres[2] + 1][pres[3]] == 0)
                    points.add(new int[] { pres[2], pres[3], pres[2] + 1, pres[3], 1, pres[5] + 1 });
                if (pres[0] > 0 && board[pres[0] - 1][pres[1]] == 0)
                    points.add(new int[] { pres[0] - 1, pres[1], pres[0], pres[1], 1, pres[5] + 1 });
                if (pres[1] < n - 1 && board[pres[0]][pres[1] + 1] == 0 && board[pres[2]][pres[3] + 1] == 0) {
                    points.add(new int[] { pres[0], pres[1] + 1, pres[2], pres[3] + 1, 1, pres[5] + 1 });
                    points.add(new int[] { pres[0], pres[1], pres[0], pres[1] + 1, 0, pres[5] + 1 });
                    points.add(new int[] { pres[2], pres[3], pres[2], pres[3] + 1, 0, pres[5] + 1 });
                }
                if (pres[1] > 0 && board[pres[0]][pres[1] - 1] == 0 && board[pres[2]][pres[3] - 1] == 0) {
                    points.add(new int[] { pres[0], pres[1] - 1, pres[2], pres[3] - 1, 1, pres[5] + 1 });
                    points.add(new int[] { pres[0], pres[1] - 1, pres[0], pres[1], 0, pres[5] + 1 });
                    points.add(new int[] { pres[2], pres[3] - 1, pres[2], pres[3], 0, pres[5] + 1 });
                }
            }
            points.remove(0);
        }
        return answer;
    }
}
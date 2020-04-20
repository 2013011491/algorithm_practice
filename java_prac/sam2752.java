import java.util.Scanner;

class Solution
{
    public static int score[];
    public static int possi[];
    public static int n;
    public static void main(final String args[]) throws Exception {
        final Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        for (int tc = 1; tc <= t; ++tc) {
            n = sc.nextInt();
            int limit=0;
            score = new int[101];
            possi = new int[10001];
            for (int i = 0; i < n; ++i) {
                score[i] = sc.nextInt();
                possi[score[i]] = 1;
                limit+=score[i];
            }
            dfs(0, 0);
            int count=1;
            System.out.print("#"+tc+" ");
            for(int i=0; i<=limit; ++i){if(possi[i]!=0) count++;}
            System.out.println(count);   
        }
        return;
    }

    public static void dfs(final int st, final int sum)
    {
        for(int i=st; i<n; ++i)
        {
            possi[score[i]+sum]=1;
            dfs(i+1,score[i]+sum);
        }
    }

}
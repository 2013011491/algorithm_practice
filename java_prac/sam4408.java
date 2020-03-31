import java.util.Scanner;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T,n;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
            n=sc.nextInt();
            int room[] = new int[201];
            int ans=1;
            for(int i=0; i<n; ++i)
            {
                int a,b;
                a=sc.nextInt();
                b=sc.nextInt();
                a=(a+1)/2;
                b=(b+1)/2;
                if(a>b)
                {
                    int temp=a;
                    a=b;
                    b=temp;
                }
                for(int j=a; j<=b; ++j){room[j]++;}
            }
            for(int i=0; i<201; ++i){if(room[i]>ans) ans=room[i];}
            System.out.println("#"+test_case+" "+ans);
		}
	}
}
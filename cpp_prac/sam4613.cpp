//200220 15:22 start d4  65.43% 15:46end
//색칠하기의 경우 자리 신경 안쓰고 색 갯수만 구해서 하면 더빠름.
#include<iostream>
#include<array>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,m;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        array<string,51> flag;
        cin>>n>>m;
        for(int i=0; i<n; ++i){ cin>>flag[i]; }
        int remain=n-3;
        int min=2501;
        for(int i=0; i<=remain; ++i)
        {
            for(int j=0; j<=remain-i; ++j)
            {
                int k=remain-i-j;
                int count=0;
                // 0~i, i+1 ~ i+1+j, i+j+2 ~ i+j+2+k
                for(int l=0; l<=i; ++l)
                {
                    for(int c=0; c<m; ++c){ if(flag[l][c]!='W') count++;}
                }
                for(int l=i+1; l<=i+1+j; ++l)
                {
                    for(int c=0; c<m; ++c){ if(flag[l][c]!='B') count++;}
                }
                for(int l=i+j+2; l<=i+j+2+k; ++l)
                {
                    for(int c=0; c<m; ++c){ if(flag[l][c]!='R') count++;}
                }
                if(count<min) min=count;
            }
        }
        cout<<"#"<<tc<<" "<<min<<"\n";
    }
    return 0;
}
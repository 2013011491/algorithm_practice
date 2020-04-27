//200422 19:35 gold4 re_solve
#include <iostream>

using namespace std;

int main(void)
{
    int A[22][22]={0,};
    int n;
    int ans=4000000;
    cin>>n;
    for(int i=1; i<=n; ++i){for(int j=1; j<=n; ++j){cin>>A[i][j];}}
    for(int x=1; x<n; ++x)
    {
        for(int y=2; y<n; ++y)
        {
            for(int d1=1; x+d1<n; ++d1)
            {
                if((y-d1)<1) break;
                for(int d2=1; x+d1+d2<=n; ++d2)
                {
                    if(y+d2>n) break;
                    int cri=x, st=y, fi=y;
                    int part[6]={0,};
                    int ott=1, ttf=2;
                    for(int i=1; i<=n; ++i)
                    {
                        if(i<cri)
                        {
                            for(int j=1; j<=n; ++j)
                            {
                                if(j<=st) part[1]+=A[i][j];
                                else part[2]+=A[i][j];
                            }
                        }else if(i>cri)
                        {
                            for(int j=1; j<=n; ++j)
                            {
                                if(j<st) part[3]+=A[i][j];
                                else part[4]+=A[i][j];
                            }
                        }else
                        {
                            if(st==y-d1) ott=3;
                            for(int j=1; j<=n; ++j)
                            {
                                if(j<st) part[ott]+=A[i][j];
                                else if(j>fi) part[ttf]+=A[i][j];
                                else part[5]+=A[i][j];
                            }
                            if(fi==y+d2) ttf=4;
                            
                            if(cri!=x+d1+d2) 
                            {
                                cri++;
                                if(ott==1) st--;
                                else st++;
                                if(ttf==2) fi++;
                                else fi--;
                            }
                        }
                    }
                    int min=part[1],max=part[1];
                    for(int i=2; i<6; ++i)
                    {
                        if(min>part[i]) min=part[i];
                        if(max<part[i]) max=part[i];
                    }
                    if(max-min<ans) ans=max-min;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
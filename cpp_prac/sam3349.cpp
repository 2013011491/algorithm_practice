//200303 21:10 start D4 35.42% ver2
#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

int main(void)
{
    int t,w,h,n,ans;
    scanf("%d",&t);
    for(int tc=1; tc<=t; ++tc)
    {
        array<int,2> prev;
        array<int,2> pres;
        ans=0;
        scanf("%d %d %d %d %d",&w,&h,&n,&prev[0],&prev[1]);
        for(int i=1; i<n; ++i)
        {
            scanf("%d %d",&pres[0],&pres[1]);
            int x=abs(pres[0]-prev[0]);
            int y=abs(pres[1]-prev[1]);
            if((prev[0]<=pres[0] && prev[1]<=pres[1])||
            (pres[0]<prev[0] && pres[1]<prev[1])) ans+=max(x,y);
            else ans+=(x+y);
            prev=pres;
        }
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}
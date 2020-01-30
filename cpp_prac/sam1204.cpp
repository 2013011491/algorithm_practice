//20200130 1739 start   1800 end
#include<iostream>
#include<algorithm>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    array<int,1000> score;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        int tnum;
        cin>>tnum;
        cout<<"#"<<tnum<<" ";
        for(int i=0; i<1000; ++i)
        {
            cin>>score[i];
        }
        sort(score.begin(),score.end());

        int ans=0;
        int freq=0;
        int pres=score[0];
        int pindex=0;

        for(int i=1; i<1000; ++i)
        {
            if(score[i]!=pres)
            {
                if((i-pindex)>=freq)
                {
                    freq=i-pindex;
                    ans=score[pindex];
                }
                pindex=i;
                pres=score[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
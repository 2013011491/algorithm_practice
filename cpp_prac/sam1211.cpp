#include<iostream>
#include<queue>
#include<array>


using namespace std;

int main(void)
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);

    int trash;
    for(int tc=0; tc<1; tc++)
    {
        queue<array<int,6>> bucket;  //prevx,prevy,x,y,len,stpoint
        array<int,6> pres;
        int nofst=0;
        int ladder[100][100]={0,};
        cin>>trash;
        for(int j=0; j<100; j++)
        {
            cin>>ladder[0][j];
            if(ladder[0][j]==1)
            { 
                bucket.push({0,j,1,j,1,j});
                nofst++;
            }
        }        
        for(int i=1; i<100; i++)
        {
            for(int j=0; j<100; j++) cin>>ladder[i][j];
        }
        cout<<"#"<<tc+1<<" ";

        while(1)
        {
            pres=bucket.front();
            bucket.pop();
            cout<<pres[0]<<" "<<pres[1]<<" "<<pres[2]<<" "<<pres[3]<<" "<<pres[4]<<" "<<pres[5]<<"\n";
            if(pres[2]==99)
            {
                int stpoint=pres[5];
                for(int i=1; i<nofst; i++)
                {
                    if(bucket.front()[0]==99 && bucket.front()[3]>stpoint) stpoint=bucket.front()[5];
                }
                cout<<stpoint<<"\n";
                break;
            }else
            {
                if(pres[3]<99 && ladder[pres[2]][pres[3]+1]==1 && pres[3]+1!=pres[1]) bucket.push({pres[2],pres[3],pres[2],pres[3]+1,pres[4]+1,pres[5]});
                else if(pres[3]>0 && ladder[pres[2]][pres[3]-1]==1 && pres[3]-1!=pres[1]) bucket.push({pres[2],pres[3],pres[2],pres[3]-1,pres[4]+1,pres[5]});
                else bucket.push({pres[2],pres[3],pres[2]+1,pres[3],pres[4]+1,pres[5]});
            }
        }
    }

    return 0;
}
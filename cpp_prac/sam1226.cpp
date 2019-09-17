#include<iostream>
#include<stack>


using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int tc=0; tc<10; tc++)
    {
        int trash;
        int possi=0;
        int check[16][16]={0,};
        char mirror[16][16];
        stack<pair<int,int>> bucket;

        cin>>trash;
        for(int i=0; i<16; i++) cin>>mirror[i];

        cout<<"#"<<tc+1<<" ";

        pair<int,int> stp;
        int tempcheck=0;
        for(int i=1; i<15; i++)
        {
            for(int j=1; j<15; j++)
            {
                if(mirror[i][j]=='2')
                {
                    stp=make_pair(i,j);
                    tempcheck=1;
                    break;
                }
            }
            if(tempcheck==1) break;
        }
        bucket.push(stp);

        while(bucket.size())
        {
            stp=bucket.top();
            bucket.pop();
            if(mirror[stp.first][stp.second]=='3')
            {
                possi=1;
                break;
            }
            
            if(check[stp.first][stp.second]==1) continue;
            else check[stp.first][stp.second]=1;

            if(mirror[stp.first-1][stp.second]=='0'||mirror[stp.first-1][stp.second]=='3') bucket.push(make_pair(stp.first-1,stp.second)); //north
            if(mirror[stp.first][stp.second-1]=='0'||mirror[stp.first][stp.second-1]=='3') bucket.push(make_pair(stp.first,stp.second-1)); //west            
            if(mirror[stp.first+1][stp.second]=='0'||mirror[stp.first+1][stp.second]=='3') bucket.push(make_pair(stp.first+1,stp.second)); //south
            if(mirror[stp.first][stp.second+1]=='0'||mirror[stp.first][stp.second+1]=='3') bucket.push(make_pair(stp.first,stp.second+1)); //east
        }
        if(possi==1) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}
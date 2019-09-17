#include<iostream>
#include<stack>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int trash;
    char mirror[101][101];
    array<int,2> pres;
    for(int tc=0; tc<1; tc++)
    {
        stack<array<int,2>> bucket;
        int check[100][100]={0,};
        int possi=0;
        cin>>trash;
        for(int i=0; i<100; i++) cin>>mirror[i];
        bucket.push({1,1});

        cout<<"#"<<tc+1<<" ";
        while(bucket.size())
        {
            pres=bucket.top();
            bucket.pop();
            if(mirror[pres[0]][pres[1]]=='3')
            {
                possi=1;
                break;
            }
            check[pres[0]][pres[1]]=1;
            if(mirror[pres[0]-1][pres[1]]!='1' && !check[pres[0]-1][pres[1]]) bucket.push({pres[0]-1,pres[1]});
            if(mirror[pres[0]][pres[1]-1]!='1' && !check[pres[0]][pres[1]-1]) bucket.push({pres[0],pres[1]-1});
            if(mirror[pres[0]+1][pres[1]]!='1' && !check[pres[0]+1][pres[1]]) bucket.push({pres[0]+1,pres[1]});
            if(mirror[pres[0]][pres[1]+1]!='1' && !check[pres[0]][pres[1]+1]) bucket.push({pres[0],pres[1]+1});
        }
        cout<<possi<<"\n";
    }
    return 0;
}
//200212 20:25 start D4 42.60%  21:18 53min
//역시 dfs가 답, 쓸데없이 copy함 그냥 배열 하나를 더만들었으면 됐었음.
#include<iostream>
#include<array>
#include<algorithm>
#include<stack>

using namespace std;

int n;
int cheeze[102][102]={0,};

void eatch(int days)
{
    for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=n; ++j)
        {
            if(cheeze[i][j]==days) cheeze[i][j]=0;
        }
    }
}

int checkch()
{
    int ccheeze[102][102];
    stack<array<int,2>> bucket;
    copy(&cheeze[0][0],&cheeze[0][0]+(102*102),&ccheeze[0][0]);
    int result=0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(ccheeze[i][j]!=0)
            {
                result++;
                bucket.push({i,j});
                while(!bucket.empty())
                {
                    array<int,2> pres=bucket.top();
                    bucket.pop();
                    ccheeze[pres[0]][pres[1]]=0;
                    if(ccheeze[pres[0]+1][pres[1]]!=0) bucket.push({pres[0]+1,pres[1]});
                    if(ccheeze[pres[0]-1][pres[1]]!=0) bucket.push({pres[0]-1,pres[1]});
                    if(ccheeze[pres[0]][pres[1]+1]!=0) bucket.push({pres[0],pres[1]+1});
                    if(ccheeze[pres[0]][pres[1]-1]!=0) bucket.push({pres[0],pres[1]-1});
                }
            }
        }
    }
    return result;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        int maxday=1;
        cin>>n;
        for(int i=1; i<=n; ++i)
        { 
            for(int j=1; j<=n; ++j)
            { 
                cin>>cheeze[i][j];
                if(cheeze[i][j]>maxday) maxday=cheeze[i][j];
            }
            cheeze[i][n+1]=0;
        }
        for(int i=0; i<=n+1; ++i){ cheeze[n+1][i]=0;}

        int maxch=1;
        for(int days=1; days<maxday; ++days)
        {
            eatch(days);
            int presch=checkch();
            if(maxch<presch) maxch=presch;
        }
        cout<<maxch<<"\n";
    }
    return 0;
}
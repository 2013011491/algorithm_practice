#include<iostream>
#include<queue>
#include<array>

using namespace std;

int visited[100001]={0,};
int main(void)
{
    int n,k;
    
    array<int,2> pres;
    queue<array<int,2>> bucket;
    cin>>n>>k;
    bucket.push({n,0});
    while(1)
    {
        pres=bucket.front();
        bucket.pop();
        if(visited[pres[0]]==1) continue;

        if(pres[0]==k)
        {
            cout<<pres[1];
            return 0;
        }
        visited[pres[0]]=1;
        if(pres[0]>0) bucket.push({pres[0]-1,pres[1]+1});
        if(pres[0]<100000) bucket.push({pres[0]+1,pres[1]+1});
        if(pres[0]>0 && pres[0]<=50000) bucket.push({pres[0]*2,pres[1]+1});
    }
    
}
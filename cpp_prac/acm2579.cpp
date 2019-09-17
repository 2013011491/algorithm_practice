#include<iostream>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int stairs[301];
    for(int i=0; i<n; i++) cin>>stairs[i+1];
    if(n==1)
    {
        cout<<stairs[1];
        return 0;
    }
    if(n==2)
    {
        cout<<stairs[1]+stairs[2];
        return 0;
    }

    pair<int,int> bucket[n+1];
    bucket[1]=make_pair(stairs[1],1);
    bucket[2]=make_pair(stairs[2]+stairs[1],2);
    if(stairs[2]>stairs[1]) bucket[3]=make_pair(stairs[2]+stairs[3],2);
    else bucket[3]=make_pair(stairs[1]+stairs[3],1);

    pair<int,int> max=make_pair(0,0);
    for(int i=4; i<=n; i++)
    {
        if(bucket[i-1].second!=2) max=make_pair(bucket[i-1].first+stairs[i],2);
        else max=make_pair(bucket[i-3].first+stairs[i-1]+stairs[i],2);

        if(max.first<bucket[i-2].first+stairs[i]) max=make_pair(bucket[i-2].first+stairs[i],1);
        bucket[i]=max;
    }
    cout<<bucket[n].first<<"\n";
     
    return 0;

}
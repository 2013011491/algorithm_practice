#include<iostream>

using namespace std;

int way[11]={0,};
int main(void)
{

    int t,n;
    cin>>t;
    int quest[t];
    for(int i=0; i<t; i++) cin>>quest[i];

    way[1]=0;
    way[2]=2;
    way[3]=4;
    way[4]=7;
    for(int i=5; i<11; i++)
    {
        int count=0;
        for(int j=1; j<4; j++) count+=way[i-j];
        way[i]=count;
    }
    way[1]=1;
    for(int i=0; i<t; i++) cout<<way[quest[i]]<<"\n";
    return 0;
}
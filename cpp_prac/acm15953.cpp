#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,a,b;
    int sum;
    int prize7[22]={0,500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10};
    int prize8[32]={0,512,256,256,128,128,128,128,64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32};
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>a>>b;
        sum=0;
        if(a>0 && a<22) sum+=prize7[a];
        if(b>0 && b<32) sum+=prize8[b];
        cout<<sum*10000<<"\n";
    }
    return 0;
}
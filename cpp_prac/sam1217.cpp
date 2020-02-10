//200207 17:57 start D3 83.48% just prac   18:02  5min
#include<iostream>

using namespace std;

int pow(int n, int m)
{
    if(m==1) return n;
    else return n * pow(n, m-1); 
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int tt=1; tt<=10; ++tt)
    {
        int tc,n,m;
        cin>>tc>>n>>m;
        cout<<"#"<<tc<<" "<<pow(n,m)<<"\n";
    }
    return 0;
}
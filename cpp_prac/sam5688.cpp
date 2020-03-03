//200303 20:19 start D3 28.72% 20:37end 18min
#include<iostream>

using namespace std;

long long sto[1000001]={0,};

long long bsearch(long long n, long long left, long long right)
{
    long long mid=(left+right)/2;
    if(sto[mid]==n) return mid;
    if(left>right) return -1;
    if(sto[mid]<n) return bsearch(n,mid+1,right);
    else return bsearch(n,left,mid-1);
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    long long n;
    cin>>t;
    for(long long i=2; i<=1000001; ++i){sto[i]=i*i*i;}
    sto[1]=1;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        cout<<"#"<<tc<<" "<<bsearch(n,1,1000000)<<"\n";
    }
    return 0;
}
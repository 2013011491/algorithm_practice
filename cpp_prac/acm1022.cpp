#include<iostream>
#include<cmath>

using namespace std;

long long maxv=1;

long long valueofp(int r,int c)
{
    if(r==0 && c==0) return 1;
    long long bar;
    int dif=abs(abs(r)-abs(c));
    long long layer;
    bool isxbig;
    long long ans;
    if(abs(r)>abs(c)) 
    {
        layer=abs(r);
        isxbig=true;
    }else
    {
        layer=abs(c);
        isxbig=false;
    }
    if(r<=0 && c>0)
    {
        bar=(2*layer+1)*(2*layer+1)-(6*layer);
        if(dif==0)  ans=bar;
        else if(isxbig) ans=bar+dif;
        else ans=bar-dif;
    }else if(r<0 && c<=0)
    {
        bar=(2*layer+1)*(2*layer+1)-(4*layer);
        if(dif==0)  ans=bar;
        else if(isxbig) ans=bar-dif;
        else ans=bar+dif;
    }else if(r>=0 && c<0)
    {
        bar=(2*layer+1)*(2*layer+1)-(2*layer);
        if(dif==0)  ans=bar;
        else if(isxbig) ans=bar+dif;
        else ans=bar-dif;
    }else if(r>0 && c>=0)
    {
        bar=(2*layer+1)*(2*layer+1);
        if(dif==0)  ans=bar;
        else if(isxbig) ans=bar-dif;
        else
        {
          bar=(2*layer-1)*(2*layer-1);
          ans=bar+dif;  
        }
    }
    if(ans>maxv) maxv=ans;
    return ans;
}

int main(void)
{
    int rc[4];
    cin>>rc[0]>>rc[1]>>rc[2]>>rc[3];
    int ans[50][5]={0,};
    int k=0,l=0;
    for(int i=rc[0]; i<=rc[2]; ++i)
    {
        l=0;
        for(int j=rc[1]; j<=rc[3]; ++j)
        {
            ans[k][l++]=valueofp(i,j);
        }
        k++;
    }
    int count=0;
    while(maxv!=0)
    {
        count++;
        maxv/=10;
    }
    for(int i=0; i<k; ++i)
    {
        for(int j=0; j<l; ++j)
        {
            cout.width(count);
            cout<<ans[i][j]<<" ";
        }
        if(i!=k-1) cout<<"\n";
    }

    return 0;
}
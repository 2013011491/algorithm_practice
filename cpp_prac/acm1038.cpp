#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    if(n>1022)
    {
        cout<<-1;
        return 0;
    } 

    long long bucket[1023]={0,};
    for(int i=0; i<10; ++i){bucket[i]=i;}
    if(n<10){cout<<n; return 0;}
    int st=0, end=9;
    long long exp=1;
    int count=10;
    for(int i=1; i<10; ++i)
    {
        for(int j=i; j<10; ++j)
        {
            for(int k=st; k<=end; ++k)
            {
                if(bucket[k]/exp<j) 
                {
                    bucket[count++]=j*10*exp+bucket[k];
                    if(count==n+1)
                    {
                        cout<<bucket[n];
                        return 0;
                    }
                }
                else break;
            }
        }
        st=end+1;
        end=count-1;
        exp*=10;
    }
    cout<<count;
    return 0;
}
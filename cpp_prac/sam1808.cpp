#include<iostream>
#include<cmath>

using namespace std;

int count=0;
int digit[10];

int Result(int num)
{
    int n=num;
    int check=0;
    while(n!=0)
    {
        if(digit[n%10]!=1) break;
        else
        {
            check++;
            n/=10;
        }
    }
    if(n==0) return check;

    check=0;
    int root=sqrt(num);
    int min=1000001;
    for(int i=2; i<=root; i++)
    {   
        check=0;
        if(num%i==0)
        {
            int result1=Result(i);
            if(result1==0) continue;
            int result2=Result(num/i);
            if(result2==0) continue;

            check=result1+result2+1;
            if(min>check) min=check;
        }
    }
    if(min!=1000001) return min;
    else return 0;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    int target;
    cin>>t;

    for(int tc=0; tc<t; tc++)
    {
        for(int i=0; i<10; i++) cin>>digit[i];
        cin>>target;
        cout<<"#"<<tc+1<<" ";

        int n=target;
        int possi=0;
        while(n!=0)
        {
            if(digit[n%10]==0) break;
            else
            {
                n/=10;
                possi++;
            }
        }
        if(n==0)
        {
            cout<<possi+1<<"\n";
            continue;
        }
        
        int solu=Result(target);
        if(solu==0) cout<<-1<<"\n";
        else cout<<solu+1<<"\n";

    }
    return 0;
}
#include<iostream>

using namespace std;

int broken[10]={0,};

int check(int n)
{
    int plus=n;
    int minus=n;
    int testp;
    int testm;
    int complete=0;
    int count;
    while(1)
    {
        
        testp=plus;
        testm=minus;
        if(testp==100) return 100-n;
        if(testm==100) return n-100;
        count=0;
        while(testm>=0)
        {
            count++;
            if(broken[testm%10]==1) break;
            else if(testm>=10) testm/=10;
            else
            {
                complete=1;
                break;
            }
        }
        if(complete)
        {
            if(minus==101) return n-minus+1;
            else if(minus==102) return n-minus+2;
            return n-minus+count;
        }

        count=0;
        while(testp)
        {
            count++;
            if(broken[testp%10]==1) break; 
            else if(testp>=10) testp/=10;
            else
            {
                complete=1;
                break;
            }
        }
        if(complete)
        {
            if(plus==99) return plus-n+1; 
            return plus-n+count;
        }
        
        plus++;
        minus--;
    }

}
int main(void)
{
    int n,m;

    cin>>n;
    cin>>m;
    if(m!=0)
    {
        int temp;
        for(int i=0; i<m; i++)
        {
            cin>>temp;
            broken[temp]=1;
        }
    }else
    {
        int count=0;
        if(n==99 || n==101)
        {
            cout<<1; 
            return 0;
        }else if(n==102)
        {
            cout<<2;
            return 0;
        }else if(n==100)
        {
            cout<<0;
            return 0;
        }

        if(n==0)
        {
            cout<<1;
            return 0;
        }
        while(n)
        {
            count++;
            n/=10;
        }
        cout<<count;
        return 0;
    }
    if(n==99 || n==101)
    {
        cout<<1; 
        return 0;
    }else if(n==102)
    {
        cout<<2;
        return 0;
    }else if(n==100)
    {
        cout<<0;
        return 0;
    }
    cout<<check(n);
    return 0;
}
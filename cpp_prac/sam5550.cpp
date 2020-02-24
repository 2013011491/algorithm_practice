//200224 start 16:19 d4 49.19% 17:26 end 67min
//문제 이해 너무 오래걸림.
#include<iostream>
#include<string>
#include<array>

using namespace std;

int trans(char c)
{
    int result=0;
    if(c=='r') result=1;
    else if(c=='o') result=2;
    else if(c=='a') result=3;
    else if(c=='k') result=4;
    return result;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    string roar;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        int arr[500]={0,};
        int size=0;
        int presn=0;
        int ans=0;
        cin>>roar;
        int possi=1;
        for(int i=0; i<roar.size(); ++i)
        {
            int pres=trans(roar[i]);
            int check=1;
            for(int j=0; j<size; ++j)
            {
                if(arr[j]==pres)
                { 
                    check=0;
                    arr[j]++;
                    if(arr[j]==5)
                    { 
                        arr[j]=0;
                        presn--;
                    }
                    if(arr[j]==1) presn++;
                    break;
                }
            }
            if(check==1)
            {
                if(pres==0)
                {
                    presn++;
                    arr[size]++;
                    size++;
                }else
                {
                    possi=-1;
                    break;
                }
            }
        }
        cout<<"#"<<tc<<" ";
        if(possi==-1 || presn!=0) cout<<-1<<"\n"; 
        else if(presn==0 && possi==1) cout<<size<<"\n";
    }
    return 0;
}
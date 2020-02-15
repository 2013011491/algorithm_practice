//200215 15:10 start D3 81.95%  15:26 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int pp=1; pp<=10; ++pp)
    {
        int tc;
        int arr[8]={0,};
        cin>>tc;
        for(int i=0; i<8; ++i){ cin>>arr[i]; }
        int i=1;
        int st=0;
        while(1)
        {
            arr[st]-=i;
            i++;
            if(i>5) i=1;
            int origin=st;
            if(++st == 8) st=0;
            if(arr[origin]<=0)
            {
                arr[origin]=0;
                break;
            }
        }
        cout<<"#"<<tc<<" ";
        for(int i=0; i<8; ++i)
        { 
            cout<<arr[st++]<<" ";
            if(st==8) st=0;
        }
        cout<<"\n";
    }
    return 0;
}
//200212 18:05 start d2 75.14%  18:17 end
#include<iostream>

using namespace std;

int arr[7][7]={0,};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        for(int i=0; i<n; ++i){ for(int j=0; j<n; ++j){ cin>>arr[i][j]; }}
        cout<<"#"<<tc<<"\n";
        for(int i=0; i<n; ++i)
        {
            for(int j=n-1; j>=0; --j){ cout<<arr[j][i]; }
            cout<<" ";
            for(int j=n-1; j>=0; --j){ cout<<arr[n-i-1][j]; }
            cout<<" ";
            for(int j=0; j<n; ++j){ cout<<arr[j][n-i-1]; }
            cout<<"\n";
        }   
    }
    return 0;
}
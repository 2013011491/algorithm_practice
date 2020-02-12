//200212 18:01 start D2 76.83%  18:04 end
#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    array<int,50> arr;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        for(int i=0; i<n; ++i){ cin>>arr[i]; }

        sort(arr.begin(),arr.begin()+n);
        cout<<"#"<<tc<<" ";
        for(int i=0; i<n; ++i){ cout<<arr[i]<<" "; }
        cout<<"\n";
    }
    return 0;
}
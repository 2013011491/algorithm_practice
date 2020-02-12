//200212 18:32 start D2 77.16%  19:28
//괜히 어렵게 string 생각했다가 망함
#include<iostream>
#include<array>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,k;
    array<string,15> arr;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        array<string,30> bucket;
        int num=0;
        int ans=0;
        cin>>n>>k;
        string target="0";
        for(int i=0; i<k; ++i){ target.append(1,'1'); }
        target.append(1,'0');
        for(int i=0; i<n; ++i)
        { 
            for(int j=0; j<n; ++j)
            {
                char temp;
                cin>>temp;
                arr[i].append(1,temp);
            }
            string temp="0";
            temp.append(arr[i]);
            temp.append(1,'0');
            bucket[num++]=temp;
        }
        for(int i=0; i<n; ++i)
        {
            string str="0";
            for(int j=0; j<n; ++j)
            {
                str.append(1,arr[j][i]);
            }
            str.append(1,'0');
            bucket[num++]=str;
        }
        cout<<target<<"\n";
        for(int i=0; i<n; ++i){ cout<<arr[i]<<"\n"; }
        cout<<"\n";
        for(int i=0; i<num; ++i){ cout<<i<<" "<<bucket[i]<<"\n";}
        for(int i=0; i<num; ++i)
        {
            for(int j=0; j<=n-k; ++j)
            {
                if(bucket[i].substr(j,k+2)==target)
                {
                    ans++;
                    cout<<i<<" ";
                }
            }
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}
#include<iostream>
#include<set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    long long sum;
    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        sum=0;
        cin>>n;
        int price[n];
        multiset<int> bucket;
        for(int i=0; i<n; i++)
        {
            cin>>price[i];
            sum+=price[i];
            bucket.insert(price[i]);
        }
        cout<<"#"<<tc+1<<" ";
        //start
        int i=1;
        for(multiset<int>::reverse_iterator rit=bucket.rbegin(); rit!=bucket.rend(); ++rit)
        {
            if(i%3==0) sum -= *rit;
            i++;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
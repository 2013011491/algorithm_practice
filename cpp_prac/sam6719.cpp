//200211 21:11 start d4 67.56%  22:11 end 
//수학적으로 하려다가 범위 생각못하고 걍 식 보이면 식대로 해봐라 
#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(6);
    

    int t,n,k;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        array<long long,201> m={0,};
        cin>>n>>k;
        for(int i=0; i<n; ++i){ cin>>m[i]; }
        sort(m.begin(),m.begin()+n);

        double sum=0;
        for(int i=n-k; i<n; ++i)
        {
            sum = (sum+m[i])/2;
        }
        cout<<"#"<<tc<<" "<<sum<<"\n";
    }
    return 0;
}
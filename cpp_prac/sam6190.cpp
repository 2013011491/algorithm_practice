//200217 16:28 start D3 27.40%  17:18
//데이터 양이 많을 땐 sort가 오히려 시간 먹음 그냥 바로바로
#include<iostream>

using namespace std;

int isdan(int num)
{
    int ans=num;
    int pres=10;
    while(num!=0)
    {
        if(num%10<=pres)
        {
            pres=num%10;
            num/=10;
        }else return -1;
    }
    return ans;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n;
    int arr[1001]={0,};
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        int ans=-1;
        cin>>n;
        for(int i=0; i<n; ++i){ cin>>arr[i]; }
        cout<<"#"<<tc<<" ";

        for(int i=0; i<n-1; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                int pres=arr[i]*arr[j];
                if(isdan(pres)>ans) ans=pres;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
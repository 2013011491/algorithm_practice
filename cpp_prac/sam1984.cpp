//200204 14:19 start   14:27 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
	cout.precision(0);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";

        int max=0;
        int min=10001;
        int sum=0;
        for(int i=0; i<10; ++i)
        {
            int pres;
            cin>>pres;
            sum+=pres;
            if(pres<min) min=pres;
            if(pres>max) max=pres;
        }
        sum-=(min+max);
        cout<<float(sum)/8<<"\n";
    }
    return 0;
}
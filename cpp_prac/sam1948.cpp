//200214 16:13 start D2 78.78% 16:21 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    int date[4];
    int month[12]={0,31,59,90,120,151,181,212,243,273,304,334};
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>date[0]>>date[1]>>date[2]>>date[3];    
        cout<<"#"<<tc<<" ";
        int a=month[date[2]-1]+date[3];
        int b=month[date[0]-1]+date[1];
        cout<<a-b+1<<"\n";
    }
    return 0;
}
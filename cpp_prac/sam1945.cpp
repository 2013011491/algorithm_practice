//200212 19:29 start D2 87%  19:36 end
#include<iostream>

using namespace std;

long long n;

int factor(int num)
{
    int count=0;
    while(n%num==0)
    {
        count++;
        n/=num;
    }
    return count;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        cout<<"#"<<tc<<" "<<factor(2)<<" "<<factor(3)<<" "<<factor(5)<<" "<<factor(7)<<" "<<factor(11)<<"\n";
    }
    return 0;
}
//200215 15:00 start D3 78.25% 15:08 end ez
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int tcc=1; tcc<=10; ++tcc)
    {
        int tc,ans=0;
        string tword;
        string sentence;
        cin>>tc>>tword>>sentence;
        for(int i=0; i<=sentence.size()-tword.size(); ++i)
        { if(sentence.substr(i,tword.size())==tword) ans++; }
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
    return 0;
}
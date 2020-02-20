//200220 13:47 start D3 42.30% 14:01 end ez
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int alpha[256]={0,};
    alpha['A']=2; alpha['B']=3; alpha['C']=1; alpha['D']=2; alpha['E']=1; 
    alpha['F']=1; alpha['G']=1; alpha['H']=1; alpha['I']=1; alpha['J']=1;  
    alpha['K']=1; alpha['L']=1; alpha['M']=1; alpha['N']=1; alpha['O']=2; 
    alpha['P']=2; alpha['Q']=2; alpha['R']=2; alpha['S']=1; alpha['T']=1; 
    alpha['U']=1; alpha['V']=1; alpha['W']=1; alpha['X']=1; alpha['Y']=1; alpha['Z']=1;
    int t;
    string a,b;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>a>>b;
        cout<<"#"<<tc<<" ";
        if(a.size()!=b.size()){ cout<<"DIFF\n"; continue;}
        string ans="SAME";
        for(int i=0; i<a.size(); ++i)
        {
            if(alpha[a[i]]!=alpha[b[i]])
            {
                ans="DIFF";
                break;
            } 
        }
        cout<<ans<<"\n";
    }
    return 0;
}
//200219 20:21 start D3 62.83%  20:34 end
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n;
    string tc;
    cin>>t;
    map<string,int> number;
    map<string,int>::iterator it;
    number["ZRO"]=0;
    number["ONE"]=0;
    number["TWO"]=0;
    number["THR"]=0;
    number["FOR"]=0;
    number["FIV"]=0;
    number["SIX"]=0;
    number["SVN"]=0;
    number["EGT"]=0;
    number["NIN"]=0;
    

    for(int tt=1; tt<=t; ++tt)
    {
        cin>>tc>>n;
        for(int i=0; i<n; ++i)
        {
            string pres;
            cin>>pres;
            number[pres]++;
        }
        cout<<tc<<"\n";
        for(int i=0; i<number["ZRO"]; ++i){ cout<<"ZRO"<<" ";}
        for(int i=0; i<number["ONE"]; ++i){ cout<<"ONE"<<" ";}
        for(int i=0; i<number["TWO"]; ++i){ cout<<"TWO"<<" ";}
        for(int i=0; i<number["THR"]; ++i){ cout<<"THR"<<" ";}
        for(int i=0; i<number["FOR"]; ++i){ cout<<"FOR"<<" ";}
        for(int i=0; i<number["FIV"]; ++i){ cout<<"FIV"<<" ";}
        for(int i=0; i<number["SIX"]; ++i){ cout<<"SIX"<<" ";}
        for(int i=0; i<number["SVN"]; ++i){ cout<<"SVN"<<" ";}
        for(int i=0; i<number["EGT"]; ++i){ cout<<"EGT"<<" ";}
        for(int i=0; i<number["NIN"]; ++i){ cout<<"NIN"<<" ";}
        cout<<"\n";
        number["ZRO"]=0;
        number["ONE"]=0;
        number["TWO"]=0;
        number["THR"]=0;
        number["FOR"]=0;
        number["FIV"]=0;
        number["SIX"]=0;
        number["SVN"]=0;
        number["EGT"]=0;
        number["NIN"]=0;        
    }
    return 0;
}
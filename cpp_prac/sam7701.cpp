//200207 19:27 start D4 36.19%   19:47 end  20min
#include<iostream>
#include<set>
#include<string>

using namespace std;

struct classcomp
{
    bool operator() (string lhs, string rhs) 
    {
        if(lhs.size()<rhs.size()) return true;
        else if(lhs.size()==rhs.size()) return lhs.compare(rhs)<0 ? true : false;
    }
};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t,n;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n;
        set<string,classcomp> bucket;
        set<string,classcomp>::iterator it;
        for(int i=0; i<n; ++i)
        { 
            string temp;
            cin>>temp;
            bucket.insert(temp);
        }
        cout<<"#"<<tc<<"\n";
        for(it=bucket.begin(); it!=bucket.end(); ++it)
        {
            string temp = *it;
            cout<<temp<<"\n";
        }
    }
    return 0;
}
//200226 18:11 start d3 74.35%  18:30 basic
#include<iostream>
#include<array>
#include<string>
#include<vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;

    for(int tc=1; tc<=1; ++tc)
    {
        cout<<"#"<<tc<<" ";
        vector<int> encryp;
        vector<int>::iterator it;
        cin>>n;
        for(int i=0; i<n; ++i)
        { 
            int temp;
            cin>>temp;
            encryp.push_back(temp);
        }
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            char trash;
            int x,y;
            vector<int> temp;
            cin>>trash>>x>>y;
            for(int j=0; j<y; ++j)
            {
                int temp2;
                cin>>temp2;
                temp.push_back(temp2);
            }
            it=encryp.begin()+x;
            encryp.insert(it,temp.begin(),temp.end());
        }
        for(int i=0; i<10; ++i){ cout<<encryp[i]<<" "; }
        cout<<"\n";
    }

    return 0;
}
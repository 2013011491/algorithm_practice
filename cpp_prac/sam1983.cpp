//200211 18:45 start d2 60.92% 19:19 end 34min
//sort로 풀었으면 됐었다. 괜히 set 쓰지말고
#include<iostream>
#include<array>
#include<set>
#include<string>

using namespace std;

array<string,10> grade={"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
struct classcomp
{
    bool operator() (array<int,2> lhs, array<int,2> rhs)
    {
        return lhs[1]>rhs[1];
    }
};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,n,k;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        array<array<int,2>,100> point;
        multiset<array<int,2>,classcomp> bucket;
        multiset<array<int,2>,classcomp>::iterator it;
        cin>>n>>k;
        for(int i=0; i<n; ++i)
        {   
            array<int,3> temp;
            cin>>temp[0]>>temp[1]>>temp[2];
            point[i][0]=i+1;
            point[i][1]=(temp[0]*7)+(temp[1]*9)+(temp[2]*4);
            bucket.insert(point[i]);
        }

        int check=0;
        for(it=bucket.begin(); it!=bucket.end(); ++it)
        {
            array<int,2> pres=*it;
            if(pres[0]==k) break;
            check++;
        }
        cout<<"#"<<tc<<" "<<grade[check/(n/10)]<<"\n";
    }
    return 0;
}
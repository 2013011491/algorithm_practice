//200506 gold4 for swexpert 18:37 start   for70min
// wrong case using map, if n is small, no use map, just use numbering of array value
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int ro,co,k;
int board[203][203]={0,};

bool classcomp(pair<int,int> lhs, pair<int,int> rhs)
{
    if(lhs.second<rhs.second) return true;
    else if(lhs.second==rhs.second)
    {
        if(lhs.first<rhs.first) return true;
        else return false;
    }else return false;
}
void rsort(int r, int c)
{
    int leng[102]={0,};
    int max=0;
    for(int i=1; i<=r; ++i)
    {
        map<int,int> temp;
        vector<pair<int,int>> temp2;
        map<int,int>::iterator it;
        for(int j=1; j<=c; ++j)
        {
            if(board[i][j]==0) continue;
            temp[board[i][j]]++;
        }
        for(it=temp.begin(); it!=temp.end(); ++it){temp2.push_back(make_pair(it->first,it->second));}
        sort(temp2.begin(),temp2.end(),classcomp);
        leng[i]=temp.size()*2;
        if(max<leng[i]) max=leng[i];
        int index=1;
        for(int j=0; j<temp2.size(); ++j)
        {
            board[i][index++]=temp2[j].first;
            board[i][index++]=temp2[j].second;
        }
    }
    for(int i=1; i<=r; ++i){for(int j=leng[i]+1; j<=max; ++j){board[i][j]=0;}}
    co=max;
    if(co>100) co=100;
    //for(int i=0; i<=r; ++i){for(int j=0; j<=max; ++j){cout<<board[i][j]<<" ";}cout<<"\n";}
}
void csort(int r, int c)
{
    int leng[102]={0,};
    int max=0;
    for(int i=1; i<=c; ++i)
    {
        map<int,int> temp;
        vector<pair<int,int>> temp2;
        map<int,int>::iterator it;
        for(int j=1; j<=r; ++j)
        {
            if(board[j][i]==0) continue;
            temp[board[j][i]]++;
        }
        for(it=temp.begin(); it!=temp.end(); ++it){temp2.push_back(make_pair(it->first,it->second));}
        sort(temp2.begin(),temp2.end(),classcomp);
        leng[i]=temp.size()*2;
        if(max<leng[i]) max=leng[i];
        int index=1;
        for(int j=0; j<temp2.size(); ++j)
        {
            board[index++][i]=temp2[j].first;
            board[index++][i]=temp2[j].second;
        }
    }
    for(int i=1; i<=c; ++i){for(int j=leng[i]+1; j<=max; ++j){board[j][i]=0;}}
    ro=max;
    if(ro>100) ro=100;
    //for(int i=0; i<=max; ++i){for(int j=0; j<=c; ++j){cout<<board[i][j]<<" ";}cout<<"\n";}
}
int main(void)
{
    int r,c;
    cin>>r>>c>>k;
    ro=3; co=3;
    int ans=0;
    for(int i=1; i<=3; ++i){for(int j=1; j<=3; ++j){cin>>board[i][j];}}
    while(ans<=100)
    {
        if(board[r][c]==k) break;
        if(ro>=co) rsort(ro,co);
        else csort(ro,co);
        ans++;
    }
    if(ans>100) ans=-1;
    cout<<ans;

    return 0;
}
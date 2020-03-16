#include <string>
#include <vector>
#include <set>
#include <array>
#include <iostream>

using namespace std;

struct classcomp
{
    bool operator() (array<int,3> lhs, array<int,3> rhs)
    {
        if(lhs[1]>rhs[1]) return true;
        else if(lhs[1]==rhs[1])
        {
            if(lhs[0]<rhs[0]) return true;
            else return false;
        }else return false;
    }
};

vector<vector<int>> modi;

void tree(vector<int>& bucket, int st, int end, int mid, int index)
{
    bucket.push_back(modi[index][2]);
    int lefti=index;
    int righti=index;
    while(1)
    {
        if(lefti==modi.size() || (modi[lefti][0]<mid && modi[lefti][0]>st)) break;
        lefti++;
    }
    while(1)
    {
        if(righti==modi.size() || (modi[righti][0]>mid && modi[righti][0]<end)) break;
        righti++;
    }
    if(lefti!=modi.size()) tree(bucket, st, mid, modi[lefti][0], lefti);
    if(righti!=modi.size()) tree(bucket, mid, end, modi[righti][0], righti);
}

void tree1(vector<int>& bucket, int st, int end, int mid, int index)
{
    int lefti=index;
    int righti=index;
    while(1)
    {
        if(lefti==modi.size() || (modi[lefti][0]<mid && modi[lefti][0]>st)) break;
        lefti++;
    }
    while(1)
    {
        if(righti==modi.size() || (modi[righti][0]>mid && modi[righti][0]<end)) break;
        righti++;
    }
    if(lefti!=modi.size()) tree1(bucket, st, mid, modi[lefti][0], lefti);
    if(righti!=modi.size()) tree1(bucket, mid, end, modi[righti][0], righti);
    bucket.push_back(modi[index][2]);
}
    
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<int> bucket;
    set<array<int,3>,classcomp> sorted;
    set<array<int,3>,classcomp>::iterator it;
    for(int i=0; i<nodeinfo.size(); i++) sorted.insert({nodeinfo[i][0],nodeinfo[i][1],i+1});
    for(it=sorted.begin(); it!=sorted.end(); ++it)
    {
        array<int,3> temp=*it;
        vector<int> temp1;
        temp1.push_back(temp[0]);
        temp1.push_back(temp[1]);
        temp1.push_back(temp[2]);
        modi.push_back(temp1);
        //cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<"\n";
    }
    
    tree(bucket,-1,100001,modi[0][0],0);
    answer.push_back(bucket);
    bucket.clear();
    tree1(bucket,-1,100001,modi[0][0],0);
    answer.push_back(bucket);
    
    
    return answer;
}
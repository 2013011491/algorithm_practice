#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int colLen=relation[0].size();
    int rowLen=relation.size();
    string possi[256];
    int maxnum=pow(2,colLen)-1;
    for(int i=1; i<=maxnum; i++)
    {
        possi[i]="000000000";
        int temp=i;
        int num=0;
        for(int j=1; j<9; j++)
        {
            if(temp==0) break;
            if(temp%2==1) num++;
            possi[i][j]=temp%2+'0';
            temp/=2;
        }
        possi[i][0]=num+'0';
    }
    vector<string> bucket;
    vector<string>::iterator it;
    for(int j=0; j<colLen; j++)
    {
        int result=0;
        for(int i=0; i<rowLen; i++)
        {
            it = find(bucket.begin(), bucket.end(), relation[i][j]);
            if(it!=bucket.end())
            {
                result=1;
                break;
            }else bucket.push_back(relation[i][j]);
        }
        if(result==0)
        {
            answer++;
            for(int k=1; k<=maxnum; k++)
            {
                if(possi[k][j+1]=='1') possi[k][0]='0';
            }
        }
        bucket.clear();
    }
    
    for(int i=2; i<=colLen; i++)
    {
        for(int j=1; j<=maxnum; j++)
        {
            if(possi[j][0]==i+'0')
            {
                vector<int> index;
                vector<vector<string>> comp;
                vector<string> str;
                for(int k=1; k<=colLen; k++)
                {
                    if(possi[j][k]=='1') index.push_back(k);
                }
                int result=0;
                for(int l=0; l<rowLen; l++)
                {
                    for(int k=0; k<index.size(); k++)
                    {
                        str.push_back(relation[l][index[k]-1]);
                    }
                    vector<vector<string>>::iterator it = find(comp.begin(), comp.end(), str);
                    if(it!=comp.end())
                    {
                        result=1;
                        break;
                    }else
                    {
                        comp.push_back(str);
                    }
                    str.clear();
                }
                if(result==0)
                {
                    answer++;
                    for(int l=1; l<=maxnum; l++)
                    {
                        int check=0;
                        for(int k=0; k<index.size(); k++)
                        {
                            if(possi[l][index[k]]=='0')
                            {
                                check=1;
                                break;
                            }
                        }
                        if(check==0) possi[l][0]='0';
                     }
                }

            }
        }  
    }
    
    
    return answer;
}
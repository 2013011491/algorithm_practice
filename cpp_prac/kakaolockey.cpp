#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &key)
{
    int m=key.size();
    vector<vector<int>> temp;
    for(int i=0; i<m; i++)
    {
        vector<int> temp2;
        for(int j=m-1; j>=0; j--)
        {
            temp2.push_back(key[j][i]);
        }
        temp.push_back(temp2);
    }
    key=temp;
    return key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int m=key.size();
    int n=lock.size();
    vector<vector<int>> newlock;
    vector<int> temp(m+(2*n)-2,0);
    for(int i=0; i<m-1; i++) newlock.push_back(temp);
    for(int i=0; i<n; i++)
    {
        vector<int> temp2(m-1,0);
        vector<int> temp3(m-1,0);
        temp2.insert(temp2.end(),lock[i].begin(),lock[i].end());
        temp2.insert(temp2.end(),temp3.begin(),temp3.end());
        newlock.push_back(temp2);
    }
    for(int i=0; i<m-1; i++) newlock.push_back(temp);
    //***********newlock create
    
    //
    vector<vector<int>> lockcop;
    
    for(int r=0; r<4; r++)
    {
        for(int i=0; i<n+m-1; i++)
        {
            for(int j=0; j<n+m-1; j++)
            {
                lockcop=newlock;
                int k=i;
                int l=j;
                int check=0;
                for(int ti=0; ti<m; ti++,k++)
                {
                    l=j;
                    for(int tj=0; tj<m; tj++,l++)
                    {
                        if(k>m-2 && k<m+n-1 && l>m-2 && l<m+n-1)
                        {
                            check=0;
                            if(key[ti][tj]==lockcop[k][l])
                            {
                                check=1;
                                break;
                            }else
                            {
                                lockcop[k][l]=1;
                            }
                        }
                    }
                    if(check==1) break;
                }
                
                /*
                for(int hh=0; hh<n+2*m-2; hh++)
                {
                    for(int jj=0; jj<n+2*m-2; jj++) cout<<lockcop[hh][jj]<<" ";
                    cout<<"\n";
                }
                cout<<"\n";*/
                if(check==0)
                {
                    
                    for(int ti=m-1; ti<n+m-1; ti++)
                    {
                        for(int tj=m-1; tj<n+m-1; tj++)
                        {
                            if(lockcop[ti][tj]==0)
                            {
                                check=1;
                                break;
                            }
                        }
                        if(check==1) break;
                    }
                    if(check==0) return true;
                }
            }
        }
        key=rotate(key);
    }
    
    return answer;
}
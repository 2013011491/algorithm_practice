#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> bd;
int n=0;

int ispossi(int x, int y, int content)
{
    if(x<n-1 && y<n-2)
    {
        if(bd[x+1][y]==content && bd[x+1][y+1]==content && bd[x+1][y+2]==content)
        {
            //cout<<1<<" ";
            for(int i=x; i>=0; i--)
            {
                if(bd[i][y+1]!=0 || bd[i][y+2]!=0) return 0;
            }
            bd[x][y]=0;
            bd[x][y+1]=0;
            bd[x][y+2]=0;
            bd[x+1][y]=0;
            bd[x+1][y+1]=0;
            bd[x+1][y+2]=0;
            return 1;
        }
    }
    if(x<n-2 && y>0)
    {
        if(bd[x+1][y]==content && bd[x+2][y]==content && bd[x+2][y-1]==content)
        {
             //cout<<2<<" ";
            for(int i=x+1; i>=0; i--)
            {
                if(bd[i][y-1]!=0) return 0;
            }
            bd[x][y]=0;
            bd[x][y-1]=0;
            bd[x+1][y-1]=0;
            bd[x+1][y]=0;
            bd[x+2][y]=0;
            bd[x+2][y-1]=0;
            return 1;
        }
    }
    if(x<n-2 && y<n-1)
    {
        if(bd[x+1][y]==content && bd[x+2][y]==content && bd[x+2][y+1]==content)
        {
             //cout<<3<<" ";
            for(int i=x+1; i>=0; i--)
            {
                if(bd[i][y+1]!=0) return 0;
            }
            bd[x][y]=0;
            bd[x][y+1]=0;
            bd[x+1][y+1]=0;
            bd[x+1][y]=0;
            bd[x+2][y]=0;
            bd[x+2][y+1]=0;
            return 1;
        }
    }
    if(x<n-1 && y>1)
    {
        if(bd[x+1][y]==content && bd[x+1][y-1]==content && bd[x+1][y-2]==content)
        {
             //cout<<4<<" ";
            
            for(int i=x; i>=0; i--)
            {
                if(bd[i][y-1]!=0 || bd[i][y-2]!=0) return 0;
            }
            bd[x][y]=0;
            bd[x][y-1]=0;
            bd[x][y-2]=0;
            bd[x+1][y]=0;
            bd[x+1][y-1]=0;
            bd[x+1][y-2]=0;
            return 1;
        }
    }
    if(x<n-1 && y<n-1 && y>0)
    {
        //cout<<x<<" "<<y<<" "<<content<<"\n";
        if(bd[x+1][y]==content && bd[x+1][y-1]==content && bd[x+1][y+1]==content)
        {
            //cout<<5<<" ";
            for(int i=x; i>=0; i--)
            {
                if(bd[i][y-1]!=0 || bd[i][y+1]!=0) return 0;
            }
            bd[x][y]=0;
            bd[x][y-1]=0;
            bd[x][y+1]=0;
            bd[x+1][y]=0;
            bd[x+1][y-1]=0;
            bd[x+1][y+1]=0;
            return 1;
        }
    }
    return 0;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n=board.size();
    bd=board;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(bd[j][i]!=0)
            {
                if(ispossi(j,i,bd[j][i]))
                {
                    answer++;
                    i=0;
                    j=0;
                }
            }
        }
    }
    return answer;
}
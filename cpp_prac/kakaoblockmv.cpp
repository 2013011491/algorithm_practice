#include <string>
#include <vector>
#include <queue>
#include <array>

using namespace std;


int solution(vector<vector<int>> board) {
    int visit[101][101][101][101]={0,};
    int answer = 0;
    int n=board.size();
    queue<array<int,5>> bucket;
    array<int,5> pres;
    bucket.push({0,0,0,1,0});
    while(!bucket.empty())
    {  
        pres=bucket.front();
        bucket.pop();
        if((pres[0]==n-1 && pres[1]==n-1) || (pres[2]==n-1 && pres[3]==n-1))
        {
            answer=pres[4];
            break;
        }
        if(visit[pres[0]][pres[1]][pres[2]][pres[3]]==1 || visit[pres[2]][pres[3]][pres[0]][pres[1]]==1) continue;
        visit[pres[0]][pres[1]][pres[2]][pres[3]]=1;
        visit[pres[2]][pres[3]][pres[0]][pres[1]]=1;
        int iscol=0;
        if(pres[1]==pres[3]) iscol=1;
        if(iscol) //세로모드
        {
            if(pres[2]<n-1 && board[pres[2]+1][pres[3]]!=1) bucket.push({pres[2],pres[3],pres[2]+1,pres[3],pres[4]+1});
            if(pres[0]>0 && board[pres[0]-1][pres[1]]!=1) bucket.push({pres[0]-1,pres[1],pres[0],pres[1],pres[4]+1});
            if(pres[1]<n-1 && board[pres[2]][pres[3]+1]!=1 && board[pres[0]][pres[1]+1]!=1)
            {
                bucket.push({pres[0],pres[1]+1,pres[2],pres[3]+1,pres[4]+1});
                bucket.push({pres[0],pres[1],pres[0],pres[1]+1,pres[4]+1});
                bucket.push({pres[2],pres[3],pres[2],pres[3]+1,pres[4]+1});
            }
            if(pres[1]>0 && board[pres[0]][pres[1]-1]!=1 && board[pres[2]][pres[3]-1]!=1)
            {
                bucket.push({pres[0],pres[1]-1,pres[2],pres[3]-1,pres[4]+1});
                bucket.push({pres[0],pres[1]-1,pres[0],pres[1],pres[4]+1});
                bucket.push({pres[2],pres[3]-1,pres[2],pres[3],pres[4]+1});
            }
        }else
        {
            if(pres[3]<n-1 && board[pres[2]][pres[3]+1]!=1) bucket.push({pres[2],pres[3],pres[2],pres[3]+1,pres[4]+1});
            if(pres[1]>0 && board[pres[0]][pres[1]-1]!=1) bucket.push({pres[0],pres[1]-1,pres[0],pres[1],pres[4]+1});
            if(pres[0]<n-1 && board[pres[2]+1][pres[3]]!=1 && board[pres[0]+1][pres[1]]!=1)
            {
                bucket.push({pres[0]+1,pres[1],pres[2]+1,pres[3],pres[4]+1});
                bucket.push({pres[0],pres[1],pres[0]+1,pres[1],pres[4]+1});
                bucket.push({pres[2],pres[3],pres[2]+1,pres[3],pres[4]+1});
            }
            if(pres[0]>0 && board[pres[0]-1][pres[1]]!=1 && board[pres[2]-1][pres[3]]!=1)
            {
                bucket.push({pres[0]-1,pres[1],pres[2]-1,pres[3],pres[4]+1});
                bucket.push({pres[0]-1,pres[1],pres[0],pres[1],pres[4]+1});
                bucket.push({pres[2]-1,pres[3],pres[2],pres[3],pres[4]+1});
            }
        }
    }
    
    return answer;
}
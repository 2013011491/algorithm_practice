#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<pair<int,int>> bucket;
    for(int i=0; i<m-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(board[i][j]==board[i][j+1] && board[i][j]==board[i+1][j] && board[i][j]==board[i+1][j+1]) bucket.push_back(make_pair(i,j));
        }
    }
    if(bucket.size()==0) return answer;
    for(int k=0; k<bucket.size(); k++)
    {
        int i=bucket[k].first;
        int j=bucket[k].second;
        if(board[i][j]!='0')
        {
            board[i][j]='0';
            answer++;
        }
        if(board[i][j+1]!='0')
        {
            board[i][j+1]='0';
            answer++;
        }
        if(board[i+1][j]!='0')
        {
            board[i+1][j]='0';
            answer++;
        }
        if(board[i+1][j+1]!='0')
        {
            board[i+1][j+1]='0';
            answer++;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(board[j][i]=='0')
            {
                for(int k=j; k>=0; k--)
                {
                    if(board[k][i]!='0')
                    {
                        for(k; k>=0; k--)
                        {
                            if(board[k][i]!='0')
                            {
                                board[j--][i]=board[k][i];
                                board[k][i]='0';
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
    
    
    while(bucket.size())
    {
        bucket.clear();
        for(int i=0; i<m-1; i++)
        {
            for(int j=0; j<n-1; j++)
            {
                if(board[i][j]=='0') continue;
                if(board[i][j]==board[i][j+1] && board[i][j]==board[i+1][j] && board[i][j]==board[i+1][j+1]) bucket.push_back(make_pair(i,j));
            }
        }
        if(bucket.size()==0) return answer;
        for(int k=0; k<bucket.size(); k++)
        {
            int i=bucket[k].first;
            int j=bucket[k].second;
            if(board[i][j]!='0')
            {
                board[i][j]='0';
                answer++;
            }
            if(board[i][j+1]!='0')
            {
                board[i][j+1]='0';
                answer++;
            }
            if(board[i+1][j]!='0')
            {
                board[i+1][j]='0';
                answer++;
            }
            if(board[i+1][j+1]!='0')
            {
                board[i+1][j+1]='0';
                answer++;
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=m-1; j>0; j--)
            {
                if(board[j][i]=='0')
                {
                    for(int k=j; k>=0; k--)
                    {
                        if(board[k][i]!='0')
                        {
                            for(k; k>=0; k--)
                            {
                                board[j--][i]=board[k][i];
                                board[k][i]='0';
                            }
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        
    }
    
    
    return answer;
}
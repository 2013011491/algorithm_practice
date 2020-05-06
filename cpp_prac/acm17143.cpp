//for 110min
#include<iostream>
#include<array>
#include<stack>

using namespace std;

array<array<stack<int>,103>,103> board;
int r,c,m;
array<array<int,5>,10002> sharks;

void nextmove()
{
    for(int i=1; i<=r; ++i){for(int j=1; j<=c; ++j){while(!board[i][j].empty()){board[i][j].pop();}}}
    for(int i=1; i<=m; ++i)
    {
        if(sharks[i][0]==0) continue;
        int w=sharks[i][3], s=sharks[i][2];
        int p;
        if(w==1)//상
        {
            p=sharks[i][0];
            s%=(2*(r-1));
            p-=s;
            if(p<=0)
            {
                p*=(-1); p+=2;
                if(p<=r) sharks[i][3]=2;    
                else{p-=r; p=r-p;}
            }
            sharks[i][0]=p;
            if(!board[sharks[i][0]][sharks[i][1]].empty())
            {
                int pres=board[sharks[i][0]][sharks[i][1]].top();
                if(sharks[pres][4]<sharks[i][4])
                {
                    board[sharks[i][0]][sharks[i][1]].pop();
                    board[sharks[i][0]][sharks[i][1]].push(i);
                    sharks[pres][0]=0;
                }else sharks[i][0]=0;
            }else board[sharks[i][0]][sharks[i][1]].push(i);
        }else if(w==2)
        {
            p=sharks[i][0];
            s%=(2*(r-1));
            p+=s;
            if(p>r)
            {
                p-=r; p=r-p;
                if(p>0) sharks[i][3]=1;    
                else{p*=(-1); p+=2;}
            }
            sharks[i][0]=p;
            if(!board[sharks[i][0]][sharks[i][1]].empty())
            {
                int pres=board[sharks[i][0]][sharks[i][1]].top();
                if(sharks[pres][4]<sharks[i][4])
                {
                    board[sharks[i][0]][sharks[i][1]].pop();
                    board[sharks[i][0]][sharks[i][1]].push(i);
                    sharks[pres][0]=0;
                }else sharks[i][0]=0;
            }else board[sharks[i][0]][sharks[i][1]].push(i);

        }else if(w==3)
        {
            p=sharks[i][1];
            s%=(2*(c-1));
            p+=s;
            if(p>c)
            {
                p-=c; p=c-p;
                if(p>0) sharks[i][3]=4;    
                else{p*=(-1); p+=2;}
            }
            sharks[i][1]=p;
            if(!board[sharks[i][0]][sharks[i][1]].empty())
            {
                int pres=board[sharks[i][0]][sharks[i][1]].top();
                if(sharks[pres][4]<sharks[i][4])
                {
                    board[sharks[i][0]][sharks[i][1]].pop();
                    board[sharks[i][0]][sharks[i][1]].push(i);
                    sharks[pres][0]=0;
                }else sharks[i][0]=0;
            }else board[sharks[i][0]][sharks[i][1]].push(i);

        }else if(w==4)
        {
            p=sharks[i][1];
            s%=(2*(c-1));
            p-=s;
            if(p<=0)
            {
                p*=(-1); p+=2;
                if(p<=c) sharks[i][3]=3;    
                else{p-=c; p=c-p;}
            }
            sharks[i][1]=p;
            if(!board[sharks[i][0]][sharks[i][1]].empty())
            {
                int pres=board[sharks[i][0]][sharks[i][1]].top();
                if(sharks[pres][4]<sharks[i][4])
                {
                    board[sharks[i][0]][sharks[i][1]].pop();
                    board[sharks[i][0]][sharks[i][1]].push(i);
                    sharks[pres][0]=0;
                }else sharks[i][0]=0;
            }else board[sharks[i][0]][sharks[i][1]].push(i);
        }
    }
}

int main(void)
{
    int ans=0;
    cin>>r>>c>>m;
    for(int i=1; i<=m; ++i)
    {
        for(int j=0; j<5; ++j){cin>>sharks[i][j];} // r,c 속력, 방향, 크기
        board[sharks[i][0]][sharks[i][1]].push(i);
    }  //d 상하우좌1234
    for(int i=1; i<=c; ++i)
    {
        for(int j=1; j<=r; ++j)
        {
            if(!board[j][i].empty())
            {
                int pres=board[j][i].top();
                ans+=sharks[pres][4];
                sharks[pres][0]=0;
                break;
            }
        }
        nextmove();
    }
    cout<<ans;
    return 0;
}
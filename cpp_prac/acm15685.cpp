//200529 forsds 
#include<iostream>
#include<array>
#include<queue>

using namespace std;

int n;
int board[102][102]={0,};
void printbd()
{
    for(int i=0; i<10; ++i){for(int j=0; j<10; ++j){cout<<board[i][j]<<" ";}cout<<"\n";}cout<<"\n";
}
void draw(int x, int y, int d, int g)
{
    int gen=0;
    int limit=1;
    array<array<int,2>, 1026> point;
    point[0][0]=y; point[0][1]=x;
    if(d==0){ point[1][0]=y; point[1][1]=x+1;}
    else if(d==1){point[1][0]=y-1; point[1][1]=x;}
    else if(d==2){point[1][0]=y; point[1][1]=x-1;} 
    else if(d==3){point[1][0]=y+1; point[1][1]=x;} 
    while(gen!=g)
    {
        int endx=point[limit/2+1][0],endy=point[limit/2+1][1];
        //cout<<endx<<" "<<endy<<"\n";
        int index=limit+1;
        for(int i=0; i<=limit; ++i)
        {
            if(point[i][0]==endx && point[i][1]==endy) continue;
            point[index][0]=endx+point[i][1]-endy;
            point[index][1]=endy-point[i][0]+endx;
            //cout<<point[i][0]<<" "<<point[i][1]<<" "<<point[index][0]<<" "<<point[index][1]<<"\n";
            index++;
        }
        limit*=2;
        gen++;
    }
    for(int i=0; i<=limit; ++i){board[point[i][0]][point[i][1]]=1;}
}
int main(void)
{
    cin>>n;
    int x,y,d,g;
    //printbd();
    for(int i=0; i<n; ++i)
    {
        cin>>x>>y>>d>>g;
        draw(x,y,d,g);
        //printbd();
    }
    int ans=0;
    for(int i=0; i<100; ++i)
    {
        for(int j=0; j<100; ++j)
        {
            if(board[i][j]==1 && board[i+1][j]==1 && board[i][j+1]==1 && board[i+1][j+1]==1) ans++;
        }
    }
    cout<<ans;

    return 0;
}
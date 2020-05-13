//200513 for swexpert gold1   for 100min shit!
#include<iostream>
#include<array>
#include<queue>

using namespace std;

int n,m,g,r;
int ground[53][53]={0,};
int pnum;
int ans=0;
int way[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
array<array<int,2>,11> posipoint; //possible point consisting x,y
array<array<int,3>,11> selecp;

void printground(int A[53][53])
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        { cout.width(2); cout<<A[i][j]<<" ";} cout<<"\n";}
    cout<<"\n";
}

void cal()
{
    int A[53][53]={0,};
    int count=0;
    copy(&ground[0][0], &ground[0][0]+(53*53), &A[0][0]);
    queue<array<int,3>> bucket;
    array<int,3> xyc;
    for(int i=0; i<r+g; ++i)
    {
        xyc[0]=selecp[i][0]; xyc[1]=selecp[i][1]; xyc[2]=selecp[i][2];
        bucket.push(xyc);
        A[xyc[0]][xyc[1]]=xyc[2];
    }
    while(!bucket.empty())
    {
        //printground(A);
        xyc=bucket.front();
        bucket.pop();
        if(A[xyc[0]][xyc[1]]==4) continue; //case already blossom
        if(A[xyc[0]][xyc[1]]<0)
        {
            A[xyc[0]][xyc[1]]=xyc[2];
            bucket.push(xyc);
        } 
        else
        {
            for(int i=0; i<4; ++i)
            {
                int nx=xyc[0]+way[i][0], ny=xyc[1]+way[i][1];
                if(nx<0 || ny<0 || nx>=n|| ny>=m) continue;
                if(A[nx][ny]==1)//just ground
                {
                    A[nx][ny]=(-1)*xyc[2];
                    bucket.push({nx,ny,xyc[2]});
                }else if((A[nx][ny]==-2 && xyc[2]==3) || (A[nx][ny]==-3 && xyc[2]==2))
                {
                    A[nx][ny]=4; //blossom;
                    count++;
                }
            }
        }
        
        
    }
    if(count>ans) ans=count;
}
void pick_cal(int rnum, int gnum, int rst, int gst)
{
    if(rnum<r)
    {
        for(int i=rst; i<pnum; ++i)
        {
            selecp[rnum][0]=posipoint[i][0]; selecp[rnum][1]=posipoint[i][1]; selecp[rnum][2]=2; //red=2
            pick_cal(rnum+1,gnum,i+1,gst);
        }
    }else if(rnum==r && gnum<g)
    {
        for(int i=gst; i<pnum; ++i)
        {
            int check=0;
            for(int j=0; j<r+gnum; ++j)
            {
                if(selecp[j][0]==posipoint[i][0] && selecp[j][1]==posipoint[i][1]){check=1; break;}
            }
            if(check==0)
            {
                selecp[r+gnum][0]=posipoint[i][0]; selecp[r+gnum][1]=posipoint[i][1]; selecp[r+gnum][2]=3; //green=3
                pick_cal(rnum,gnum+1,rst,i+1);
            }    
        }
    }else if(rnum==r && gnum==g)
    {
        cal();
        return;
    }
}
int main(void)
{
    cin>>n>>m>>g>>r;
    pnum=0;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            int temp;
            cin>>temp;
            if(temp==2){ posipoint[pnum][0]=i; posipoint[pnum++][1]=j; ground[i][j]=1; }
            else ground[i][j]=temp;
        }
    }
    pick_cal(0,0,0,0);
    cout<<ans;
}
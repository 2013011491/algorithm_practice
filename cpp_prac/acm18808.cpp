//200516 for sdstest gold3   for 63min yeah!
#include<iostream>
#include<array>

using namespace std;

int n,m,k;
int laptop[42][42]={0,};

typedef struct sticker
{
    int r;
    int c;
    array<array<int,11>,11> picture;
}sticker;
sticker stickers[101];

void rotStick(int p)
{
    int r=stickers[p].r;
    int c=stickers[p].c;
    int nr=0;
    int nc=r-1;
    array<array<int,11>,11> nstic={0,};
    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
        {
            nstic[nr++][nc]=stickers[p].picture[i][j];
            stickers[p].picture[i][j]=0;
        }
        nr=0;
        nc--;
    }
    for(int i=0; i<c; ++i){for(int j=0; j<r; ++j){stickers[p].picture[i][j]=nstic[i][j];}}
    stickers[p].r=c;
    stickers[p].c=r;
}

bool ismatch(int p)
{
    int r=stickers[p].r, c=stickers[p].c;
    for(int x=0; x<n; ++x)
    {
        if(n-x<r){return false;}
        for(int y=0; y<m; ++y)
        {
            if(m-y<c) break;
            int check=1;
            for(int i=0; i<r; ++i)
            {
                for(int j=0; j<c; ++j){if(laptop[x+i][y+j] & stickers[p].picture[i][j]){check=0; break;}}
                if(check==0) break;
            }
            if(check==1)
            {
                for(int i=0; i<r; ++i){for(int j=0; j<c; ++j){laptop[x+i][y+j]|=stickers[p].picture[i][j];}}
                return true;
            }
        }
    }
    return false;
}

void attach()
{
    for(int i=0; i<k; ++i)
    {
        int r,c;
        for(int j=0; j<4; ++j)
        {
            r=stickers[i].r; c=stickers[i].c;
            if(r>n || c>m){ rotStick(i); continue;}
            if(ismatch(i)) break;
            else rotStick(i);
        }
    }
}

int main(void)
{
    cin>>n>>m>>k;
    for(int i=0; i<k; ++i)
    {
        int r,c;
        cin>>r>>c;
        for(int j=0; j<r; ++j){for(int k=0; k<c; ++k){cin>>stickers[i].picture[j][k];}}
        stickers[i].r=r; stickers[i].c=c;
    }
    attach();
    int ans=0;
    for(int i=0; i<n; ++i){for(int j=0; j<m; ++j){if(laptop[i][j]==1) ans++;}}
    cout<<ans;
    return 0;
}


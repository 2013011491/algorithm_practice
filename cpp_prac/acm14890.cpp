//200604 forsds gold3 during 47min yeah!
#include<iostream>
#include<cmath>

using namespace std;

typedef struct point
{
    int height=0;
    int adding=0;
}point;

int n,l,ans=0;
point board[101][101];

void check(int rc)
{
    for(int i=0; i<n; ++i)
    {
        point line[101];
        if(rc==0){for(int j=0; j<n; ++j){line[j].height=board[i][j].height;}}
        else if(rc==1){for(int j=0; j<n; ++j){line[j].height=board[j][i].height;}}
        
        int check=1;
        for(int j=0; j<n-1; ++j)
        {
            int dif=abs(line[j].height-line[j+1].height);
            if(dif==0) continue;
            else if(dif>=2){check=0; break;}
            else if(dif==1)
            {
                int origin;
                if(line[j].height>line[j+1].height)
                {
                    origin=line[j+1].height;
                    for(int k=j+1; k<=j+l; ++k)
                    {
                        if(k>=n){check=0; break;}
                        if(line[k].height==origin && line[k].adding==0)
                        {
                            line[k].adding=1;
                        }else{check=0; break;}
                    }
                    j+=(l-1);
                }else
                {
                    origin=line[j].height;
                    for(int k=j; k>j-l; --k)
                    {
                        if(k<0){check=0; break;}
                        if(line[k].height==origin && line[k].adding==0)
                        {
                            line[k].adding=1;
                        }else{check=0; break;}
                    }
                }
            }
            if(check==0) break;
        }
        if(check==1) ans++;
    }
}

int main(void)
{
    cin>>n>>l;
    for(int i=0; i<n; ++i){for(int j=0; j<n; ++j){cin>>board[i][j].height;}}
    check(0); check(1);
    cout<<ans;
    return 0;
}
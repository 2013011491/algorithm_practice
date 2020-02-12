//200212 19:38 start D3 49.59%  20:23 45min
#include<iostream>
#include<array>
#include<string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t,h,w,n;
    string action;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        array<string,23> map;
        cin>>h>>w;
        string blank,pres;
        array<int,3> posi;  //i,j,way
        for(int i=0; i<w+2; ++i){ blank.push_back('0'); }
        map[0]=blank;
        for(int i=1; i<=h; ++i)
        {
            cin>>pres;
            pres="0"+pres+"0";
            map[i]=pres;
        }
        map[h+1]=blank;
        cin>>n>>action;
        for(int i=0; i<h+2; ++i)
        {
            for(int j=0; j<w+2; ++j)
            {
                if(map[i][j]=='^'){ map[i][j]='.'; posi={i,j,0}; break; }
                else if(map[i][j]=='>'){ map[i][j]='.'; posi={i,j,1}; break; }
                else if(map[i][j]=='v'){ map[i][j]='.'; posi={i,j,2}; break; }
                else if(map[i][j]=='<'){ map[i][j]='.'; posi={i,j,3}; break; }
            }
        }
        for(int i=0; i<n; ++i)
        {
            if(action[i]=='U')
            {
                posi[2]=0;
                if(map[posi[0]-1][posi[1]]=='.') posi[0]--;
            }else if(action[i]=='R')
            {
                posi[2]=1;
                if(map[posi[0]][posi[1]+1]=='.') posi[1]++;
            }else if(action[i]=='D')
            {
                posi[2]=2;
                if(map[posi[0]+1][posi[1]]=='.') posi[0]++;
            }else if(action[i]=='L')
            {
                posi[2]=3;
                if(map[posi[0]][posi[1]-1]=='.') posi[1]--;
            }else if(action[i]=='S')
            {
                if(posi[2]==0)
                {
                    for(int k=posi[0]-1; k>0; --k)
                    {
                        if(map[k][posi[1]]=='#') break;
                        else if(map[k][posi[1]]=='*')
                        {
                            map[k][posi[1]]='.';
                            break;
                        }
                    }                        
                }else if(posi[2]==1)
                {
                    for(int k=posi[1]+1; k<w+1; ++k)
                    {
                        if(map[posi[0]][k]=='#') break;
                        else if(map[posi[0]][k]=='*')
                        {
                            map[posi[0]][k]='.';
                            break;
                        }
                    }
                }else if(posi[2]==2)
                {
                    for(int k=posi[0]+1; k<h+1; ++k)
                    {
                        if(map[k][posi[1]]=='#') break;
                        else if(map[k][posi[1]]=='*')
                        {
                            map[k][posi[1]]='.';
                            break;
                        }
                    }
                }else if(posi[2]==3)
                {
                    for(int k=posi[1]-1; k>0; --k)
                    {
                        if(map[posi[0]][k]=='#') break;
                        else if(map[posi[0]][k]=='*')
                        {
                            map[posi[0]][k]='.';
                            break;
                        }
                    }
                }
            }
        }
        if(posi[2]==0) map[posi[0]][posi[1]]='^';
        else if(posi[2]==1 )map[posi[0]][posi[1]]='>';
        else if(posi[2]==2) map[posi[0]][posi[1]]='v';
        else if(posi[2]==3) map[posi[0]][posi[1]]='<'; 
        for(int i=1; i<h+1; ++i)
        {
            for(int j=1; j<w+1; ++j){ cout<<map[i][j]; }
            cout<<"\n";
        }
    }
    return 0;
}
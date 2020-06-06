//200601 gold5 forsds
#include<iostream>
#include<array>
#include<algorithm>
#include<cmath>

using namespace std;

typedef struct house
{
    int x,y;
    array<array<int,2>,13> lob;
}house;

int n,m;
int selecp[13]={0,};
array<array<int,2>,13> bbq;
house hpoint[102];
int bnum=0,hnum=0;
int ans=100000000;

bool classcomp(array<int,2> lhs, array<int,2> rhs){return lhs[0]<rhs[0]? true : false;}

void update_chick()
{
    for(int i=0; i<hnum; ++i)
    {
        for(int j=0; j<bnum; ++j)
        {
            int lenofb=abs(hpoint[i].x-bbq[j][0])+abs(hpoint[i].y-bbq[j][1]);
            hpoint[i].lob[j][0]=lenofb;
            hpoint[i].lob[j][1]=j;
        }
        sort(hpoint[i].lob.begin(),hpoint[i].lob.begin()+bnum, classcomp);
    }
}

void calcul()
{
    int result=0;
    for(int i=0; i<hnum; ++i)
    {
        int check=0;
        for(int j=0; j<bnum; ++j)
        {
            for(int k=0; k<m; ++k)
            {
                if(selecp[k]==hpoint[i].lob[j][1])
                {
                    result+=hpoint[i].lob[j][0];
                    check=1;
                    break;
                }
            }
            if(check==1) break;
        }
    }
    if(result<ans) ans=result;
}

void comb(int st,int size)
{
    if(size==m){calcul(); return;}
    for(int i=st; i<bnum; ++i)
    {
        selecp[size]=i;
        comb(i+1,size+1);
    }
}

int main(void)
{
    cin>>n>>m;
    int temp;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin>>temp;
            if(temp==2){bbq[bnum][0]=i; bbq[bnum][1]=j; bnum++;}
            else if(temp==1){hpoint[hnum].x=i; hpoint[hnum].y=j; hnum++;}
        }
    }
    update_chick();
    comb(0,0);
    cout<<ans;
    return 0;
}
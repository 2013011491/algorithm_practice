//200416 21:15 start gold4 for swexpert  22:38 pause   13:47 restart 14:13 end
//total 60+23+26=109  19min overtime
#include <iostream>

using namespace std;

int main(void)
{
    int n,sum=0;
    int A[22][22]={0,};
    int ans=400001;
    cin>>n;
    for(int i=1; i<=n; ++i){for(int j=1; j<=n; ++j){cin>>A[i][j]; sum+=A[i][j];}}
    for(int x=1; x<=n; ++x)
    {
        for(int y=1; y<=n; ++y)
        {
            for(int d1=1; x+d1<n; ++d1)
            {
                if(y-d1<1) break;
                for(int d2=1; x+d1+d2<=n; ++d2)
                {
                    if(y+d2>n) break;
                    //x,y,d1,d2 selction complete;
                    int ot[2]={0,}; //one->three
                    int tf[2]={0,}; //two->four;
                    int oti=0,tfi=0;
                    int five=sum;
                    int str=x,stc=y,fir=x,fic=y;
                    for(int i=1; i<=n; ++i)
                    {
                        if(i<str)
                        {
                            for(int j=1; j<=n; ++j)
                            {
                                if(j<=stc) ot[oti]+=A[i][j];
                                else tf[tfi]+=A[i][j];
                            }
                        }else if(i>str)
                        {
                            for(int j=1; j<=n; ++j)
                            {
                                if(j<stc) ot[oti]+=A[i][j];
                                else tf[tfi]+=A[i][j];
                            }
                        }else
                        {
                            if(stc==y-d1) oti=1;
                            for(int j=1; j<=n; ++j)
                            {    
                                if(j<stc) ot[oti]+=A[i][j];
                                else if(j>fic) tf[tfi]+=A[i][j];
                            }
                            if(str!=x+d1+d2)
                            {
                                if(fic==y+d2) tfi=1;
                                str++,fir++;
                                if(oti==1) stc++;
                                else stc--;
                                if(tfi==1) fic--;
                                else fic++;
                            }
                        }
                    }
                    five-=(ot[0]+ot[1]+tf[0]+tf[1]);
                    int max=ot[0],min=ot[0];
                    if(ot[1]>max) max=ot[1];
                    if(ot[1]<min) min=ot[1];
                    for(int k=0; k<2; ++k)
                    {
                        if(max<tf[k]) max=tf[k];
                        if(min>tf[k]) min=tf[k];
                    }   
                    if(five>max) max=five;
                    if(five<min) min=five;
                    if(ans>(max-min)) ans=max-min;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
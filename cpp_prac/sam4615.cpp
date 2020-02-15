//200215 16:09 start D3 33.74% start  17:03 54min  
// too long code
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,m;
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin>>n>>m;
        int board[10][10]={0,};
        board[n/2][n/2+1]=1; board[n/2+1][n/2]=1;
        board[n/2+1][n/2+1]=2; board[n/2][n/2]=2;
        int pres[3]={0,};
        
        for(int i=0; i<m; ++i)
        {
            cin>>pres[1]>>pres[0]>>pres[2];
            board[pres[0]][pres[1]]=pres[2];
            
        //6-way check
            //right check
            int fin=pres[1];
            while(1)
            {
                fin++;
                if(board[pres[0]][fin]==0) break;
                else if(board[pres[0]][fin]==pres[2])
                {
                    for(int j=pres[1]+1; j<fin; ++j){ board[pres[0]][j]=pres[2];}
                    break;
                }
            }
            //left check
            fin=pres[1];
            while(1)
            {
                fin--;
                if(board[pres[0]][fin]==0) break;
                else if(board[pres[0]][fin]==pres[2])
                {
                    for(int j=pres[1]-1; j>fin; --j){ board[pres[0]][j]=pres[2];}
                    break;
                }
            }
            //up check
            fin=pres[0];
            while(1)
            {
                fin--;
                if(board[fin][pres[1]]==0) break;
                else if(board[fin][pres[1]]==pres[2])
                {
                    for(int j=pres[0]-1; j>fin; --j){ board[j][pres[1]]=pres[2];}
                    break;
                }
            }
            //down check
            fin=pres[0];
            while(1)
            {
                fin++;
                if(board[fin][pres[1]]==0) break;
                else if(board[fin][pres[1]]==pres[2])
                {
                    for(int j=pres[0]+1; j<fin; ++j){ board[j][pres[1]]=pres[2];}
                    break;
                }
            }
            //NE check
            fin=pres[0];
            int fin2=pres[1];
            while(1)
            {
                fin--;
                fin2++;

                if(board[fin][fin2]==0) break;
                else if(board[fin][fin2]==pres[2])
                {
                    int k=pres[0]-1;
                    for(int j=pres[1]+1; j<fin2; ++j){ board[k--][j]=pres[2];}
                    break;
                }
            }
            //SE check
            fin=pres[0];
            fin2=pres[1];
            while(1)
            {
                fin++;
                fin2++;

                if(board[fin][fin2]==0) break;
                else if(board[fin][fin2]==pres[2])
                {
                    int k=pres[0]+1;
                    for(int j=pres[1]+1; j<fin2; ++j){ board[k++][j]=pres[2];}
                    break;
                }
            }
            //sw check
            fin=pres[0];
            fin2=pres[1];
            while(1)
            {
                fin++;
                fin2--;

                if(board[fin][fin2]==0) break;
                else if(board[fin][fin2]==pres[2])
                {
                    int k=pres[0]+1;
                    for(int j=pres[1]-1; j>fin2; --j){ board[k++][j]=pres[2];}
                    break;
                }
            }
            //nw check
            fin=pres[0];
            fin2=pres[1];
            while(1)
            {
                fin--;
                fin2--;

                if(board[fin][fin2]==0) break;
                else if(board[fin][fin2]==pres[2])
                {
                    int k=pres[0]-1;
                    for(int j=pres[1]-1; j>fin2; --j){ board[k--][j]=pres[2];}
                    break;
                }
            }
        }
        int black=0;
        int white=0;
        
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(board[i][j]==1) black++;
                else if(board[i][j]==2) white++;
            }
        }
        cout<<"#"<<tc<<" "<<black<<" "<<white<<"\n";
    }
    return 0;
}
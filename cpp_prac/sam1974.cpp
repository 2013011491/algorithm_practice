//200207 18:17 start d2 68.16% 18:51  wrong logic shit
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    int board[9][9]={0,};
    
    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        for(int i=0; i<9; ++i)
        { 
            for(int j=0; j<9; ++j){ cin>>board[i][j]; }
        }

        cout<<"#"<<tc<<" ";
        int possi=1;
        for(int i=0; i<9; ++i)
        {
            int check[10]={0,};
            for(int j=0; j<9; ++j)
            {
                if(check[board[i][j]]!=0)
                {
                    possi=0;
                    break;
                }else check[board[i][j]]++;
            }
            if(possi==0) break;
        }
        if(possi==0)
        {
            cout<<0<<"\n";
            continue;
        }

        for(int i=0; i<9; ++i)
        {
            int check[10]={0,};
            for(int j=0; j<9; ++j)
            {
                if(check[board[j][i]]!=0)
                {
                    possi=0;
                    break;
                }else check[board[j][i]]++;
            }
            if(possi==0) break;
        }
        if(possi==0)
        {
            cout<<0<<"\n";
            continue;
        }
        for(int i=0; i<9; i+=3)
        {
            for(int j=0; j<9; j+=3)
            {
                int check[10]={0,};
                for(int k=i; k<i+3; ++k)
                {
                    for(int l=j; l<j+3; ++l)
                    {
                        if(check[board[k][l]]!=0)
                        {
                            possi=0;
                            break;
                        }else check[board[k][l]]++;
                    }
                    if(possi==0) break;
                }
                if(possi==0) break;
            }
            if(possi==0) break;
        }
        if(possi==0)
        {
            cout<<0<<"\n";
            continue;
        }
        cout<<1<<"\n";
    }
    return 0;
}

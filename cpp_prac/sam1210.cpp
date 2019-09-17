#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int tc=0; tc<10; tc++)
    {
        int trash;
        char data[100][100];
        int x=99,y=0;
        int pastX,pastY;

        cin>>trash;
        for(int i=0; i<100; i++)
        {
            for(int j=0; j<100; j++)
            {
                 cin>>data[i][j];
            }
            cout<<data[i]<<"\n";
        }

        cout<<"#"<<tc+1<<" ";
        for(int i=0; i<100; i++)
        {
            if(data[99][i]=='2')
            {
                y=i;
                break;
            }
        }

        pastX=99; pastY=y; x=98;
        while(x!=0)
        {
            if(data[x][y-1]=='1'&&pastY!=(y-1)&&y!=0)
            {
                y-=1;
                pastY=y+1;
            }else if(data[x][y+1]=='1'&&pastY!=(y+1)&&y!=99)
            {
                y+=1;
                pastY=y-1;
            }else
            {
                x-=1;
                pastX=x+1;
                pastY=y;
            }
        }
        cout<<y<<"\n";
    }
    return 0;
}
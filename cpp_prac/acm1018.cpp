#include<iostream>
#include<string>

using namespace std;

int checkboard(string board[50], int starti,int startj)
{
    string b="BWBWBWBW";
    string w="WBWBWBWB";
    int first=0;
    int second=0;
    //first patter bw;
    for(int i=0; i<8; i+=2)
    {
        for(int j=0; j<8; j++)
        {
            if(board[starti+i][startj+j]!=b[j]) first++;
            if(board[starti+i][startj+j]!=w[j]) second++;
        }
    }
    for(int i=1; i<8; i+=2)
    {
        for(int j=0; j<8; j++)
        {
            if(board[starti+i][startj+j]!=w[j]) first++;
            if(board[starti+i][startj+j]!=b[j]) second++;
        }
    }
    return first<second ? first: second;
}
int main(void)
{
    int m,n;
    cin>>m>>n;
    string board[50];
    for(int i=0; i<m; i++) cin>>board[i];

    int coln=m-8;
    int rown=n-8;
    int min=2500;
    int temp;
    for(int i=0; i<=coln; i++)
    {
        for(int j=0; j<=rown; j++)
        {
            temp=checkboard(board,i,j);
            if(temp<min) min=temp;
        }
    }
    cout<<min;
    return 0;
}
#include<iostream>
#include<array>
#include<vector>
using namespace std;


int main(void)
{
    int n,x,y;
    cin>>n;
    array<array<int,2>,100001> bucket;
    int size=1;
    int num=0;
    array<int,2> temp;
    cin>>x>>y;
    bucket[0]={x,y};
    for(int i=1; i<n; i++)
    {
        cin>>x>>y;
        temp={x,y};
        for(int j=0; j<size; j++)
        {
            if(y<bucket[j][1])
            {
                swap(bucket[j],temp);
                for(int k=j+1; k<size; k++) swap(bucket[k],temp);
                break;
                
            }else if(y==bucket[j][1])
            {
                if(x>bucket[j][0])
                {
                    swap(bucket[j],temp);
                    for(int k=j+1; k<size; k++) swap(bucket[k],temp);
                }else
                {
                    for(int k=j+1; k<size; k++) swap(bucket[k],temp);
                } 
                break;
            }
        }
        bucket[size]=temp;
        size++;
    }
    y=bucket[0][1];
    num++;
    for(int i=1; i<size; i++)
    {
        if(bucket[i][0]>=y)
        {
            num++;
            y=bucket[i][1];
        }
    }
    cout<<num;
    return 0;
}
//2019-11-12 19:46
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
void rotate(array<array<int,52>,52> &temp, int r, int c, int s)
{
    for(int i=1; i<=s; ++i)
    {
        int st=temp[r-i][c-i];
        for(int j=r-i; j<r+i; j++){temp[j][c-i]=temp[j+1][c-i];}
        for(int j=c-i; j<c+i; j++){temp[r+i][j]=temp[r+i][j+1];}
        for(int j=r+i; j>r-i; j--){temp[j][c+i]=temp[j-1][c+i];}
        for(int j=c+i; j>c-i; j--){temp[r-i][j]=temp[r-i][j-1];}
        temp[r-i][c-i+1]=st;
    }

}
int main(void)
{
    int k;
    array<array<int,52>,52> arr;
    vector<array<int,3>> bucket;

    cin>>n>>m>>k;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j){cin>>arr[i][j];}
    }
    for(int i=0; i<k; ++i)
    {
        array<int,3> tt;
        cin>>tt[0]>>tt[1]>>tt[2];
        bucket.push_back(tt);
    }
    int min=500000;
    sort(bucket.begin(),bucket.end());
    do
    {
        array<array<int,52>,52> temp;
        copy(arr.begin(),arr.end(),temp.begin());
        for(int i=0; i<k; ++i){rotate(temp,bucket[i][0],bucket[i][1],bucket[i][2]);}
        for(int i=1; i<=n; ++i)
        { 
            int sum=0;
            for(int j=1; j<=m; ++j){ sum+=temp[i][j];}
            if(min>sum) min=sum;
        }
    }while(next_permutation(bucket.begin(),bucket.end()));
    cout<<min;
    return 0;
}
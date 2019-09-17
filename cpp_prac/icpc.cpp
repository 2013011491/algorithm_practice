#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int arr[n+1];
    int count1, count2, count3;
    int min;
    arr[0]=0;
    arr[1]=0;
    
    for(int i=2; i<=n; i++)
    {
    	min=1000000;
    	if(i%3==0)
		{
			count1=1+arr[i/3];
			min=count1;
		}
    	if(i%2==0)
		{
			count2=1+arr[i/2];
			if(count2<min) min=count2;
		}
    	count3=1+arr[i-1];
    	if(count3<min) min=count3;
    	arr[i]=min;
	}
	cout<<arr[n];
    return 0;
}

#include<iostream>

using namespace std;

int main(void)
{
	int n;
	int s=0;
	cin>>n;
	
	int f=0;
	int se=1;
	int temp;
	for(int i=0; i<n; i++)
	{
		temp=f;
		f=se;
		se=temp+se;
	}
	
	cout<<se;
	return 0;
}

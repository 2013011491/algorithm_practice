#include <iostream>

using namespace std;

int main(void){
	int a=30;
	int **dp;
	int *p=&a;
	dp=&p;
	cout<<dp<<" "<<p<<" "<<*p<<" "<<a<<" "<<&a;
	return 0;
}

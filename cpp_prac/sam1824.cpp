#include<iostream>
#include<stack>
#include<array>

using namespace std;

int check[20][20][4][16]={0,};

void way(int &x, int &y, int r, int c,int dir)
{
	if(dir==0) y=(y+1)%c;
	else if(dir==1) y=(y-1+c)%c;
	else if(dir==2) x=(x+1)%r;
	else x=(x-1+r)%r;
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t,r,c;
	int possi=0;
	char data[20][20];
	cin>>t;

	for(int i=0; i<t; i++)
	{
		array<int,4> pre={0,};
		char prechar;
		int premem;
		int predir;
		stack<array<int,4>> bucket;

		cin>>r>>c;
		for(int j=0; j<r; j++) cin>>data[j];
		bucket.push({0,0,0,0});
		cout<<"#"<<i+1<<" ";
		while(bucket.size())
		{
			pre=bucket.top();
			bucket.pop();
			prechar=data[pre[0]][pre[1]];
			if(check[pre[0]][pre[1]][pre[2]][pre[3]]==i+1) continue;
			else check[pre[0]][pre[1]][pre[2]][pre[3]]=i+1;
			

			if(prechar=='>') bucket.push({pre[0],(pre[1]+1)%c,0,pre[3]});
			else if(prechar=='<') bucket.push({pre[0],(pre[1]-1+c)%c,1,pre[3]});
			else if(prechar=='v') bucket.push({(pre[0]+1)%r,pre[1],2,pre[3]});
			else if(prechar=='^') bucket.push({(pre[0]-1+r)%r,pre[1],3,pre[3]});
			else if(prechar=='_')
			{
				if(pre[3]==0) bucket.push({pre[0],(pre[1]+1)%c,0,pre[3]});
				else bucket.push({pre[0],(pre[1]-1+c)%c,1,pre[3]});
			}else if(prechar=='|')
			{
				if(pre[3]==0) bucket.push({(pre[0]+1)%r,pre[1],2,pre[3]});
				else bucket.push({(pre[0]-1+r)%r,pre[1],3,pre[3]});				
			}else if(prechar=='+')
			{
				way(pre[0],pre[1],r,c,pre[2]);
				bucket.push({pre[0],pre[1],pre[2],(pre[3]+1)%16});
			}else if(prechar=='-')
			{
				way(pre[0],pre[1],r,c,pre[2]);
				bucket.push({pre[0],pre[1],pre[2],(pre[3]-1+16)%16});				
			}else if(prechar=='.')
			{
				way(pre[0],pre[1],r,c,pre[2]);
				bucket.push({pre[0],pre[1],pre[2],pre[3]});				
			}else if(prechar=='@')
			{
				possi=1;
				break;
			}else if(prechar=='?')
			{
				bucket.push({pre[0],(pre[1]+1)%c,0,pre[3]});
				bucket.push({pre[0],(pre[1]-1+c)%c,1,pre[3]});
				bucket.push({(pre[0]+1)%r,pre[1],2,pre[3]});
				bucket.push({(pre[0]-1+r)%r,pre[1],3,pre[3]});
			}else
			{
				way(pre[0],pre[1],r,c,pre[2]);
				bucket.push({pre[0],pre[1],pre[2],prechar-'0'});
			}
		}
		if(possi==1) cout<<"YES\n";
		else cout<<"NO\n";
		possi=0;
	}
	return 0;
}
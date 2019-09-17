#include<iostream>
#include<string>
#include<vector>

using namespace std;

string tile[4];
vector<string> buck;

void bfs(int x, int y, string str)
{
	if(str.length()==7)
	{
		int check=0;
		for(check; check<buck.size(); check++)
		{
			if(!buck[check].compare(str))
			{
				check=-1;
				break;
			}
		}
		if(check!=-1) buck.push_back(str);
		return;
	}
	if(y<=2) bfs(x,y+1,str+tile[x][y+1]); //east_way
	if(y>=1) bfs(x,y-1,str+tile[x][y-1]); //west_way
	if(x<=2) bfs(x+1,y,str+tile[x+1][y]); //south
	if(x>=1) bfs(x-1,y,str+tile[x-1][y]); //north	
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	string temp;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		for(int r=0; r<4; r++) cin>>tile[r][0]>>tile[r][1]>>tile[r][2]>>tile[r][3]; //tile input
		for(int row=0; row<4; row++)
		{
			for(int col=0; col<4; col++)
			{
				temp.append(1,tile[row][col]);
				bfs(row,col,temp);
				temp.clear();	
			}
		}
		cout<<"#"<<i+1<<" "<<buck.size()<<"\n";
		buck.clear();
	}
	return 0;
}

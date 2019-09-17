#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{  }
	
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
	}
	
	Point operator+=(const Point &pos2)
	{
		xpos+=pos2.xpos;
		ypos+=pos2.ypos;
		return this;	
	}
	
	Point operator-=(const Point &ref)
	{
		xpos-=ref.xpos;
		ypos-=ref.ypos;
		return this;
	}
	
	Point opertaor-()
	{
		Point pos1(-xpos,-ypos);
		return ps1;
	}
	
	friend Point operator~(const Point &);
	friend Point operator+(const Point &pos1, const Point &pos2);
	friend Point operator-(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
	return pos;
}

Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
	return pos;
}

Point operator~(const Point &ref)
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}
int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);	
	Point pos3=pos1+pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}

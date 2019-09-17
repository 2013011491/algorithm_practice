/*
proplem 13-1
*/

#include <iostream>
#include <cstring>

using namespace std;

class Point
{
	private:
		int xpos, ypos;
		
	public:
		Point(int x=0, int y=0) : xpos(x), ypos(y)
		{ }
		
		void SetPos(int x, int y)
		{
			xpos=x;
			ypos=y;
		}
		void ShowPosition() const
		{
			cout<<'['<<xpos<<","<<ypos<<']'<<endl;
		}
};

template <class T>
void SwapData(T& a, T& b)
{
	T temp=a;
	a=b;
	b=temp;
}

template <class T>
T SumArray(T arr[], int len)
{
	T sum=0;
	for(int i=0; i<len; i++)
	{
		sum+=arr[i];
	}
	
	return sum;
}



template <typename T>
class SmartPtr
{
	private:
		T * posptr;

	public:
		SmartPtr(T *ptr) : posptr(ptr)
		{ }
		
		T& operator*() const
		{
			return *posptr;
		}
		T* operator->() const
		{
			return posptr;
		}
		~SmartPtr()
		{
			delete posptr;
		}		
};

int main(void)
{
	/*Point p1(3,5);
	Point p2(8,9);
	p1.ShowPosition();
	p2.ShowPosition();
	SwapData(p1,p2);
	p1.ShowPosition();
	p2.ShowPosition();
	
	double arr[3]={2.9,0.2,4.5};
	cout<<SumArray(arr,3)<<endl;*/
	
	SmartPtr<Point> sptr1(new Point(1,2));
	SmartPtr<Point> sptr2(new Point(3,4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();
	return 0;
	
}

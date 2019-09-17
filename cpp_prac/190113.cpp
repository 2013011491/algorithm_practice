#include<iostream>
#include<cstring>

using namespace std;

/*class Point
{
	private:
		int xpos, ypos;
	public:
		
		Point(int x, int y) : xpos(x), ypos(y) 
		{ }
		Point():xpos(0), ypos(0)
		{ }
		void ShowPointInfo() const
		{
			cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
		}
};

class Circle
{
	private:
		Point center;
		int radius;
		
	public:
		Circle(int x, int y, int b) : center(x,y), radius(b) {}
		
		void ShowCircleInfo() const
		{
			cout<<"Circle Info ..."<<endl<<"radius: "<<radius<<endl;
			center.ShowPointInfo();
		}
};

class Ring
{
	private:
		Circle inner;
		Circle outer;
	
	public:
		Ring(int x1, int y1, int r1, int x2, int y2, int r2) : inner(x1,y1,r1), outer(x2,y2,r2) {}
		
		void ShowRingInfo() const
		{
			cout<<"Inner";
			inner.ShowCircleInfo();
			cout<<"Outter";
			outer.ShowCircleInfo();
		}
};

int main(void)
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}*/

namespace COMP_POS
{
	enum
	{
		CLERK, SENIOR, ASSIST, MANAGER	
	};
	
	void ShowPosition(int a)
	{
		switch(a)
		{
			case CLERK :
				cout<<"직급: 사원"<<endl;
				break;
			
			case SENIOR :
				cout<<"직급: 주임"<<endl;
				break;
			
			case ASSIST :
				cout<<"직급: 대리"<<endl;
				break;
			
			case MANAGER :
				cout<<"직급: 과장"<<endl;
				break;
		}
	}
}
class NameCard
{
	private :
		char *name;
		char *compname;
		char *phone;
		int position;
	
	public :
		NameCard(char *a, char *b, char* c,int d)
		{
			int len1=strlen(a)+1;
			int len2=strlen(b)+1;
			int len3=strlen(c)+1;
			name = new char[len1];
			compname = new char[len2];
			phone = new char[len3];
			strcpy(name, a);
			strcpy(compname, b);
			strcpy(phone, c);
			position = d;
		}
		~NameCard()
		{
			delete []name;
			delete []compname;
			delete []phone;
		}
		void ShowNameCardInfo()
		{
			cout<<"이름: "<<name<<endl;
			cout<<"회사: "<<compname<<endl;
			cout<<"전화번호: "<<phone<<endl;
			COMP_POS::ShowPosition(position);
			
		}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}

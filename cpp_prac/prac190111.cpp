#include<iostream>
#include<cstring>

using namespace std;

/*class Calculator
{
	private :
		int addNo;
		int subNo;
		int mulNo;
		int divNo;
	
	public :
		void Init();
		double Add(double a, double b);
		double Min(double a, double b);
		double Mul(double a, double b);
		double Div(double a, double b);
		void ShowOpCount();
};

void Calculator::Init(){
	addNo=0;
	subNo=0;
	mulNo=0;
	divNo=0;
}

double Calculator::Add(double a, double b){
	addNo++; 
	return a+b;
}

double Calculator::Min(double a, double b){
	
	subNo++;
	return a-b;
}

double Calculator::Mul(double a, double b){
	mulNo++;
	return a*b;
}

double Calculator::Div(double a, double b){
	divNo++;
	return a/b;
}

void Calculator::ShowOpCount(){
	cout<<"µ¡¼À: "<<addNo<<" "<<"»¬¼À: "<<subNo<<" "<<"°ö¼À: "<<mulNo<<" "<<"³ª´°¼À: "<<divNo;
}

int main(void){
	Calculator cal;
	cal.Init();
	cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
	cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
	cal.ShowOpCount();
	return 0;
}*/

/*class Printer
{
	private :
		char name[30];
	
	public :
		void SetString(char *a);
		void ShowString();
};

void Printer::SetString(char *a)
{
	strcpy(name,a);
}

void Printer::ShowString()
{
	cout<<name<<endl;
}

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();
	
	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}*/

class Point
{
	private:
		int xpos, ypos;
		
	public:
		void Init(int x, int y)
		{
			xpos=x;
			ypos=y;
		}
		
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
		void CircleInit(int x, int y,int b)
		{
			center.Init(x,y);
			radius=b;
		}
		
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
		void Init(int x1, int y1, int r1, int x2, int y2, int r2)
		{
			inner.CircleInit(x1,y1,r1);
			outer.CircleInit(x2,y2,r2);
		}
		
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
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}

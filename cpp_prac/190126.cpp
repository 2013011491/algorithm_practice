#include <iostream>
#include <cstring>

using namespace std;

class Car
{
	private :
		int gasolineGauge;
		
	public :
		Car(int gas) : gasolineGauge(gas)
		{}
		
		int GetGasGauge()
		{
			return gasolineGauge;
		}
};

class HybridCar : public Car
{
	private :
		int electricGauge;
		
	public :
		HybridCar(int gas, int elec) : Car(gas), electricGauge(elec)
		{
		}
		
		int GetElecGauge()
		{
			return electricGauge;
		}
};

class HybridWaterCar : public HybridCar
{
	private :
		int waterGauge;
	
	public :
		HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGauge(water)
		{
		}
		
		void ShowCurrentGauge()
		{
			cout<<"�ܿ� ���ָ�: "<<GetGasGauge()<<endl;
			cout<<"�ܿ� ���ⷮ: "<<GetElecGauge()<<endl;
			cout<<"�ܿ� ���ͷ�: "<<waterGauge<<endl;
		}
};

class MyFriendInfo
{
	private :
		char *name;
		int age;
	
	public :
		MyFriendInfo(char *fname, int fage) : age(fage)
		{
			name = new char[strlen(fname)+1];
			strcpy(name,fname);
		}
		
		~MyFriendInfo()
		{
			delete []name;
		}
		
		void ShowMyFriendInfo()
		{
			cout<<"�̸�: "<<name<<endl;
			cout<<"����: "<<age<<endl;
		}
};

class MyFriendDetailInfo : public MyFriendInfo
{
	private:
		char *addr;
		char *phone;
		
	public:
		MyFriendDetailInfo(char *fname, int fage, char *faddr, char *fphone) : MyFriendInfo(fname, fage)
		{
			addr = new char[strlen(faddr)+1];
			phone = new char[strlen(fphone)+1];
			strcpy(addr,faddr);
			strcpy(phone,fphone);
		}
		
		~MyFriendDetailInfo()
		{
			delete []addr;
			delete []phone;
		}
		
		void ShowMyFriendDetailInfo()
		{
			ShowMyFriendInfo();
			cout<<"�ּ�: "<<addr<<endl;
			cout<<"��ȭ: "<<phone<<endl<<endl;
		}
};

int main(void)
{
	HybridWaterCar sm3(80,70,30);
	sm3.ShowCurrentGauge();
	
	MyFriendDetailInfo rla("����", 26, "�Ⱦ��", "20202");
	rla.ShowMyFriendDetailInfo(); 
	return 0;
}

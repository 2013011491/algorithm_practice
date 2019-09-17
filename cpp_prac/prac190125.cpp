#include <iostream>
#include <cstring>

using namespace std;

class Account
{
	private :
		int accID;
		char *name;
		int balance;
		
	public :
		Account(int ID, char *tname,int tBlance) : accID(ID), balance(tBlance)
		{
			name = new char[strlen(tname)+1];
			strcpy(name,tname);
		}
		
		Account(const Account& copy) : accID(copy.accID), balance(copy.balance)
		{
			name = new char[strlen(copy.name)+1];
			strcpy(name,copy.name);
		}
		
		~Account()
		{
			delete []name;
		}
		
		void Insert(int money)
		{
			balance += money;
			cout<<"입금완료"<<endl;
		}
		
		void withdraw(int money)
		{
			if(balance>=money)
			{
				balance -= money;
				cout<<"출금완료"<<endl;
			}else cout<<"잔액부족"<<endl;
		}
		
		int GetID() const
		{
			return accID;
		}
		
		void ShowInfo() const
		{
			cout<<accID<<endl;
			cout<<name<<endl;
			cout<<balance<<endl;
			cout<<endl;
		}
};

Account * accList[30];
int accNum=0;

int main(void)
{
	char select;
	while(1){
		cout<<"----Menu----"<<endl;
		cout<<"1. 계좌개설"<<endl;
		cout<<"2. 입금"<<endl;
		cout<<"3. 출금"<<endl;
		cout<<"4. 계좌정보 전체 출력"<<endl;
		cout<<"5. 프로그램 종료"<<endl;
		cout<<"선택:";
		cin>>select;
		
		switch(select){
			case '1' :
				int temID;
				char tname[30];
				int tempbal;
				cout<<"게좌ID: ";
				cin>>temID;
				cout<<"이름: ";
				cin>>tname;
				cout<<"입금액: ";
				cin>>tempbal;
				accList[accNum] = new Account(temID, tname, tempbal);
				accNum=accNum+1;
				break;
			case '2':
				int tempID;
				int inputM;
				cout<<"[입금]"<<endl; 
				cout<<"계좌ID: ";
				cin>>tempID;
				int i;
				for(i=0; i<accNum; i++){
					if(accList[i]->GetID()==tempID) break;
					else continue;
				}
				cout<<"입금액: ";
				cin>>inputM;
				if(i!=accNum){
					accList[i]->Insert(inputM);
				}
				else cout<<"존재 하지 않는 계좌"<<endl;
				break;
			case '3':
				cout<<"[출금]"<<endl;
				cout<<"계좌ID: ";
				cin>>tempID;
				for(i=0; i<accNum; i++){
					if(accList[i]->GetID()==tempID) break;
					else continue;
				}
				cout<<"출금액: ";
				cin>>inputM;
				if(i==accNum) cout<<"존재 하지 않는 계좌"<<endl;
				else accList[i]->withdraw(inputM);
				break;
			case '4':
				for(int i=0; i<accNum; i++)
				{
					accList[i]->ShowInfo();
				}
				break;
			case '5':
				return 0;
		}
	}
	return 0;
}

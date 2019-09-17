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

class AccountHandler
{
	private :
		Account * accList[30];
		int accNum;
		
	public :
		AccountHandler() : accNum(0)
		{}
		
		~AccountHandler()
		{
			for(int i=0; i<accNum; i++) delete accList[i];
		}
		
		void ShowMenu(void) const
		{
			cout<<"----Menu----"<<endl;
			cout<<"1. 계좌개설"<<endl;
			cout<<"2. 입금"<<endl;
			cout<<"3. 출금"<<endl;
			cout<<"4. 계좌정보 전체 출력"<<endl;
			cout<<"5. 프로그램 종료"<<endl;
		}
		
		void MakeAccount(void)
		{
			int temID;
			char tname[30];
			int tempbal;
			cout<<"계좌ID: ";
			cin>>temID;
			cout<<"이름: ";
			cin>>tname;
			cout<<"입금액: ";
			cin>>tempbal;
			cout<<endl;
			 
			accList[accNum] = new Account(temID, tname, tempbal);
			accNum=accNum+1;
		}
		
		void DepositAcc(void)
		{
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
		}
		
		void WithdrawAcc(void)
		{
			int tempID;
			int inputM;
			cout<<"[출금]"<<endl;
			cout<<"계좌ID: ";
			cin>>tempID;
			int i;
			for(i=0; i<accNum; i++){
				if(accList[i]->GetID()==tempID) break;
				else continue;
			}
			cout<<"출금액: ";
			cin>>inputM;
			if(i==accNum) cout<<"존재 하지 않는 계좌"<<endl;
			else accList[i]->withdraw(inputM);
		}
		
		void AllPrint(void)
		{
			for(int i=0; i<accNum; i++)
			{
				accList[i]->ShowInfo();
			}
		}
};


int main(void)
{
	AccountHandler manager;
	char select;
	while(1){
		manager.ShowMenu();
		cout<<"선택:";
		cin>>select;
		switch(select){
			case '1':
				manager.MakeAccount();
				break;
			case '2':
				manager.DepositAcc();
				break;
			case '3':
				manager.WithdrawAcc();
				break;
			case '4':
				manager.AllPrint();
				break;
			case '5':
				return 0;
		}
	}
}

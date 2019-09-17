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
			cout<<"�ԱݿϷ�"<<endl;
		}
		
		void withdraw(int money)
		{
			if(balance>=money)
			{
				balance -= money;
				cout<<"��ݿϷ�"<<endl;
			}else cout<<"�ܾ׺���"<<endl;
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
			cout<<"1. ���°���"<<endl;
			cout<<"2. �Ա�"<<endl;
			cout<<"3. ���"<<endl;
			cout<<"4. �������� ��ü ���"<<endl;
			cout<<"5. ���α׷� ����"<<endl;
		}
		
		void MakeAccount(void)
		{
			int temID;
			char tname[30];
			int tempbal;
			cout<<"����ID: ";
			cin>>temID;
			cout<<"�̸�: ";
			cin>>tname;
			cout<<"�Աݾ�: ";
			cin>>tempbal;
			cout<<endl;
			 
			accList[accNum] = new Account(temID, tname, tempbal);
			accNum=accNum+1;
		}
		
		void DepositAcc(void)
		{
			int tempID;
			int inputM;
			cout<<"[�Ա�]"<<endl; 
			cout<<"����ID: ";
			cin>>tempID;
			int i;
			for(i=0; i<accNum; i++){
				if(accList[i]->GetID()==tempID) break;
				else continue;
			}
			cout<<"�Աݾ�: ";
			cin>>inputM;
			if(i!=accNum){
				accList[i]->Insert(inputM);
			}
			else cout<<"���� ���� �ʴ� ����"<<endl;
		}
		
		void WithdrawAcc(void)
		{
			int tempID;
			int inputM;
			cout<<"[���]"<<endl;
			cout<<"����ID: ";
			cin>>tempID;
			int i;
			for(i=0; i<accNum; i++){
				if(accList[i]->GetID()==tempID) break;
				else continue;
			}
			cout<<"��ݾ�: ";
			cin>>inputM;
			if(i==accNum) cout<<"���� ���� �ʴ� ����"<<endl;
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
		cout<<"����:";
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

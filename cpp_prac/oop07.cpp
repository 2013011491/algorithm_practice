#include <iostream>
#include <cstring>

using namespace std;

namespace CreditRating
{
	enum
	{
		RATING_A=7, RATING_B=4, RATING_C=2
	};
}

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
		
		virtual ~Account()
		{
			delete []name;
		}
		
		virtual void Insert(int money)
		{
			balance += money;
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

class NormalAccount : public Account
{
	private:
		int interest;
		
	public:
		NormalAccount(int ID, char *tname,int tBlance, int tinterest) : Account(ID, tname, tBlance), interest(tinterest)
		{}
		
		void Insert(int money)
		{
			Account::Insert(money);
			Account::Insert((int)(money*(interest/100.0)));
			cout<<"�ԱݿϷ�"<<endl;
		}
};

class HighCreditAccount : public Account
{
	private:
		int interest;
		int level;
		
	public:
		HighCreditAccount(int ID, char *tname, int tBalance, int tinterest, int tlevel) : Account(ID, tname, tBalance), interest(tinterest), level(tlevel)
		{}
		
		void Insert(int money)
		{
			Account::Insert(money);
			Account::Insert((int)(money*((level+interest)/100.0)));
			cout<<"�ԱݿϷ�"<<endl;
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
			int selec;
			cout<<"[������������]"<<endl;
			cout<<"1.���뿹�ݰ��� 2.�ſ�ŷڰ���"<<endl;
			cout<<"����: ";
			cin>>selec;
			if(selec==1) MakeNorm();
			else if(selec==2) MakeHigh();
			else MakeAccount();
		}
		
		void MakeNorm(void)
		{
			int temID;
			char tname[30];
			int tempbal;
			int tinterest;
			
			cout<<"[���뿹�ݰ��� ����]"<<endl;
			cout<<"����ID: ";
			cin>>temID;
			cout<<"�̸�: ";
			cin>>tname;
			cout<<"�Աݾ�: ";
			cin>>tempbal;
			cout<<"������: ";
			cin>>tinterest; 
			cout<<endl;
			 
			accList[accNum] = new NormalAccount(temID, tname, tempbal, tinterest);
			accNum=accNum+1;
		}
		
		void MakeHigh(void)
		{
			int temID;
			char tname[30];
			int tempbal;
			int tinterest;
			int tlevel;
			
			cout<<"[�ſ�ŷڰ��� ����]"<<endl;
			cout<<"����ID: ";
			cin>>temID;
			cout<<"�̸�: ";
			cin>>tname;
			cout<<"�Աݾ�: ";
			cin>>tempbal;
			cout<<"������: ";
			cin>>tinterest; 
			cout<<"�ſ���: ";
			cin>>tlevel;
			cout<<endl;
			
			if(tlevel==1) tlevel=CreditRating::RATING_A;
			else if(tlevel==2) tlevel=CreditRating::RATING_B;
			else if(tlevel==3) tlevel=CreditRating::RATING_C;
			else exit(-1);
			 
			accList[accNum] = new HighCreditAccount(temID, tname, tempbal, tinterest, tlevel);
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

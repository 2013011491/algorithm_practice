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

Account * accList[30];
int accNum=0;

int main(void)
{
	char select;
	while(1){
		cout<<"----Menu----"<<endl;
		cout<<"1. ���°���"<<endl;
		cout<<"2. �Ա�"<<endl;
		cout<<"3. ���"<<endl;
		cout<<"4. �������� ��ü ���"<<endl;
		cout<<"5. ���α׷� ����"<<endl;
		cout<<"����:";
		cin>>select;
		
		switch(select){
			case '1' :
				int temID;
				char tname[30];
				int tempbal;
				cout<<"����ID: ";
				cin>>temID;
				cout<<"�̸�: ";
				cin>>tname;
				cout<<"�Աݾ�: ";
				cin>>tempbal;
				accList[accNum] = new Account(temID, tname, tempbal);
				accNum=accNum+1;
				break;
			case '2':
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
				break;
			case '3':
				cout<<"[���]"<<endl;
				cout<<"����ID: ";
				cin>>tempID;
				for(i=0; i<accNum; i++){
					if(accList[i]->GetID()==tempID) break;
					else continue;
				}
				cout<<"��ݾ�: ";
				cin>>inputM;
				if(i==accNum) cout<<"���� ���� �ʴ� ����"<<endl;
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

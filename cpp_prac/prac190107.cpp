#include <iostream>

using namespace std;

typedef struct{
	int accID;
	char name[30];
	int balance;
}Acount;

Acount accList[30];
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
				cout<<"����ID: ";
				cin>>accList[accNum].accID;
				cout<<"�̸�: ";
				cin>>accList[accNum].name;
				cout<<"�Աݾ�: ";
				cin>>accList[accNum].balance;
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
					if(accList[i].accID==tempID) break;
					else continue;
				}
				cout<<"�Աݾ�: ";
				cin>>inputM;
				if(i!=accNum){
					accList[i].balance+=inputM;
					cout<<"�ԱݿϷ�"<<endl;
				}
				else cout<<"���� ���� �ʴ� ����"<<endl;
				break;
			case '3':
				cout<<"[���]"<<endl;
				cout<<"����ID: ";
				cin>>tempID;
				for(i=0; i<accNum; i++){
					if(accList[i].accID==tempID) break;
					else continue;
				}
				cout<<"��ݾ�: ";
				cin>>inputM;
				if(i==accNum) cout<<"���� ���� �ʴ� ����"<<endl;
				else if(accList[i].balance>=inputM){
					accList[i].balance-=inputM;
					cout<<"��ݿϷ�"<<endl;
				}else cout<<"�ܾ׺���"<<endl;
				break;
			case '4':
				for(int i=0; i<accNum; i++){
					cout<<accList[i].accID<<endl;
					cout<<accList[i].name<<endl;
					cout<<accList[i].balance<<endl;
					cout<<endl;
				}
				break;
			case '5':
				return 0;
		}
	}
	return 0;
}

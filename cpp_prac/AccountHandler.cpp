#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Account.h"
#include "String.h"

AccountHandler::AccountHandler() : accNum(0)
{ }

AccountHandler::~AccountHandler()
{
	for(int i=0; i<accNum; i++) delete accList[i];
}


void AccountHandler::ShowMenu(void) const
{
	cout<<"----Menu----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �Ա�"<<endl;
	cout<<"3. ���"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
}

void AccountHandler::MakeAccount(void)
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

void AccountHandler::MakeNorm(void)
{
	int temID;
	String tname;
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

void AccountHandler::MakeHigh(void)
{
	int temID;
	String tname;
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
	 
	accList[accNum] = new HighCreditAccount(temID, tname, tempbal, tinterest, tlevel);
	accNum=accNum+1;
}

void AccountHandler::DepositAcc(void)
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

void AccountHandler::WithdrawAcc(void)
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

void AccountHandler::AllPrint(void)
{
	for(int i=0; i<accNum; i++)
	{
		accList[i]->ShowInfo();
	}
}


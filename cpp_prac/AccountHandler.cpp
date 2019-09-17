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
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입금"<<endl;
	cout<<"3. 출금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void AccountHandler::MakeAccount(void)
{
	int selec;
	cout<<"[계좌종류선택]"<<endl;
	cout<<"1.보통예금계좌 2.신용신뢰계좌"<<endl;
	cout<<"선택: ";
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
	
	cout<<"[보통예금계좌 개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>temID;
	cout<<"이름: ";
	cin>>tname;
	cout<<"입금액: ";
	cin>>tempbal;
	cout<<"이자율: ";
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
	
	cout<<"[신용신뢰계좌 개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>temID;
	cout<<"이름: ";
	cin>>tname;
	cout<<"입금액: ";
	cin>>tempbal;
	cout<<"이자율: ";
	cin>>tinterest; 
	cout<<"신용등급: ";
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

void AccountHandler::WithdrawAcc(void)
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

void AccountHandler::AllPrint(void)
{
	for(int i=0; i<accNum; i++)
	{
		accList[i]->ShowInfo();
	}
}


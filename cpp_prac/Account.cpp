#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int ID, String tname,int tBlance) : accID(ID), balance(tBlance)
{
	name=tname;
}

void Account::Insert(int money)
{
	if(money<0){
		DepositException expn(money);
		throw expn;
	}
	balance += money;
}

void Account::withdraw(int money)
{
	if(balance>=money)
	{
		balance -= money;
		cout<<"출금완료"<<endl;
	}else throw WithdrawException(balance);
}

int Account::GetID() const
{
	return accID;
}

void Account::ShowInfo() const
{
	cout<<accID<<endl;
	cout<<name<<endl;
	cout<<balance<<endl;
	cout<<endl;
}


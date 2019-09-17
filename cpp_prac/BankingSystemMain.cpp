#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "AccountException.h"

int main(void)
{
	AccountHandler manager;
	char select;
	while(1)
	{
		manager.ShowMenu();
		cout<<"¼±ÅÃ:";
		cin>>select;
		switch(select)
		{
			case '1':
				manager.MakeAccount();
				break;
			case '2':
				try
				{
					manager.DepositAcc();
				}	
				catch(DepositException& expn)
				{
					expn.ShowExceptionReason();
					manager.DepositAcc();
				}
				break;
			case '3':
				try
				{
					manager.WithdrawAcc();
				}
				catch(WithdrawException& expn)
				{
					expn.ShowExceptionReason();
					manager.WithdrawAcc();
				}
				break;
			case '4':
				manager.AllPrint();
				break;
			case '5':
				return 0;
		}
	}
}

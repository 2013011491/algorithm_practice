#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
	private :
		BoundCheckArray<Account*> accList;
		int accNum;
		
	public :
		AccountHandler();		
		~AccountHandler();
		
		void ShowMenu(void) const;
		void MakeAccount(void);
		void MakeNorm(void);
		void MakeHigh(void);
		void DepositAcc(void);
		void WithdrawAcc(void);
		void AllPrint(void);
};

#endif
 

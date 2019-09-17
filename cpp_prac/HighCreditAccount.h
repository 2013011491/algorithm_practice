#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "Account.h"
#include "String.h"

class HighCreditAccount : public Account
{
	private:
		int interest;
		int level;
		
	public:
		HighCreditAccount(int ID, String tname, int tBalance, int tinterest, int tlevel) : Account(ID, tname, tBalance), interest(tinterest), level(tlevel)
		{}
		
		void Insert(int money)
		{
			Account::Insert(money);
			Account::Insert((int)(money*((level+interest)/100.0)));
			cout<<"입금완료"<<endl;
		}
};

#endif

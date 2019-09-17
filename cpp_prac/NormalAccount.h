#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount : public Account
{
	private:
		int interest;
		
	public:
		NormalAccount(int ID, String tname,int tBlance, int tinterest) : Account(ID, tname, tBlance), interest(tinterest)
		{}
		
		void Insert(int money)
		{
			Account::Insert(money);
			Account::Insert((int)(money*(interest/100.0)));
			cout<<"입금완료"<<endl;
		}
};

#endif

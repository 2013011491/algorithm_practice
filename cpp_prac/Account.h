#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
	private :
		int accID;
		String name;
		int balance;
		
	public :
		Account(int ID, String tname, int tBlance);
		
		virtual void Insert(int money);
		void withdraw(int money);
		int GetID() const;
		void ShowInfo() const;
};

#endif


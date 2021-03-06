#ifndef __ACCOUNTEXCEPTION_H__
#define __ACCOUNTEXCEPTION_H__

class DepositException
{
	private:
		int reqDep;
		
	public:
		DepositException(int money) : reqDep(money)
		{ }
	
		void ShowExceptionReason()
		{
			cout<<"[예외 메시지: "<<reqDep<<"는 입금불가]"<<endl;
		}
};

class WithdrawException
{
	private:
		int balance;
	
	public:
		WithdrawException(int money) : balance(money)
		{ }
		
		void ShowExceptionReason()
		{
			cout<<"[예외 메시지: 잔액"<<balance<<", 잔액부족]"<<endl;
		}
};
#endif 

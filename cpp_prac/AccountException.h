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
			cout<<"[���� �޽���: "<<reqDep<<"�� �ԱݺҰ�]"<<endl;
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
			cout<<"[���� �޽���: �ܾ�"<<balance<<", �ܾ׺���]"<<endl;
		}
};
#endif 

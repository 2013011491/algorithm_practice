#include <iostream>

using namespace std;

typedef struct{
	int accID;
	char name[30];
	int balance;
}Acount;

Acount accList[30];
int accNum=0;
int main(void)
{
	char select;
	while(1){
		cout<<"----Menu----"<<endl;
		cout<<"1. 계좌개설"<<endl;
		cout<<"2. 입금"<<endl;
		cout<<"3. 출금"<<endl;
		cout<<"4. 계좌정보 전체 출력"<<endl;
		cout<<"5. 프로그램 종료"<<endl;
		cout<<"선택:";
		cin>>select;
		
		switch(select){
			case '1' :
				cout<<"게좌ID: ";
				cin>>accList[accNum].accID;
				cout<<"이름: ";
				cin>>accList[accNum].name;
				cout<<"입금액: ";
				cin>>accList[accNum].balance;
				accNum=accNum+1;
				break;
			case '2':
				int tempID;
				int inputM;
				cout<<"[입금]"<<endl;
				cout<<"게좌ID: ";
				cin>>tempID;
				int i;
				for(i=0; i<accNum; i++){
					if(accList[i].accID==tempID) break;
					else continue;
				}
				cout<<"입금액: ";
				cin>>inputM;
				if(i!=accNum){
					accList[i].balance+=inputM;
					cout<<"입금완료"<<endl;
				}
				else cout<<"존재 하지 않는 계좌"<<endl;
				break;
			case '3':
				cout<<"[출금]"<<endl;
				cout<<"게좌ID: ";
				cin>>tempID;
				for(i=0; i<accNum; i++){
					if(accList[i].accID==tempID) break;
					else continue;
				}
				cout<<"출금액: ";
				cin>>inputM;
				if(i==accNum) cout<<"존재 하지 않는 계좌"<<endl;
				else if(accList[i].balance>=inputM){
					accList[i].balance-=inputM;
					cout<<"출금완료"<<endl;
				}else cout<<"잔액부족"<<endl;
				break;
			case '4':
				for(int i=0; i<accNum; i++){
					cout<<accList[i].accID<<endl;
					cout<<accList[i].name<<endl;
					cout<<accList[i].balance<<endl;
					cout<<endl;
				}
				break;
			case '5':
				return 0;
		}
	}
	return 0;
}

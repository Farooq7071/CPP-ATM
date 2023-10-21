			// Program for ATM by Muhammad Farooq 19064 BSCS
#include <iostream>
#include <conio.h>
using namespace std;
class Bank{
	protected:
		string	Uname;
		int UPins;
		int UBalances;
	public:
		void add_acount(){
			cout<<"Enter your Name : ";
			cin.ignore(); getline(cin, Uname);
			cout<<"Enter Your Pin : ";
			cin>>UPins;
			cout<<"Enter  Balance : ";
			cin>>UBalances;
		}
		string get_name(){
			return Uname;
		}
		int get_pin(){
			return UPins;
		}
		int get_balance(){
			return UBalances;
		}
};

class ATM : public Bank{
		public:
			void welcome(){
				cout <<"\n                   "<<Uname;
				cout <<"\n                   WELCOME TO ATM.\n ";
			}
			int get_options(){
				int Option;
				cout <<"\n    PLEASE SELECT AN OPTION <1 - 4>.\n\n";
				cout <<"    1- Check Balance          2- Withdraw Balance\n";
				cout <<"    3- Send Money             4- Deposite Balance\n    ";
				cin>>Option;
				return Option;
			}
			void check_bal(){
				cout<<"    Your Balance is Rs."<<UBalances<<"\n";
			}
			void withdraw_bal(){
				int Withdraw_Amount; int Loop3=1;
			while (Loop3<4){
						cout <<"    Please Enter Amount for Withdraw: ";
						cin >> Withdraw_Amount;
						if (Withdraw_Amount <= UBalances && Withdraw_Amount > 0 && Withdraw_Amount % 500==0){
							UBalances = UBalances-Withdraw_Amount;
							cout <<"    You have successfully withdraw your Balance.\n";
							cout <<"    Your new Balance is Rs."<<UBalances;
							cout<<"\n          Thanks for Using ATM.     \n";
							Loop3=4;
						}
		    			else {
		    				cout <<"		Invalid Input.\n";
		    				Loop3++;
						}
				}
		}
			void send_money(){
					int Act_No, S_Amt;
					cout<<"    Enter Receiver Account Number:"; cin>>Act_No;
					cout<<"    Enter Amount to be send:"; cin>>S_Amt;
					cout<<"\n    You money has been send to the Entered Account.";
					UBalances = UBalances-S_Amt;
					cout<<"\n    Your New Balance is Rs."<<UBalances;
					cout<<"\n          Thanks for Using ATM.     \n";
		}
			void deposit_bal(){
				int DepAmt, DepAct;
				cout<<"    Enter Account Number from which you Deposite the Balance: ";cin>>DepAct;
				cout<<"    Enter the Amount to be Deposite: "; cin>>DepAmt;
				cout<<"\n    Your Amount is successfully Deposited"; UBalances = UBalances+DepAmt;
				cout<<"\n    You New Balance is Rs."<<UBalances;
				cout<<"\n          Thanks for Using ATM.     \n";
			}	
};

int main(){
	int N;  cout<<"Enter acount you want add: "; cin>>N;
	ATM Act[N];
	for(int i=0; i<N; i++){
		Act[i].add_acount();
		cout<<endl;
	}
	system("cls");
		string Name; int Uin =0;  bool More_Trans = true ;
		int Pin,    search_acct=0; 
		cout <<"\n             PAKISATAN ATM";
		cout <<"\nEnter Username: ";
		cin.ignore(); getline(cin, Name);
		cout <<"PLEASE ENTER YOUR PIN: "; cin>>Pin;
		
	while (Uin<2){	
		while (search_acct < N ){
			if(Name==Act[search_acct].get_name() && Pin==Act[search_acct].get_pin()){
				Act[search_acct].welcome();			
				while(More_Trans){
					int Option = Act[search_acct].get_options();
			
					if      (Option==1){
						Act[search_acct].check_bal();
					}
					else if (Option==2){
						Act[search_acct].withdraw_bal();
					}
					else if (Option==3){
						Act[search_acct].send_money();
					}
					else if (Option==4){		
						Act[search_acct].deposit_bal();
					}
				cout<<"\n    Do you want more Transection\n";
				cout<<"    [ 1 = Yes   &    0 = No ]\n    ";
				int mt;
				cin>>mt;
				if(mt<=0){
					More_Trans = false;
					search_acct = 5; Uin=3;
				}
			}
			}
			else {
				search_acct++;
			}
	    }
		   if (Uin!=2 && More_Trans){
			cout<<"\n       Invalid Input.       \n";
			cout<<"    Please Enter correct UserName and Password \n";
			cout <<"\nEnter Username: ";
			cin.ignore(); getline(cin, Name);
		    cout <<"PLEASE ENTER YOUR PIN: "; cin>>Pin;
		    search_acct=0; Uin++;
			}
	}
return 0;}


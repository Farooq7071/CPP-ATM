			// Program for ATM by Muhammad Farooq 19064 BSCS
#include <iostream>
using namespace std;
int main(){
	string Uname[5] = {"Muhammad_Farooq", "Azeem_Shakir", "Shoaib_Nazir", "Hamza_Haseeb", "Muhammad_Shakir"};
	int Loop1=0, 	UPins[5] = {19064, 20489, 16680, 19912, 19985}, 
				 	UBalances[5] = {150000, 120000, 200000, 100000, 130000};
	
	while (Loop1<=2 ){
		string Name; bool cond=true;
		int Pin, lop=0, Balance; 
		cout <<"\n             PAKISATAN ATM";
		cout <<"\nEnter Username: "; cin>>Name;
		cout <<"PLEASE ENTER YOUR PIN: "; cin>>Pin;
		while (lop<=4){
		if (Name==Uname[lop] && Pin==UPins[lop]){
			Balance=UBalances[lop];
			cout <<"\n                   "<<Uname[lop];
			cout <<"\n                   WELCOME TO ATM.\n ";
			string Loop2="Yes";
			while( Loop2=="Yes" || Loop2=="Yes" || Loop2=="yes" || Loop2=="1"){
			int Option;
			
			cout <<"\n    PLEASE SELECT AN OPTION <1 - 4>.\n\n";
			cout <<"    1- Check Balance          2- Withdraw Balance\n";
			cout <<"    3- Send Money             4- Deposite Balance\n    ";
			cin>>Option;
			
				if (Option==1){
					cout<<"Your Balance is Rs."<<Balance<<"\n";
					cout<<"Do you want more Transection: ";cin>>Loop2;
					Loop1=5;	
				}
			
				else if (Option==2){
					int Withdraw_Amount, New_Bal, Loop3=1;
					while (Loop3<4){
						cout <<"Please Enter Amount for Withdraw: ";
						cin >> Withdraw_Amount;
						if (Withdraw_Amount <= Balance && Withdraw_Amount > 0 && Withdraw_Amount % 500==0){
							Balance= Balance-Withdraw_Amount;
							cout <<"    You have successfully withdraw your Balance.\n";
							cout <<"    Your new Balance is Rs."<<Balance;
							cout<<"\n          Thanks for Using ATM.     \n";
							cout<<"Do you want more Transection: ";cin>>Loop2;
							Loop3=4;
						}
		    			else {
		    				cout <<"		Invalid Input.\n";
		    				Loop3++;
		    				Loop2="no";
						}
				}
					Loop1=5;
				}
				else if (Option==3){
					int Act_No, S_Amt;
				
					cout<<"Enter Receiver Account Number:"; cin>>Act_No;
					cout<<"Enter Amount to be send:"; cin>>S_Amt;
					cout<<"\n   You money has been send to the Entered Account.";
					Balance=Balance-S_Amt;
					cout<<"\n   Your New Balance is Rs."<<Balance;
					cout<<"\n          Thanks for Using ATM.     \n";
					cout<<"Do you want more Transection: ";cin>>Loop2; Loop1=5;
				}
		
				else if (Option==4){
					int DepAmt, DepAct;
				
					cout<<"Enter Account Number from which you Deposite the Balance: ";cin>>DepAct;
					cout<<"Enter the Amount to be Deposite: "; cin>>DepAmt;
					cout<<"\n   Your Amount is successfully Deposited"; Balance=Balance+DepAmt;
					cout<<"\n   You New Balance is Rs."<<Balance;
					cout<<"\n          Thanks for Using ATM.     \n";
					cout<<"Do you want more Transection: ";cin>>Loop2; Loop1=5;
				}
				else {
					cout<<"You have not select the given Option.\n";
					cout<<"Please select from the given Option."; Loop1=5;	
				}
			}
		cond=false;		
		}
		lop++;
		}
		
		if(lop==5 && cond){
		cout <<"          Invalid Username or PIN.\n";
    	Loop1++ ;
    	}
	}
	return 0;
}

			// Program for ATM by Muhammad Farooq 19064 BSCS
#include <iostream>
#include <ctime>
#include <conio.h>
#include "ATM_Welcome_Func.h"
using namespace std;

class Bank{
	protected:	string Uname; int ActNo; int UPins; int UBalances;
	public:    string AdActm; int Adbal; 	 	
		void add_acount(){
			cout<<"Enter your Name : ";	cin.ignore(); getline(cin, Uname);
			cout<<"Enter Your Account No : "; cin>>ActNo;
			cout<<"Enter Your Pin : "; cin>>UPins;
			cout<<"Enter  Balance : "; cin>>UBalances;	Adbal=UBalances;
			AdActm = getime(); }
		string get_name(){ return Uname; }
		int get_ActNo()  { return ActNo; }
		int get_pin()    { return UPins; }
		int get_balance(){ return UBalances; } };
class ATM : public Bank{
	public:
		int cnt1; ATM(){
		cnt1 = 0; }
		struct Mstm{
			string Func;	
			string Dtime;
			int p2_act;
			int dvbal;
			int newBal;
		};
		Mstm mst[1000];
	
		void check_bal(){ cout<<"    Your Balance is Rs."<<UBalances<<endl;
		mst[cnt1].Dtime = getime(); mst[cnt1].Func = "Bal Check.\n";
		mst[cnt1].newBal= UBalances;     cnt1++;
		}	
		void withdraw_bal(){
				int Withdraw_Amount; int Loop3=1;
				while (Loop3<4){
						cout <<"    Please Enter Amount for Withdraw: "; cin >> Withdraw_Amount;
						if (Withdraw_Amount <= UBalances && Withdraw_Amount > 0 && Withdraw_Amount % 500==0){
							UBalances = UBalances-Withdraw_Amount;
							cout <<"    You have successfully withdraw your Balance.\n";
							cout <<"    Your new Balance is Rs."<<UBalances;   
							mst[cnt1].dvbal= Withdraw_Amount;  mst[cnt1].Dtime = getime();
							mst[cnt1].newBal= UBalances;  mst[cnt1].Func = "Bal Withdraw.\n"; cnt1++;
							cout<<"\n          Thanks for Using ATM.     \n";	Loop3=4; }
		    			else { cout <<"		Invalid Input.\n"; Loop3++; }
					} 
				}
		void send_money(ATM Actc[], int N){
					int Act_No, S_Amt; int L1=0; int T1=0;
					while (T1<3) {
					cout<<"    Enter Receiver Account Number:"; cin>>Act_No;
					cout<<"    Enter Amount to be send:"; cin>>S_Amt;
					while ( L1<N ){
						if (Act_No==Actc[L1].ActNo && S_Amt<=UBalances && S_Amt > 0){
							cout<<"\n    You money has been send to the Entered Account.";
							UBalances = UBalances-S_Amt;  
							cout<<"\n    Your New Balance is Rs."<<UBalances;
							cout<<"\n          Thanks for Using ATM.     \n\n"; cout<<"The Value of : "<<Actc[L1].cnt1<<endl;
							mst[cnt1].dvbal= S_Amt;  mst[cnt1].Dtime = getime(); mst[cnt1].Func = "Send Money.\n";
							mst[cnt1].newBal= UBalances;    mst[cnt1].p2_act = Act_No;  cnt1++;
							Actc[L1].UBalances = Actc[L1].UBalances + S_Amt;  T1=3;
							Actc[L1].mst[Actc[L1].cnt1].dvbal= S_Amt;  Actc[L1].mst[Actc[L1].cnt1].Dtime = getime(); Actc[L1].mst[Actc[L1].cnt1].Func = "Deposited Money From.\n";
							Actc[L1].mst[Actc[L1].cnt1].newBal= Actc[L1].UBalances;  Actc[L1].mst[Actc[L1].cnt1].p2_act =  ActNo;  Actc[L1].cnt1++; L1=N;
						}
						else {	L1++;	}	
						}
					if (L1==(N) && T1<2){
							cout<<"Please Enter correct Data.\n"; L1=0; T1++;
					}
					else {	T1++; }
						}
					}
		void deposit_bal(ATM Actc[], int N){
				int DepAmt, DepAct, DAP;int L2=0; int T2=0;
				while (T2<3) {
				cout<<"    Enter the Amount to be Deposite: "; cin>>DepAmt;
				cout<<"    Enter Account Number from which you Deposite the Balance: ";cin>>DepAct;
				cout<<"    Enter the Pin of Deposited Account: "; cin>>DAP;
					while ( L2<N ){
						if (DepAct==Actc[L2].ActNo && DAP==Actc[L2].UPins && DepAmt<=Actc[L2].UBalances && DepAmt > 0 ){
							cout<<"\n    Your Amount is successfully Deposited"; UBalances = UBalances+DepAmt;
							cout<<"\n    You New Balance is Rs."<<UBalances; cout<<"The Value of : "<<Actc[L2].cnt1<<endl;
							mst[cnt1].dvbal= DepAmt;  mst[cnt1].Dtime = getime();   mst[cnt1].Func = "Deposited Money.\n";
							mst[cnt1].newBal= UBalances;    mst[cnt1].p2_act = DepAct;  cnt1++;
							Actc[L2].UBalances = Actc[L2].UBalances - DepAmt;  T2=3;
							Actc[L2].mst[Actc[L2].cnt1].dvbal= DepAmt;  Actc[L2].mst[Actc[L2].cnt1].Dtime = getime(); Actc[L2].mst[Actc[L2].cnt1].Func = "Send Money To.\n";
							Actc[L2].mst[Actc[L2].cnt1].newBal= Actc[L2].UBalances;  Actc[L2].mst[Actc[L2].cnt1].p2_act =  ActNo;  Actc[L2].cnt1++; L2=N;
							cout<<"\n          Thanks for Using ATM.     \n\n";}					
						else {	L2++;		}
					}
					if (L2==N && T2<2)	{
						cout<<"Please Enter correct Data.\n"; L2=0; T2++;	}
					else {T2++;}							 
				}}
		int Mrop()	{
			cout<<"\n    Select The Option.\n";
				cout<<"      0 - Terminate \n";
				cout<<"      1 - More Transections.\n";
				cout<<"      2 - Logout.\n";
				int mop; cin>>mop;
			return mop;}	
};

int main(){
	int N;    cout<<"        Pakistan ATM    \n"; cout<<"   How many Accounts: ";cin>>N; ATM Acts;
	ATM* Act = new ATM[1000];  	    for(int i=0; i<N; i++){ Act[i].add_acount();cout<<endl; }																			
																							//cout<<"Balance : "<<Act->Adbal;
	int AcN; int Uin =0, Pin,  Opt;  
		    cout <<"\n             PAKISATAN ATM";
		while (Uin<3){
			cout <<"\n              User Login: ";
			cout <<"\n   Enter Account No: "; cin>>AcN;  
			cout <<"   PLEASE ENTER YOUR PIN: "; cin>>Pin; int srh_act=0; bool srh=true;
			while( srh_act < N && srh){
				if (AcN==Act[srh_act].get_ActNo() && Pin==Act[srh_act].get_pin()){
					welcome(Act[srh_act].get_name());
					 int mop; bool Gop=true, mp=false;
					while(Gop || mp){
						Opt=get_options();
						if (Opt==1){ 
							Act[srh_act].check_bal(); Gop=false; 
							//cout<<"Time : "<<Act[srh_act].cnt1<<"\n"<<Act[srh_act].mst[Act[srh_act].cnt1].Dtime<<endl;
						}
						else if (Opt==2){						
							Act[srh_act].withdraw_bal(); Gop=false;
						}
						else if (Opt==3){						
							Act[srh_act].send_money(Act, N); Gop=false;
						}
						else if (Opt==4){						
							Act[srh_act].deposit_bal(Act, N); Gop=false;
						}
						else if (Opt==5){
						
							cout<<"Statement : \n";						
							for (int i=0; i<Act[srh_act].cnt1; i++){
								cout<<"Operation : "<<Act[srh_act].mst[i].Func;
								cout<<"D&T : "<<Act[srh_act].mst[i].Dtime;
								cout<<"2nd Person Act_No : "<<Act[srh_act].mst[i].p2_act<<endl;
								cout<<"Amount : "<<Act[srh_act].mst[i].dvbal<<endl;
								cout<<"New Bal : "<<Act[srh_act].mst[i].newBal<<endl<<endl;
							}
							
							Gop=false;
						}
						else if (Opt==6){	
												
							Act[N].add_acount(); N=N+1;  Gop=mp=false;
						}
						else {
							cout<<"   Please select from Given Options.";
						}
					
						mop=Act[srh_act].Mrop();
						if (mop<=0 || mop > 2){
							Uin=3; srh=false; Gop=mp=false; 
						}
						else if (mop==1){
							 mp=true;
						}
						else if (mop==2){
							Uin=0; srh=Gop=mp=false; 
						}
					}
				}
				else{
					srh_act++;
				}				
			}
			Uin++;
		}
}

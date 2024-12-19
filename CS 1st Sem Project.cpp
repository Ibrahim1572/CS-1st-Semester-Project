#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void login_register()
{
	int user_type;
	cout<<"Enter number according to your role:\n1 for User\n2 for Restruant Manager\n3 for Owner\n4 To exit"<<endl;
	cin>>user_type;
	
	if(user_type>4||user_type<1)
	{
		cout<<"enter number of valid role"<<endl;
		cout<<"---------------------------------------------------------------------------------------"<<endl;
		login_register();
	}
	
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	
	if(user_type==1)
		login_user();
	else if(user_type==2)
		login_manager();
	else if(user_type==3)
		login_owner();
	else if(user_type==4)
		exit(0);

}


void login_user()
{
	int acc_type;
	cout<<"Enetr 1 to Login to Existing accout\nEnetr 2 to Register as a new user"<<endl;
	cin>>acc_type;
	
	if(acc_type==1)
	{
		string iAcc, iPass;
		cout<<"Enetr user name: ";
		cin>>iAcc;
		cout<<"Enter password: ";
		cin>>iPass;
		
		fstream user_accounts;
		string acc, pass;
		user_accounts.open("user_accounts.txt");
		while(getline(user_accounts, acc))
		{
			if(acc==iAcc)
			{
				getline(user_accounts, acc);
				if(acc==iPass)
				{
					cout<<"Login Successful"<<endl;
					break;
				}
				else
				{
					cout<<"Invalid password"<<endl;
					cout<<"---------------------------------------------------------------------------------------"<<endl;
					login_user();
				}
				
			}
			else
				{
					cout<<"Invalid username"<<endl;
					cout<<"---------------------------------------------------------------------------------------"<<endl;
					login_user();
				}
			

		}
		cout<<"---------------------------------------------------------------------------------------"<<endl;
	}
	else if(acc_type==2)
	{
		string iAcc, iPass;
		cout<<"Enetr user name: ";
		cin>>iAcc;
		
		fstream user_accounts;
		string acc, pass;
		user_accounts.open("user_accounts.txt");
		while(getline(user_accounts, acc))
		{
			if(acc==iAcc)
			{
				cout<<"Username already taken"<<endl;
				cout<<"---------------------------------------------------------------------------------------"<<endl;
				login_user();
				
			}
			else 
			{
				cout<<"Enter password: ";
				cin>>iPass;
				
				user_accounts.seekg(0, ios::end);
				user_accounts<<iAcc<<endl;
				user_accounts<<iPass<<endl;
				user_accounts.close();
				
				cout<<"Your account is registered and now you can login"<<endl;
				cout<<"---------------------------------------------------------------------------------------"<<endl;
				login_user();
			}
		}
	}
}

int main(){
	cout<<"Semester Project";
	login_register();
	return 0;
}

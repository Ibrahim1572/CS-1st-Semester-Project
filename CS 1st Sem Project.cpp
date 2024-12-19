#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void menu_edit(int res_num);
void login_register();
void login_user();
void login_manager();
void login_owner();
void menu_display();

//void menu_edit()
//{
//	
//}

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

void login_manager()
{
	int acc_type;
	cout<<"Enetr 1 to Login to Existing restraunt\nEnetr 2 to Register a new restraunt"<<endl;
	cin>>acc_type;
	
	if(acc_type==1)
	{
		string iAcc, iPass;
		cout<<"Enetr restraunt name: ";
		cin>>iAcc;
		cout<<"Enter password: ";
		cin>>iPass;
		
		fstream restraunts;
		string acc, pass;
		restraunts.open("restraunts.txt");
		while(getline(restraunts, acc))
		{
			if(acc==iAcc)
			{
				getline(restraunts, acc);
				if(acc==iPass)
				{
					cout<<"Login Successful"<<endl;
					break;
				}
				else
				{
					cout<<"Invalid password"<<endl;
					cout<<"---------------------------------------------------------------------------------------"<<endl;
					login_manager();
				}
			}
			else
				{
					cout<<"Invalid restraunt name"<<endl;
					cout<<"---------------------------------------------------------------------------------------"<<endl;
					login_user();
				}
			

		}
		cout<<"---------------------------------------------------------------------------------------"<<endl;
	}
	else if(acc_type==2)
	{
		string iAcc, iPass;
		cout<<"Enetr restraunt name: ";
		cin>>iAcc;
		
		fstream restraunts;
		string acc, pass;
		restraunts.open("restraunts.txt");
		while(getline(restraunts, acc))
		{
			if(acc==iAcc)
			{
				cout<<"restraunt name already taken"<<endl;
				cout<<"---------------------------------------------------------------------------------------"<<endl;
				login_manager();
				
			}
			else 
			{
				cout<<"Enter password: ";
				cin>>iPass;
				
				restraunts.seekg(0, ios::end);
				restraunts<<iAcc<<endl;
				restraunts<<iPass<<endl;
				restraunts.close();
				
				cout<<"Your restraunt is registered and now you can login"<<endl;
				cout<<"---------------------------------------------------------------------------------------"<<endl;
				login_manager();
			}
		}
	}
	
	

	
}

void login_owner()
{
	string iAcc, iPass;
		cout<<"Enetr owner user name: ";
		cin>>iAcc;
		cout<<"Enter password: ";
		cin>>iPass;
		
		fstream owner;
		string acc, pass;
		owner.open("owner.txt");
		while(getline(owner, acc))
		{
			if(acc==iAcc)
			{
				getline(owner, acc);
				if(acc==iPass)
				{
					cout<<"Login Successful"<<endl;
					break;
				}
				else
				{
					cout<<"Invalid password"<<endl;
					cout<<"---------------------------------------------------------------------------------------"<<endl;
					login_owner();
				}
			}
			else
				{
					cout<<"Invalid owner username"<<endl;
					cout<<"---------------------------------------------------------------------------------------"<<endl;
					login_user();
				}
			

		}
		cout<<"---------------------------------------------------------------------------------------"<<endl;
		
}

void menu_display()
{
	cout<<"Enter restraunt number"<<endl;
	
	fstream res_name;
	string name;
	int counter=1, res_num;
	res_name.open("res_name.txt");
	while(getline(res_name, name))
	{
		cout<<counter<<"\t"<<name<<endl;
		counter++;
	}
	
	cin>>res_num;
	
	fstream res_item;
	res_item.open("res_items.txt");
	string item;
	
	if(res_num==1)
	{
		int counter=1;
		
		while(getline(res_item, item))
		{
			if(item=="2")
				break;
			else
			{
				cout<<counter<<"\t"<<setw(15)<<item;
				getline(res_item, item);
				cout<<setw(10)<<item<<endl;
				counter++;
			}
		}
	}
	else if(res_num==2)
	{
		int counter=1;
		
		while(true)
		{
			getline(res_item, item);
			if(item=="2")
			{
				while(getline(res_item, item))
				{
					cout<<counter<<"\t"<<setw(15)<<item;
					getline(res_item, item);
					cout<<setw(10)<<item<<endl;
					counter++;
			}
			}else if(item=="3")
				break;
		}
	}
	
}

int main()
{
	login_register();
	
	menu_display();
	
//	fstream order;
//	order.open("order.txt", ofstream::out | ofstream::trunc);
//	order.close();

	return 0;
}


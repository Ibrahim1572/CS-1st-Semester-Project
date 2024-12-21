#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void opt_menu();
void menu_edit(int res_num);
void login_register();
void login_user();
void login_manager();
void login_owner();
void menu_display();
void res_edit();
void order(int res_num, int it_num);

//void menu_edit()
//{
//	
//}

void order(int res_num, int it_num)
{
	
	string ord, item;
	fstream res_item;
	res_item.open("res_item.txt");
	fstream order;
	order.open("order.txt", ios::app);
	
	string marker="*", next_marker;
	
	for(int i=1; i<res_num; i++)
	{
		marker=marker+"*";
	}
	next_marker=marker+"*";
	
	while(getline(res_item, item))
	{
		
		if(item==marker)
		{
			for(int i=1; i<=it_num; i++)
			{
				
				if(i==it_num)
				{
					getline(res_item, item);
					order<<item<<endl;
					getline(res_item, item);
					order<<item<<endl;
				}
				getline(res_item, item);
				getline(res_item, item);
			}
		}
	}
//	while(getline(res_item, item))
//	{
//		if(item==&r_num)
//	}
	opt_menu();
	
}

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
		bool flag=0;
		while(getline(user_accounts, acc))
		{
			
			if(acc==iAcc)
			{
				getline(user_accounts, acc);
				if(acc==iPass)
				{
					cout<<"Login Successful"<<endl;
					flag=1;
					break;
				}
//				else
//				{
//					cout<<"Invalid password"<<endl;
//					cout<<"---------------------------------------------------------------------------------------"<<endl;
//					login_user();
//				}
				
			}
//			else
//				{
//					cout<<"Invalid username"<<endl;
//					cout<<"---------------------------------------------------------------------------------------"<<endl;
//					login_user();
//				}
			

		}
		if(flag==0)
		{
			cout<<"Invalid username or password "<<endl;
			cout<<"---------------------------------------------------------------------------------------"<<endl;
			login_user();
		}
		
			
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
		bool flag=0;
		while(getline(restraunts, acc))
		{
			if(acc==iAcc)
			{
				getline(restraunts, acc);
				if(acc==iPass)
				{
					cout<<"Login Successful"<<endl;
					flag=1;
					break;
				}
//				else
//				{
//					cout<<"Invalid password"<<endl;
//					cout<<"---------------------------------------------------------------------------------------"<<endl;
//					login_manager();
//				}
			}
//			else
//				{
//					cout<<"Invalid restraunt name"<<endl;
//					cout<<"---------------------------------------------------------------------------------------"<<endl;
//					login_user();
//				}
			

		}
		if(flag==0)
		{
			cout<<"Invalid username or password "<<endl;
			cout<<"---------------------------------------------------------------------------------------"<<endl;
			login_user();
		}
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
	bool flag=0;
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
					flag=1;
					break;
				}
//				else
//				{
//					cout<<"Invalid password"<<endl;
//					cout<<"---------------------------------------------------------------------------------------"<<endl;
//					login_owner();
//				}
			}
//			else
//				{
//					cout<<"Invalid owner username"<<endl;
//					cout<<"---------------------------------------------------------------------------------------"<<endl;
//					login_user();
//				}
			

		}
		if(flag==0)
		{
			cout<<"Invalid username or password "<<endl;
			cout<<"---------------------------------------------------------------------------------------"<<endl;
			login_user();
		}
//		
}

void menu_display() {
    cout << "Enter restaurant number:" << endl;
				
    fstream res_name;
    string name;
    int counter = 1, res_num;
			
    // Display restaurant names
    res_name.open("res_name.txt");
    while (getline(res_name, name)) {
        cout << counter << "\t" << name << endl;
        counter++;
    }		
    res_name.close();
			
    cin >> res_num;
    if (res_num < 1 || res_num > 4) {
    cout << "Invalid restaurant number!" << endl;
    return; // Exit the function
}			
			
			
    fstream res_items;
    res_items.open("res_items.txt");
    string item;
    string marker,next_marker;
    marker="*";
	for(int i=1;i<res_num;i++){
		marker=marker+"*";
	}				
	next_marker= marker+"*";
//		if (res_num == 1){
//		marker = "*";
//		next_marker="**";
//	} 			
//	else if(res_num==2){
//		marker = "**";
//		next_marker ="***";}
//	else if(res_num ==3 ){
//		marker = "***";
//		next_marker= "****"; }
//	else{		
//	cout<<"Invalid restuarant number!"<<endl;
//	}			
//				
    // Skip to the selected restaurant menu
    while (getline(res_items, item)) {
        if (item == marker) {
            break;
        }
    }

    // Display the menu 
    counter = 1;
    cout<<"\n \t Menu \n";
    while (getline(res_items, item)) {
        if (item == next_marker) {
            break;
			}
        cout  <<counter << "\t" << left << setw(20) << item; // Print  name
        if (getline(res_items, item)) { // Print price
            cout <<right << setw(10) << item << endl;
        }	
        counter++;
    //    cout<<seekg();
    }
	int it_num;
	cin>>it_num;
    res_items.close();
    order(res_num, it_num);
    
}

}
int main()
{
//	login_register();
	fstream order;
	order.open("order.txt", ofstream::out | ofstream::trunc);
	order.close();
	
	menu_display();
	


	return 0;
}

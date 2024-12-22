#include<iostream>	//standard
#include<fstream>	//for file handaling
#include<string>//for strings
#include <cstring>
#include<iomanip>//for formatting and spaces
#include<sstream>//to convert string to int
#include <vector>// to include vectors
#include<limits>//used  to overcome errors in input of strings when there are spaces involved
using namespace std;

void payment_delivery();
void bill_calc();	
void opt_menu();	
void menu_edit();
void login_register();
void login_user();
void login_manager();
void login_owner();
void menu_display();
void res_edit();
void it_search();

void it_search()
{
    fstream res_items;
    res_items.open("res_items.txt", ios::in);

    if (!res_items) {
        cout << "\033[1;31mError: Unable to open the file!\033[0m" << endl;
        return;
    }

    ofstream outFile("temp.txt", ios::out);

    if (!outFile) {
        cout << "\033[1;31mError: Unable to create a temporary file!\033[0m" << endl;
        res_items.close();
        return;
    }

    char del_item[100];  // Array to store the item to be deleted
    cout << "\033[1;34mWhich item do you want to remove:\033[0m" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(del_item, 100);

    char item[100];  // Array to store each line read from the file

    while (res_items.getline(item, 100)) {
        
        if (strcmp(item, del_item) != 0) {
            outFile << item << endl;
        } else {
            // Skip the next line 
            res_items.getline(item, 100);
        }
    }

    res_items.close();
    outFile.close();

    remove("res_items.txt");
    rename("temp.txt", "res_items.txt");
    cout << "\033[1;31mItem successfully removed\033[0m" << endl;

    cout << "\033[1;34mIf you want to edit more, enter 1\nIf you want to exit, enter any other number:\033[0m" << endl;
    int opt;
    cin >> opt;
    if (opt == 1) {
        menu_edit();
    } else {
        exit(0);
    }
}

void bill_calc()
{
	fstream order;
	string item;
	order.open("order.txt");
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	
	int sum=0, counter =1, num;
	
	while(getline(order, item))
	{
		cout  <<counter << "\t" << left << setw(20) << item; // Print  name
        if (getline(order, item)) { // Print price
            cout <<right << setw(10) << item << endl;
            stringstream ss(item);
    			ss >> num;
    			sum=sum+num;
            
        }	
        counter++;
	}
	cout<<"\033[1;31mTotal is:\033[0m "<<sum<<endl;
	payment_delivery();
}

void menu_edit() 
{
    while (true) 
	{ // Loop to handle repeated edits
        cout << "\033[1;34mEnter restaurant number:\033[0m" << endl;

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
            cout << "\033[1;31mInvalid restaurant number!\033[0m" << endl;
            return; // Exit the function
        }

        // Open the menu file 
        fstream res_items("res_items.txt", ios::in);
        vector<string> file_content;
        string item, marker = "*";

        for (int i = 1; i < res_num; i++) {
            marker += "*";
        }

        // Read file content into a vector
        while (getline(res_items, item)) {
            file_content.push_back(item);
        }
        res_items.close();

        // Locate the marker 
        int insert_position = -1;
        for (int i = 0; i < file_content.size(); i++) {
            if (file_content[i] == marker) {
                insert_position = i + 1;
                break;
            }
        }

        if (insert_position == -1) {
            cout << "\033[1;31mError: Restaurant marker not found!\033[0m" << endl;
            return;
        }
		int opt;
		cout<<"\033[1;34mIf you want to add anything enter 1\nIf you want to remove anything enter 2\033[0m"<<endl;
		cin>>opt;
		if(opt==2)
		{
			it_search();
		}
        else if(opt==1)
        {
        	// Get new menu item at the correct position
        cout << "\033[1;34m\nWhich dish do you want to enter?\033[0m\n";
        string edit;
        cin.ignore();
        getline(cin, edit);
        
        cout << "\033[1;34mEnter the price of the dish:\033[0m\n";
        string dish_price;
        cin >> dish_price;

        // Insert the new dish name and price into the vector
        file_content.insert(file_content.begin() + insert_position, edit); 
        file_content.insert(file_content.begin() + insert_position + 1, dish_price); 
        
        // Write updated content back to the file
        ofstream menu_edit("res_items.txt", ios::out | ios::trunc);
        for (size_t i = 0; i < file_content.size(); i++) {
            menu_edit << file_content[i];
            if (i < file_content.size() - 1) { 
                menu_edit << endl; 
            }
        }
        menu_edit.close();

        cout << "\033[1;34m\nDish added successfully\n\033[1;34mIf you want to edit more, enter 1\nIf you want to exit, enter any other number:\033[0m" << endl;
        int opt;
        cin >> opt;
        if (opt != 1) { // Exit the loop if the user doesn't enter 1
            exit(0);
        }
		}
		else
		{
			cout<<"\033[1;31mEnter valid option\033[0m"<<endl;
			menu_edit();
		}
    }
}

void payment_delivery()
{
	cout<<"\033[1;34m\nSelect payment option:\n1 for debit card\n2 for cash on delivery\033[0m"<<endl;
	cin.ignore();
	int opt;
	string card[4];
	cin>>opt;
	if(opt==1)
	{
		cout<<"\033[1;34mEnter cardholder name:\033[0m"<<endl;
		getline(cin, card[0]);
		cout<<"\033[1;34mEnter card number (XXXX-XXXX-XXXX-XXXX):\033[0m"<<endl;
		getline(cin, card[1]);
		cout<<"\033[1;34mEnter cvv:\033[0m"<<endl;
		getline(cin, card[2]);
		cout<<"\033[1;34mEnter card expiry (MM-YYYY):\033[0m"<<endl;
		getline(cin, card[3]);
	}
	else if(opt<1||opt>2)
	{
		cout<<"\033[1;31mEnter valid option\033[0m"<<endl;
		payment_delivery();
	}
	cin.ignore();
	string address, zip, city, name;
	cout<<"\033[1;34m\n Enter your name:\033[0m"<<endl;
	getline(cin, name);
	cout<<"\033[1;34m\n Enter your delivery address:\033[0m"<<endl;
	getline(cin, address);
	cout<<"\033[1;34m\n Enter your city:\033[0m"<<endl;
	getline(cin, city);
	
	cout<<"\033[1;31m\n\nYour order has been confirmed\nIt will be delivered within 45 min\nThank you for ordering\033[0m"<<endl;
}

void opt_menu()
{
	int opt; 
	cout<<"\033[1;34mIf you want to order anything else enter 1\nIf you want to check out press 2\033[0m"<<endl;
	cin>>opt;
	if(opt==1)
	{
		menu_display();
	}
	else if(opt==2)
		bill_calc();
	else
		opt_menu();
}
void order(int res_num, int it_num)
{

	string ord, item;
	fstream res_item;
	res_item.open("res_items.txt");
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
		cout<<"Enter number of valid role"<<endl;
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
	cout<<"Enter 1 to Login to Existing accout\nEnetr 2 to Register as a new user"<<endl;
	cin>>acc_type;
	
	if(acc_type==1)
	{
		string iAcc, iPass;
		cout<<"Enter user name: ";
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
		menu_display();
			
	}
	else if(acc_type==2)
	{
		string iAcc, iPass;
		cout<<"Enter user name: ";
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
	else
		{
			login_register();
		}
	

	
}

void login_manager()
{
	int acc_type;
	cout<<"Enter 1 to Login to Existing restraunt\nEnetr 2 to Register a new restraunt"<<endl;
	cin>>acc_type;
	
	if(acc_type==1)
	{
		string iAcc, iPass;
		cout<<"Enter restraunt name: ";
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
		menu_edit();
	}
	else if(acc_type==2)
	{
		string iAcc, iPass;
		cout<<"Enter restraunt name: ";
		cin>>iAcc;
		
		fstream restraunts;
		string acc, pass;
		restraunts.open("restraunts.txt");
		while(getline(restraunts, acc))
		{
			if(acc==iAcc)
			{
				cout<<"Restraunt name already taken"<<endl;
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
	
	else
		{
			login_register();
		}

	
}

void login_owner()
{
	string iAcc, iPass;
		cout<<"Enter owner user name: ";
		cin>>iAcc;
		cout<<"Enter password: ";
		cin>>iPass;
		bool flag=0;
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
		cout<<"enetr 1 for ordering food\n2 for restraunt edit"<<endl;
		int opt;
		cin>>opt;
		if(opt==1)
		{
			menu_display();
		}
		else
		{
			exit(0);
		}
		
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
    system(" ");
    cout<<"\n \t \033[1;31m Menu\033[0m \n";
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

int main()
{
	system(" ");
	cout << "\033[1;31mFood Delivery App\033[0m" << endl;
	fstream order;
	order.open("order.txt", ofstream::out | ofstream::trunc);
	order.close();
	
	login_register();
	
//	menu_display();
  
//	it_search();

	return 0;
}

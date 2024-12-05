#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	string x;
	fstream menu;
	menu.open("Menu1.txt");
	for(int i=0; i<12; i++)
	{
		menu>>x;
		cout<<x<<"\t";
		if((i+1)%3==0)
			cout<<endl;
	}
	return 0;
}

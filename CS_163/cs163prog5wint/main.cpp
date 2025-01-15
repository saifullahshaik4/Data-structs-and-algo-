#include "list.h"

using namespace std;

//Saifullah Shaik, CS163, 03/20/23
//this is where I get the info from the user and call the functions and pass the info in.

int main()
{
	table my_table;
	baking to_add;
	char copy_bakingstep[SIZE];	
	char copy_attach[SIZE];
	bool stop = true;
	char option = ' ';
	while(stop)
	{
		cout<<"Please choose what to do"<<endl;
		cout<<"1.Add a baking step"<<endl<<"2.Connect with previously added baking step"<<endl<<"3.Display list"<<endl<<"4.Quit"<<endl;
		cin >> option;
		cin.ignore(100, '\n');
		switch(option)
		{
			case'1':
				cout<<"Please enter your baking step "<<endl;
				cin.get(copy_bakingstep, SIZE, '\n');
				cin.ignore(100, '\n');
				to_add.create(copy_bakingstep);
				my_table.add_vertex(to_add);
				break;
			case'2':
				cout<<"Please enter your baking step  "<<endl;
				cin.get(copy_bakingstep, SIZE, '\n');
				cin.ignore(100, '\n');
				cout<<"Please enter your baking step"<<endl;
				cin.get(copy_attach, SIZE, '\n');
				cin.ignore(100, '\n');
				my_table.add_edge(copy_bakingstep, copy_attach);
				break;
			case'3':
				my_table.display_adj_path();
				break;
			case'4':
				stop = false;
				break;


		}


	}	




	return 0;
}

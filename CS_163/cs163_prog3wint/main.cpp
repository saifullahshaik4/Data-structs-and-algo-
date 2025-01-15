#include "table.h"

using namespace std;
//Saifullah Shaik 2/21/23 


int main()
{
	table my_table;//object from my table class 
	characters to_add;//the object for the keyword hash table;
	characters to_add2;//the object for the species hash table
	characters results[SIZE];//the array of items that I will copy into from the hash table
	//these are the arrays I pass into my functions that I get from the user
	char copy_name[SIZE];
	char copy_pow[SIZE];
	char copy_species[SIZE];
	char copy_bio[SIZE];
	char copy_keyword[SIZE];
	bool stop = true;//stopping condition for my loop
	char option = ' ';//user option
	int results_size = 0;//size of the array that I use for the retrieve function
	//the menu
	while(stop == true)
	{
		cout<<"Please choose what you would like to do"<<endl;
		cout<<"1.Add a character"<<endl<<"2.Load info"<<endl<<"3.Display keyword"<<endl<<"4.Retrieve keyword"<<endl
			<<"5.Remove by keyword"<<endl<<"6.Display species"<<endl<<"7.Display all"<<endl<<"8.Quit"<<endl;
		cin >> option;
		cin.ignore(100,'\n');
		switch(option)
		{
			case'1':cout<<"Please enter the name of the characetr"<<endl;
				cin.get(copy_name,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the Power and Ability"<<endl;
				cin.get(copy_pow,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the Species"<<endl;
				cin.get(copy_species,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the description/bio of the character"<<endl;
				cin.get(copy_bio,SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the keyword of the character"<<endl;
				cin.get(copy_keyword,SIZE,'\n');
				cin.ignore(100,'\n');

				to_add.create_character(copy_name,copy_pow,copy_species,copy_bio,copy_keyword);
				my_table.add_character(to_add, copy_keyword, copy_species); 
				break;

			case'2':my_table.load_character();
				break;

			case'3':cout<<"Please enter the keyword of the character"<<endl;
				cin.get(copy_keyword,SIZE,'\n');
				cin.ignore(100,'\n');
				my_table.display_key(copy_keyword);
				break;
			
			case'4':cout<<"Please enter the keyword of the character"<<endl;
				cin.get(copy_keyword,SIZE,'\n');
				cin.ignore(100,'\n');
				results_size = my_table.retrieve_key(copy_keyword, results, SIZE);
				my_table.display_results(results, results_size);
				break;

			case'5':cout<<"Please enter the keyword of the character"<<endl;
				cin.get(copy_keyword,SIZE,'\n');
				cin.ignore(100,'\n');
				my_table.remove_key(copy_keyword);
				break;
			case'6':cout<<"Please enter the species of the character"<<endl;
				cin.get(copy_species,SIZE,'\n');
				cin.ignore(100,'\n');
				my_table.display_species(copy_species);
				break;
			case'7':my_table.display_all();
				break;
				
			case'8':stop = false;
				break;

		}

	}
	return 0;
}





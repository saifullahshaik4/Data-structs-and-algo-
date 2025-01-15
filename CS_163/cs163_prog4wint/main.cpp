//Saifullah Shaik

#include "bst.h"

using namespace std;


int main()
{
	bst my_bst;
	superheros to_add;
	char copy_name[SIZE];
	char copy_pow[SIZE];
	char copy_species[SIZE];
	char copy_bio[SIZE];
	char copy_keyword[SIZE];
	bool stop = true;
	char option = ' ';
	while(stop)
	{
		cout<<"Please choose what you would like to do" <<endl;
		cout<<"1.Add a superhero"<<endl<<"2.Display all"<<endl<<"3.Display of a certain power"<<endl<<"4.Retreive name and species"
		    <<endl<<"5.Remove by power"<<endl<<"6.Display by Size"<<endl<<"7.Quit"<<endl;
		cin >> option;
		cin.ignore(100,'\n');
		switch(option)
		{
			case'1':cout<<"Please enter the name of the superhero"<<endl;
				cin.get(copy_name, SIZE,'\n');
				cin.ignore(100,'\n');
				cout<<"Please enter the power of the superhero"<<endl;
				cin.get(copy_pow, SIZE,'\n');
				cin.ignore(100, '\n');
				cout<<"Please enter the species of the superhero"<<endl;
				cin.get(copy_species, SIZE,'\n');
				cin.ignore(100, '\n');
				cout<<"Please enter the description of the superhero"<<endl;
				cin.get(copy_bio, SIZE,'\n');
				cin.ignore(100, '\n');
				cout<<"Please enter the keyword of the superhero"<<endl;
				cin.get(copy_keyword, SIZE,'\n');
				cin.ignore(100, '\n');
				to_add.create_superhero(copy_name,copy_pow,copy_species,copy_bio,copy_keyword);
				my_bst.add_superhero(to_add);
				break;
			case'2':my_bst.display_all();
				break;
			case'7':stop = false;
				break;
			
		}	



	}


	return 0;
}

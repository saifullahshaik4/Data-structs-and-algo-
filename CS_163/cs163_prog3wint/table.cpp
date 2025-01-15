#include "table.h"

using namespace std;

//Saifullah Shaik, CS163, 2/21/23, This is where I implement the functions from my table and term class.

//table constructor
table::table(int size)
{
	hash_size = size;
	hash_table = new node * [hash_size];
	hash_table2 = new node * [hash_size];
	for(int i = 0; i < hash_size; ++i)
	{
		hash_table[i] = nullptr;
		hash_table2[i] = nullptr;

	}


}
//table destructor
table::~table()
{
	for(int i = 0; i < hash_size; ++i)
	{
		destructor(hash_table[i]);
		destructor2(hash_table2[i]);
	}
	delete [] hash_table;
	delete [] hash_table2;
	hash_table = nullptr;
	hash_table2 = nullptr;

}

//these two functions destroy the LLL that each node points to for both hash tables
int table::destructor(node *& head)
{
	if(!head)
		return 0;
	destructor(head->next);
	delete head;
	head = nullptr;
	return 1;	


}

int table::destructor2(node *& head2)
{
	if(!head2)
		return 0;
	destructor2(head2->next);
	delete head2;
	head2 = nullptr;
	return 1;


}

//this takes the info from main and copies it to each data member in the character class
int characters::create_character(char * copy_name, char * copy_pow, char * copy_species, char * copy_bio, char * copy_keyword)
{
	//this is to prevent memory leaks
	if(name)
	{
		delete [] name;
		name = nullptr;
	}
	if(pow)
	{
		delete [] pow;
		pow = nullptr;
	}
	if(species)
	{
		delete [] species;
		species = nullptr;
	}
	if(bio)
	{
		delete [] bio;
		bio = nullptr;
	}
	if(keyword)
	{
		delete [] keyword;
		keyword = nullptr;
	}
	
	name = new char[strlen(copy_name) + 1];
	strcpy(name, copy_name);

	pow = new char[strlen(copy_pow) + 1];
	strcpy(pow, copy_pow);

	species = new char[strlen(copy_species) + 1];
	strcpy(species, copy_species);

	bio = new char[strlen(copy_bio) + 1];
	strcpy(bio, copy_bio);

	keyword = new char[strlen(copy_keyword) + 1];
	strcpy(keyword, copy_keyword);

	return 1;	
}

//this copies the info into the object of the class which is to_add
int characters::copy_character(characters & to_add)
{

	if(name)
	{
		delete [] name;
		name = nullptr;
	}
	if(pow)
	{
		delete [] pow;
		pow = nullptr;
	}
	if(species)
	{
		delete [] species;
		species = nullptr;
	}
	if(bio)
	{
		delete [] bio;
		bio = nullptr;
	}

	if(keyword)
	{
		delete [] keyword;
		keyword = nullptr;
	}
	
	name = new char[strlen(to_add.name) + 1];
	strcpy(name, to_add.name);

	pow = new char[strlen(to_add.pow) + 1];
	strcpy(pow, to_add.pow);

	species = new char[strlen(to_add.species) + 1];
	strcpy(species, to_add.species);

	bio = new char[strlen(to_add.bio) + 1];
	strcpy(bio, to_add.bio);

	keyword = new char[strlen(to_add.keyword) + 1];
	strcpy(keyword, to_add.keyword);

	return 1;
}

//This allows a user to add to both hash tables
int table::add_character(characters & to_add, char * keyword, char * pow)
{
	int index = hash_function(keyword);
	int index2 = hash_function2(pow);
	node * temp = hash_table[index];
	node * temp2 = hash_table2[index2];
	if(!hash_table[index])
	{
		hash_table[index] = new node;
		hash_table[index]->object.copy_character(to_add);
		hash_table[index]->next = nullptr;
	}
	else
	{
		node * temp = hash_table[index];
		hash_table[index] = new node;
		hash_table[index]->object.copy_character(to_add);
		hash_table[index]->next = temp;
		
	}
	
	if(!hash_table2[index2])
	{
		hash_table2[index2] = new node;
		hash_table2[index2]->object.copy_character(to_add);
		hash_table2[index2]->next = nullptr;
	}
	else
	{
		node * temp2 = hash_table2[index2];
		hash_table2[index2] = new node;
		hash_table2[index2]->object.copy_character(to_add);
		hash_table2[index2]->next = temp2;
		
	}

	return 1;
}

//this loads the info from the external data file
int table::load_character()
{
	char name[SIZE];
	char pow[SIZE];
	char species[SIZE];
	char bio[SIZE];
	char keyword[SIZE];
	characters obj;

	ifstream filein;
	filein.open("term.txt");

	if(!filein)
	{
		filein.clear();
		return 0;
	}	
	filein.peek();
	while(filein && !filein.eof())
	{
		filein.get(name, SIZE,'|');
		filein.ignore(100, '|');
		filein.get(pow, SIZE,'|');
		filein.ignore(100, '|');
		filein.get(species, SIZE,'|');
		filein.ignore(100, '|');
		filein.get(bio, SIZE,'|');
		filein.ignore(100, '|');
		filein.get(keyword, SIZE,'|');
		filein.ignore(100, '|');
		filein.ignore(100, '\n');

		obj.create_character(name,pow,species,bio,keyword);
		add_character(obj,keyword, species);
		filein.peek();
	}
	filein.close();
	return 1;
}

//this is the has function for the first hash table, the main one
int table::hash_function(char * keyword)
{
	int sum = 0;
	for(int i = 0; i < strlen(keyword) ; ++i)
	{
		sum = sum + keyword[i];

	} 	
	return sum % hash_size;
}

//this hash function is for the extra credit hash table.
int table::hash_function2(char * species)
{
	int sum = 0;
	for(int i = 0; i < strlen(species) ; ++i)
	{
		sum = sum + species[i];
	} 	
	return sum % hash_size;
}

//this allows the user to retrieve by using the keyword
int table::retrieve_key(char * keyword, characters results[], int result_size)
{
	int i = 0;//this is the count and index of results
	int index = hash_function(keyword);
	node * current = hash_table[index];
	while(current)
	{
		if(i < SIZE && current->object.match_keyword(keyword))
		{
			results[i].copy_character(current->object);		
			++i;
		}
		current = current -> next;
	}
	return i;
}

//this function was used to test if the retrieve function worked
int table::display_results(characters results [], int results_size)
{
	for(int i = 0; i < results_size; ++i)
	{
		results[i].display_character();

	}
	return 1;

}


//finds a matching keyword
int characters::match_keyword(char * keyword)
{
	if(strcmp(this->keyword, keyword) == 0)
	{
		return 1;
	} 
	return 0;
}

//finds a matching species
int characters::match_species(char * species)
{
	if(strcmp(this->species, species) == 0)
	{
		return 1;
	}
	return 0;
}

//this function is to test if the load function worked.
int table::display_all()
{
	for(int i = 0; i < hash_size; ++i)
	{
		node * current = hash_table[i];
		if(current)
		{
			cout<<"Index is: " << i <<endl;
		}
		while(current)
		{
			current->object.display_character();
			current = current -> next;
		}


	}


	return 1;
}

//this is to allow to to output the info in the class because it's private data
int characters::display_character()
{
	cout<<"The name is: "<< name <<'|';
	cout<<"The power and ability is : "<< pow <<'|';
	cout<<"The species is: "<< species << '|';
	cout<<"The characters Bio is: "<< bio << '|';
	cout<<"The keyword is: " << keyword << '|';
	return 1;
}

//this function calls the display character function
int table::display_key(char * keyword)
{
	int index = hash_function(keyword);
	node * current = hash_table[index];
	while(current)
	{
		if(current->object.match_keyword(keyword) == 1)
		{
			current->object.display_character();
		}
		current = current -> next;	
	}
	return 1;
}

//this function uses the second hash table to display the species
int table::display_species(char * species)
{
	int index2 = hash_function2(species);
	node * current2 = hash_table2[index2];
	while(current2)
	{
		if(current2->object.match_species(species) == 1)
		{
			current2->object.display_character();
		}
		current2 = current2 -> next;
	}
	
	return 1;
}

//the recursive function to remove a LLL by keyword
int table::remove_character(node *& head, char * keyword)
{
	if(head == nullptr)
		return 0;
	if(head->object.match_keyword(keyword) == 1)
	{
		node * temp = head;
		head = head -> next;
		delete temp;	
	}
	remove_character(head->next, keyword);	
	return 1;
}

//this calls the recursive function
int table::remove_key(char * keyword)
{
	int index = hash_function(keyword);
	remove_character(hash_table[index], keyword);	
	

	return 1;
}

//character class constructor
characters::characters()
{
	name = nullptr;
	pow = nullptr;
	species = nullptr;
	bio = nullptr;
	keyword = nullptr;

}

//character class destructor
characters::~characters()
{
	delete [] name;
	delete [] pow;
	delete [] species;
	delete [] bio;
	delete [] keyword;
	name = nullptr;
	pow = nullptr;
	species = nullptr;
	bio = nullptr;
	keyword = nullptr;

	

}





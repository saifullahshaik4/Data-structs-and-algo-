#include<iostream>
#include<cstring>
#include<cctype>
#include<fstream>

//Saifullah Shaik, CS163, 2/20/23, this is the header file that contains the struct node, and the classes

class characters
{
	public:
	int create_character(char * copy_name, char * copy_pow, char * copy_species, char * copy_bio, char * copy_keyword);
	int copy_character(characters & to_add);
	int display_character();
	int match_keyword(char * keyword);
	int match_species(char * species);
	characters();
	~characters();	


	private:
	char * name;
	char * pow;
	char * species;
	char * bio;
	char * keyword;

};

const int SIZE = 15;

struct node
{
	node * next;
	characters object;


};



class table
{
	public:
	table(int size = 101);
	~table();
	int hash_function(char * keyword);
	int hash_function2(char * species);
	int add_character(characters & to_add, char * keyword, char * species);
	int load_character();
	int display_key(char * copy_keyword);
	int retrieve_key(char * copy_keyword, characters results[], int result_size);
	int remove_key(char * copy_keyword);
	int display_species(char * copy_species); 
	int remove_term();
	int display_results(characters results[], int results_size);
	int display_all();
	private:
	node ** hash_table;//hash table for keyword
	node ** hash_table2;//The hash table for species
	int hash_size;//hash size for keyword
	int destructor(node *& head);
	int destructor2(node *& head2);
	int remove_character(node *& head, char * keyword);
	
};

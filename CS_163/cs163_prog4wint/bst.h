//Saifullah Shaik 
#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>

class superheros
{
	public:
	superheros();
	~superheros();
	int create_superhero(char * copy_name, char * copy_pow, char * copy_species, char * copy_bio, char * copy_keyword);
	int copy_superhero(superheros & to_add);
	int display_superhero();
	int compare_pow(char * copy_pow);
	int compare_species(char * copy_species);
	int get_pow(char * copy_pow);
	int get_species(char * copy_species);

		private:
	char * name;
	char * pow;
	char * species;
	char * bio;
	char * keyword;
};

const int SIZE = 20;


struct node
{
	node * left;
	node * right;
	superheros object;
};


class bst
{
	public:
	bst();
	~bst();
	int add_superhero(superheros & to_add);
	int display_all();
	int display_pow(char * pow);
	int retrieve(char * pow, char * species);
	int remove_pow(char * pow);

	private:
	node * root;
	int add_superhero(superheros & to_add, node *& root, char * copy_pow);
	int display_all(node * root);
};





//Saifullah Shaik 03/07/23
#include "bst.h"

using namespace std;


bst::bst()
{
	root = nullptr;
}



bst::~bst()
{



}

int superheros::create_superhero(char * copy_name, char * copy_pow, char * copy_species, char * copy_bio, char * copy_keyword)
{
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

int superheros::copy_superhero(superheros & to_add)
{
	 
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

int superheros::compare_pow(char * copy_pow)
{
	return strcmp(pow, copy_pow);
}

int superheros::compare_species(char * copy_species)
{
	return strcmp(species, copy_species);
}

int superheros::get_pow(char * copy_pow)
{
	copy_pow = new char[strlen(pow) + 1];
	strcpy(copy_pow, pow);
	return 1;
}


int superheros::get_species(char * copy_species)
{
	copy_species = new char[strlen(species) + 1];
	strcpy(copy_species, species);
	return 1;
}
int bst::add_superhero(superheros & to_add)
{
	char * copy_name;
	to_add.get_pow(copy_name);
	add_superhero(to_add,root, copy_name);
	return 1;
}

int bst::add_superhero(superheros & to_add, node *& root, char * copy_name)
{
	if(!root)
	{
		root = new node;
		root->object.copy_superhero(to_add);
		root->left = nullptr;
		root->right = nullptr;
		return 1;
	}
	if(root->object.compare_pow(copy_name) < 0) 
	{
	  add_superhero(to_add, root->left, copy_name);

	}
	else if(root->object.compare_pow(copy_name) > 0)
	{
		add_superhero(to_add, root->right, copy_name);
	}
	else 
	{
		char * copy_species;
		to_add.get_species(copy_species);
		if(root->object.compare_pow(copy_species) < 0)
			add_superhero(to_add, root->left, copy_name);
		else
			add_superhero(to_add, root->right, copy_name);
	}
	return 1;
}

int superheros::display_superhero()
{
	cout<<"The superhero is: "<< name << endl;
	cout<<"The superhero's power is: "<< pow << endl;
	cout<<"The species of the superhero is: "<< species << endl;
	cout<<"The description/Bio of the superhero is: "<< bio << endl;
	cout<<"The keyword is: "<< keyword << endl;
	return 1;

}

int bst::display_all()
{
	if(!root)
		return 0;
	display_all(root);
	return 1;
}

int bst::display_all(node * root)
{
	if(!root)
		return 0;
	display_all(root->left);
	root->object.display_superhero();

	display_all(root->right);

	return 1;
}


superheros::superheros()
{
	name = nullptr;
	pow = nullptr;
	species = nullptr;
	bio = nullptr;
	keyword = nullptr;	

}


superheros::~superheros()
{
	delete [] name;
	name = nullptr;

	delete [] pow;
	pow = nullptr;

	delete [] species;
	species = nullptr;

	delete [] bio;
	bio = nullptr;

	delete [] keyword;
	keyword = nullptr;	
}

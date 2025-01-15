#include "list.h"

using namespace std;


//Saifullah Shaik, CS163, 03/20/23
//this is the file where I implement all of the functions in my .h file.


//constructor
table::table(int size)
{
	list_size = size;
	adj_list = new vertex[list_size];
	for(int i = 0; i < list_size; ++i)
	{
		adj_list[i].head = nullptr;
		adj_list[i].data = nullptr;	
	}	
}

//destructor
table::~table()
{
	for(int i = 0; i < list_size; ++i)
	{
		if(adj_list[i].data)
			delete adj_list[i].data;
		destructor(adj_list[i].head);
	}
	delete [] adj_list;
}

//contructor for the baking class
baking::baking()
{
	bakingstep_entry = nullptr;

}

//destructor for the baking class
baking::~baking()
{
	delete bakingstep_entry;
	bakingstep_entry = nullptr;
}

//the destructor function
int table::destructor(node *& head)
{
	if(!head)
		return 0;
	destructor(head->next);
	delete head;
	head = nullptr;
	return 1;


}

//checks if the key passed in from main is a match
int baking::match(char * key)
{
	return strcmp(bakingstep_entry, key);

}

//finds the location to connect the vertices
int table::find_location(char * key)
{
	for(int i = 0; i < list_size; ++i)
	{
		if(!adj_list[i].data)
			return 0;
		if(adj_list[i].data->match(key) == 0)
			return i;

	}
	return 1;	
}

//dynamically allocates an array for the concept
int baking::create(char * copy_bakingstep)
{
	bakingstep_entry = new char[strlen(copy_bakingstep) + 1];	
	strcpy(bakingstep_entry, copy_bakingstep);
	return 1;
}
//copies the baking steps into the object
int baking::copy(baking & to_add)
{
	bakingstep_entry = new char[strlen(to_add.bakingstep_entry) + 1];
	strcpy(bakingstep_entry, to_add.bakingstep_entry);
	return 1;

}
//allows the user to add a vertex
int table::add_vertex(baking & to_add)
{
	for(int i = 0; i < list_size; ++i)
	{
		if(!adj_list[i].data)	
		{
			adj_list[i].data = new baking;
			adj_list[i].data->copy(to_add);
			return 1;

		}
	}
	return 0;//nothing was added
}

//connects between two concepts
int table::add_edge(char * key, char * to_attach)
{
	int connect1 = find_location(key); 
	int connect2 = find_location(to_attach);

	node * temp = new node;
	temp->adjacent = &adj_list[connect2];
	temp->next = adj_list[connect1].head;
	adj_list[connect1].head = temp;
	return 1;



}

//display's the baking steps
int baking::display()
{
	cout<<"The Baking Step is: "<< bakingstep_entry << endl;
	return 1;
}

//wrapper function
//display's the entire adjacency list
int table::display_adj_path()
{
	// If no adj_list, then return

	int count = 0;
	for(int i = 0; i < list_size; ++i)
	{
		if(adj_list[i].data)
		{
			cout<<"This is the data: " <<endl;
			adj_list[i].data->display();
			cout<<"This is the connected data: "<<endl;
			count += display_adj(adj_list[i].head);

		}
	}
	return count;

}
//recursive function that display's all
int table::display_adj(node * head)
{

	if(!head) 
		return 0;
	head->adjacent->data->display();
	return display_adj(head->next) + 1;

}



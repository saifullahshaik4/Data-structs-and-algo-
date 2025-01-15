#include "queue.h"


using namespace std;

//Saifullah Shaik, Cs 163, 02/09/23, this is where I implemented the functions for my queue. This also had a stack added in which is why I have some functions being called from my bill.cpp file.



//constructor
queue::queue()
{
        rear = nullptr;
        index = 0;
}
//To create the bill using the info from main
int bills::create_bill(char * copy_payeeName, char * copy_description, char * copy_use)
{
        if(copy_payeeName)
        {
                this->payeeName = new char[strlen(copy_payeeName) + 1];
                strcpy(this->payeeName, copy_payeeName);
        }
        if(copy_description)
        {
                this->description = new char[strlen(copy_description) + 1];
                strcpy(this->description, copy_description);
        }
        if(copy_use)
        {
                this->use = new char[strlen(copy_use) + 1];
                strcpy(this->use, copy_use);
        }
        return 1;

}
//copies the info
int bill::copy_entry(bill & add)
{
        if(add.payeeName)
        {
                payeeName = new char[strlen(add.payeeName) + 1];
                strcpy(payeeName, add.payeeName);
        }
        if(add.description)
        {
                description = new char[strlen(add.description) + 1];
                strcpy(description, add.description);
        }
        if(add.use)
        {
                use = new char[strlen(add.use) + 1];
                strcpy(use, add.use);
        }


        return 1;
}
//calls the function that copies the bill info into the queue
int bills::copy_stack(stack & copy)
{
        object.copy_stack(copy);
        return 1;

}
//adds to the queue
int queue::enqueue(bill & add, stack &copy)
{
        if(rear == nullptr)
        {
                rear = new q_node;
                rear->next = rear;
                rear->data.copy_entry(add);
                rear->data.copy_stack(copy);
                return 1;
        }
        else
        {
                q_node * temp = new q_node;
                temp->next = rear->next;
                rear->next = temp;
                rear = temp;
                rear->data.copy_entry(add);
                rear->data.copy_stack(object);
                return 1;
        }
        return 1;

}
//removes from the queue
int queue::dequeue()
{
        if(!rear)
                return 0;
        if(rear == rear->next)
        {
                delete rear;
                rear = nullptr;
                return 1;
        }
        else
        {
                q_node * temp = rear->next->next;
                delete rear->next;
                rear->next = temp;
                return 1;
        }


}
//peeks the first node added
int queue::q_peek()
{
        if(!rear)
        {
                cout<<"The list is empty"<<endl;
                return 0;
        }
        rear->next->data.display_bill();
        return 1;


}
//wrapper function
int queue::q_display()
{
        if(!rear)
        {
                cout<<"The list is empty"<<endl;
                return 0;
        }
        return q_display(rear->next);
}
int queue::q_display(q_node * rear)
{
        if(rear == this->rear)
        {
                rear->data.display_bill();
                return 0;
        }
        rear->data.display_bill();
        return q_display(rear->next);

}

//displays the assignment info and calls function to display bill
int bills::display_bill()
{

        cout<<"The payees name is: "<<endl;
        cout<< payeeName <<endl;

        cout<<"The description is: "<<endl;
        cout<< description <<endl;

        cout<<"The use is: "<<endl;
        cout<< use <<endl;

        object.display();

        return 1;

}
int queue::destructor()
{
        if(!this->rear)
                return 0;
        return destructor(rear);


}

int queue::destructor(q_node *& current)
{
        if(current == rear)
        {
                delete current;
                return 0;
        }
        destructor(current->next);
        delete current;
        return 1;

}
queue::~queue()
{
        destructor();

}

bill::bill()
{
        payeeName = nullptr;
        description = nullptr;
        use = nullptr;

}

bill::~bill()
{

        delete [] payeeName;
        delete [] description;
        delete [] use;

}


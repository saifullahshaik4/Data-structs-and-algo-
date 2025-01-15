#include "stack.h"


//Saifullah Shaik, CS163, 02/09/23, this is where the implementations of my stack functions are. I created a couple extra functions like the is_empty and copy_entry function to make things easier.


using namespace std;
stack::stack()
{
        head = nullptr;
        top_index = 0;


}
//creates the bills info
int bill::create_bill(char * copy_payeeName,  char * copy_description, char * copy_use, int copy_amount)
{
        //this is to prevent memory leaks. If memory already exists then it will replace it and cause a leak
        if(payeeName)
                delete [] payeeName;
        if(description)
                delete [] description;
        if(use)
                delete [] use;

        this->payeeName = new char[strlen(copy_payeeName) + 1];
        strcpy(this->payeeName, copy_payeeName);


        this->description = new char[strlen(copy_description) + 1];
        strcpy(this->description, copy_description);

        this->use = new char[strlen(copy_use) + 1];
        strcpy(this->use, copy_use);

        this->amount = copy_amount;

        return 1;
}
//copies the bills info
int bill::copy_entry(bill & to_add)
{
        if(to_add.payeeName)
        {
                this->payeeName = new char[strlen(to_add.payeeName) + 1];
                strcpy(this->payeeName, to_add.payeeName);
        }
        if(to_add.description)
        {
                this->description = new char[strlen(to_add.description) + 1];
                strcpy(this->description, to_add.description);
        }
        if(to_add.use)
        {
                this->use = new char[strlen(to_add.use) + 1];
                strcpy(this->use, to_add.use);
        }
        if(to_add.amount)
        {
                this->amount = to_add.amount;
        }
        return 1;

}
//copies the stack into the queue.
int stack::copy_stack(stack & copy)
{
        node * current = copy.head;
        while(current)
        {
                for(int i = 0; i < MAX; ++i)
                {
                        if(current->bill1[i].is_empty() == 1)
                                push(current->bill1[i]);
                }
                current = current -> next;
        }
        return 1;
}
//this function checks if the stack is empty
int bill::is_empty()
{
        if(payeeName == nullptr)
                return 0;
        return 1;


}
//this pushes a book onto the stack
int stack::push(bill & to_add)
{
        if(head == nullptr)
        {
                head = new node;
                head->next = nullptr;
                head->bill1 = new bill[MAX];
                head->bill1[top_index].copy_entry(to_add);
                ++top_index;
                return 1;
        }

        if(top_index < MAX)
        {
                head->bill1[top_index].copy_entry(to_add);
                ++top_index;
                return 1;
        }
        if(top_index == MAX)
        {
                node * temp = new node;
                temp->next = head;
                head = temp;
                head->bill1  = new bill[MAX];
                head->bill1[top_index].copy_entry(to_add);
                ++top_index;
                return 1;
        }
        return 1;
}
//wrapper function
int stack::display()
{
        if(head == nullptr)
                return 0;
        int i = top_index;
        node * current = head;
        while(current)
        {
                while(i != 0)
                {
                        current->bill1[i-1].display_bill();
                        --i;
                }
                current = current -> next;
                i = MAX;
        }
        return 1;
}
int bill::display_bill()
{

        cout<<"The payee Name is: "<<endl;
        cout<<payeeName<<endl;

        cout<<"The description is: "<<endl;
        cout<<description<<endl;

        cout<<"The use is: "<<endl;
        cout<<use<<endl;

        cout<<"The amount is: "<<endl;
        cout<<amount<<endl;
        return 1;

}
//this pops a bill off the stack. Deleting the latest bill added
int stack::pop()
{
        if(head == nullptr)
                return 0;
        if(top_index > 0)
        {
                delete [] head->bill1;
                --top_index;
                return 1;
        }
        if(top_index ==0)
        {
                delete [] head->bill1;
                node * hold = head->next;
                delete head;
                head = hold;
                --top_index;
                return 1;
        }
        return 0;

}
//this displays the last bill added
int stack::peek()
{
        if(head == nullptr)
        {
                cout<<"The list is empty"<<endl;
                return 0;
        }
        head->bill1[top_index].display_bill();
        return 1;
}

//destructor
stack::~stack()
{
        node * temp = nullptr;
        while(head)
        {
                temp = head->next;
                if(head->bill1)
                {
                        delete [] head->bill1;
                        head->bill1 = nullptr;
                }
                delete head;
                head = temp;
        }

}
bill::bill()
{


}

//destructor
bill::~bill()
{
        if(payeeName)
        {
                delete [] payeeName;
                payeeName = nullptr;
        }
        if(description)
        {
                delete [] description;
                description = nullptr;
        }
        if(use)
        {
                delete [] use;
                use = nullptr;
        }


}





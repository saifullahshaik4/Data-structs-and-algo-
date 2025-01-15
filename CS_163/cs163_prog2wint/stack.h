#include <iostream>
#include <cstring>
#include <cctype>


//Saifullah Shaik, CS163, 02/09/23, this header file contains the class for the billing info and the stack. It also contains the struct node.

class bill
{
        public:
                bill();
                ~bill();
                int display_bill();
                int create_bill(char * copy_payeeName, char * copy_description, char * copy_use, int copy_amount);
                int copy_entry(bill & to_add);
                int is_empty();//returns 0 if it's empty
        private:
                char * payeeName;
                char * description;
                char * use;
                int amount;

};
struct node
{
        bill * bill1;
        node * next;

};

const int MAX = 5;

class stack
{
        public:
                int push(bill & to_add);
                int pop();
                int display();
                int peek();
                int copy_stack(stack & object);
                stack();
                ~stack();
        private:
                node * head;
                int top_index;


};


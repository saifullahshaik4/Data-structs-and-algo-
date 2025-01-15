#include "stack.h"
#include <iostream>
#include <cstring>
#include <cctype>

//Saifullah Shaik, CS163, 02/09/23 this header file contains the classes for my queue and all of the info for my assignment. It has the struct node for my queue also.

class bills
{
        public:
                bills();
                ~bills();
                int create_bill(char * copy_payeeName, char * copy_description, char * copy_use);
                int copy_bill(bill & add);
                int display_bill();
                int insert_bill(bills & to_add);
                int copy_stack(stack & copy);
              
        private:
                char * payeeName;
                char * description;
                char * use;
                stack object;
};
struct q_node
{
        q_node * next;
        bill data;

};



class queue
{
        public:
                queue();
                ~queue();
                int enqueue(bill & add, stack & object);
                int q_display();
                int dequeue();
                int q_peek();
                int destructor();
        private:
                q_node * rear;
                int index;
                int q_display(q_node * rear);
                int destructor(q_node *& current);

};

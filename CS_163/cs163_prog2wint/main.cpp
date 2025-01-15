#include "queue.h"

using namespace std;

const int SIZE = 100;

//Saifullah Shaik, CS163, 02/10/23, in main I gather all of the info I need from the user and I pass it into each function.


int main()
{
        char option = ' ';//user option
        char user_option = ' ';
        bool stop = true;//loop variable
        stack to;//object to call functions
        bill call;//object to call functions
        queue obj;//object to call functions
        bill call2;
        char copy_payeeName[SIZE];
        char copy_description[SIZE];
        char copy_use[SIZE];
        int copy_amount = 0;
        char copy_bill[SIZE];
        char copy_billtype[SIZE];
        char copy_billuse[SIZE];
        while(stop == true)
        {
                cout<<"Please choose what you would like to do"<<endl;
                cout<<"1.Add a bill"<<endl<<"2.Display all bills"<<endl<<"3.Remove a bill"<<endl<<"4.Retrieve the last bill added"<<endl<<"5.Add a peyeeName"<<endl
                        <<"6.Delete a payeeName"<<endl<<"7.Retrieve the last payeeName added"<<endl<<"8.Display all"<<endl<<"9.Quit"<<endl;
                         cin >> option;
                cin.ignore(100, '\n');
                switch(option)
                {
                        case '1':cout<<"Please enter the payee name"<<endl;
                                 cin.get(copy_payeeName, SIZE, '\n');
                                 cin.ignore(100, '\n');

                                 cout<<"Please enter the description"<<endl;
                                 cin.get(copy_description, SIZE, '\n');
                                 cin.ignore(100, '\n');

                                 cout<<"Please enter the use of the bill"<<endl;
                                 cin.get(copy_bill, SIZE, '\n');
                                 cin.ignore(100, '\n');

                                 cout<<"Please enter the amount of the bill"<<endl;
                                 cin >> copy_amount;
                                 cin.ignore(100, '\n');
                                 call.create_bill(copy_payeeName,copy_description,copy_use,copy_amount);
                                 to.push(call);
                                 break;

                        case '2':to.display();
                                 break;
                        case '3':to.pop();
                                 break;
                        case '4':to.peek();
                                 break;
                        case '5':
                                 cout<<"Please enter the bill"<<endl;
                                 cin.get(copy_bill, SIZE, '\n');
                                 cin.ignore(100, '\n');

                                 cout<<"Please enter bill type "<<endl;
                                 cin.get(copy_billtype, SIZE, '\n');
                                 cin.ignore(100, '\n');

                                 cout<<"Please enter the bill use"<<endl;
                                 cin.get(copy_use, SIZE, '\n');
                                 call2.create_bill(copy_payeeName, copy_description, copy_use, copy_amount);
                                 cin.ignore(100, '\n');

                                 cout<<"To add a bill enter the letter y, if you don't want to enter a name enter the letter n."<<endl;

                                 cin >> user_option;
                                 cin.ignore(100, '\n');
                                 while(user_option == 'y')
                                 {
                                         cout<<"Please enter the payee name"<<endl;
                                         cin.get(copy_payeeName, SIZE, '\n');
                                         cin.ignore(100, '\n');

                                         cout<<"Please enter the name of the on ramp"<<endl;
                                         cin.get(copy_description, SIZE, '\n');
                                         cin.ignore(100, '\n');

                                         cout<<"Please enter the use"<<endl;
                                         cin.get(copy_use, SIZE, '\n');
                                         cin.ignore(100, '\n');
                                   
                                         cout<<"Please enter the amount of the bill"<<endl;
                                         cin >> copy_amount;
                                         cin.ignore(100, '\n');
                                         cout<<"To add another bill enter the letter y, if you don't want to enter another road enter the letter n."<<endl;
                                         cin >> user_option;
                                         cin.ignore(100, '\n');
                                         call.create_bill(copy_payeeName,copy_description,copy_use,copy_amount);
                                         to.push(call);
                                 }

                                 obj.enqueue(call2, to);
                                 break;
                        case '6':obj.dequeue();
                                 break;
                        case '7':obj.q_peek();
                                 break;
                        case '8':obj.q_display();
                                 break;
                        case '9':stop = false;
                                 break;
                        default:
                                 cout<<"This is the wrong option"<<endl;
                                 break;

                }

        }
        return 0;
  }

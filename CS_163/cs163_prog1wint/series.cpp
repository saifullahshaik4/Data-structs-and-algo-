#include "series.h"
using namespace std;

//Saifullah Shaik,cs163, 10/11/2022
//This is where all of the functions are implemented. In this program multiple functions will be used to complete one task.
//Using recursion and the help of a wrapper function.
//It's important to not cin info from the user inside the functions so we receive this info from main and pass it into the functions.//Deallocating the dynamic memory in the structs
nodesources::~nodesources()
{
        nameseries = nullptr;


}
nodeseries::~nodeseries()
{

        name = nullptr;

}
series::series()
{
        headseries = nullptr;

}
//The constructor
series::~series()
{
        if(headseries == nullptr)
                return;
        remove_all(headseries);
  }

//wrapper function
int series::remove_series(char * series_name)
{
        //base case
        if(headseries == nullptr)
                return 0;
        return remove_series(series_name, headseries);
}
int series::remove_series (char * series_name, nodeseries *&headseries)
{

        if(headseries == nullptr)
                return 0;
        if(strcmp(series_name, headseries->name)==0)
        {
                nodeseries * hold = headseries;
                headseries = hold->nextseries;
                remove_series(hold->headseries);
                delete hold;
                return 1;

        }
        return remove_series(series_name, headseries->nextseries);//recursive call



}
//This function will be called in the destructor to destroy the LLL
int series::remove_all(nodeseries *& headseries)
{
        if(headseries == nullptr)
                return 0;
        remove_all(headseries->nextseries);
        delete headseries;
        headseries = nullptr;
        return 1;

}
//This function removes all info on a certain series
int series::remove_series(nodeseries *& hold )
{
        if(hold == nullptr)
                return 0;
        remove_series(hold->nextseries);
        delete hold;
        hold = nullptr;
        return 1;
}
//wrapper function
int series::add_series(char * series_name)
{
        return add_series(series_name, headseries);
}
int series::add_series(char * series_name, nodeseries *&headseries)
{
        //empty list
        if(headseries == nullptr)
        {
                headseries = new nodeseries;
                headseries->name = new char[strlen(series_name) +1];
                strcpy(headseries->name, series_name);
                return 1;
        }
        //if the user enters the same name twice
        if(strcmp(series_name, headseries->name) == 0)
                return 0;
        //inserting at the front
        if(strcmp(series_name, headseries->name) < 0)
        {
                nodeseries * temp = new nodeseries;
                temp->nextseries = headseries;
                headseries = temp;
                temp->name = new char[strlen(series_name) +1];
                strcpy(temp->name, series_name);
                return 1;
        }
        //inserting at the back of the LLL
        if(strcmp(series_name, headseries->name) > 0)
        {
                nodeseries * temp = new nodeseries;
                temp->nextseries = headseries->nextseries;
                headseries->nextseries = temp;
                temp->name = new char[strlen(series_name) +1];
                strcpy(temp->name, series_name);
                          return 1;
        }
        return add_series(series_name, headseries->nextseries);
}
//wrapper function
int series:: display_all()
{
        //check if list is empty
        if(headseries == nullptr)
                return 0;
        return display_all(headseries);


}

int series:: display_all(nodeseries * headseries)
{
        //stopping condition
        if(headseries == nullptr)
                return 0;
        cout<<headseries->name<<endl;
        return 1 + display_all(headseries->nextseries);


}
//wrapper function to call from main
int series::add_series(int seasoncount, char * series_name, char * genre_name, int episodecount)
{
        if(headseries == nullptr) //if we have nothing in our series list there is no series to add
                return 0;
        return add_helper(seasoncount, series_name, genre_name, episodecount, headseries);  //calling recursive function
}
int series::add_helper(int seasoncount, char * series_name, char * genre_name, int episodecount, nodeseries *& headseries) //recursive function
{
        if(headseries == nullptr)
                return 0;
        if(strcmp(headseries->name,series_name) == 0) //stopping condition if we have a match for genre name
        {
                add_genre(seasoncount, series_name, genre_name, episodecount, headseries->headseries); //call recursive site function
        }
        return add_helper(seasoncount, series_name, genre_name,episodecount, headseries->nextseries);
        //traversing our series list until we have a match or return if no match is found

}
int series::add_genre(int seasoncount, char *series_name, char *genre_name, int episodecount, nodeseries *& headseries)
{
        //adding the first node
        if(headseries == nullptr)
        {
                headseries = new nodeseries;
                headseries->name = new char[strlen(series_name)+1];
                strcpy(headseries->name, series_name);
                headseries->seasoncount = seasoncount;
                headseries->nextseries = nullptr;
                return 1;
        }
          //inserting at the beginning
        if( headseries->seasoncount  < seasoncount)
        {
                nodeseries * temp = new nodeseries; //create a temp variable to be new head of list
                temp->nextseries = headseries; //temp is new head of the list
                temp->name = new char[strlen(series_name)+1]; //storing our data
                strcpy(temp->name, genre_name);
                temp->seasoncount = seasoncount;
                return 1; //return a 1 for success


        }
        //inserting at the end
        if(headseries->seasoncount > seasoncount)
        {
                nodeseries * temp = new nodeseries;
                temp->nextseries = headseries->nextseries; //temp goes after our current head pointer
                headseries->nextseries = temp; //head's next item in the list points to temp
                temp->name = new char[strlen(series_name)+1]; //saving our variables
                strcpy(temp->name, series_name);
                temp->seasoncount = seasoncount;
                return 1;

        }
        return add_genre(seasoncount,series_name,  genre_name, episodecount, headseries->nextseries);
}
int series::search_series(char * series_name)
{
        if(headseries == nullptr)
                return 0;
        nodeseries * current1 = headseries;
        while(current1)
        {
                search_series(headseries->headseries, series_name);
                current1 = current1 -> nextseries;

        }
        return 1;


}
int series::search_series(nodeseries * headseries, char * series_name)
{
        if(headseries == nullptr)
                return 0;
        nodeseries * current2 = headseries;
        while(current2)
        {
                if(strcpy(current2->name,series_name)==0)
                {
                        cout<<headseries->name<<endl;
                }
                current2 = current2 -> nextseries;
        }
        return 0;
}
//wrapper function
int series::display_series(char * series_name)
{
        if(headseries == nullptr)
                return 0;
        nodeseries * current = headseries;//current series name
        while(current && strcmp(current->name, series_name) != 0)
        {
                current = current -> nextseries;
        }
        if(current == nullptr)
        {
                cout<<"No match"<<endl;
                return 0;
        }
        return display_series(current->headseries);


}
int series::display_series(nodeseries * headseries)
{
        if(headseries == nullptr)
                return 0;
        cout<<headseries->nextseries<<endl;
        return display_series(headseries->nextseries);

}

#include <iostream>
#include <cstring>
#include <cctype>
//This program will have a class and two structs. The class contains the head of the main LLL and all of the functions
//prototypes. All functions that have head in the argumant list are the private section.
//The structs have deconstructor to deallocate the dynamic memory in them.
struct nodesources
{
        ~nodesources();
        
        nodesources * nextseries;
        char * nameseries;
        int seasoncount;
};

struct nodeseries
{
        ~nodeseries();
        
        nodeseries * nextseries;
        nodeseries * headseries;
        char * name;
        int seasoncount;
};

class series
{
        public:
        series();
        ~series();
        int add_series(char * series_name);
        int display_all();
        int add_series(int seasoncount, char * series_name, char * genre_name, int episodecount);
        int add_genre(int seasoncount, char *series_name, char *genre_name, int episodecount);
        int display_series(char * series_name);
        int remove_series(char * series_name);
        int search_series(char * series_name);

        private:
        nodeseries * headseries;
        int display_all(nodeseries * headseries);
        int add_helper(int seasoncount, char * series_name, char * genre_name, int episodecount, nodeseries *& headseries);
        //int add_series(int seasoncount, char *series_name, char *genre_name, int episodecount, nodeseries *& headseries);
        int add_genre(int seasoncount, char *series_name, char *genre_name, int episodecount, nodeseries *& headseries);
        int display_series(nodeseries * headseries);
        int remove_series(nodeseries *& hold);
        int remove_all(nodeseries *& headseries);
        int remove_series(char * series_name, nodeseries *&headseries);
        int add_series(char * series_name, nodeseries *&headseries);
        int search_series(nodeseries * headseries, char * series_name);
};

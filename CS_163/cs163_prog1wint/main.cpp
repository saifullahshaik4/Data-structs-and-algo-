#include "series.h"

using namespace std;

//Saifullah Shaik, cs163, 10/11/22
//This is where we will be prompting the user and passing the information to the functions to complete the tasks

int main()
{

        series series_obj;//class object to call the functions
        nodeseries genre_obj;//struct object
        bool stop = true;//to run the loop
        int option = 0;
        const int SIZE = 40;
        char series_name[SIZE];//name of the series that we pass in
        char genre_name[SIZE];//name of the genre that we pass in
        int seasoncount_copy = 0;//number of seasons that we pass in
        int episodecount_copy = 0;
        while(stop)
        {

                cout<<"1.Add series"<<endl<<"2.Display all series"<<endl<<"3.Add genre"<<endl<<"4.Display genre"<<endl<<"5.Remove a series" <<endl<<"6.Search genre"<<endl<<"7.Quit"<<endl;
                cin >> option;
                cin.ignore(100, '\n');
                if(option == 1)
                {
                        cout<<"Please enter the series name"<<endl;
                        cin.get(series_name, SIZE, '\n');
                        cin.ignore(100, '\n');
                        int count = series_obj.add_series(series_name);
                                       if(count == 0)
                                cout<<"You entered the same name twice"<<endl;
                }
                if(option == 2)
                {
                        series_obj.display_all();
                }
                if(option == 3)
                {
                        cout<<"Please enter the series name"<<endl;
                        cin.get(series_name, SIZE, '\n');
                        cin.ignore(100, '\n');
                        cout<<"Please enter the genre name"<<endl;
                        cin.get(genre_name, SIZE, '\n');
                        cin.ignore(100, '\n');
                        cout<<"Please enter the number of seasons in the series"<<endl;
                        cin >> seasoncount_copy;
                        cin.ignore(100, '\n');
                        cout<<"Please enter the number of episodes in the series"<<endl;
                        cin >> episodecount_copy;
                        cin.ignore(100, '\n'); 
			series_obj.add_series(seasoncount_copy, series_name, genre_name, episodecount_copy);
                }
                if(option == 4)
                {
                        cout<<"Please enter the series name"<<endl;
                        cin.get(series_name, SIZE, '\n');
                        cin.ignore(100, '\n');
                        series_obj.display_series(series_name);
                }
                if(option == 5)
                {
                        cout<<"Please enter the series name"<<endl;
                        cin.get(series_name, SIZE, '\n');   
                                  cin.ignore(100, '\n');
                        series_obj.remove_series(series_name);
                }
                if(option == 6)
                {
                        cout<<"Please enter the genre name"<<endl;
                        cin.get(series_name, SIZE, '\n');
                        cin.ignore(100, '\n');
                        series_obj.search_series(genre_name);
                }
                if(option == 7)
                        stop = false;


        }
        return 0;
}

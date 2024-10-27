#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <random>
#include <time.h> //for better randomization
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // note: names/colors arrays now full of values
    

    //my code
    int choice = main_menu();

    switch(choice)
    {
        case(1):
        {
            add_goat();
            break;
        }
        case(2):
        {
            delete_goat();
            break;
        }
        case(3):
        {
            display_trip(); 
            break;
        }   
        case(4):
        {
            break;
        }
        // no default needed, as int choice validation is in main_menu() function
    }

    return 0;
}

int main_menu()
{
    int choice;
    cout << "*** GOAT MANAGER 3001 ***\n[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit\nChoice --> "; 
    cin >> choice; 

    while(choice > 4 || choice < 1) //validation loop
    {
        cout << "Invalid choice, please choose one (1-4): ";
        cin >> choice;
    }
    return(choice);
    
}

void display_trip() //displays all goats in the "trip"
{

}

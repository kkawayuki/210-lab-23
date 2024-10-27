// COMSC-210 | lab 22 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list> // for std::list
#include <random>
#include <time.h> //for better randomization
#include "Goat.h"
using namespace std;

// global variables
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

// function prototypes
int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string[], string[]);
void display_trip(list<Goat> trip);
int main_menu();

int main()
{
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++])
        ;
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++])
        ;
    fin1.close();

    // note: names/colors arrays now full of values
    list<Goat> trip; // list of goats is called a trip?

    // my code
    int choice = main_menu();

    switch (choice)
    {
    case (1):
    {
        add_goat();
        break;
    }
    case (2):
    {
        delete_goat();
        break;
    }
    case (3):
    {
        display_trip(trip);
        break;
    }
    case (4):
    {
        break;
    }
        // no default needed, as int choice validation is in main_menu() function
    }

    return 0;
}

// functions**********************************

int main_menu()
{
    int choice;
    cout << "*** GOAT MANAGER 3001 ***\n[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit\nChoice --> ";
    cin >> choice;

    while (choice > 4 || choice < 1) // validation loop
    {
        cout << "Invalid choice, please choose one (1-4): ";
        cin >> choice;
    }
    return (choice);
}

void display_trip(list<Goat> trip) // displays all goats in the "trip"
{
    int i = 0; //keep track of iterations

    if (trip.empty())
        cout << "Trip is empty\n";
    else
    {
        for (auto it = trip.begin(); it != trip.end(); ++it, ++i) // for each element in trip
        {
            cout << "[" << i << "] " << it->get_name() << "(" << it->get_age() << ", " << it->get_color() << ")\n"; //messy to read line, outputs something like: [5] Lena (12, Teal)
        }
    }
}

int select_goat(list<Goat> trip)
{

}

void delete_goat(list<Goat> &trip)
{

}

void add_goat(list<Goat> &trip, string[], string[])
{
    
}
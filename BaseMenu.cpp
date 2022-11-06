//
// Created by m3ped on 05/11/2022.
//

#include "BaseMenu.h"

using namespace std;
void BaseMenu::displayBaseMenu()
{
    int option;

    cout << "WELCOME TO TIMETABLE MANAGER" << "\n";
    cout << "\n";
    cout << "[1] " << "Change student's schedule or classes" << endl;
    cout << "[2] " << "Display listings" << endl;

    cin >> option;

    if (option == 1)
    {
        ChangeMenu::displayChangeMenu();
    }
    else if (option == 2)
    {
        ListingMenu::displayListingMenu();
    }
    else
    {
        cout << "Invalid input." << endl;
    }
}
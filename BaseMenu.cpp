//
// Created by Miguel Pedrosa and Joana Marques on 01/11/2022.
//

#include "BaseMenu.h"

using namespace std;
void BaseMenu::displayBaseMenu()
{
    int option;

    std::cout << R"(

           ______ _____    _    _                      _
     /\   |  ____|  __ \  | |  | |                    (_)
    /  \  | |__  | |  | | | |__| | ___  _ __ __ _ _ __ _  ___  ___
   / /\ \ |  __| | |  | | |  __  |/ _ \| '__/ _` | '__| |/ _ \/ __|
  / ____ \| |____| |__| | | |  | | (_) | | | (_| | |  | | (_) \__ \
 /_/    \_\______|_____/  |_|  |_|\___/|_|  \__,_|_|  |_|\___/|___/



    )" << '\n';
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
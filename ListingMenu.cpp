//
// Created by m3ped on 05/11/2022.
//

#include "ListingMenu.h"

void ListingMenu::displayListingMenu()
{
    int option;
    cout << "LISTING SUBMENU" << "\n";
    cout << "\n";
    cout << "Click 0 to quit." << "\n";
    cout << "\n";
    cout << "[1] " << "Display all students" << endl;
    cout << "[2] " << "Display listings" << endl;

    cin >> option;

    vector<Estudante> vectorEstudantes;
    map<pair<string, string>, Slot> mapUcClassTimeSlot;
    map<pair<string, string>, int> mapUcClassNumberSudents;
    TTM::csvStudentsClassesReader(vectorEstudantes, mapUcClassNumberSudents);


        switch(option)  //dependendo da escolha do utilizador
        {
            case 0:
                cout << "Goodbye!" <<endl;
            case 1:
                TTM::displayAllStudents(vectorEstudantes);
                break;
            case 2:
                //Estudante.Classes();
            case 3:
                cout << "Enter class you want to remove:" << endl;
                string choice1;
                cin >> choice1;
                //Student.remove(choice1);
                cout << "Enter class you want to add:" << endl;
                string choice2;
                cin >> choice2;

                //Estudante.add(choice2);

                /* if(Estudante.add(choice2) == true)
                 * {
                 *      cout << "Class added to you schedule successfully!" << endl;
                 *  }
                 * else if(Estudante.add(choice2) == false)
                 *  {
                 *       cout << "Unable to process request. Class is either full or incompatible with your schedule." << endl;
                 *  }
                 *  */
        }


};
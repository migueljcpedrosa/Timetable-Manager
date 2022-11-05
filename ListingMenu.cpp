//
// Created by m3ped on 05/11/2022.
//

#include "ListingMenu.h"

void ListingMenu::displayListingMenu()
{
    int option;
    cout << "LISTING SUBMENU" << "\n";
    cout << "\n";
    cout << "[0] " << "Quit" << endl;
    cout << "[1] " << "Display all students" << endl;
    cout << "[2] " << "Display student's schedule" << endl;

    cin >> option;

    vector<Estudante> vectorEstudantes;
    map<pair<string, string>, Slot> mapUcClassTimeSlot;
    map<pair<string, string>, int> mapUcClassNumberSudents;
    TTM::csvStudentsClassesReader(vectorEstudantes, mapUcClassNumberSudents);
    TTM::csvClassesReader(mapUcClassTimeSlot);

    switch(option)  //dependendo da escolha do utilizador
    {
        case 0:
            cout << "Goodbye!" <<endl;
            break;
        case 1:
            TTM::displayAllStudents(vectorEstudantes);
            break;
        case 2:
            string studentName;
            string upCode;

            cout << "Insert student name: " << endl;
            cin >> studentName;

            cout << "Insert university code: " << endl;
            cin >> upCode;

            TTM::studentFind(upCode, vectorEstudantes)->displaySchedule(mapUcClassTimeSlot);
            break;
    }


};
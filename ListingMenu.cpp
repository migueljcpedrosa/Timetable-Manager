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
    cout << "[3] " << "Display students with more than n UcClasses (aulas)" << endl;
    cout << "[4] " << "Display students in a UcClass (aula)" << endl;
    cout << "[5] " << "Display students in a specific study year" << endl;

    cin >> option;

    vector<Estudante> vectorEstudantes;
    TTM::sortStudentsByName(vectorEstudantes);
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
        case 2: {
            string studentName;
            string upCode;

            cout << "Insert student name: " << endl;
            cin >> studentName;

            cout << "Insert university code: " << endl;
            cin >> upCode;

            TTM::studentFind(upCode, vectorEstudantes)->displaySchedule(mapUcClassTimeSlot);
            break;
        }
        case 3:
            int n;
            cout << "Insert number of UCs: " << endl;
            cin >> n;

            TTM::displayStudentsWithMoreThanNUcClasses(n, vectorEstudantes, mapUcClassNumberSudents);
            break;
        case 4: {
            string ucCode, classCode;
            cout << "Insert UC code: " << endl;
            cin >> ucCode;
            cout << "Insert Class code: " << endl;
            cin >> classCode;

            TTM::displayStudentInUcClass(ucCode, classCode, vectorEstudantes);
        }
        case 5:
            string year;

            cout << "Insert year: " << endl;
            cin >> year;

            TTM::displayStudentInYear(year, vectorEstudantes);
    }


};
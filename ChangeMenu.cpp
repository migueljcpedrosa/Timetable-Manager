//
// Created by m3ped on 06/11/2022.
//

#include "ChangeMenu.h"

void ChangeMenu::displayChangeMenu()
{
    int option;
    cout << "CHANGE SUBMENU" << "\n";
    cout << "\n";
    cout << "[0] " << "Quit" << endl;
    cout << "[1] " << "Remove student from UcClass (aula)" << endl;
    cout << "[2] " << "Add student to UcClass (aula)" << endl;
    cout << "[3] " << "Change student's UcClass (aula)" << endl;

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
        case 1: {
            string upCode, ucCode, classCode;
            cout << "Insert student's upCode: " << endl;
            cin >> upCode;
            cout << "Insert UcClass' ucCode: " << endl;
            cin >> ucCode;
            cout << "Insert UcClass' classCode: " << endl;
            cin >> classCode;
            TTM::removeStudentFromClass(upCode, ucCode, classCode, vectorEstudantes, mapUcClassTimeSlot);
            TTM::studentFind(upCode, vectorEstudantes)->displayUpClasses();

            break;
        }
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
}
}
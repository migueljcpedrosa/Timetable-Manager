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
            Pedido tempPedidoRemove(upCode, ucCode, classCode);
            TTM::removeStudentFromClass(tempPedidoRemove.getUpCodeChange(), tempPedidoRemove.getUcCode1(), tempPedidoRemove.getClassCode1(), vectorEstudantes, mapUcClassTimeSlot);

            break;
        }
        case 2: {
            string upCode, ucCode, classCode;
            cout << "Insert student's upCode: " << endl;
            cin >> upCode;
            cout << "Insert UcClass' ucCode: " << endl;
            cin >> ucCode;
            cout << "Insert UcClass' classCode: " << endl;
            cin >> classCode;
            TTM::addStudentToClass(upCode, ucCode, classCode, vectorEstudantes, mapUcClassNumberSudents, mapUcClassTimeSlot);
            break;
        }
        case 3:
            string upCodeChange, ucCodeRemove, classCodeRemove, ucCodeAdd, classCodeAdd;
            cout << "Insert student's upCode: " << endl;
            cin >> upCodeChange;
            cout << "Insert UcClass to be removed ucCode: " << endl;
            cin >> ucCodeRemove;
            cout << "Insert UcClass to be removed classCode: " << endl;
            cin >> classCodeRemove;
            cout << "Insert UcClass to be added classCode: " << endl;
            cin >> classCodeAdd;
            cout << "Insert UcClass to be added classCode: " << endl;
            cin >> classCodeAdd;
            TTM::changeStudentToClass(upCodeChange, ucCodeRemove, classCodeRemove, ucCodeAdd, classCodeAdd, vectorEstudantes, mapUcClassNumberSudents, mapUcClassTimeSlot);
            TTM::studentFind(upCodeChange, vectorEstudantes)->displayUpClasses();
            break;
}
}
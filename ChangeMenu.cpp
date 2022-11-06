//
// Created by m3ped on 06/11/2022.
//

#include "ChangeMenu.h"
#include <queue>

void ChangeMenu::displayChangeMenu()
{
    int option;
    string execute;
    cout << "CHANGE SUBMENU" << "\n";
    cout << "\n";
    cout << "[0] " << "Quit" << endl;
    cout << "[1] " << "Remove student from UcClass (aula)" << endl;
    cout << "[2] " << "Add student to UcClass (aula)" << endl;
    cout << "[3] " << "Change student's UcClass (aula)" << endl;


    queue<Pedido> queuePedido;
    vector<Estudante> vectorEstudantes;
    TTM::sortStudentsByName(vectorEstudantes);
    map<pair<string, string>, Slot> mapUcClassTimeSlot;
    map<pair<string, string>, int> mapUcClassNumberSudents;
    TTM::csvStudentsClassesReader(vectorEstudantes, mapUcClassNumberSudents);
    TTM::csvClassesReader(mapUcClassTimeSlot);

    for (int i = 0; i <= 1; i++)
    {
        cin >> option;
        switch(option)  //dependendo da escolha do utilizador
        {
            case 1: {
                string upCode, ucCode, classCode;
                cout << "Insert student's upCode: " << endl;
                cin >> upCode;
                cout << "Insert UcClass' ucCode: " << endl;
                cin >> ucCode;
                cout << "Insert UcClass' classCode: " << endl;
                cin >> classCode;
                Pedido tempPedidoRemove(upCode, ucCode, classCode, "remove");
                //TTM::removeStudentFromClass(tempPedidoRemove.getUpCodeChange(), tempPedidoRemove.getUcCode1(), tempPedidoRemove.getClassCode1(), vectorEstudantes, mapUcClassTimeSlot);
                queuePedido.push(tempPedidoRemove);
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
                //TTM::addStudentToClass(upCode, ucCode, classCode, vectorEstudantes, mapUcClassNumberSudents, mapUcClassTimeSlot);
                Pedido tempPedidoAdd(upCode, ucCode, classCode, "add");
                queuePedido.push(tempPedidoAdd);
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
                //TTM::changeStudentToClass(upCodeChange, ucCodeRemove, classCodeRemove, ucCodeAdd, classCodeAdd, vectorEstudantes, mapUcClassNumberSudents, mapUcClassTimeSlot);
                //TTM::studentFind(upCodeChange, vectorEstudantes)->displayUpClasses();
                Pedido tempPedidoChange(upCodeChange, ucCodeRemove, classCodeRemove, ucCodeAdd, classCodeAdd, "change");
                queuePedido.push(tempPedidoChange);
                break;
        }

    }


    cout << "Execute schedule alteration requests? (yes/no)" << endl;
    cin >> execute;
    if (execute == "yes")
    {
        while(!queuePedido.empty())
        {
            if(queuePedido.front().getPedidoType() == "remove")
            {
                TTM::removeStudentFromClass(queuePedido.front().getUpCodeChange(), queuePedido.front().getUcCode1(), queuePedido.front().getClassCode1(), vectorEstudantes, mapUcClassTimeSlot);
                queuePedido.pop();
            }
            else if(queuePedido.front().getPedidoType() == "add")
            {
                TTM::addStudentToClass(queuePedido.front().getUpCodeChange(), queuePedido.front().getUcCode1(), queuePedido.front().getClassCode1(), vectorEstudantes, mapUcClassNumberSudents, mapUcClassTimeSlot);
                queuePedido.pop();
            }
            else if (queuePedido.front().getPedidoType() == "change")
            {
                TTM::changeStudentToClass(queuePedido.front().getUpCodeChange(), queuePedido.front().getUcCode1(), queuePedido.front().getClassCode1(), queuePedido.front().getUcCode2(), queuePedido.front().getClassCode2(), vectorEstudantes, mapUcClassNumberSudents, mapUcClassTimeSlot);
                queuePedido.pop();
            }
            else
            {
                cout << "Error: invalid request, coud not perform operation." << endl;
                queuePedido.pop();
            }
        }

    }
    else if (execute == "no")
    {
        cout << "Requests not executed. Stored in queue to be executed later." << endl;
    }
}
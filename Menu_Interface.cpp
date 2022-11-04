//
// Created by Joana on 04/11/2022.
//

#include <iostream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Estudante.h"
#include "Slot.h"
#include "TTM.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <utility>

#define students_classes "../students_classes.csv"
#define classes "../classes.csv"
using namespace std;
using namespace TTM;

//include <Student.h>

using namespace std;

int main(){

    //OPÇÕES DO MENU
    cout << "Welcome to Student Schedule Manager!" << endl;
    cout << "\n" << "Please choose one of the following options:" <<endl;
    cout << "0. Quit Menu" << endl << "1. See Student Schedule" << endl << "2. See Student Classes" << endl << "3. Request to change Schedule" <<endl;

    int input;
    cin >> input;

    do
    {
        switch(input)  //dependendo da escolha do utilizador
        {
            case 0:
                cout << "Goodbye!" <<endl;
                return 0;
            case 1:
                //Estudante.showschedule();
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
    }
    while(input !=0); //


}



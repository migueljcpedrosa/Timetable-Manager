#include <iostream>
#include <map>
#include <vector>
#include "Estudante.h"
#include "Slot.h"
#include "TTM.h"
#include "BaseMenu.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <utility>
#include <queue>

#define students_classes "../students_classes.csv"
#define classes "../classes.csv"
using namespace std;
using namespace TTM;


int main() {
    vector<Estudante> vectorEstudantes;
    map<pair<string, string>, Slot> mapUcClassTimeSlot;
    map<pair<string, string>, int> mapUcClassNumberSudents;
    csvStudentsClassesReader(vectorEstudantes, mapUcClassNumberSudents);

    /*
    Slot mySlot(9.5, 1.5, "T");
    for (Estudante itEstudante : vectorEstudantes)
    {
            cout<<itEstudante.getName()<<endl;
            //itEstudante.vectorUcClass.push_back(make_pair(ucCode, classCode));
            cout << itEstudante.vectorUcClass.size() << endl;
            cout << itEstudante.vectorUcClass[0].first << endl;
    }
    cout << "Hello, World!" << std::endl;
    cout << mySlot.getBegin() << endl;
    return 0;
    */
    TTM::removeStudentFromClass("202071557", "L.EIC021", "3LEIC04", vectorEstudantes, mapUcClassTimeSlot);

    csvClassesReader(mapUcClassTimeSlot);
    /*
    for (auto const& x: mapUcClassTimeSlot)
    {
        cout << x.first.first << ", " << x.first.second << ": " << x.second.getBegin() << ";" << x.second.getDuration() << ";" << x.second.getClassType() << endl;
    }
    //cout << mapUcClassTimeSlot.size();

    //cout << vectorEstudantes[0].getUpCode();
     */
    //displayAllStudents(vectorEstudantes);
    sortStudentsByName(vectorEstudantes);
    displayAllStudents(vectorEstudantes);
    vectorEstudantes[3].displaySchedule(mapUcClassTimeSlot);
    //cout <<vectorEstudantes[vectorEstudantes.size() - 3].getName();
    //cout << mapUcClassTimeSlot.size() << endl;
    //mapUcClassNumberSudents.insert({make_pair("b", "d"), 5});
    //mapUcClassNumberSudents.clear();
    //cout << mapUcClassNumberSudents.size() << endl;
    for (auto &e : mapUcClassNumberSudents)
    {
        cout << "aaaa" << e.first.first << "; " << e.first.second << "; " << e.second << endl;
    }
    //TTM::addStudentToClass("202025232", "L.EIC005", "1LEIC07", vectorEstudantes, mapUcClassNumberSudents);
    //TTM::changeStudentToClass("202025232", "L.EIC002", "1LEIC05", "L.EIC023", "3LEIC07", vectorEstudantes, mapUcClassNumberSudents);
    //cout << "Max: " << TTM::maxStudentsinClassFromUc("L.EIC003", mapUcClassNumberSudents) << endl;
    //cout << "Min: " << TTM::minStudentsinClassFromUc("L.EIC003", mapUcClassNumberSudents) << endl;
    //cout << "Imbalance: " << thereIsImbalanceInClassesFromUc("L.EIC003", mapUcClassNumberSudents) << endl;

    displayStudentsWithMoreThanNUcClasses(2, vectorEstudantes, mapUcClassNumberSudents);

    displayStudentInUcClass("L.EIC005", "1LEIC07", vectorEstudantes);

    displayStudentInYear("1", vectorEstudantes);

    string execute;
    BaseMenu::displayBaseMenu();
    cout << "Execute schedule alteration requests? (yes/no)" << endl;
    cin >> execute;
    if (execute == "yes")
    {
        //
    }
    cout << "End";

    return 0;
}

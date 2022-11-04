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


int main() {
    vector<Estudante> vectorEstudantes;
    map<pair<string, string>, Slot> mapUcClassTimeSlot;
    csvStudentsClassesReader(vectorEstudantes);
    map<pair<string, string>, int> mapUcClassNumberSudents;

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
    TTM::removeStudentFromClass("202071557", "L.EIC021", "3LEIC04", vectorEstudantes);

    csvClassesReader(mapUcClassTimeSlot, mapUcClassNumberSudents);
    /*
    for (auto const& x: mapUcClassTimeSlot)
    {
        cout << x.first.first << ", " << x.first.second << ": " << x.second.getBegin() << ";" << x.second.getDuration() << ";" << x.second.getClassType() << endl;
    }
    //cout << mapUcClassTimeSlot.size();

    //cout << vectorEstudantes[0].getUpCode();
     */
    //displayAllStudents(vectorEstudantes);
    sortStudentsByUpCode(vectorEstudantes);
    displayAllStudents(vectorEstudantes);
    vectorEstudantes[3].displaySchedule(mapUcClassTimeSlot);
    //cout <<vectorEstudantes[vectorEstudantes.size() - 3].getName();
    auto itt = mapUcClassNumberSudents.find({make_pair("1LEIC04","L.EIC001")});
    cout << mapUcClassTimeSlot.size() << endl;
    //mapUcClassNumberSudents.insert({make_pair("b", "d"), 5});
    //mapUcClassNumberSudents.clear();
    cout << mapUcClassNumberSudents.size() << endl;
    cout << "End";

    return 0;
}

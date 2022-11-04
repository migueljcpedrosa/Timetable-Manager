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

    csvClassesReader(mapUcClassTimeSlot);
    /*
    for (auto const& x: mapUcClassTimeSlot)
    {
        cout << x.first.first << ", " << x.first.second << ": " << x.second.getBegin() << ";" << x.second.getDuration() << ";" << x.second.getClassType() << endl;
    }
    //cout << mapUcClassTimeSlot.size();

    //cout << vectorEstudantes[0].getUpCode();
     */
    displayAllStudents(vectorEstudantes);
    cout <<vectorEstudantes[vectorEstudantes.size() - 1].getName();
    cout << "End";

    return 0;
}

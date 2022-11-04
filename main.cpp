#include <iostream>
#include <map>
#include <vector>
#include "Estudante.h"
#include "Slot.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <utility>

#define students_classes "../students_classes.csv"
#define classes "../classes.csv"
using namespace std;


void csvStudentsClassesReader(vector<Estudante>& vectorEstudantes)
{
    // File variables.
    string studentCode, studentName, ucCode, classCode;

    // Filename
    ifstream file(students_classes); // Opens the file.

    if (file.is_open()) // Checks if the file is open.
    {
        // Skip the first line (ClassCode,UcCode,Weekday,StartHour,Duration,Type).
        string line;
        getline(file, line);
        bool estudanteExists = false;

        // While the end of the file is not reached.
        while (!file.eof())
        {
            //{class_code, uc_code, weekday, start_hour, duration, type}
            getline(file, studentCode, ',');

            getline(file, studentName, ',');

            getline(file, ucCode, ',');

            getline(file, classCode, '\n');;


            Estudante estudanteTemp(studentName, studentCode);

            for (int i = 0; i < vectorEstudantes.size(); i++)
            {
                if (vectorEstudantes[i].getUpCode() == studentCode)
                {
                    estudanteExists = true;
                    //cout<<itEstudante.getName()<<endl;
                    vectorEstudantes[i].vectorUcClass.emplace_back(ucCode, classCode);
                    //cout << vectorEstudantes[i].vectorUcClass.size();
                    //cout << itEstudante.vectorUcClass[0].first << endl;
                    //cout << itEstudante.vectorUcClass[1].second << endl;
                }
            }



            if (!estudanteExists)
            {
                estudanteTemp.vectorUcClass.emplace_back(ucCode, classCode);
                vectorEstudantes.push_back(estudanteTemp);
            }

            estudanteExists = false;
        }

        file.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}


void csvClassesReader(map<pair<string,string>, Slot>& mapUcClassTimeSlot)
{ //csv_classes_reader
    // File variables.


    string classCode, ucCode, weekday, cType;
    string startHour, duration;


    // Filename
    ifstream file(classes); // Opens the file.

    if (file.is_open()) // Checks if the file is open.
    {
        // Skip the first line (ClassCode,UcCode,Weekday,StartHour,Duration,Type).
        string line;
        getline(file, line);

        // While the end of the file is not reached.
        while (!file.eof()) {
            //{class_code, uc_code, weekday, start_hour, duration, type}
            getline(file, classCode, ',');

            getline(file, ucCode, ',');

            getline(file, weekday, ',');
            getline(file, startHour, ',');
            getline(file, duration, ',');
            getline(file, cType, '\n');

            Slot tempSlot(stof(startHour), stof(duration), cType);
            cout << tempSlot.getBegin() + 2;
            mapUcClassTimeSlot.insert({make_pair(ucCode, classCode), tempSlot});
        }

        file.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}


int main() {
    vector<Estudante> vectorEstudantes;
    map<pair<string,string>, Slot> mapUcClassTimeSlot;
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
    csvClassesReader(mapUcClassTimeSlot);
    for (auto const& x: mapUcClassTimeSlot)
    {
        cout << x.first.first << ", " << x.first.second << ": " << x.second.getBegin() << ";" << x.second.getDuration() << ";" << x.second.getClassType() << endl;
    }
    cout << mapUcClassTimeSlot.size();
    cout << "End";
}

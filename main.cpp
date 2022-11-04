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
using namespace std;


void csvStudentsClassesReader(vector<Estudante>& vectorEstudantes)
{
    // File variables.
    string studentCode, studentName, ucCode, classCode;

    // Filename
    ifstream coeff(students_classes); // Opens the file.

    if (coeff.is_open()) // Checks if the file is open.
    {
        // Skip the first line (ClassCode,UcCode,Weekday,StartHour,Duration,Type).
        string line;
        getline(coeff, line);
        bool estudanteExists = false;

        // While the end of the file is not reached.
        while (!coeff.eof())
        {
            //{class_code, uc_code, weekday, start_hour, duration, type}
            getline(coeff, studentCode, ',');

            getline(coeff, studentName, ',');

            getline(coeff, ucCode, ',');

            getline(coeff, classCode, '\n');;


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

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}


void csvClassesReader(const string& filename) { //csv_classes_reader
    // File variables.
    string classCode, ucCode, weekday, cType;
    string startHour, duration;


    // Filename
    ifstream coeff(filename); // Opens the file.

    if (coeff.is_open()) // Checks if the file is open.
    {
        // Skip the first line (ClassCode,UcCode,Weekday,StartHour,Duration,Type).
        string line;
        getline(coeff, line);

        // While the end of the file is not reached.
        while (!coeff.eof()) {
            //{class_code, uc_code, weekday, start_hour, duration, type}
            getline(coeff, classCode, ',');

            getline(coeff, ucCode, ',');

            getline(coeff, weekday, ',');
            getline(coeff, startHour, ',');
            getline(coeff, duration, ',');
            getline(coeff, cType, '\n');

        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}


int main() {
    vector<Estudante> vectorEstudantes;
    map<pair<string,string>, string> mapUcClassTimeSlot;
    csvStudentsClassesReader(vectorEstudantes);
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
}

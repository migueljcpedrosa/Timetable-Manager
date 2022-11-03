#include <iostream>
#include <map>
#include <vector>
#include "Estudante.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#define students_classes "../students_classes.csv"
using namespace std;


void csv_students_classes_reader(vector<Estudante>& vectorEstudantes)
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

            for (Estudante itEstudante : vectorEstudantes)
            {
                if (itEstudante.getUpCode() == studentCode)
                {
                    estudanteExists = true;
                    itEstudante.vectorUcClass.push_back({ucCode, classCode});
                }
            }

            if (!estudanteExists)//if estudante doesn't exist create a new object
            {
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

int main() {
    vector<Estudante> vectorEstudantes;
    map<pair<string,string>,int> mapUcClassTimeSlot;
    csv_students_classes_reader(vectorEstudantes);
    for (Estudante estudante : vectorEstudantes)
    {
        cout<<estudante.getName()<<endl;
    }
    cout << vectorEstudantes.size();
    cout << "Hello, World!" << std::endl;
    return 0;
}

#include <iostream>
#include <map>
#include <vector>
#include "Estudante.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


void csv_students_classes_reader(const string& filename, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code)
{
    vector<Estudante> vectorEstudantes;
    // File variables.
    string student_code, student_name, uc_code, class_code;

    // Filename
    ifstream coeff(filename); // Opens the file.

    int number_students = 0;

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
            getline(coeff, student_code, ',');
            v_student_code.push_back(student_code);

            getline(coeff, student_name, ',');
            v_student_name.push_back(student_name);

            getline(coeff, uc_code, ',');
            v_uc_code.push_back(uc_code);

            getline(coeff, class_code, '\n');
            v_class_code.push_back(class_code);

            for (Estudante itEstudante : vectorEstudantes)
            {
                if (itEstudante.getUpCode() == student_code)
                {
                    estudanteExists = true;
                }
            }

            if (!estudanteExists)//if estudante doesn't exist create a new object
            {
                Estudante estudanteTemp(student_name, student_code);
            }


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
    cout << "Hello, World!" << std::endl;
    return 0;
}

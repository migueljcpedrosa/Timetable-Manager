//
// Created by m3ped on 04/11/2022.
//
#include "TTM.h"
#include "UcTurma.h"

using namespace std;


void TTM::csvStudentsClassesReader(vector<Estudante>& vectorEstudantes)
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


void TTM::csvClassesReader(map<pair<string,string>, Slot>& mapUcClassTimeSlot, map<pair<string, string>, int>& mapUcClassNumberSudents)
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

            Slot tempSlot(weekday, stof(startHour), stof(duration), cType);
            mapUcClassTimeSlot.insert({make_pair(ucCode, classCode), tempSlot});

            auto it = mapUcClassNumberSudents.find(make_pair(ucCode, classCode));
            if (it != mapUcClassNumberSudents.end())
            {
                it->second++;
            }
            else
            {
                mapUcClassNumberSudents.insert({make_pair(ucCode, classCode), 1});
            }
        }

        file.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}


void TTM::removeStudentFromClass(string upCode, string ucCode, string classCode, vector<Estudante>& vectorEstudantes)
{
    vector<Estudante>::iterator itEstudante = TTM::studentFind(upCode, vectorEstudantes);

    cout << "Before UpClass removal:" << "\n";
    itEstudante->displayUpClasses();

    for (int i = 0; i < itEstudante->vectorUcClass.size(); i++)
    {
        if (itEstudante->vectorUcClass[i].first == ucCode && itEstudante->vectorUcClass[i].second == classCode)
        {
            itEstudante->vectorUcClass.erase(itEstudante->vectorUcClass.begin() + i);
        }
    }
    cout << "\n";
    cout << "After UpClass removal:" << "\n";
    itEstudante->displayUpClasses();

    cout << "\n";

}


void TTM::addStudentToClass(string upCode, string ucCode, string classCode, vector<Estudante>& vectorEstudantes, map<pair<string, string>, int> mapUcClassNumberSudents)
{
    vector<Estudante>::iterator itEstudante = TTM::studentFind(upCode, vectorEstudantes);

    cout << "Before UpClass removal:" << "\n";
    itEstudante->displayUpClasses();

    for (int i = 0; i < itEstudante->vectorUcClass.size(); i++)
    {
        if (itEstudante->vectorUcClass[i].first == ucCode && itEstudante->vectorUcClass[i].second == classCode)
        {
            cout << "The student is already in this UcClass." << endl;
        }
        else
        {
            if (mapUcClassNumberSudents.find(make_pair(ucCode, classCode))->second < UcTurma::ucTurmaCapacity)
            {
                itEstudante->vectorUcClass.push_back(make_pair(ucCode, classCode));
                auto mapUcClassNumberSudentsit = mapUcClassNumberSudents.find(make_pair(ucCode, classCode));
                mapUcClassNumberSudentsit->second++;
            }
            else
            {
                cout << "UcClass' capacity is full. Student couldn't be added." << endl;
            }
        }
    }
    cout << "\n";
    cout << "After UpClass removal:" << "\n";
    itEstudante->displayUpClasses();

    cout << "\n";

}


vector<Estudante>::iterator TTM::studentFind(string upCode, vector<Estudante>& vectorEstudantes)
{
    struct MatchString
    {
        MatchString(const std::string& s) : s_(s) {}
        bool operator()(const Estudante obj) const
        {
            return obj.getUpCode() == s_;
        }
    private:
        const std::string& s_;
    };

    vector<Estudante>::iterator itEstudante = find_if(vectorEstudantes.begin(), vectorEstudantes.end(), MatchString(upCode));

    return itEstudante;
}

void TTM::displayAllStudents(vector<Estudante>& vectorEstudantes)
{
    for (int i = 0; i < vectorEstudantes.size(); i++)
    {
        cout << vectorEstudantes[i].getName() << ";" << vectorEstudantes[i].getUpCode() << "\n";
    }

    cout << "\n";
}

void TTM::sortStudentsByUpCode(vector<Estudante> &vectorEstudantes) {
    std::sort(vectorEstudantes.begin(), vectorEstudantes.end(),
              [](const Estudante &x, const Estudante &y) {
// compare last names first
                  if (x.getUpCode() != y.getUpCode()) {
                      return x.getUpCode() < y.getUpCode();
                  }

// compare first names only if the last names are equal
                  return x.getUpCode() < y.getUpCode();
              });
}

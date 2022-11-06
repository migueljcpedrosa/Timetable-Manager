//
// Created by m3ped on 04/11/2022.
//
#include "TTM.h"
#include "UcTurma.h"

using namespace std;


void TTM::csvStudentsClassesReader(vector<Estudante>& vectorEstudantes, map<pair<string, string>, int>& mapUcClassNumberSudents)
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

            getline(file, classCode, '\n');


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

            auto it = mapUcClassNumberSudents.find(make_pair(ucCode, classCode));
            if (it != mapUcClassNumberSudents.end())
            {
                it->second++;
            }
            else
            {
                mapUcClassNumberSudents.insert({make_pair(ucCode, classCode), 1});
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


void TTM::csvClassesReader(map<pair<string,string>, Slot>& mapUcClassTimeSlot)
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

        }

        file.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}


void TTM::removeStudentFromClass(string upCode, string ucCode, string classCode, vector<Estudante>& vectorEstudantes, map<pair<string, string>, Slot> mapUcClassTimeSlot)
{
    cout << "Removal operation in course." << "\n";
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


void TTM::addStudentToClass(string upCode, string ucCode, string classCode, vector<Estudante>& vectorEstudantes, map<pair<string, string>, int> mapUcClassNumberSudents, map<pair<string, string>, Slot> mapUcClassTimeSlot)
{
    cout << "Addition operation in course." << "\n";
    vector<Estudante>::iterator itEstudante = TTM::studentFind(upCode, vectorEstudantes);
    bool studentAlreadyInUcClass = false;
    cout << "Before adding student to the requested class:" << "\n";
    itEstudante->displayUpClasses();

    for (int i = 0; i < itEstudante->vectorUcClass.size(); i++)
    {
        if (itEstudante->vectorUcClass[i].first == ucCode && itEstudante->vectorUcClass[i].second == classCode)
        {
            studentAlreadyInUcClass = true;
            cout << "The student is already in this UcClass." << endl;
            break;
        }
    }

    if (!studentAlreadyInUcClass)
    {
        mapUcClassNumberSudents.find(make_pair(ucCode, classCode))->second++; //In case the addition occurs this will be the new occupation value. Will be used to check whether the addition will cause imbalance.
        if (mapUcClassNumberSudents.find(make_pair(ucCode, classCode))->second < UcTurma::ucTurmaCapacity + 1 && !thereIsImbalanceInClassesFromUc(ucCode, mapUcClassNumberSudents) && !coincidentTimeSlot(upCode, ucCode, classCode, vectorEstudantes, mapUcClassTimeSlot))
        {
            itEstudante->vectorUcClass.push_back(make_pair(ucCode, classCode));
            //cout << "map: " << mapUcClassNumberSudentsit->second;
            //cout << "map: " << mapUcClassNumberSudentsit->second;
        }
        else
        {
            mapUcClassNumberSudents.find(make_pair(ucCode, classCode))->second--;
            cout << "UcClass' capacity is full. Student couldn't be added." << endl;
        }
    }

    cout << "\n";
    cout << "After adding student to the requested UcClass:" << "\n";
    itEstudante->displayUpClasses();

    cout << "\n";

}


void TTM::changeStudentToClass(string upCodeChange, string ucCodeRemove, string classCodeRemove, string ucCodeAdd, string classCodeAdd, vector<Estudante>& vectorEstudantes, map<pair<string, string>, int> mapUcClassNumberSudents, map<pair<string, string>, Slot> mapUcClassTimeSlot)
{
    cout << "Change operation in course." << endl;

    if (mapUcClassNumberSudents.find(make_pair(ucCodeAdd, classCodeAdd))->second < UcTurma::ucTurmaCapacity)
    {
        TTM::removeStudentFromClass(upCodeChange, ucCodeRemove, classCodeRemove, vectorEstudantes, mapUcClassTimeSlot);
        TTM::addStudentToClass(upCodeChange, ucCodeAdd, classCodeAdd, vectorEstudantes, mapUcClassNumberSudents, mapUcClassTimeSlot);
    }
    else
    {
        cout << "Couldn't change student's class." << endl;
    }

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
    TTM::sortStudentsByName(vectorEstudantes);
    for (int i = 0; i < vectorEstudantes.size(); i++)
    {
        cout << vectorEstudantes[i].getName() << "; " << vectorEstudantes[i].getUpCode() << "\n";
    }

    cout << "\n";
}


void TTM::sortStudentsByName(vector<Estudante> &vectorEstudantes) {
    std::sort(vectorEstudantes.begin(), vectorEstudantes.end(),
              [](const Estudante &x, const Estudante &y) {
// compare last names first
                  if (x.getName() != y.getName()) {
                      return x.getName() < y.getName();
                  }

// compare first names only if the last names are equal
                  return x.getName() < y.getName();
              });
}

int TTM::maxStudentsinClassFromUc(string ucCode, map<pair<string, string>, int> mapUcClassNumberSudents)
{
    map<pair<string, string>, int>::iterator it;
    int max = -1;
    for (it = mapUcClassNumberSudents.begin(); it != mapUcClassNumberSudents.end(); it++)
    {
        if (it->first.first == ucCode)
        {
            if (it->second > max)
            {
                max = it->second;
            }
        }
    }

    return max;
}



int TTM::minStudentsinClassFromUc(string ucCode, map<pair<string, string>, int> mapUcClassNumberSudents)
{
    map<pair<string, string>, int>::iterator it;
    int min = INT_MAX;
    for (it = mapUcClassNumberSudents.begin(); it != mapUcClassNumberSudents.end(); it++)
    {
        if (it->first.first == ucCode)
        {
            if (it->second < min)
            {
                min = it->second;
            }
        }
    }

    return min;
}

bool TTM::thereIsImbalanceInClassesFromUc(string ucCode, map<pair<string, string>, int> mapUcClassNumberSudents)
{
    cout <<"Max"<< maxStudentsinClassFromUc(ucCode, mapUcClassNumberSudents) << endl;
    cout <<"Min"<< minStudentsinClassFromUc(ucCode, mapUcClassNumberSudents) << endl;
    if (maxStudentsinClassFromUc(ucCode, mapUcClassNumberSudents) - minStudentsinClassFromUc(ucCode, mapUcClassNumberSudents) >= 4 )
    {
        return true;
    }

    return false;
}

bool TTM::coincidentTimeSlot(string upCode, string ucCode, string classCode, vector<Estudante>& vectorEstudantes, map<pair<string, string>, Slot> mapUcClassTimeSlot)
{
    auto mapUcClassTimeSlotIt = mapUcClassTimeSlot.find(make_pair(ucCode, classCode));
    string weekday = mapUcClassTimeSlotIt->second.getWeekDay();
    float begin = mapUcClassTimeSlotIt->second.getBegin();
    float duration = mapUcClassTimeSlotIt->second.getDuration();
    string classType = mapUcClassTimeSlotIt->second.getClassType();

    auto vectorStudentIt = studentFind(upCode, vectorEstudantes);
    for (auto studentUcClassesit : vectorStudentIt->vectorUcClass)
    {
        auto tempUcClassit = mapUcClassTimeSlot.find(make_pair(studentUcClassesit.first, studentUcClassesit.second));
        if (       weekday == tempUcClassit->second.getWeekDay()
                && begin == tempUcClassit->second.getBegin()
                && duration == tempUcClassit->second.getDuration()
                && (classType == "TP" && tempUcClassit->second.getClassType() == "TP") )
        {
            return true;
        }
    }

    return false;
}


void TTM::displayStudentsWithMoreThanNUcClasses(int n, vector<Estudante> &vectorEstudantes, map<pair<string, string>, int> mapUcClassNumberSudents)
{
    TTM::sortStudentsByName(vectorEstudantes);
    cout << "Students with more than " << n << " UCClasses (Aulas):" << endl;
    for (auto itEstudante : vectorEstudantes)
    {
        if (itEstudante.vectorUcClass.size() > n)
        {
            cout << itEstudante.getName() << "; " << itEstudante.getUpCode() << endl;
        }
    }

    cout << "\n";
}

void TTM::displayStudentInUcClass(string ucCode, string classCode, vector<Estudante> &vectorEstudantes)
{
    TTM::sortStudentsByName(vectorEstudantes);
    cout << "Students in the " << ucCode << "; " << classCode << ": " << endl;
    for (auto itEstudante : vectorEstudantes)
    {
        if ( find(itEstudante.vectorUcClass.begin(), itEstudante.vectorUcClass.end(), make_pair(ucCode, classCode)) != itEstudante.vectorUcClass.end() )
        {
            cout << itEstudante.getName() << "; " << itEstudante.getUpCode() << endl;
        }
    }

    cout << "\n";
}

void TTM::displayStudentInYear(string year, vector<Estudante> &vectorEstudantes)
{
    sortStudentsByName(vectorEstudantes);
    bool studentInYear = false;

    string tempClassCode;
    cout << "Students in year " << year << ": " << endl;

    for (auto itEstudante : vectorEstudantes)
    {
        for (auto ucClass : itEstudante.vectorUcClass)
        {
            tempClassCode = ucClass.second;
            if (tempClassCode.compare(0,1,year) == 0)
            {
                studentInYear = true;
                //cout << "inside";
                break;
            }
            //cout << itEstudante.getName() << "; " << itEstudante.getUpCode() << endl;
            studentInYear = false;
        }

        if (studentInYear)
        {
            cout << itEstudante.getName() << "; " << itEstudante.getUpCode() << endl;
        }
    }


}

void TTM::writeStudentsClassesUpdated(vector<Estudante> vectorEstudantes)
{
    ofstream file(students_classes_updated);

    file << "UpCode,StudentName,UcCode,ClassCode" << "\n";
    for(Estudante estudanteTemp : vectorEstudantes)
    {
        for(auto ucClassTemp : estudanteTemp.vectorUcClass)
        {
            file << estudanteTemp.getUpCode() << "," << estudanteTemp.getName() << "," << ucClassTemp.first << "," << ucClassTemp.second << "\n";
        }
    }
}
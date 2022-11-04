//
// Created by m3ped on 03/11/2022.
//

#ifndef UNTITLED2_ESTUDANTE_H
#define UNTITLED2_ESTUDANTE_H

#include <vector>
#include <string>
#include <utility>
using namespace std;


//#include "aula.h"
#include <string>
#include <vector>
using namespace std;

/**
 * A class to store the general information about a Student (Estudante)
 */
class Estudante {
public:
    vector<pair<string, string>> vectorUcClass;
    //Estudante();
    Estudante(string name, string upCode);
    string getName() const;
    string getUpCode() const;
    void readStudent(const string& filename);
    void displayUpClasses();
private:
    string name;
    string upCode;

};

#endif //UNTITLED2_ESTUDANTE_H

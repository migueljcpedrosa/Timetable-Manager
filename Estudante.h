//
// Created by Miguel Pedrosa and Joana Marques on 01/11/2022.
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
#include <map>
#include "Slot.h"

using namespace std;

/**
 * A class to store the general information about a Student (Estudante)
 */
class Estudante {
    public:
        /** Estudante Constructor
        * @param name the name of the student
        * @param upCode the university code of the student
        */;
        Estudante(string name, string upCode);

        /**
        * Get name
        *
        * @returns name
        */
        string getName() const;

        /**
        * Get upCode
        *
        * @returns upCode
        */
        string getUpCode() const;

        /**
        * Displays the UpClasses of a student
        *
        * @returns void
        */
        void displayUpClasses();

        /**
        * Displays the Schedule of a student
        * @param mapUcClassTimeSlot a map that links each ucClass to it's correspondent timeSlot
        *
        * @returns void
        */
        void displaySchedule(map<pair<string,string>, Slot>& mapUcClassTimeSlot);

        vector<pair<string, string>> vectorUcClass; /**< A vector of pairs made by a ucCode and a classCode*/

    private:
        string name; /**< The student's name*/
        string upCode; /**< The student's university code*/

};

#endif //UNTITLED2_ESTUDANTE_H

//
// Created by m3ped on 04/11/2022.
//

#ifndef UNTITLED2_TTM_H
#define UNTITLED2_TTM_H

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

/**
 * A namespace to store the functions that don't belong to any specific class
 */
namespace TTM {
    /** students_classes.csv Reader
    * @param vectorEstudantes a vector that stores all the students
    */
    void csvStudentsClassesReader(vector<Estudante> &vectorEstudantes);

    /** classes.csv Reader
    * @param mapUcClassTimeSlot a map that links each ucClass to it's correspondent timeSlot
    */
    void csvClassesReader(map<pair<string, string>, Slot> &mapUcClassTimeSlot, map<pair<string, string>, int>& UcClassNumberSudents);

    /** Removes Student from Class (Aula)
    * @param upCode a student's upCode
    * @param ucCode the class's (aula) ucCode
    * @param ucCode the class's (aula) classCode
    * @param vectorEstudantes a vector that stores all the students
    */
    void removeStudentFromClass(string upCode, string ucCode, string classCode, vector<Estudante> &vectorEstudantes);

    /** Adds Student to Class (Aula)
    * @param upCode a student's upCode
    * @param ucCode the class's (aula) ucCode
    * @param ucCode the class's (aula) classCode
    * @param vectorEstudantes a vector that stores all the students
    */
    void addStudentToClass(string upCode, string ucCode, string classCode, vector<Estudante>& vectorEstudantes, map<pair<string, string>, int> mapUcClassNumberSudents);

    /** Finds a student with a specific university code in the students' vector
    * @param upCode a student's upCode
    * @param ucCode the class's (aula) ucCode
    * @param ucCode the class's (aula) classCode
    * @param vectorEstudantes a vector that stores all the students
    * @returns the iterator that corresponds to the student
    */
    vector<Estudante>::iterator studentFind(string upCode, vector<Estudante> &vectorEstudantes);

    /** Displays the name and university code of each student in a students' vector
    * @param vectorEstudantes a vector that stores all the students
    */
    void displayAllStudents(vector<Estudante> &vectorEstudantes);

    /** Sorts the students in a students' vector by their university code
    * @param vectorEstudantes a vector that stores all the students
    */
    void sortStudentsByUpCode(vector<Estudante> &vectorEstudantes);
}

#endif //UNTITLED2_TTM_H
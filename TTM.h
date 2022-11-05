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
    void csvStudentsClassesReader(vector<Estudante> &vectorEstudantes, map<pair<string, string>, int>& mapUcClassNumberSudents);

    /** classes.csv Reader
    * @param mapUcClassTimeSlot a map that links each ucClass to it's correspondent timeSlot
    */
    void csvClassesReader(map<pair<string, string>, Slot> &mapUcClassTimeSlot);

    /** Removes Student from Class (Aula)
    * @param upCode the student's upCode
    * @param ucCode the class's (aula) ucCode
    * @param classCode the class's (aula) classCode
    * @param vectorEstudantes a vector that stores all the students
    */
    void removeStudentFromClass(string upCode, string ucCode, string classCode, vector<Estudante> &vectorEstudantes);

    /** Adds Student to Class (Aula)
    * @param upCode the student's upCode
    * @param ucCode the class's (aula) ucCode
    * @param classCode the class's (aula) classCode
    * @param vectorEstudantes a vector that stores all the students
    */
    void addStudentToClass(string upCode, string ucCode, string classCode, vector<Estudante>& vectorEstudantes, map<pair<string, string>, int> mapUcClassNumberSudents);

    /** Changes Student's Class (Aula)
    * @param upCodeChange the student's upCode
    * @param ucCodeRemove the class's (aula) ucCode
    * @param classCodeRemove the class's (aula) classCode
    * @param ucCodeAdd the class's (aula) ucCode
    * @param classCodeAdd the class's (aula) classCode
    * @param vectorEstudantes a vector that stores all the students
    */
    void changeStudentToClass(string upCodeChange, string ucCodeRemove, string classCodeRemove, string ucCodeAdd, string classCodeAdd, vector<Estudante>& vectorEstudantes, map<pair<string, string>, int> mapUcClassNumberSudents);

    /** Finds a student with a specific university code in the students' vector
    * @param upCode a student's upCode
    * @param ucCode the class's (aula) ucCode
    * @param classCode the class's (aula) classCode
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

    /** Finds the maximum number of students in any class from a specific Uc
    * @param ucCode the class's (aula) ucCode
    * @param vectorEstudantes a map that links each ucClass to it's current student number
    * @returns the integer value that corresponds to the maximum student number in any class from the specified Uc
    */
    int maxStudentsinClassFromUc(string ucCode, map<pair<string, string>, int> mapUcClassNumberSudents);

    /** Finds the minimum number of students in any class from a specific Uc
    * @param ucCode the class's (aula) ucCode
    * @param vectorEstudantes a map that links each ucClass to it's current student number
    * @returns the integer value that corresponds to the minimum student number in any class from the specified Uc
    */
    int minStudentsinClassFromUc(string ucCode, map<pair<string, string>, int> mapUcClassNumberSudents);

    /** Checks whether there's imbalance in the number of students from different classes of the same Uc (if difference between max occupation and min occupation is >= 4)
    * @param ucCode the class's (aula) ucCode
    * @param vectorEstudantes a map that links each ucClass to it's current student number
    * @returns boolean value that checks whether there's imbalance in the number of students from different classes of the same Uc
    */
    bool thereIsImbalanceInClassesFromUc(string ucCode, map<pair<string, string>, int> mapUcClassNumberSudents);

    /** Checks whether there's imbalance in the number of students from different classes of the same Uc (if difference between max occupation and min occupation is >= 4)
    * @param ucCode the class's (aula) ucCode
    * @param vectorEstudantes a map that links each ucClass to it's current student number
    * @returns boolean value that checks whether there's imbalance in the number of students from different classes of the same Uc
    */
    bool coincidentTimeSlot(string upCode, string ucCode, string classCode, vector<Estudante>& vectorEstudantes, map<pair<string, string>, Slot> mapUcClassTimeSlot);

}

#endif //UNTITLED2_TTM_H
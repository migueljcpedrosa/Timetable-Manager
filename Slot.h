//
// Created by Miguel Pedrosa and Joana Marques on 01/11/2022.
//

#ifndef UNTITLED2_SLOT_H
#define UNTITLED2_SLOT_H

#include <string>
using namespace std;

/**
 * A class to store the general information about the starting hour, duration and type of a Class (Aula)
 */
class Slot{
    public:
        /** Slot Constructor
        * @param begin the starting hour of the class (aula)
        * @param duration the duration of the class (aula)
        * @param classType the type of the class (aula T or TP)
        */
        Slot(string weekday, float begin, float duration, string classType);

        /**
        * Get weekDay
        *
        * @returns weekDay
        */
        string getWeekDay() const;

        /**
        * Get begin
        *
        * @returns begin
        */
        float getBegin() const;

        /**
        * Get the duration
        *
        * @returns the duration
        */
        float getDuration() const;

        /**
        * Get the classType
        *
        * @returns the classType
        */
        string getClassType() const;
    private:
        string weekDay;/**< Weekday of the class (aula)*/
        float begin;/**< Starting hour of the class (aula)*/
        float duration;/**< Duration of the class (aula)*/
        string classType;/**< Type of the class (aula: T or TP)*/
};


#endif //UNTITLED2_SLOT_H
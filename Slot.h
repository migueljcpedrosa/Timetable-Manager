//
// Created by m3ped on 03/11/2022.
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
        Slot(float begin, float duration, string classType);
        float getBegin() const;
        float getDuration() const;
        string getClassType() const;
    private:
        float begin;
        float duration;
        string classType;
};


#endif //UNTITLED2_SLOT_H

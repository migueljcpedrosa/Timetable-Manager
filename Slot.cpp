//
// Created by m3ped on 03/11/2022.
//

#include "Slot.h"

Slot::Slot(float begin, float duration, string classType)
{
    this->begin = begin;
    this->duration = duration;
    this->classType = classType;
}

float Slot::getBegin() const
{
    return this->begin;
}

float Slot::getDuration() const
{
    return this->duration;
}

string Slot::getClassType() const
{
    return this->classType;
}
//
// Created by Miguel Pedrosa e Joana Marques on 01/11/2022.
//

#include "Slot.h"

Slot::Slot(string weekday, float begin, float duration, string classType)
{
    this->weekDay = weekday;
    this->begin = begin;
    this->duration = duration;
    this->classType = classType;
}

string Slot::getWeekDay() const
{
    return weekDay;
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
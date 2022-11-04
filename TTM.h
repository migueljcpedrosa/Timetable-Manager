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

namespace TTM
{
    void csvStudentsClassesReader(vector<Estudante>& vectorEstudantes);
}

#endif //UNTITLED2_TTM_H

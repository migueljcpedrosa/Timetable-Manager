//
// Created by m3ped on 06/11/2022.
//

#ifndef UNTITLED2_PEDIDOADD_H
#define UNTITLED2_PEDIDOADD_H

#include <iostream>
#include <map>
#include <vector>
#include "Estudante.h"
#include "Slot.h"
#include "TTM.h"
#include "BaseMenu.h"
#include "ChangeMenu.h"
#include "ListingMenu.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <utility>

class PedidoAdd {
    public:
    const string getUpCode() const;

    const string getUcCode() const;

    const string getClassCode() const;

private:
        string upCode;
        string ucCode;
        string classCode;
};


#endif //UNTITLED2_PEDIDOADD_H
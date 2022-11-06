//
// Created by m3ped on 06/11/2022.
//

#ifndef UNTITLED2_PEDIDOCHANGE_H
#define UNTITLED2_PEDIDOCHANGE_H

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


class PedidoChange {
public:
    const string getUpCodeChange() const;

    const string getUcCodeRemove() const;

    const string getClassCodeRemove() const;

    const string getUcCodeAdd() const;

    const string getClassCodeAdd() const;

private:
    string upCodeChange;
    string ucCodeRemove;
    string classCodeRemove;
    string ucCodeAdd;
    string classCodeAdd;

};


#endif //UNTITLED2_PEDIDOCHANGE_H

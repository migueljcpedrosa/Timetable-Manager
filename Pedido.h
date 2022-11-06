//
// Created by m3ped on 06/11/2022.
//

#ifndef UNTITLED2_PEDIDO_H
#define UNTITLED2_PEDIDO_H

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


class Pedido {
public:
    Pedido(const string upCodeChange, const string ucCode1, const string classCode1);

    Pedido(const string upCodeChange,  const string ucCode1, const string classCode1, const string ucCode2, const string classCode2);

    const string getUpCodeChange() const;

    const string getUcCode1() const;

    const string getClassCode1() const;

    const string getUcCode2() const;

    const string getClassCode2() const;

private:
    string upCodeChange;
    string ucCode1;
    string classCode1;
    string ucCode2;
    string classCode2;

};


#endif //UNTITLED2_PEDIDO_H

//
// Created by Miguel Pedrosa e Joana Marques on 01/11/2022.
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
#include <queue>

using namespace std;

/**
 * A class to store the general information about a request (Pedido)
 */
class Pedido {
    public:
        /** Pedido Constructor
        * @param upCodeChange the upCode of the student whose classes we want to change
        * @param ucCode1 the ucCode of the ucClass we want to add or remove
        * @param classCode1 the classCode of the ucClass we want to add or remove
        * @param pedidoType the type of request (add or remove)
        */
        Pedido(const string upCodeChange, const string ucCode1, const string classCode1, string pedidoType);

        /** Pedido Constructor
        * @param upCodeChange the upCode of the student whose classes we want to change
        * @param ucCode1 the ucCode of the ucClass we want to remove
        * @param classCode1 the classCode of the ucClass we want to remove
        * @param ucCode2 the ucCode of the ucClass we want to add
        * @param classCode2 the classCode of the ucClass we want to add
        * @param pedidoType the type of request (change)
        */
        Pedido(const string upCodeChange,  const string ucCode1, const string classCode1, const string ucCode2, const string classCode2, string pedidoType);

        /**
        * Get the upCodeChange
        *
        * @returns the upCodeChange
        */
        const string getUpCodeChange() const;

        /**
        * Get the ucCode1
        *
        * @returns the ucCode1
        */
        const string getUcCode1() const;

        /**
        * Get the classCode1
        *
        * @returns the classCode1
        */
        const string getClassCode1() const;

        /**
        * Get the ucCode2
        *
        * @returns the ucCode2
        */
        const string getUcCode2() const;

        /**
        * Get the classCode2
        *
        * @returns the classCode2
        */
        const string getClassCode2() const;

        /**
        * Get the pedidoType
        *
        * @returns the pedidoType
        */
        const string getPedidoType() const;


    private:
        string upCodeChange;/**< The upCode*/
        string ucCode1;/**< The ucCode1*/
        string classCode1;/**< The classCode1*/
        string ucCode2;/**< The ucCode2*/
        string classCode2;/**< The classCode2*/
        string pedidoType;/**< Type of the request (remove, add or change)*/

};


#endif //UNTITLED2_PEDIDO_H

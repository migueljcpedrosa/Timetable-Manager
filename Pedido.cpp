//
// Created by m3ped on 06/11/2022.
//

#include "Pedido.h"

const string Pedido::getUpCodeChange() const {
    return upCodeChange;
}

const string Pedido::getClassCode1() const {
    return classCode1;
}

const string Pedido::getUcCode1() const {
    return ucCode1;
}

const string Pedido::getUcCode2() const {
    return ucCode2;
}

const string Pedido::getClassCode2() const {
    return classCode2;
}

Pedido::Pedido(const string upCodeChange, const string ucCodeRemove, const string classCodeRemove)
{
    this->upCodeChange = upCodeChange;
    this->ucCode1 = ucCodeRemove;
    this->classCode1 = classCodeRemove;
}

Pedido::Pedido(const string upCodeChange,  const string ucCodeRemove, const string classCodeRemove, const string ucCodeAdd, const string classCodeAdd)
{
    this->upCodeChange = upCodeChange;
    this->ucCode1 = ucCodeRemove;
    this->classCode1 = classCodeRemove;
    this->ucCode2 = ucCodeAdd;
    this->classCode2 = classCodeAdd;
}
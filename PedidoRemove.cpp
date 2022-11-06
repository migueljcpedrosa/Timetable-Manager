//
// Created by m3ped on 06/11/2022.
//

#include "PedidoRemove.h"

const string PedidoRemove::getUpCode() const {
    return upCode;
}

const string PedidoRemove::getUcCode() const {
    return ucCode;
}

const string PedidoRemove::getClassCode() const {
    return classCode;
}

PedidoRemove::PedidoRemove(const string upCode, const string ucCode, const string classCode)
{
    this->upCode = upCode;
    this->ucCode = ucCode;
    this->classCode = classCode;
}
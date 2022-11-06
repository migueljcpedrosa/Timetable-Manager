//
// Created by m3ped on 03/11/2022.
//

#include <algorithm>
#include <iostream>
#include "Estudante.h"

Estudante::Estudante(string name, string upCode)
{
    this->name=name;
    this->upCode=upCode;
}

string Estudante::getName() const
{
    return this->name;
}
string Estudante::getUpCode() const
{
    return this->upCode;
}

void Estudante::displayUpClasses()
{
    cout << "Student " << this->name << "; " << this->upCode << "\n";
    for (int i = 0; i < vectorUcClass.size(); i++)
    {
        cout << vectorUcClass[i].first << "; " << vectorUcClass[i].second << endl;
    }

    cout << "\n";
}


void Estudante::displaySchedule(map<pair<string,string>, Slot>& mapUcClassTimeSlot)
{
    cout << "Student " << this->name << ";" << this->upCode << "\n";

    for (int i = 0; i < vectorUcClass.size(); i++)
    {
        /*
        cout << vectorUcClass[i].first << "; " << vectorUcClass[i].second << ": ";
        auto it = mapUcClassTimeSlot.find({vectorUcClass[i].first, vectorUcClass[i].second}); //finds key pair <uccode, ucclass> position in map

        //************************** PSEUDO-CODE para fazer sorting das slotes de aulas por dia da semana ****************************+*******************

         map<int, Slot> orderSlots;         //------> criar uma mapa ordenado pela key (1-5), imprimir apenas segundo elemento (slot de horario)
          for(auto el: mapUcClassTimeSlot){  //  -------> fazer loop dos el (corresponde a elemento do mapa  mapUcClassTimeSlot)
               if(el.second.getWeekDay()=="Monday") // ----> se o 2o elemento de mapUcClassTimeSlot (slot de horario) for segunda, mapear elemento segunda a key = 1
               {
                   orderSlots[1]=el.second;
                }
                else if(el.second.getWeekDay()=="Tuesday")
                {
                   orderSlots[2]=el.second;
                }
                else if(el.second.getWeekDay()=="Wednesday")
                {
                   orderSlots[3]=el.second;
                }
                else if(el.second.getWeekDay()=="Thursday")
                {
                   orderSlots[4]=el.second;
                }
                else if(el.second.getWeekDay()=="Friday")
                {
                   orderSlots[5]=el.second;
                }
           }

           for(auto el: orderSlots) {
               cout << el.second.getWeekDay() << "; " << el.second.getBegin() << "; " << el.second.getDuration() << "; " << el.second.getClassType() << endl;
           }

           //***************************************END OF PSEUDO-CODE****************************************************************

        cout << it->second.getWeekDay() << "; " << it->second.getBegin() << "; " << it->second.getDuration() << "; " << it->second.getClassType() << "\n";
    */
         }

    cout << "\n";
}

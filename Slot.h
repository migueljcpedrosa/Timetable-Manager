//
// Created by m3ped on 03/11/2022.
//

#ifndef UNTITLED2_SLOT_H
#define UNTITLED2_SLOT_H


class Slot {
    public:
        int getBegin() const;
        int getDuration() const;
        int getClassType();
    private:
        int begin;
        int duration;
        int classType;
};


#endif //UNTITLED2_SLOT_H

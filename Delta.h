//
// Created by Admin on 4/11/2022.
//

#ifndef OOP_HW1_DELTA_H
#define OOP_HW1_DELTA_H
#include "SARS_COV_2.h"


class Delta: public SARS_COV_2{

public:
    Delta();
    Delta(std::string s);
    Delta(std::string s, float prob);
    virtual ~Delta();
    void printHey();
    void updateSingleVirus();
    std::string tostring();
    std::string printVirusRefcnt();
//    friend std::ostream& operator<<(std::ostream& os,  Delta& delta);

};


#endif //OOP_HW1_DELTA_H

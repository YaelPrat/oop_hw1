//
// Created by Admin on 4/11/2022.
//

#ifndef OOP_HW1_OMICRON_H
#define OOP_HW1_OMICRON_H
#include "SARS_COV_2.h"


class omicron : public SARS_COV_2{

public:
    omicron();
    omicron(std::string s);
    omicron(std::string s, float prob);
    void printHey();
    void updateSingleVirus();
    std::string tostring();
    std::string printVirusRefcnt();
//    friend std::ostream& operator<<(std::ostream& os,  omicron& om);
virtual ~omicron();

};


#endif //OOP_HW1_OMICRON_H

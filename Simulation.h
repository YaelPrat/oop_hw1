//
// Created by Admin on 4/21/2022.
//
#include "SARS_COV_2.h"
#include "omicron.h"
#include "Alpha.h"
#include "Delta.h"
#ifndef OOP_HW1_SIMULATION_H
#define OOP_HW1_SIMULATION_H


class Simulation {
public:
    void choose2viruses(int *i, int* j, int size);
    void choose2indexes(int *i, int *j, int dim);
    void switchStrings(int i, int j, int s, int t,std::vector<SARS_COV_2 *> * colony);
    void groupUpdate(int dim,std::vector<SARS_COV_2 *> * colony ,std::vector<SARS_COV_2*> * weakest2 );
    void printColony(std::vector<SARS_COV_2 *> * colony ,bool withPower);
};


#endif //OOP_HW1_SIMULATION_H

//
// Created by Yael Prat on 4/11/2022.
//
#ifndef OOP_HW1_SARS_COV_2_H
#define OOP_HW1_SARS_COV_2_H
#include <iostream>
#include <vector>

class SARS_COV_2 {
private:
//    std::vector<std::string> atcg;
std::string atcg;
public:
    SARS_COV_2();
    SARS_COV_2(std::string s);
    virtual void printHey();
    virtual std::string getATCG();
    virtual void setATCG(std::string newATCG);
    //return the Adjustment of the ATCG string to given string
    float adjustment(const char* targetString, int len);

};

#endif //OOP_HW1_SARS_COV_2_H

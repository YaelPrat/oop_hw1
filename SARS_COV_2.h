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
    float prob;
public:
    SARS_COV_2();
    SARS_COV_2(std::string s);
    SARS_COV_2(std::string s, float prob);
    virtual void printHey();
    virtual std::string getATCG();
    virtual void setATCG(std::string newATCG);
    virtual float getProb();
    virtual void setProb(float prob);
    virtual char getSingleATCG(int i);
    virtual void setSingleATCG(int i,char c);

    //return the Adjustment of the ATCG string to given string
    float adjustment(const char* targetString, int len);
    virtual void updateSingleVirus();

};

#endif //OOP_HW1_SARS_COV_2_H

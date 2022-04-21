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
    float power;
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
    virtual std::string getATCGByIndex(int i,int j);
    virtual void setATCGByIndex(int i,std::string s);
    virtual void setPower(float power);
    virtual float getPower();
    virtual void tostring();

    //return the Adjustment of the ATCG string to given string
    float adjustment(std::string , int len);
    virtual void updateSingleVirus();

};

#endif //OOP_HW1_SARS_COV_2_H

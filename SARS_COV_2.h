//
// Created by Yael Prat on 4/11/2022.
//
#ifndef OOP_HW1_SARS_COV_2_H
#define OOP_HW1_SARS_COV_2_H
#include <iostream>
#include <vector>

class SARS_COV_2 {
private:
    struct ancestor_{ // the ref counter
        SARS_COV_2 * parent=NULL;
        int refCounter=0;
    };
    std::string atcg;
    float prob;
    float power;
    ancestor_ ancestor;

public:
    SARS_COV_2();
    SARS_COV_2(std::string s);
    SARS_COV_2(std::string s, float prob);
    SARS_COV_2(std::string s, float prob,SARS_COV_2* parent);
    virtual ~SARS_COV_2();
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
    virtual ancestor_ getAncestor();

    virtual int getRefCount();
    virtual void setRefCount(int newref);
    virtual SARS_COV_2* getParent();
    virtual void setParent(SARS_COV_2* parent);
    virtual void decRefCount();
    virtual void addRefCount();
    virtual std::string tostring();
    virtual std::string printVirusRefcnt();

    //return the Adjustment of the ATCG string to given string
    float adjustment(std::string , int len);
    virtual void updateSingleVirus();
//    friend std::ostream& operator<<(std::ostream& os,  SARS_COV_2& SC2);



};

#endif //OOP_HW1_SARS_COV_2_H

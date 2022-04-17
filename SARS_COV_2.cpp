//
// Created by Yael Prat on 4/11/2022.
//
#include "SARS_COV_2.h"
using namespace std;

 void SARS_COV_2::printHey() {
    std::cout << "Hello, World! from sars-cov-2 "<<this->atcg << std::endl;
}

SARS_COV_2::SARS_COV_2() {
    this->atcg = "aaa";
//    SARS_COV_2::printHey();
}

SARS_COV_2::SARS_COV_2(std::string s) {
    this->atcg = s;
}

SARS_COV_2::SARS_COV_2(std::string s, float prob) {
    this->atcg = s;
    this->prob = prob;
//    SARS_COV_2::printHey();
}

std::string SARS_COV_2::getATCG() {
    return atcg;
}
void SARS_COV_2::setATCG(std::string newATCG) {
    this->atcg= newATCG;
}

float SARS_COV_2::adjustment(const char* targetString, int len) {
    int cnt=0;
    for(int i=0; i<len; i++){
//        std::cout<<"target "<<targetString[i]<<" this atc "<<this->getSingleATCG(i)<<std::endl;
        if (targetString[i]==(this->atcg[i])){
            cnt++;
        }
    }
    return float(cnt)/len;
}

void SARS_COV_2::updateSingleVirus() {
    std::cout<<"update single virus"<<std::endl;
}

float SARS_COV_2::getProb() {
    return this->prob;
}

void SARS_COV_2::setProb(float prob) {
    this->prob = prob;
}

char SARS_COV_2::getSingleATCG(int i) {
    return this->atcg[i];
}

void SARS_COV_2::setSingleATCG(int i,char c) {
    this->atcg[i]= c;
}




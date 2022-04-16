//
// Created by Yael Prat on 4/11/2022.
//
#include "SARS_COV_2.h"

 void SARS_COV_2::printHey() {
    std::cout << "Hello, World! from sars-cov-2 "<<this->atcg << std::endl;
}

SARS_COV_2::SARS_COV_2() {
    this->atcg = "aaa";
    SARS_COV_2::printHey();
}

SARS_COV_2::SARS_COV_2(std::string s) {
    this->atcg = s;
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
        std::cout<<"target "<<targetString[i]<<" this atc "<<this->atcg[i]<<std::endl;
        if (targetString[i]==(this->atcg[i])){
            cnt++;
        }
    }
    return float(cnt)/len;
}




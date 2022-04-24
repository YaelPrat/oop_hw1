//
// Created by Yael Prat on 4/11/2022.
//
#include "SARS_COV_2.h"
using namespace std;
//struct ancestor;
 void SARS_COV_2::printHey() {
    std::cout << "Hello, World! from sars-cov-2 "<<this->atcg << std::endl;
}

SARS_COV_2::SARS_COV_2() {
}

SARS_COV_2::SARS_COV_2(std::string s) {
    this->atcg = s;
}

SARS_COV_2::SARS_COV_2(std::string s, float prob) {
    this->atcg = s;
    this->prob = prob;
}
SARS_COV_2::SARS_COV_2(std::string s, float prob,SARS_COV_2* parent) {
    this->atcg = s;
    this->prob = prob;
    this->ancestor.parent=parent;
}
 SARS_COV_2::~SARS_COV_2(){
     if (this->ancestor.parent== NULL){ //this is ancestor.
         if (this->ancestor.refCounter == 0){
//             cout<<"dtor"<<endl;
             delete this;
         } else{
             cerr<<"You try to delete object that steal have pointers to."<<endl;
         }
     } else{ // not an ancestor.
         (*this->ancestor.parent).decRefCount();
     }
}
std::string SARS_COV_2::getATCG() {
     string s= atcg;
     if(s[s.size()-1] == '\r'){
         s.erase(s.size() - 1);
     }
    return s;
}
void SARS_COV_2::setATCG(std::string newATCG) {
    this->atcg= newATCG;
}

float SARS_COV_2::adjustment(string targetString, int len) {
    int cnt=0;
    for(int i=0; i<len; i++){
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

void SARS_COV_2::setATCGByIndex(int i,  string s) {
     int k=0;
    for (int j = i; j <s.length()+i ; ++j) {
            this->atcg[j]= s[k++];
    }
}
string SARS_COV_2::getATCGByIndex(int i,int j){
return this->atcg.substr(i,j);
 }

float SARS_COV_2::getPower() {
    return this->power;
}

void SARS_COV_2::setPower(float power) {
    this->power= power;
}

string SARS_COV_2::tostring() {
    return "covid sars 2 ";
}

SARS_COV_2::ancestor_ SARS_COV_2::getAncestor() {
    return SARS_COV_2::ancestor_();
}


 int SARS_COV_2::getRefCount(){
     return this->ancestor.refCounter;
 }
void SARS_COV_2::setRefCount(int newref){
    this->ancestor.refCounter = newref;
 }
SARS_COV_2* SARS_COV_2::getParent(){
    return this->ancestor.parent;
 }
void SARS_COV_2::setParent(SARS_COV_2* parent){ //updates the counter of the parent.
    this->ancestor.parent = parent;
    parent->addRefCount();
 }
void SARS_COV_2::decRefCount(){
    this->ancestor.refCounter--;
 }
void SARS_COV_2::addRefCount(){
    this->ancestor.refCounter++;
 }

string SARS_COV_2::printVirusRefcnt(){
    return "";
 }

//ostream& operator<<(ostream& os,  SARS_COV_2& SC2)
//{
//    os <<SC2.type<<" "<< SC2.atcg << " " <<to_string(SC2.ancestor.refCounter) ;
//    return os;
//}


//
// Created by Admin on 4/11/2022.
//

#include "Alpha.h"
using namespace std;

//c`tors:
Alpha::Alpha(){

}
Alpha::Alpha(std::string s) : SARS_COV_2(s,0.37) {

}

void Alpha::updateSingleVirus() {
    string s = getATCG();
    srand((unsigned)time(0));
    bool yesProb = (rand()%100)<getProb()*100;

    for(unsigned i=0; i<s.length();i++){

            if(getSingleATCG(i) == 'A'){
                yesProb = (rand()%100)<getProb()*100;
                if(yesProb) {
                    setSingleATCG(i, 'T');
                }
            }
            if(getSingleATCG(i) == 'T'){
                yesProb = (rand()%100)<getProb()*100;
                if(yesProb) {
                    setSingleATCG(i, 'A');
                }
            }

    }
}

string Alpha::tostring() {
    string spacesAtcg;
    for (unsigned i = 0; i < getATCG().length(); ++i) {
        spacesAtcg = spacesAtcg+ getSingleATCG(i);
        if (i!= getATCG().length()-1) spacesAtcg+=' ';
    }
    return "a "+spacesAtcg;
}


Alpha::~Alpha() {

}


//
// Created by Admin on 4/11/2022.
//

#include "Delta.h"
using namespace std;
Delta::Delta(){


}
Delta::Delta(std::string s): SARS_COV_2(s) {

}
Delta::Delta(std::string s,float prob): SARS_COV_2(s,prob) {

}

void Delta::updateSingleVirus() {
    string s = getATCG();
    srand((unsigned)time(0));
    bool yesProb;
    for(unsigned i=0; i< s.length();i++){
            if(getSingleATCG(i) == 'A'){
                yesProb = (rand()%100)<getProb()*100;
                if(yesProb) {
                    setSingleATCG(i,'T');
                }
            }
            if(getSingleATCG(i) == 'C'){
                yesProb = (rand()%100)<getProb()*100;
                if(yesProb) {
                    setSingleATCG(i,'G');
                }
            }
            if(getSingleATCG(i)== 'G'){
                yesProb = (rand()%100)<getProb()*100;
                if(yesProb) {
                    cout << s[i] << endl;
                    setSingleATCG(i,'C');
                }
            }

    }
}

string Delta::tostring() {
    string spacesAtcg;
    for (unsigned i = 0; i < getATCG().length(); ++i) {
        spacesAtcg = spacesAtcg+ getSingleATCG(i);
        if (i!=getATCG().length()-1) spacesAtcg+=' ';
    }
return "d "+spacesAtcg;
}


Delta::~Delta() {

}


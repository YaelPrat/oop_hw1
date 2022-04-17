//
// Created by Admin on 4/11/2022.
//

#include "Delta.h"
using namespace std;

void Delta::printHey() {
    std::cout << "Hello, World! from Delta"<< this->getATCG() << std::endl;
}

void Delta::updateSingleVirus() {
    string s = getATCG();
    srand((unsigned)time(0));
    bool yesProb;
    for(int i=0; i<s.length();i++){
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

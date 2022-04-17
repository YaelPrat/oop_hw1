//
// Created by Admin on 4/11/2022.
//

#include "omicron.h"
using namespace std;

 void omicron::printHey() {
     std::cout << "Hello, World! from omicron " << this->getATCG()<< std::endl;
 }


void omicron::updateSingleVirus() {
    string s = getATCG();
    srand((unsigned) time(0));
    bool yesProb = (rand() % 100) < getProb() * 100;
//    cout << "in update single omicron " << yesProb << " the prob is:" << getProb() << endl;

    for (int i = 0; i < s.length(); i++) {

        if (getSingleATCG(i) == 'T') {
            yesProb = (rand() % 100) < getProb() * 100;
            if (yesProb) {
                setSingleATCG(i, 'A');
            }
        }
        if (getSingleATCG(i) == 'C') {
            yesProb = (rand() % 100) < getProb() * 100;
            if (yesProb) {
                setSingleATCG(i, 'G');
            }
        }
        if (getSingleATCG(i) == 'G') {
            yesProb = (rand() % 100) < getProb() * 100;
            if (yesProb) {
                setSingleATCG(i, 'C');
            }
        }

    }
}

#include <iostream>
#include "SARS_COV_2.h"
#include "omicron.h"
#include "Alpha.h"
#include "Delta.h"
#include <vector>

using namespace std;
int main() {
    std::vector<SARS_COV_2 *> colony;
    omicron *ss = new omicron() ;
    colony.push_back(ss);

    SARS_COV_2  * s=  new Delta();
    colony.push_back(s);

    SARS_COV_2 *sss = new Alpha();
    colony.push_back(sss);
    string testString[3] = {"abc","cde","aba"};
    int j=0;
    for(auto i= colony.begin(); i !=colony.end();i++){
        (*i)->setATCG(testString[j]);
        j++;
        (*i)->printHey();
        cout << "Target test"<<endl<<(*i)->adjustment("aba",3)<<endl;
    }
    return 0;
}

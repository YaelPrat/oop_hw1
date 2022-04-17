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
    string testString[3] = {"ATC","CTA","GCT"};
    float testProb[3]= {1,0.333,0.6667};
    int j=0;
    for(auto i= colony.begin(); i !=colony.end();i++){
        (*i)->setATCG(testString[j]);
        (*i)->setProb(testProb[j]);
        j++;
        (*i)->printHey();

        cout<<(*i)->adjustment("ATC",3)<<endl;
        (*i)->updateSingleVirus();
        cout<<"change the ATCG to: "<<(*i)->getATCG()<<endl;
        cout<<(*i)->adjustment("ATC",3)<<endl;
    }
    return 0;
}

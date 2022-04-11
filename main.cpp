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

    for(auto i= colony.begin(); i !=colony.end();i++){
//        i.printHey();
//    cout<<*i->printHey()<<endl;
        (*i)->printHey();
    }
//    cout<<typeid(colony.begin()).name();

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

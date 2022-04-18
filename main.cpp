#include <iostream>
#include <fstream>
#include "SARS_COV_2.h"
#include "omicron.h"
#include "Alpha.h"
#include "Delta.h"
#include <vector>

using namespace std;
void test(){
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
}

void testFiles(){
    std::vector<SARS_COV_2 *> colony;
    string line;
    int dim;
    string targetString;
    int maxNumOfTransitions;
    int numOfVirus=0;

//open the dat file TODO: input validation.
//    ifstream myfile ("config.dat");
    fstream myfile;
    myfile.open("config.dat",ios::out | ios::in);

    if (myfile.is_open())
    {
        int i=0;
        while ( getline (myfile,line) )
        {
            if(i==0){
                dim =stoi(line) ;
            }
            if(i==1){
                targetString= line;
            }
            if(i==2){
                maxNumOfTransitions = stoi(line);
            }
            i++;
        }
        myfile.close();
        cout<<"dim: "<<dim<<" target: "<<targetString<<" max transitions: "<<maxNumOfTransitions<<endl;

//        for(int j=0; j< maxNumOfTransitions;j++){
//            for (int k = 0; k < dim; ++k) {
//                cout<<j<<"*";
//            }
//            cout<<endl;
//        }
    }
    else cout << "Unable to open file";


// second file:
    fstream firstGFile;
    firstGFile.open("first_generation.dat",ios::out | ios::in);

    if (firstGFile.is_open())
    {
        int i=0;
        int j=0;
        while ( getline (firstGFile,line) )
        {
            if(i==0){
                numOfVirus =stoi(line) ;
                i++;
            }
            else{
                if(line[0]=='o'){
//                    omicron *ss = new omicron() ;
//                    colony.push_back(ss);
                    colony.push_back(new omicron());
                } if(line[0]=='d'){
                    SARS_COV_2  * s=  new Delta();
                    colony.push_back(s);
                } if(line[0]=='a'){
                    SARS_COV_2 *sss = new Alpha();
                    colony.push_back(sss);
                }
            }
        }
        myfile.close();

    }
    else cout << "Unable to open file";

    string testString[3] = {"ATC","CTA","GCT"};
    float testProb[3]= {1,0.333,0.6667};
    int j=0;
    for(auto i= colony.begin(); i !=colony.end();i++){
//        (*i)->setATCG(testString[j]);
//        (*i)->setProb(testProb[j]);
//        j++;
        (*i)->printHey();

//        cout<<(*i)->adjustment("ATC",3)<<endl;
//        (*i)->updateSingleVirus();
//        cout<<"change the ATCG to: "<<(*i)->getATCG()<<endl;
//        cout<<(*i)->adjustment("ATC",3)<<endl;
    }


}
int main() {
//    test();
testFiles();
    return 0;
}

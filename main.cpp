#include <iostream>
#include <fstream>
#include "SARS_COV_2.h"
#include "omicron.h"
#include "Alpha.h"
#include "Delta.h"
#include <vector>
#include <algorithm>

void choose2viruses(int *first, int* second, int size);

void choose2indexes(int *i, int *j, int dim);

void switchStrings(int i, int j, int s, int t,std::vector<SARS_COV_2 *> * colony);
void groupUpdate(int dim,std::vector<SARS_COV_2 *> * colony ,std::vector<SARS_COV_2*> * weakest2 );
void printColony(std::vector<SARS_COV_2 *> * colony);
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
    vector<SARS_COV_2 *> colony;//change dooring the simulation
    vector<SARS_COV_2*> ancestors;
    SARS_COV_2 * strongest= new SARS_COV_2();//the stronger virus of all viruses
    strongest->setPower(0);
//    SARS_COV_2 * strongest;
    vector<SARS_COV_2*> weakest2;// 2 weakest viruses in each round.

    string line;
    int dim;//dimension of the ATCG string
    string targetString;
    int maxNumOfTransitions;//for the simulation
    int numOfVirus=0;//how many virus in simulation
    bool strongestVirusIsOne= false; // if there is virus that his power is 1 we stop the simulation.

//open the dat file TODO: input validation.
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
                line.erase(remove(line.begin(), line.end(), ' '), line.end());
                if(line[0]=='o'){
                    line.erase(0,1);
                    ancestors.push_back(new omicron(line,2/dim));
                    colony.push_back(new omicron(line,2/dim));
                } if(line[0]=='d'){
                    line.erase(0,1);
                    ancestors.push_back(new Delta(line,1/dim));
                    colony.push_back(new Delta(line,1/dim));
                } if(line[0]=='a'){
                    line.erase(0,1);
                    ancestors.push_back(new Alpha(line));
                    colony.push_back(new Alpha(line));
                }
            }
        }
        myfile.close();

    }
    else cout << "Unable to open file";


//The simulation:
int iteration=0;

    while(iteration++ < maxNumOfTransitions || strongestVirusIsOne == true ){
        vector<SARS_COV_2*>min  = {new SARS_COV_2(),new SARS_COV_2()};
        min[0]->setPower(2);
        min[1]->setPower(2);

//single update foreach virus.
        for(auto i= colony.begin(); i !=colony.end();i++){
            (*i)->updateSingleVirus();
            (*i)->setPower((*i)->adjustment(targetString,dim));
            if( int((*i)->getPower()) == 1){
                strongest = (*i);
                break;
            }
//            find the max power virus in all simulation:
            if(strongest->getPower() < (*i)->getPower()){
                strongest = *i;
            }

//find the 2 weakest:
            if(min[0] !=NULL &&min[1]!=NULL){
                if((*min[0]).getPower() > (*i)->getPower() ||(*min[1]).getPower() > (*i)->getPower() ){
                    min.push_back(*i);
                    std::sort(min.begin(), min.end(),[](SARS_COV_2 *a,SARS_COV_2 *b)->bool{
                        return (*a).getPower() < (*b).getPower();
                    }); //the vector sorted from the smallest so always the first 2 is my weakest virus.
                }
            }

        }//for single update

        groupUpdate(dim, &ancestors, &min);

    }//while
    cout<<endl;
    printColony(&colony);
    cout<<endl;
    printColony(&ancestors);
    cout<<endl;
    strongest->tostring();

}

//group update:
void groupUpdate(int dim,vector<SARS_COV_2 *> * ancestors,vector<SARS_COV_2*> *weakest2 ){
    int i,j;
    int s,t;
    choose2viruses(&i,&j, ancestors->size());
    choose2indexes(&s,&t, dim);
    switchStrings(i,j,s,t,ancestors);
    (*weakest2)[0]->setATCG((*ancestors)[i]->getATCG());
    (*weakest2)[1]->setATCG((*ancestors)[j]->getATCG());

}
void switchStrings(int i, int j, int s, int t,vector<SARS_COV_2 *> * colony ) {
string subStringI= (*colony)[i]->getATCGByIndex(s,t);
string subStringJ= (*colony)[j]->getATCGByIndex(s,t);
    (*colony)[i]->setATCGByIndex(s,subStringJ);
    (*colony)[j]->setATCGByIndex(s,subStringI);

}
void choose2indexes(int *s, int *t, int dim) {
    bool flag=true;
    while (flag){
        srand(time(NULL));
        int i=0,j=0;
        i= rand() % (((dim-2) - 2) + 1) + 2;
        j = rand() % ((dim-1 - 3) + 1) + 3;
        if(i<j){
            *s=i;
            *t=j;
            flag= false;
        }
    }

}
void choose2viruses(int *i, int *j, int size) {
    srand(time(NULL));
    int first=0,sec=0;
    while(true){
        first= rand() % (((size)) );
        sec= rand() % (((size)) );
        if(first != sec){
            *i=first;
            *j= sec;
            break;
        }
    }


}
void printColony(vector<SARS_COV_2 *> * colony){
    for(auto i= (*colony).begin(); i !=(*colony).end();i++){
        (*i)->tostring();
    }
}


int main() {
testFiles();
    return 0;
}

//
// Created by Admin on 4/21/2022.
//

#include "Simulation.h"
using namespace std;

void Simulation::switchStrings(int i, int j, int s, int t,vector<SARS_COV_2 *> * colony ) {
    string subStringI= (*colony)[i]->getATCGByIndex(s,t);
    string subStringJ= (*colony)[j]->getATCGByIndex(s,t);
    (*colony)[i]->setATCGByIndex(s,subStringJ);
    (*colony)[j]->setATCGByIndex(s,subStringI);

}
void Simulation::choose2indexes(int *s, int *t, int size) {
    bool flag=true;
    while (flag){
        srand(time(NULL));
        int i=0,j=0;
        i= rand() % (((size-2) - 2) + 1) + 2;
        j = rand() % ((size-1 - 3) + 1) + 3;
        if(i<j){
            *s=i;
            *t=j;
            flag= false;
        }
    }

}

void Simulation::choose2viruses(int *i, int *j, int size) {
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

void Simulation::printColony(vector<SARS_COV_2 *> * colony, bool withPower){
    for(auto i= (*colony).begin(); i !=(*colony).end();i++){

        if(withPower){
            cout<<(*i)->tostring()<<" "<<to_string((*i)->getRefCount())<<endl;
        } else  cout<<(*i)->tostring()<<endl;
    }

//SARS_COV_2 *sc = new SARS_COV_2();
//sc->setATCG("sars");
//omicron * o = new omicron("omicrom");
//Delta * d= new Delta("delta");
//Alpha * a = new Alpha("alpha");
//cout<<*sc<<endl;
//cout<<*o<<num<<endl;
//cout<<*d<<endl;
//cout<<*a<<endl;

}
void Simulation::groupUpdate(int dim,vector<SARS_COV_2 *> * ancestors,vector<SARS_COV_2*> *weakest2 ){
    int i,j;
    int s,t;
    choose2viruses(&i,&j, int(ancestors->size()));
    choose2indexes(&s,&t, dim);
    switchStrings(i,j,s,t,ancestors);
    (*weakest2)[0]->setATCG((*ancestors)[i]->getATCG());
    (*weakest2)[1]->setATCG((*ancestors)[j]->getATCG());

}
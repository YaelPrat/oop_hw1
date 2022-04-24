#include <iostream>
#include <fstream>
#include "Simulation.h"
#include <vector>
#include <algorithm>


using namespace std;


void testFiles(){
    vector<SARS_COV_2 *> colony;//change dooring the simulation
    vector<SARS_COV_2*> ancestors;
    SARS_COV_2 * strongest= new SARS_COV_2();//the stronger virus of all viruses
    strongest->setPower(0);
    vector<SARS_COV_2*> weakest2;// 2 weakest viruses in each round.
    Simulation* simulation= new Simulation();
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
//                    colony[colony.size()-1]->setParent(ancestors[ancestors.size()-1]);
                } if(line[0]=='d'){
                    line.erase(0,1);
                    ancestors.push_back(new Delta(line,1/dim));
                    colony.push_back(new Delta(line,1/dim));
//                    colony[colony.size()-1]->setParent(ancestors[ancestors.size()-1]);
                } if(line[0]=='a'){
                    line.erase(0,1);
                    ancestors.push_back(new Alpha(line));
                    colony.push_back(new Alpha(line));
//                    colony[colony.size()-1]->setParent(ancestors[ancestors.size()-1]);
                }
            }
        }
        myfile.close();

    }
    else cout << "Unable to open file";
    for(auto i= ancestors.begin(); i !=ancestors.end();i++){
//        (*i)->setIsAncestor(true);
        (*i)->setRefCount(1);
    }
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

        simulation->groupUpdate(dim, &ancestors, &min);

    }//while
    simulation->printColony(&colony, false);

    cout<<endl;
    simulation->printColony(&ancestors, true);

    cout<<endl;
    cout<<strongest->tostring()<<endl;
    delete strongest;


}



int main() {
testFiles();


    return 0;
}

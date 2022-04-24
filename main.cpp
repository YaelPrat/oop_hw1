#include <iostream>
#include <fstream>
#include "Simulation.h"
#include <vector>
#include <algorithm>
#include <cmath>

#define MIN_POP 2
#define MAX_POP 1000
#define MIN_DIM 3
#define MAX_DIM pow(10,4)
#define MAX_GENERTIONS pow(10,6)

using namespace std;


void run(char* configFile, char* FirstGenFile){
    vector<SARS_COV_2 *> colony;//change dooring the simulation
    vector<SARS_COV_2*> ancestors; // The ancestors viruses.
    SARS_COV_2 * strongest= new SARS_COV_2();//the stronger virus of all viruses in the simulation
    strongest->setPower(0);

    Simulation* simulation= new Simulation(); //simulation object
    //fields
    string line;
    int dim;//dimension of the ATCG string
    string targetString;
    int maxNumOfTransitions;//for the simulation
    int numOfVirus=0;//how many virus in simulation
    bool strongestVirusIsOne= false; // if there is virus that his power is 1 we stop the simulation.

//open the dat file
    fstream myfile;
    myfile.open(configFile,ios::out | ios::in);

    if (myfile.is_open())
    {
        int i=0;
        while ( getline (myfile,line) )
        {
            if(i==0){
                dim =stoi(line) ;
                if (dim < MIN_DIM || dim > MAX_DIM) {
                    cerr << "Error: Invalid dimension" << endl;
                    exit(1);
                }
            }
            if(i==1){
                targetString= line;
                targetString.erase(remove_if(targetString.begin(), targetString.end(), ::isspace), targetString.end());

                if ((int)targetString.length() != dim) {
                    cout<<line<<endl;
                    cerr << "Error: target string length is not match to dimension " << endl;
                    exit(1);
                }
            }
            if(i==2){
                maxNumOfTransitions = stoi(line);
                if (maxNumOfTransitions > MAX_GENERTIONS ){
                    cerr << "Error: number of generations is bigger than the maximum" << endl;
                    exit(1);
                }
            }
            i++;
        }
        myfile.close();

    }
    else cerr << "Unable to open file";


// second file:
    fstream firstGFile;
    firstGFile.open(FirstGenFile,ios::out | ios::in);

    if (firstGFile.is_open())
    {
        int i=0;
        int j=0;
        while ( getline (firstGFile,line) )
        {
            if(i==0){
                numOfVirus =stoi(line) ;
                if (numOfVirus < MIN_POP || numOfVirus > MAX_POP) {
                    cerr << "Error: Invalid population" << endl;
                    exit(1);
                }
                i++;
            }
            else{
                line.erase(remove(line.begin(), line.end(), ' '), line.end());
                if(line[line.size()-1] == '\r'){
                    line.erase(line.size() - 1);
                }
                if(line[0]=='o'){
                    line.erase(0,1);
                    if ((int) line.length() != dim) {
                        cerr << "Virus string dimension doesn't match to dimension"<<endl;
                        exit(1);
                    }
                    ancestors.push_back(new omicron(line,2/dim));
                    colony.push_back(new omicron(line,2/dim));
                    colony[colony.size()-1]->setParent(ancestors[ancestors.size()-1]);
                } if(line[0]=='d'){
                    line.erase(0,1);
                    if ((int) line.length() != dim) {
                        cerr << "Virus string dimension doesn't match to dimension"<<(int) line.length()<<" "<<dim<<endl;
                        exit(1);
                    }
                    ancestors.push_back(new Delta(line,1/dim));
                    colony.push_back(new Delta(line,1/dim));
                    colony[colony.size()-1]->setParent(ancestors[ancestors.size()-1]);
                } if(line[0]=='a'){
                    line.erase(0,1);
                    if ((int) line.length() != dim) {
                        cout<<line<<endl;
                        cerr << "Virus string dimension doesn't match to dimension"<<endl;
                        exit(1);
                    }
                    ancestors.push_back(new Alpha(line));
                    colony.push_back(new Alpha(line));
                    colony[colony.size()-1]->setParent(ancestors[ancestors.size()-1]);
                }
                j++;
            }
        }
        if(j != numOfVirus){
            cout << "You send more viruses than declared";
            exit(1);
        }
        myfile.close();

    }
    else cout << "Unable to open file";
    //set the ref counter for the ancestors as 1(each have one ref at the beginning)
    for(auto i= ancestors.begin(); i !=ancestors.end();i++){
        (*i)->setRefCount(1);
        (*i)->setParent(NULL);
    }
    for(auto i= colony.begin(); i !=colony.end();i++){
        (*i)->setRefCount(-1);
    }
//The simulation:
int iteration=0;

    while(iteration++ < maxNumOfTransitions || strongestVirusIsOne == true ){
        vector<SARS_COV_2*>min  = {new SARS_COV_2(),new SARS_COV_2()};
        min[0]->setPower(2); // set the power to 2 because it is out of limit
        min[1]->setPower(2);

//single update foreach virus.
        for(auto i= colony.begin(); i !=colony.end();i++){
            (*i)->updateSingleVirus();
            (*i)->setPower((*i)->adjustment(targetString,dim));
            if( int((*i)->getPower()) == 1){ //the simulation stops if virus power is 1.0
                strongest = (*i);
                break;
            }
//            find the max power virus in all simulation:
            if(strongest->getPower() < (*i)->getPower()){
                strongest = *i;
            }

//find the 2 weakest:
            if(min[0] !=NULL && min[1]!=NULL){
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

}



int main(int argc, char* argv[]) {
    if (argc !=3){
        cerr << "Error: Invalid input. Must have 2 files: config.dat, first_generation.dat " << endl;
        exit(1);
    }
    run(argv[1] , argv[2]);
    return 0;
}

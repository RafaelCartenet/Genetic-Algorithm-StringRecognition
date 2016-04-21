#include "genome.h"
#include <string.h>
#include <stdlib.h>
#include <GA_parameters.h>

using namespace std;

// Constructor
genome::genome(){
    string chainetemp;
    for (int j=0; j<target.size(); j++){
        chainetemp += (rand() % 90) + 32;
    }
    chaine = chainetemp;
    fitness = calculfitness();
}

genome::genome(string chaine_init){
    chaine = chaine_init;
    fitness = calculfitness();
}

// Destructor
genome::~genome()
{
}

// Getters / Setters
int genome::getfitness(){
    return fitness;
}

string genome::getchaine(){
    return chaine;
}

void genome::setchaine(string newchaine){
    this->chaine=newchaine;
}

// Methods
int genome::calculfitness() {
    int sum = 0;
    for (int i = 0; i < target.size(); i++){
        if (chaine.at(i)!=target.at(i)){
            sum += 1;
        }
    }
    return sum;
}

void genome::mutation() { // on fait muter chaque allèle avec une proba MUTERATE
    //int delta = (rand() % 90)+32;
    string tempchaine = this->chaine;

    for (int i=0; i<target.size(); i++) {
        if (RANDOM<MUTERATE) {
            // (chaine.at(i) + delta) % 122
            tempchaine.replace(i,1, ".");
        }
    }

    this->setchaine(tempchaine);
}

// toString
string genome::toString() {
    return "chaine : "+chaine+" | fitness : ("+std::to_string(fitness)+")\n";
}

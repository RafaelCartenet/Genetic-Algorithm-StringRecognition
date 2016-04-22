#include "genome.h"
#include <iostream>
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
int genome::getfitness() const{
    return fitness;
}

string genome::getchaine(){
    return chaine;
}

void genome::setchaine(string newchaine){
    this->chaine=newchaine;
}

// Methods
void genome::updatefitness(){
    fitness = calculfitness();
}

int genome::calculfitness() {
    int sum = 0;
    for (int i = 0; i < target.size(); i++){
        if (chaine.at(i)!=target.at(i)){
            sum += 1;
        }
    }

    //for (int i = 0; i < target.size(); i++){
    //    sum += abs(this->getchaine().at(i)-target.at(i));
    //}

    return SIZE - sum;
}

void genome::mutation() { // on fait muter chaque allèle avec une proba MUTERATE
    string tempchaine = this->chaine;

    for (int i=0; i<target.size(); i++) {
        if (RANDOM<MUTERATE) {
            tempchaine.at(i) = (rand() % 91)+32;
        }
    }

    this->setchaine(tempchaine);
}

// toString
string genome::toString() {
    return "chaine : "+chaine+" | fitness : ("+std::to_string(fitness)+")\n";
}

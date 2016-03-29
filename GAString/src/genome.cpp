#include "genome.h"
#include <string.h>
#include <GA_parameters.h>

// Constructor
genome::genome()
{
    string chainetemp;
    for (int j=0; j<target.size(); j++){
        chainetemp += (rand() % 90) + 32;
    }
    chaine = chainetemp;
    fitness = calculfitness();
}

// Destructor
genome::~genome()
{
}

// Getters / Setters
int genome::getfitness()
{
    return fitness;
}

string genome::getchaine()
{
    return chaine;
}

// Methods
int genome::calculfitness()
{
    int sum = 0;
    for (int i = 0; i < target.size(); i++){
        if (chaine.at(i)!=target.at(i)){
            sum += 1;
        }
    }
    return sum;
}

void genome::mutation() { // on fait muter chaque allèle avec une proba MUTERATE
    //int tsize=target.size();
    //int ipos=rand() %tsize;

    int delta = (rand() % 90)+32;

    for (int i=0; i<target.size(); i++) {
        if ( (rand()%100+1)/100<MUTERATE ) this.getchaine()[i] = ((this.getchaine()[i] + delta) % 122);
}

// toString
string genome::toString()
{
    return "chaine : "+chaine+" | fitness : ("+to_string(fitness)+")\n";
}

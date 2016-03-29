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

// toString
string genome::toString()
{
    return "chaine : "+chaine+" | fitness : ("+to_string(fitness)+")\n";
}

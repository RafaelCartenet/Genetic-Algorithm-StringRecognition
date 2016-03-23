#include "genome.h"

// Constructeurs
genome::genome()
{
    chaine = "allo";
    fitness = 0;
}

genome::~genome()
{
    //dtor
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

// Méthodes
void genome::calculfitness()
{
    fitness = 50;
}

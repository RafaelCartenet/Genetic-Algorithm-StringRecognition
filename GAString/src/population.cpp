#include "population.h"
#include <genome.h>
#include <GA_parameters.h>
#include <string.h>
#include <algorithm>

// Constructor
population::population()
{
    vector<genome> poptemp;
    poptemp.reserve(NBGENOME);
    for (int i = 0; i < NBGENOME; i++){
        poptemp.push_back(genome());
    }
    pop = poptemp;
}

// Destructor
population::~population()
{
    //dtor
}

// Getters / Setters
vector<genome> population::getpop()
{
    return pop;
}

// Méthodes
genome population::getbestgenome(){
// A FAIRE
}

bool fitness_sort(genome gen1, genome gen2)
{
    return (gen1.getfitness() < gen2.getfitness());
}

void population::sort_by_fitness()
{
    stable_sort(begin(pop),begin(pop), fitness_sort);
    int a = 5;
}

void population::crossover(){
// A FAIRE
}

void population::selection(){
// A FAIRE
}

void population::mutation(){
// A FAIRE
}

// toString
string population::toString()
{
    string chaine;
    for (int i = 0; i < NBGENOME; i++){
        chaine+=pop.at(i).toString();
    }
    return chaine;
}



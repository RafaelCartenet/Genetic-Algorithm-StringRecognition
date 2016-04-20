#include "population.h"
#include <iostream>
#include <genome.h>
#include <GA_parameters.h>
#include <string.h>
#include <algorithm>


// Constructor
population::population(){
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
void population::initialiser_population() {
    vector<genome> poptemp;
    for (int i = 0; i < NBGENOME; i++){
        poptemp.push_back(genome());
    }
    pop = poptemp;
}


void population::add_genome(genome Jauby) {
    pop.push_back(Jauby);
}

genome population::getbestgenome(){
    unsigned int fitness;
    for (int i=0; i< NBGENOME ; i++) {
        fitness=0;
        for (int j=0; j<target.size(); j++) {
            fitness+=abs(int(pop.at(i).chaine[j]-target[j]));
        }
    }
}

bool fitness_sort(genome gen1, genome gen2)
{
    return (gen1.getfitness() < gen2.getfitness());
}

//void population::sort_by_fitness()
//{
//    stable_sort(begin(pop),end(pop), fitness_sort);
//}

void population::crossover(){
    population temp = population();
    string chaine1, chaine2;

    for (int k=0; k<NBGENOME; k=k+2) {

        genome fils1=pop.at(k);
        genome fils2=pop.at(k+1);
        if (RANDOM<CROSSOVERRATE) {
            int pas=(rand()%(target.size()-2)+1); //random entre 1 et target.size-2
            chaine1 = fils1.getchaine().substr(0,pas) + fils2.getchaine().substr(pas,target.size()-pas);
            chaine2 = fils2.getchaine().substr(0,pas) + fils1.getchaine().substr(pas,target.size()-pas);
            fils1.chaine=chaine1;
            fils2.chaine=chaine2;
        }

        temp.add_genome(fils1);
        temp.add_genome(fils2);
    }
    this->pop=temp.pop;
}

void population::selection(){
// A FAIRE
}

void population::mutation(){

    for (int i=0; i<NBGENOME; i++) {
        pop.at(i).mutation();
    }
}

// toString
string population::toString()
{
    string chaine;
    for (int i = 0; i < pop.size(); i++){
        chaine+=pop.at(i).toString();
    }

    return chaine;
}



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

population::population_vierge() {
    vector<genome> poptemp;

    poptemp.reserve(NBGENOME);
}


population::add_genome(genome Jauby) {
    this.pop.push_back(Jauby);
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
    unsigned int fitness;
    for (int i=0; i< NBGENOME ; i++) {
        fitness=0;
        for (int j=0; j<target.size(); j++) {
            fitness+=abs(int(this.getpop().at(i).chaine[j]-target[j])
        }
    }
}

bool fitness_sort(genome gen1, genome gen2)
{
    return (gen1.getfitness() < gen2.getfitness());
}

void population::sort_by_fitness()
{
    stable_sort(begin(pop),end(pop), fitness_sort);
}

void population::crossover(){
    for (int k=0; k<NBGENOME; k=k+2) {

        genome fils1=this.getpop().at(k);
        genome fils2=this.getpop().at(k+1);

        if (rand()%100+1)/100)<CROSSOVERRATE {
            int pas=(rand()%(target.size()-2)+1); //random entre 1 et target.size-2
            fils1=fils1.getchaine().substr(0,pas) + fils2.getchaine().substr(pas,target.size()-pas);
            fils2=fils2.getchaine().substr(0,pas) + fils1.getchaine().substr(pas,target.size()-pas);
        }

        this.pop.add_genome(fils1);
        this.pop.add_genome(fils2);
    }
}

void population::selection(){
// A FAIRE
}

void population::mutation(){

    for (int i=0; i<NBGENOME; i++) {
        this.getpop().at(i).mutation();
    }

    member.chaine[ipos] = ((member.chaine[ipos] + delta) % 122);
}

// toString
string population::toString()
{
    string chaine;
    for (int i = 0; i < NBGENOME; i++){
        chaine+=this.getpop().at(i).toString();
    }
    return chaine;
}



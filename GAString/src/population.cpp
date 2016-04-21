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
    return this->pop;
}

void population::setpop(vector<genome> newpop){
    this->pop=newpop;
}

// Méthodes
void population::initialiser_population() {
    vector<genome> poptemp;
    for (int i = 0; i < NBGENOME; i++){
        poptemp.push_back(genome());
    }
    this->getpop() = poptemp;
}


void population::add_genome(genome Jauby) {
    pop.push_back(Jauby);
}

genome population::getbestgenome(){
    unsigned int fitness;
    for (int i=0; i< NBGENOME ; i++) {
        fitness=0;
        for (int j=0; j<target.size(); j++) {
            fitness += abs(int(pop.at(i).getchaine()[j]-target[j]));
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
    population newpop = population();
    string chaine1, chaine2;
    genome fils1, fils2;
    for (int k=0; k<NBGENOME; k=k+2) {
        fils1=pop.at(k);
        fils2=pop.at(k+1);
        if (RANDOM<CROSSOVERRATE) {
            int pas=(rand()%(target.size()-2)+1); //random entre 1 et target.size-2
            chaine1 = fils1.getchaine().substr(0,pas) + fils2.getchaine().substr(pas,target.size()-pas);
            chaine2 = fils2.getchaine().substr(0,pas) + fils1.getchaine().substr(pas,target.size()-pas);
            fils1.setchaine(chaine1);
            fils2.setchaine(chaine2);
        }

        newpop.add_genome(fils1);
        newpop.add_genome(fils2);
    }

    this->setpop(newpop.getpop());
}

void population::selection(){
    population newpop = population();
    int sum_fitness = 0;
    int fitnesscount;
    int bound;
    int count;
    int k;

    for (int i = 0; i < this->getpop().size(); i++){
        sum_fitness += this->getpop().at(i).getfitness();
    }

    for (int i = 0; i < NBGENOME; i++) {
        bound = rand()%sum_fitness+1;
        fitnesscount = 0;
        k = 0;
        while (fitnesscount < bound) {fitnesscount += this->getpop().at(k++).getfitness();}
        newpop.add_genome(this->getpop().at(k));
    }

    this->setpop(newpop.getpop());
}

void population::mutation(){
    vector<genome> newpop = this->getpop();

    for (int i=0; i<NBGENOME; i++) {
        newpop.at(i).mutation();
    }

    this->setpop(newpop);
}

// toString
string population::toString()
{
    string chaine;
    for (int i = 0; i < this->getpop().size(); i++){
        chaine+=this->getpop().at(i).toString();
    }

    return chaine;
}

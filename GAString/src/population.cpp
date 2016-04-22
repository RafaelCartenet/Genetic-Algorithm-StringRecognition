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
    this->setpop(poptemp);
}


void population::add_genome(genome Jauby) {
    pop.push_back(Jauby);
}

void population::del_genome(int i) {
    pop.erase (pop.begin()+i-1);
}

genome population::getbestgenome() const{
    int indice=0;
    for (int i=1; i< NBGENOME ; i++) {
        if (pop.at(indice).getfitness()<pop.at(i).getfitness()){
            indice = i;
        }
    }
    return pop.at(indice);
}

void population::updatefitness(){
    for (int i = 0; i < NBGENOME; i++){
        pop.at(i).updatefitness();
    }
}

void population::sort_by_fitness(){
    sort(pop.begin(), pop.end(),[](const genome& a,const genome &b){
            return a.getfitness() > b.getfitness();
         });
}

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
    this->updatefitness();

    this->sort_by_fitness();

    int Elitnb = ELITRATE*NBGENOME;

    population newpop = population();

    /* Elitisme */
    for (int i = 0; i < Elitnb; i++){
        newpop.add_genome(this->getpop().at(i));
    }

    /* RWS */
    int sum_fitness = 0;
    int fitnesscount;
    int bound;
    int k;

    for (int i = 0; i < NBGENOME; i++){
        sum_fitness += this->getpop().at(i).getfitness();
    }

    for (int i = Elitnb; i < NBGENOME; i++) {
        bound = (rand()%sum_fitness)+1;
        fitnesscount = 0;
        k = 0;
        while ((fitnesscount < bound)&&(k<NBGENOME)) {
            //cout << k << " " << bound << " " << fitnesscount << " " << sum_fitness << endl;
            fitnesscount += this->getpop().at(k).getfitness();
            k++;
        }
        newpop.add_genome(this->getpop().at(--k));
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
    unsigned int i;
    string chaine;
    for (i = 0; i < this->getpop().size(); i++){
        chaine+=this->getpop().at(i).toString();
    }

    return chaine;
}

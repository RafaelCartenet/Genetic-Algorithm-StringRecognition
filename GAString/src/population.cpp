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

/** \brief Méthode de création d'une population vide
 * \details On ajoute NBGENOME vides dans une population
 * \return void
 *
 */
void population::initialiser_population() {
    vector<genome> poptemp;
    for (int i = 0; i < NBGENOME; i++)
        poptemp.push_back(genome());
    this->setpop(poptemp);
}


/** \brief Méthode d'ajout d'un génome dans une population
 *
 * \param gen genome le génome ajouté en fin de population
 * \return void
 *
 */
void population::add_genome(genome gen) {
    pop.push_back(gen);
}



/** \brief Méthode de suppression d'un génome dans une population
 *
 * \param i int l'indice dans la population où le génome est supprimé
 * \return void
 *
 */
void population::del_genome(int i) {
    pop.erase (pop.begin()+i-1);
}


/** \brief Méthode qui renvoie le génome avec la meilleure fitness
 *
 * \return genome le génome avec la fitness la plus élevée dans la population
 *
 */
genome population::getbestgenome() const{
    int indice=0;
    for (int i=1; i< NBGENOME ; i++) {
        if (pop.at(indice).getfitness()<pop.at(i).getfitness()){
            indice = i;
        }
    }
    return pop.at(indice);
}


/** \brief Méthode de mise à jour de la fitness pour toute une population
 * \details Cette méthode appelle la méthode updatefitness définie dans la classe genome à tous les génomes de la population
 * \return void
 *
 */
void population::updatefitness(){
    for (int i = 0; i < NBGENOME; i++)
        pop.at(i).updatefitness();
}


/** \brief Méthode de tri d'une population
 * \details Le but de cette méthode est de trier les différents génome d'une population selon une certaine règle.
 * La règle ici définie est de positionner les génomes avec la meilleure fitness au début de la population.
 * \return void
 *
 */
void population::sort_by_fitness(){
    sort(pop.begin(), pop.end(),[](const genome& a,const genome &b){
            return a.getfitness() > b.getfitness();
         });
}


/** \brief Méthode principale du crossover
 * \details Cette méthode va parcourir la population et sélectionner 2 génomes dans l'ordre de la population.
 * On génère un entier entre 0 et 1, si celui-ci est inférieur à CROSSOVERRATE, alors on fait un crossover sur ces 2 génomes.
 * Cela consiste à prendre une portion (définie aléatoirement) de caractères dans le premier génome, et le reste dans le second.
 * \return void
 *
 */
void population::crossover(){
    population newpop = population();
    string chaine1, chaine2;
    genome fils1, fils2;
    for (int k=0; k<NBGENOME; k=k+2) {
        fils1=pop.at(k);
        fils2=pop.at(k+1);
        if (RANDOM<CROSSOVERRATE) {
            int pas=(rand()%(SIZE-2)+1);
            chaine1 = fils1.getchaine().substr(0,pas) + fils2.getchaine().substr(pas,SIZE-pas);
            chaine2 = fils2.getchaine().substr(0,pas) + fils1.getchaine().substr(pas,SIZE-pas);
            fils1.setchaine(chaine1);
            fils2.setchaine(chaine2);
        }

        newpop.add_genome(fils1);
        newpop.add_genome(fils2);
    }

    this->setpop(newpop.getpop());
}


/** \brief Méthode de la selection des génomes
 * \details On met d'abord à jour la fitness de la population, pour la trier ensuite pour mettre les génomes avec la meilleure fitness au début et la pire au fond de la population
 * On conserve alors un certain pourcentage (défini en paramètres par ELITRATE) de génomes intacts - principe d'élitisme.
 * La méthode de selection qu'on utilise alors ensuite est celle de la roulette : on additionne les fitness de toute la population, ce qui va créer un intervalle [0;F]
 * On va alors choisir un nombre aléatoire dans cet intervalle [0;F], et prendre le génome dont la fitness se situe à cet endroit dans l'intervalle.
 * Ainsi, les génomes avec une grande fitness ont plus de chances d'être selectionnés, tout en gardant un processus de selection aléatoire.
 * \return void
 *
 */
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
            fitnesscount += this->getpop().at(k).getfitness();
            k++;
        }
        newpop.add_genome(this->getpop().at(--k));
    }

    this->setpop(newpop.getpop());
}


/** \brief Méthode de mutation pour une population
 * \details On applique la méthode mutation de la classe genome dans toute la population
 * \return void
 *
 */
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

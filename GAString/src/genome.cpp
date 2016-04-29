#include "genome.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <GA_parameters.h>

using namespace std;

// Constructor
genome::genome(){
    string chainetemp;
    for (int j=0; j<SIZE; j++){
        chainetemp += (rand() % 90) + 32;
    }
    chaine = chainetemp;
    fitness = calculfitness();
}

genome::genome(const string chaine_init){
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

string genome::getchaine() const{
    return chaine;
}

void genome::setchaine(const string newchaine){
    this->chaine=newchaine;
}

// Methods

/** \brief Méthode qui va recalculer la fitness de chaque génome
 *
 * \return void
 *
 */
void genome::updatefitness(){
    fitness = calculfitness();
}


/** \brief Une première méthode de calculer la fitness d'un génome
 * \details Celle-ci est égale au nombre de caractères que le génome a en commun avec la chaîne cible.
 * \return int
 *
 */
int genome::calculfitness() {
    int sum = 0;
    for (int i = 0; i < SIZE; i++){
        if (chaine.at(i)!=target.at(i)){
            sum += 1;
        }
    }
    /* Une deuxième méthode éventuelle, mais qui marche beaucoup moins bien
    for (int i = 0; i < SIZE; i++){
        sum += abs(this->getchaine().at(i)-target.at(i));
    }
    */

    return SIZE - sum;
}


/** \brief Méthode qui va remplacer certains caractères du génome
 * \details On parcourt la chaîne du génome actuel de caractère en caractère et à chaque pas on génère un nombre entre 0 et 1.
 * Si celui-ci est inférieur au paramètre MUTERATE, on remplace le caractère correspondant par un autre aléatoire de la table ASCII
 * compris entre 32 et 122 (32 afin d'éviter les premiers caractères qui ne correspondent à aucune lettre de l'alphabet, 122 pour la dernière lettre relevante de la table ASCII).
 * \return void
 *
 */
void genome::mutation() {
    string tempchaine = this->chaine;

    for (int i=0; i<SIZE; i++) {
        if (RANDOM<MUTERATE)
            tempchaine.at(i) = (rand() % 91)+32;
    }

    this->setchaine(tempchaine);
}


// toString
string genome::toString() const{
    return "chaine : "+chaine+" | fitness : ("+std::to_string(fitness)+")";
}


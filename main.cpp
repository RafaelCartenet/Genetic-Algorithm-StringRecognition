#include <iostream>
#include <cstdlib>
#include <ctime>
#include <genome.h>
#include <population.h>
#include <GA_parameters.h>
#include <fstream>

using namespace std;

/** \brief Méthode principale de l'algorithme génétique.
 * \details Cette méthode est la seule que nous utiliserons dans le main : elle va créer une population vide,
 * à partir de laquelle on va travailler. On y appliquera les mutations, crossovers et selections et on
 * affichera à chaque génération le meilleur génome ainsi que le MUTERATE actuel.
 * La méthode s'arrête quand elle est arrivée au terme des générations ou que la fitness du meilleur génome est égal à la taille de la chaine target.
 * \return void
 *
 */
void GeneticAlgorithm(){
    ofstream myfile;
    myfile.open ("results.txt");
    int i;
    population unepop = population();
    unepop.initialiser_population();
    genome best_global_genome = unepop.getbestgenome();

    for (i = 0; i < NBGENE; i++){
        unepop.mutation();
        unepop.crossover();
        unepop.selection();
        unepop.update_muterate(MUTERATE);

        if (unepop.getbestgenome().getfitness() >= best_global_genome.getfitness())
            best_global_genome = unepop.getbestgenome();

        cout << i << " : " << best_global_genome.toString() << "/" << SIZE << ") Muterate actuel : " << MUTERATE << endl;
        myfile << i << " " << best_global_genome.getfitness() << " " << MUTERATE << endl;
        if (best_global_genome.getfitness() == (int)SIZE) break;
    }
    cout << "Génération finale : " << i << endl;

    myfile.close();
}


int main()
{
    srand(std::time(0));
    GeneticAlgorithm();
}

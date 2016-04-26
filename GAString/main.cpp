#include <iostream>
#include <cstdlib>
#include <ctime>
#include <genome.h>
#include <population.h>
#include <GA_parameters.h>
#include <fstream>

using namespace std;

void GeneticAlgorithm(){
    population pop = population();
    for (int i = 0; i < NBGENE; i++){
        pop.selection();
        pop.crossover();
        // pop.mutation();
        cout << pop.toString() << endl;
    }
}


int main()
{
    ofstream myfile;
    myfile.open ("results.txt");

    srand(std::time(0));
    int i;
    population unepop = population();
    unepop.initialiser_population();

    genome best_global_genome = unepop.getbestgenome();


    for (i = 0; i < NBGENE; i++){
        unepop.mutation();
        unepop.crossover();
        unepop.selection();

        int delta = unepop.getpop().at(0).getfitness() - unepop.getpop().at(NBGENOME/2).getfitness();

        if (delta < DELTAFITNESS && MUTERATE<MUTERATEMAX)
            MUTERATE*=COEFFMUTERATE;


        if (unepop.getbestgenome().getfitness() >= best_global_genome.getfitness())
            best_global_genome = unepop.getbestgenome();

        cout << i << " : " << best_global_genome.toString() << " muterate : " << MUTERATE << endl;
        if (best_global_genome.getfitness() == SIZE) break;
        myfile << i << " " << best_global_genome.getfitness() << " " << MUTERATE << endl;
    }
    cout << "Génération actuelle : " << i << endl;

    myfile.close();
}


/* From  the  literature  reviewed  it is  observed  that  the  optimal  values for  mutation  probability
(0.001)  and single point crossover with probability (0.6) with population size (50-100) as suggested by DeJong (1975) have been used in many GA implementations. Mutation proba
bility above 0.05 is in general harmful for the  optimal performance  of GAs  as concluded  by Grefenstelle
(1986). Schaffer et al.(1989) suggested optimal  parameter  settings  which  are  nearly  the  same  as  that  of  Grefenstelle
(1986). Forgarty  (1989) showed that the varying mutation probabilities significantly prove the performance of GA and Hesset &
Mannar  (1991)  showed  that  the  mutation  probability  should  be  decreased  during  the  convergence  in
agreement with the results of Forgarty (1989 */

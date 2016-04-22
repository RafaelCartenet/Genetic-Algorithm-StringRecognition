#include <iostream>
#include <cstdlib>
#include <ctime>
#include <genome.h>
#include <population.h>
#include <GA_parameters.h>

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
    srand(std::time(0));
    int i;
    population unepop = population();
    unepop.initialiser_population();

    for (i = 0; i < NBGENE; i++){
        unepop.mutation();
        unepop.crossover();
        unepop.selection();
        cout << unepop.getbestgenome().toString();
        if (unepop.getbestgenome().getfitness() == SIZE){break;}
    }
    cout << i << endl;
}

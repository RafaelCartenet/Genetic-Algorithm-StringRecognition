#include <iostream>
#include <genome.h>
#include <population.h>
#include <GA_parameters.h>

using namespace std;

void GeneticAlgorithm(){
    population pop = population();
    for (int i = 0; i < NBGENE; i++){
        pop.selection();
        pop.crossover();
        pop.mutation();
        cout << pop.toString() << endl;
    }
}


int main()
{
    GeneticAlgorithm();
}

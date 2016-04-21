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

    population unepop = population();

    //genome genA = genome("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    //genome genB = genome("bbbbbbbbbbbbbbbbbbbbbbbbbbbb");
    //unepop.add_genome(genA);
    //unepop.add_genome(genB);

    unepop.initialiser_population();


    for (int i = 0; i < 50; i++){
        unepop.crossover();
        unepop.mutation();
        unepop.selection();
        cout << unepop.toString() << endl;
    }
}

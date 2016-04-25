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
        if (unepop.getbestgenome().getfitness() >= best_global_genome.getfitness()) {
            best_global_genome = unepop.getbestgenome();
        }
        cout << best_global_genome.toString();
        if (best_global_genome.getfitness() == SIZE){break;}
        myfile << i << " " << best_global_genome.getfitness() << endl;
    }
    cout << i << endl;

    myfile.close();
}

#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include <genome.h>

using namespace std;

class population
{
    public:
        // Constructor / Destructor
        population();
        virtual ~population();

        // Getters / Setters
        vector<genome> getpop();
        void setpop(vector<genome>);

        // Methods
        genome getbestgenome() const;
        void initialiser_population();
        void updatefitness();
        void population_vierge();
        void add_genome(genome gen);
        void del_genome(int i);
        bool fitness_sort(genome gen1, genome gen2);
        void sort_by_fitness();
        void crossover();
        void selection();
        void mutation();


        // toString
        string toString();
    private:
        vector<genome> pop;
};

#endif // POPULATION_H

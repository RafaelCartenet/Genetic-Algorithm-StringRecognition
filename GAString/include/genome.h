#ifndef GENOME_H
#define GENOME_H
#include <string>

using namespace std;

class genome
{
    public:
        // Constructeurs / Destructeurs
        genome();
        virtual ~genome();

        // Getters / Setters
        int getfitness();
        string getchaine();

        // Méthodes
        void calculfitness();
    private:
        string chaine;
        int fitness;
};

#endif // GENOME_H

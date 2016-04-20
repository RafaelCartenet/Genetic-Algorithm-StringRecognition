#ifndef GENOME_H
#define GENOME_H
#include <string>

using namespace std;

class genome
{
    public:
        // Constructor / Destructor
        genome();
        genome(string chaine_init);
        virtual ~genome();

        // Getters / Setters
        int getfitness();
        string getchaine();

        // Methods
        int calculfitness();
        void mutation();

        // toString
        string toString();

        string chaine;
    private:

        int fitness;
};

#endif // GENOME_H

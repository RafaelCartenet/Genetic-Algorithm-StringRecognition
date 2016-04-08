#ifndef GENOME_H
#define GENOME_H
#include <string>

using namespace std;

class genome
{
    public:
        // Constructor / Destructor
        genome();
        virtual ~genome();

        // Getters / Setters
        int getfitness();
        string getchaine();

        // Methods
        int calculfitness();
        void mutation();
        void mutation2();

        // toString
        string toString();
    private:
        string chaine;
        int fitness;
};

#endif // GENOME_H

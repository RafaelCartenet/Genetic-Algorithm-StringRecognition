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
        void setchaine(string newchaine);

        // Methods
        int calculfitness();
        void mutation();

        // toString
        string toString();


    private:
        string chaine;
        int fitness;
};

#endif // GENOME_H

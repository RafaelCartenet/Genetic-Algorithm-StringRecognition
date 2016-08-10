#ifndef GENOME_H
#define GENOME_H
#include <string>

using namespace std;

/** \brief Classe génome
 * \details La classe est composée d'une chaîne de caractères ainsi qu'une fitness qui correspond au degré de similarité
 * entre la chaîne du génome et la chaîne cible que l'on cherche à reproduire.

 */
class genome
{
    public:
        // Constructor / Destructor
        genome();
        genome(string chaine_init);
        virtual ~genome();

        // Getters / Setters
        int getfitness() const;
        string getchaine() const;
        void setchaine(string newchaine);

        // Methods
        int calculfitness();
        void updatefitness();
        void mutation();

        // toString
        string toString() const;

    private:
        string chaine;
        int fitness;
};

#endif // GENOME_H

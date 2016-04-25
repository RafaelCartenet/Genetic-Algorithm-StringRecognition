#ifndef GA_PARAMETERS_H
#define GA_PARAMETERS_H


#define target string("Jaubert le punk qui avale")
#define SIZE target.size()
#define ELITRATE 0.20
#define CROSSOVERRATE 0.65
#define NBGENOME 30
#define NBGENE 10000
#define RANDOM (float)(rand()%100+1)/100
#define DELTAFITNESS 1
#define COEFFMUTERATE 1.008

static double MUTERATE=0.02; //On définit MUTERATE ainsi afin d'avoir la possibilité de le faire varier dans l'algo.

#endif GA_PARAMETERS_H


/* Param Optimaux actuels :
#define ELITRATE 0.20
#define CROSSOVERRATE 0.65
#define NBGENOME 76
#define NBGENE 10000
#define RANDOM (float)(rand()%100+1)/100
#define DELTAFITNESS 1
*/

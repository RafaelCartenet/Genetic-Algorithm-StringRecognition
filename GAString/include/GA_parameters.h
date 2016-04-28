#ifndef GA_PARAMETERS_H
#define GA_PARAMETERS_H


#define target string("Hello world !")

#define SIZE target.size()
#define RANDOM (float)(rand()%100+1)/100
#define NBGENE 10000

//Paramètres du GA

#define ELITRATE 0.20
#define CROSSOVERRATE 0.65
#define NBGENOME (SIZE%2==1?SIZE+1:SIZE)
#define DELTAFITNESS 1
#define COEFFMUTERATE 1.008
#define MUTERATEMAX 0.05

//On définit MUTERATE ainsi afin d'avoir la possibilité de le faire varier dans l'algo.
static double MUTERATE=0.01;

#endif GA_PARAMETERS_H

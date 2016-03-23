#include <iostream>
#include <genome.h>
#include <GA_parameters.h>

using namespace std;

int main()
{
    genome a;
    a=genome();
    int test = MUTERATE;
    cout << a.getchaine() << endl;
    cout << a.getfitness() << endl;
    a.calculfitness();
    cout << a.getfitness() << endl;
}

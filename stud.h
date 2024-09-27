#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "mylib.h"

struct Stud {
    string vardas, pavarde;
    vector<double> ND;
    double vid, med, egz, rezvid, rezmed;
};

void ived(Stud &Lok);
void output(Stud Lok);
void val(Stud &Lok);
void vidurkis(Stud &Lok);
void galutinisvid(Stud &Lok);
void mediana(Stud &Lok);
void galutinismed(Stud &Lok);
void autom(Stud &Lok);


#endif // STUD_H_INCLUDED

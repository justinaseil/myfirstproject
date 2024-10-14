#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "mylib.h"

struct Stud {
    string vardas, pavarde;
    vector<double> ND;
    double vid, med, egz, rezvid, rezmed;
    bool sumediana;
};

void ived(Stud &Lok);
void output(Stud Lok);
void val(Stud &Lok);
void vidurkis(Stud &Lok);
void galutinisvid(Stud &Lok);
void mediana(Stud &Lok);
void galutinismed(Stud &Lok);
void autom(Stud &Lok);
void nuskaitymas(vector<Stud> &students, const string &filename);
void genfailas(const string& filename, int numStudents);
void ratefailas(const vector<Stud>& students, ofstream& outFile, const string& title);



#endif // STUD_H_INCLUDED

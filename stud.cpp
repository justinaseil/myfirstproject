#include "stud.h"


void ived(Stud &Lok) {
    cout << "Input Name, Surname and Exam point: ";
    cin >> Lok.vardas >> Lok.pavarde >> Lok.egz;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    double grade;
    cout << "Input homework grades and press enter twice to finish: " << endl;

    while (true) {
        string input;
        getline(cin, input);
        if (input.empty()) {
            break;
        }
        try {
            grade = stod(input);
            Lok.ND.push_back(grade);
        } catch (...) {
            cout << "Error. Try again" << endl;
        }
    }
}

void autom(Stud &Lok) {
    cout << "Input Name, Surname: ";
    cin >> Lok.vardas >> Lok.pavarde;

    srand(time(0));
    Lok.egz = rand() % 10 + 1;

    for (int j = 0; j < 12; ++j) {
        Lok.ND.push_back(rand() % 10 + 1);
    }
}


void vidurkis(Stud &Lok) {
    if (!Lok.ND.empty()) {
        Lok.vid = accumulate(Lok.ND.begin(), Lok.ND.end(), 0.0) / Lok.ND.size();
    } else {
        Lok.vid = 0.0;
    }
}


void mediana(Stud &Lok) {
    if (!Lok.ND.empty()) {
        sort(Lok.ND.begin(), Lok.ND.end());
        int size = Lok.ND.size();
        if (size % 2 == 0) {
            Lok.med = (Lok.ND[size / 2 - 1] + Lok.ND[size / 2]) / 2.0;
        } else {
            Lok.med = Lok.ND[size / 2];
        }
    } else {
        Lok.med = 0.0;
    }
}

void galutinisvid(Stud &Lok) {
    vidurkis(Lok);
    Lok.rezvid = 0.4 * Lok.vid + 0.6 * Lok.egz;
}

void galutinismed(Stud &Lok) {
    mediana(Lok);
    Lok.rezmed = 0.4 * Lok.med + 0.6 * Lok.egz;
}


void output(Stud Lok) {
    cout << left << setw(18) << Lok.vardas
         << setw(20) << Lok.pavarde
         << fixed << setprecision(2)
         << Lok.rezvid << "                      "
         << fixed << setprecision(2)
         << Lok.rezmed << endl;
}

void val(Stud &Lok) {
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.ND.clear();
    Lok.vid = 0;
    Lok.rezmed = 0;
    Lok.rezvid = 0;
}

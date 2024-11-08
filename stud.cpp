#include "stud.h"

void genfailas(const string& filename, int numStudents) {

    auto start = steady_clock::now();

    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    file << "Vardas Pavarde ";
    for (int i = 1; i <= 10; ++i) {
        file << "ND" << i << " ";
    }
    file << "Egzaminas" << endl;

    srand(time(0));

    for (int i = 1; i <= numStudents; ++i) {
        file << "Vardas" << i << " Pavarde" << i << " ";

        for (int j = 0; j < 10; ++j) {
            file << rand() % 10 + 1 << " ";
        }

        file << rand() % 10 + 1 << endl;
    }

    file.close();

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);

    cout << "File " << filename << " created in " << diff.count() << " s." << endl;
}

    void generuotifailus() {
    genfailas("studentai1000.txt", 1000);
    genfailas("studentai10000.txt", 10000);
    genfailas("studentai100000.txt", 100000);
    genfailas("studentai1000000.txt", 1000000);
    genfailas("studentai10000000.txt", 10000000);
}


void ived(Stud &Lok) {
    cout << "Input Name and Surname: ";
    cin >> Lok.vardas >> Lok.pavarde;

    while (true) {
        cout << "Input Exam points: ";
        if (cin >> Lok.egz && Lok.egz >= 0 && Lok.egz <= 10) {
            break;
        } else {
            cout << "Error. Try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

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
            if (grade >= 0 && grade <= 10) {
                Lok.ND.push_back(grade);
            } else {
                cout << "Error. Enter number from 0 to 10..." << endl;
            }
        } catch (...) {
            cout << "Error. Enter number from 0 to 10..." << endl;
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
         << fixed << setprecision(2);

    if (Lok.sumediana) {
        cout << Lok.rezmed << endl;
    } else {
        cout << Lok.rezvid << endl;
    }
}


void val(Stud &Lok) {
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.ND.clear();
    Lok.vid = 0;
    Lok.rezmed = 0;
    Lok.rezvid = 0;
}



template void nuskaitymas<vector<Stud>>(vector<Stud>& students, const string& filename);
template void ratefailas<vector<Stud>>(const vector<Stud>& students, const string& filename, const string& title);
template void rusiavimas<vector<Stud>>(vector<Stud>& students, vector<Stud>& vargsiukai, bool sumediana);
template void sortabc<vector<Stud>>(vector<Stud>& students);
template void testavimas<vector<Stud>>(vector<Stud>& students, const string& filename, int numStudents);

template void nuskaitymas<list<Stud>>(list<Stud>& students, const string& filename);
template void ratefailas<list<Stud>>(const list<Stud>& students, const string& filename, const string& title);
template void rusiavimas<list<Stud>>(list<Stud>& students, list<Stud>& vargsiukai, bool sumediana);
template void sortabc<list<Stud>>(list<Stud>& students);
template void testavimas<list<Stud>>(list<Stud>& students, const string& filename, int numStudents);


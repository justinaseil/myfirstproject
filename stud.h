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
void genfailas(const string& filename, int numStudents);
void generuotifailus();

template <typename Container>
void nuskaitymas(Container& students, const string& filename) {

    auto start = steady_clock::now();

    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error opening file.");
    }

    string header;
    getline(file, header);

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        Stud student;
        ss >> student.vardas >> student.pavarde;

        double grade;
        while (ss >> grade) {
            if (grade >= 0 && grade <= 10) {
                student.ND.push_back(grade);
            } else {
                throw runtime_error("Invalid grade format in file.");
            }
        }

        if (!student.ND.empty()) {
            student.egz = student.ND.back();
            student.ND.pop_back();
        } else {
            throw runtime_error("No grades found in file.");
        }

        students.push_back(student);
    }

    file.close();

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);

    cout << "File " << filename << " read in " << diff.count() << " s." << endl;
}

template <typename Container>
void ratefailas(const Container& students, const string& filename, const string& title) {
    auto start = steady_clock::now();

    ofstream file(filename);
    if (file.is_open()) {
        file << title << ":\n";
        file << left << setw(20) << "Vardas"
             << setw(25) << "Pavardė"
             << setw(30) << "Galutinis (Vid.)/Galutinis (Med.)" << endl;
        file << "-----------------------------------------------------------------------" << endl;

        for (const auto& student : students) {
            file << left << setw(20) << student.vardas
                 << setw(25) << student.pavarde
                 << fixed << setprecision(2);
            if (student.sumediana) {
                file << student.rezmed << endl;
            } else {
                file << student.rezvid << endl;
            }
        }

        file.close();
    } else {
        cout << "Unable to open " << filename << " file." << endl;
    }

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "File " << filename << " created in " << diff.count() << " s." << endl;
}

template <typename Container>
void rusiavimas(const Container& students, Container& vargsiukai, Container& kietekai, bool sumediana) {
    auto start = steady_clock::now();

    for (const auto& student : students) {
        if (sumediana && student.rezmed == 0) {
            galutinismed(const_cast<Stud&>(student));
        } else if (!sumediana && student.rezvid == 0) {
            galutinisvid(const_cast<Stud&>(student));
        }

        if (sumediana) {
            if (student.rezmed < 5.0) {
                vargsiukai.push_back(student);
            } else {
                kietekai.push_back(student);
            }
        } else {
            if (student.rezvid < 5.0) {
                vargsiukai.push_back(student);
            } else {
                kietekai.push_back(student);
            }
        }
    }

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "Students sorted into 'vargsiukai' and 'kietekai' in " << diff.count() << " s." << endl;
}

template <typename Container>
void testavimas(Container& students, const string& filename, int numStudents) {

    auto start = steady_clock::now();

    genfailas(filename, numStudents);

    Container vargsiukai;
    Container kietekai;

    nuskaitymas(students, filename);

    bool sumediana = false;
    rusiavimas(students, vargsiukai, kietekai, sumediana);
    sortabc(kietekai);
    sortabc(vargsiukai);

    ratefailas(kietekai, "kietekai_" + filename, "Kietekai");
    ratefailas(vargsiukai, "vargsiukai_" + filename, "Vargšiukai");

    students.clear();

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "Testing time for " << filename << ": " << diff.count() << " s." << endl;
    cout << "File testing done. " << endl;
    cout << endl;
}


template <typename Container>
void sortabc(Container& students) {
    auto start = steady_clock::now();

    if constexpr (is_same<Container, vector<Stud>>::value) {
        sort(students.begin(), students.end(), [](const Stud &a, const Stud &b) {
            return toupper(a.vardas[0]) < toupper(b.vardas[0]);
        });
    } else if constexpr (is_same<Container, list<Stud>>::value) {
        students.sort([](const Stud &a, const Stud &b) {
            return toupper(a.vardas[0]) < toupper(b.vardas[0]);
        });
    }

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "Students sorted by name in " << diff.count() << " s." << endl;
}


#endif // STUD_H_INCLUDED

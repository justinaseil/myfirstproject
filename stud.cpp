#include "stud.h"

void genfailas(const string& filename, int numStudents) {
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
    cout << "File " << filename << " with " << numStudents << " students generated successfully." << endl;
}


void nuskaitymas(vector<Stud> &students, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file.");
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
                throw std::runtime_error("Invalid grade format in file.");
            }
        }

        if (!student.ND.empty()) {
            student.egz = student.ND.back();
            student.ND.pop_back();
        } else {
            throw std::runtime_error("No grades found in file.");
        }

        students.push_back(student);
    }

    file.close();
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

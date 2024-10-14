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




void nuskaitymas(vector<Stud> &students, const string &filename) {

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

void rusiavimas(const vector<Stud>& students, vector<Stud>& vargsiukai, vector<Stud>& kietekai, bool sumediana) {
    auto start = steady_clock::now();

    for (const auto& student : students) {
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

    cout << "Students were sorted to 'vargsiukai' and 'kietekai' in " << diff.count() << " s." << endl;
}

void ratefailas(const vector<Stud>& students, const string& filename, const string& title) {
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
        cout << "Nepavyko atidaryti " << filename << " failo." << endl;
    }

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "File " << filename << " created in " << diff.count() << " s." << endl;
}

void sortabc(vector<Stud>& students) {
    auto start = steady_clock::now();

    sort(students.begin(), students.end(), [](const Stud &a, const Stud &b) {
        return toupper(a.vardas[0]) < toupper(b.vardas[0]);
    });

     auto end = steady_clock::now();
     duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "Students sorted by name in " << diff.count() << " s." << endl;
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


void testavimas() {
    vector<string> failai = {
        "studentai1000.txt",
        "studentai10000.txt",
        "studentai100000.txt",
        "studentai1000000.txt",
        "studentai10000000.txt"
    };

    vector<int> studentuSkaiciai = { 1000, 10000, 100000, 1000000, 10000000 };

    for (size_t i = 0; i < failai.size(); ++i) {
        const string& filename = failai[i];
        int studentCount = studentuSkaiciai[i];

        cout << "Testing " << filename << endl;

        auto start = steady_clock::now();

        genfailas(filename, studentCount);

        vector<Stud> students;

        nuskaitymas(students, filename);


        vector<Stud> vargsiukai;
        vector<Stud> kietekai;
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
        cout << endl;
    }

    cout << "File testing done. " << endl;
}

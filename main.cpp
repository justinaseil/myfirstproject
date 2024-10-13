#include "mylib.h"
#include "stud.h"


int main() {
    vector<Stud> vec1;
    vector<Stud> vargsiukai;
    vector<Stud> kietekai;
    Stud Temp;
    char choice;
    bool sumediana = false;

    cout << "Do you want to read student data from a file? (Y/N): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 'Y' || choice == 'y') {
        string filename;
        cout << "Enter the filename: ";
        getline(cin, filename);
        nuskaitymas(vec1, filename);
    } else {
        cout << "Do you want to generate student data files? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'Y' || choice == 'y') {
            genfailas("studentai1000.txt", 1000);
            genfailas("studentai10000.txt", 10000);
            genfailas("studentai100000.txt", 100000);
            genfailas("studentai1000000.txt", 1000000);
            genfailas("studentai10000000.txt", 10000000);
            return 0;
        } else {
            cout << "How many students do you have? ";
            int n;
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            for (int i = 0; i < n; i++) {
                cout << "Please input user data for student " << endl;

                cout << "Do you want to generate random grades for this student? (Y/N): ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (choice == 'Y' || choice == 'y') {
                    autom(Temp);
                } else if (choice == 'N' || choice == 'n') {
                    ived(Temp);
                } else {
                    cout << "Error. Try again." << endl;
                    --i;
                    continue;
                }

                cout << "Do you want to calculate the final grade with median or with average ? (M/A): ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (choice == 'M' || choice == 'm') {
                        sumediana = true;
                }
                for (int i = 0; i < vec1.size(); i++) {
                        if (sumediana) {
                            galutinismed(vec1.at(i));
                } else {
                    galutinisvid(vec1.at(i));
                    }
                }

                vec1.push_back(Temp);
                val(Temp);
            }
        }
    }


    for (auto &student : vec1) {
        if (student.sumediana) {
            galutinismed(student);
            if (student.rezmed < 5.0) {
                vargsiukai.push_back(student);
            } else {
                kietekai.push_back(student);
            }
        } else {
            galutinisvid(student);
            if (student.rezvid < 5.0) {
                vargsiukai.push_back(student);
            } else {
                kietekai.push_back(student);
            }
        }
    }

    sort(kietekai.begin(), kietekai.end(), [](const Stud &a, const Stud &b) {
        return a.vardas < b.vardas;
    });

    sort(vargsiukai.begin(), vargsiukai.end(), [](const Stud &a, const Stud &b) {
        return a.vardas < b.vardas;
    });

    cout << "Kietekai" << endl;
    cout << "Vardas" << setw(20) << "Pavardė" << setw(30) << "Galutinis (Vid.)/Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    for (const auto& student : kietekai) {
        output(student);
    }

    cout << "\nVargsiukai" << endl;
    cout << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)/Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    for (const auto& student : vargsiukai) {
        output(student);
    }


    char a;
    cout << "Press any key to exit..." << endl;
    cin >> a;

    return 0;
}

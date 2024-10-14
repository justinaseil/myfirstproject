#include "mylib.h"
#include "stud.h"


int main() {
    vector<Stud> vec1;
    vector<Stud> vargsiukai;
    vector<Stud> kietekai;
    Stud Temp;
    char choice;
    bool sumediana = false;

    while (true) {
        cout << "Do you want to read student data from a file? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n') {
            break;
        } else {
            cout << "Error. Try again." << endl;
        }
    }

    if (choice == 'Y' || choice == 'y') {
        string filename;
        cout << "Enter the filename: ";
        getline(cin, filename);
        nuskaitymas(vec1, filename);

        while (true) {
            cout << "Do you want to calculate the final grade with median or with average? (M/A): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (choice == 'M' || choice == 'm') {
                sumediana = true;
                break;
            } else if (choice == 'A' || choice == 'a') {
                sumediana = false;
                break;
            } else {
                cout << "Error. Try again." << endl;
            }
        }

        for (int i = 0; i < vec1.size(); i++) {
            vec1[i].sumediana = sumediana;
            if (sumediana) {
                galutinismed(vec1[i]);
            } else {
                galutinisvid(vec1[i]);
                }
            }
    } else {

        while (true) {
            cout << "Do you want to generate student data files? (Y/N): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n') {
                break;
            } else {
                cout << "Error. Try again." << endl;
            }
        }

        if (choice == 'Y' || choice == 'y') {
            genfailas("studentai1000.txt", 1000);
            genfailas("studentai10000.txt", 10000);
            genfailas("studentai100000.txt", 100000);
            genfailas("studentai1000000.txt", 1000000);
            genfailas("studentai10000000.txt", 10000000);
            return 0;
        } else {
            int n;
            while (true) {
                cout << "How many students do you have? ";
                if (cin >> n && n > 0) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                } else {
                    cout << "Error. Try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            for (int i = 0; i < n; i++) {
                cout << "Please input user data for student " << endl;

                while (true) {
                    cout << "Do you want to generate random grades for this student? (Y/N): ";
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (choice == 'Y' || choice == 'y') {
                        autom(Temp);
                        break;
                    } else if (choice == 'N' || choice == 'n') {
                        ived(Temp);
                        break;
                    } else {
                        cout << "Error. Try again." << endl;
                    }
                }

                while (true) {
                    cout << "Do you want to calculate the final grade with median or with average? (M/A): ";
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (choice == 'M' || choice == 'm') {
                        sumediana = true;
                        break;
                    } else if (choice == 'A' || choice == 'a') {
                        sumediana = false;
                        break;
                    } else {
                        cout << "Error. Try again." << endl;
                    }
                }

                Temp.sumediana = sumediana;
                if (sumediana) {
                    galutinismed(Temp);
                } else {
                    galutinisvid(Temp);
                }

                vec1.push_back(Temp);
                val(Temp);
            }
        }
    }

    for (auto &student : vec1) {
        if (sumediana) {
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
        return a.vardas < b.vardas; //patikrinti, kaip ten su didziosiom
    });


    ofstream kietekaiFile("kietekai.txt");
    ofstream vargsiukaiFile("vargsiukai.txt");

    if (kietekaiFile.is_open()) {
        ratefailas(kietekai, kietekaiFile, "Kietekai");
        kietekaiFile.close();
    } else {
        cout << "Nepavyko atidaryti kietekai.txt failo." << endl;
    }

    if (vargsiukaiFile.is_open()) {
        ratefailas(vargsiukai, vargsiukaiFile, "Vargšiukai");
        vargsiukaiFile.close();
    } else {
        cout << "Nepavyko atidaryti vargsiukai.txt failo." << endl;
    }

    cout << "\nKietekai:\n";
    cout << left << setw(18) << "Vardas" << setw(18) << "Pavardė" << setw(25) << "Galutinis (Vid.)/Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    for (const auto& student : kietekai) {
        output(student);
    }

    cout << "\nVargšiukai:\n";
    cout << left << setw(18) << "Vardas" << setw(18) << "Pavardė" << setw(25) << "Galutinis (Vid.)/Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    for (const auto& student : vargsiukai) {
        output(student);
    }

    cout << "Files kietekai.txt and vargsiukai.txt have been written." << endl;


    char a;
    cout << "Press any key to exit..." << endl;
    cin >> a;

    return 0;
}

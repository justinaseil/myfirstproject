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
        cout << "Do you want to test the file generation and reading? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'Y' || choice == 'y') {
            testavimas();

        cout << "Do you want to continue the program? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'N' || choice == 'n') {
            return 0;
        } else if (choice == 'Y' || choice == 'y'){
            break;
        } else {
        cout << "Error.Try again" << endl;
        }
    } else if (choice == 'N' || choice == 'n') {
        break;
    } else {
        cout << "Error. Try again." << endl;
    }
    }

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
        cin >> filename;

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
            generuotifailus();
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

    rusiavimas(vec1, vargsiukai, kietekai, sumediana);

    sortabc(kietekai);
    sortabc(vargsiukai);


    cout << "\nKietekai:\n";
    cout << left << setw(18) << "Vardas" << setw(18) << "Pavardė" << setw(25) << "Galutinis (Vid.)/Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for (const auto& student : kietekai) {
        output(student);
    }

    cout << "\nVargšiukai:\n";
    cout << left << setw(18) << "Vardas" << setw(18) << "Pavardė" << setw(25) << "Galutinis (Vid.)/Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for (const auto& student : vargsiukai) {
        output(student);
    }

    ratefailas(kietekai, "kietekai.txt", "Kietekai");
    ratefailas(vargsiukai, "vargsiukai.txt", "Vargšiukai");


    char a;
    cout << "Press any key to exit..." << endl;
    cin >> a;

    return 0;
}

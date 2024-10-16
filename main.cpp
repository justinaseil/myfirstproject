#include "mylib.h"
#include "stud.h"


int main() {
    vector<Stud> vec1;
    Stud Temp;
    char choice;

    cout << "Do you want to read student data from a file? (Y/N): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 'Y' || choice == 'y') {
        string filename;
        cout << "Enter the filename: ";
        getline(cin, filename);
        try {
            nuskaitymas(vec1, filename);
        } catch (const std::exception &e) {
            cout << "Error: " << e.what() << endl;
            return 1; // return error code if file reading fails
        }
    } else {
        cout << "How many students do you have? ";
        int n;
        while (!(cin >> n) || n < 0) {
            cout << "Error. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
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

            vec1.push_back(Temp);
            val(Temp);
        }
    }

    for (int i = 0; i < vec1.size(); i++) {
        galutinisvid(vec1.at(i));
        galutinismed(vec1.at(i));
    }

    sort(vec1.begin(), vec1.end(), [](const Stud &a, const Stud &b) {
        return a.vardas < b.vardas;
    });

    cout << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    for (int i = 0; i < vec1.size(); i++) {
        output(vec1.at(i));
    }

    char a;
    cout << "Press any key to exit..." << endl;
    cin >> a;

    return 0;
}


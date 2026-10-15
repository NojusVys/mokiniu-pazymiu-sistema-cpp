#include <iostream>
#include <iomanip>

using namespace std;

void meniu();

int main() {
    string mokiniai[100];
    int pazymiai[100][10];
    int mokiniuKiekis = 0;
    int pazymiuKiekis[100] = {0};
    bool arVeikia = true;

    while(arVeikia){
        int pasirinkimas;
        meniu();
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                if (mokiniuKiekis >= 100) {
                    cout << "Sarasas pilnas, ivestis negalima." << endl;
                    break;
                }
                int x;
                cout << "Iveskite mokinio varda: ";
                cin >> mokiniai[mokiniuKiekis];
                cout << "Iveskite kiek pazymiu turi mokinys (1-10): ";
                cin >> x;
                while (x < 1 || x > 10) {
                    cout << "Ivestis neteisinga. Iveskite kiek pazymiu turi mokinys (1-10): ";
                    cin >> x;
                }
                for (int i = 0; i < x; i++) {
                    cout << "Iveskite " << i+1 << " pazymi (1-10): ";
                    cin >> pazymiai[mokiniuKiekis][i];
                    while (pazymiai[mokiniuKiekis][i] < 1 || pazymiai[mokiniuKiekis][i] > 10) {
                        cout << "Ivestis neteisinga. Iveskite " << i+1 << " pazymi (1-10): ";
                        cin >> pazymiai[mokiniuKiekis][i];
                    }
                    pazymiuKiekis[mokiniuKiekis]++;
                }
                mokiniuKiekis++;
                break;
            case 2: {
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << mokiniai[i] << ":";
                    for (int j = 0; j < pazymiuKiekis[i]; j++){
                        cout << " " << pazymiai[i][j];
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                string mokinys;
                int y = 0;
                cout << "Iveskite mokinio kurio ieskote varda: ";
                cin >> mokinys;
                for (int i = 0; i < mokiniuKiekis; i++) {
                    if (mokiniai[i] == mokinys)
                        y = i;
                }
                if (y != 0) {
                    cout << mokiniai[y] << ":";
                    for (int j = 0; j < pazymiuKiekis[y]; j++){
                        cout << " " << pazymiai[y][j];
                    }
                    cout << endl;
                    break;
                } else {
                    cout << "Mokinys nerastas." << endl;
                    break;
                }
            }
            case 4:
            case 5:
            case 6:
            case 7: {
                cout << "Programa baigiama." << endl;
                arVeikia = false;
                break;
            }
            default:
                cout << "Pasirinkimas negalimas, bandykite dar karta." << endl;
        }
    }

    return 0;
}

void meniu() {
    cout << "1. Ivesti mokini ir jo pazymius." << endl;
    cout << "2. Perziureti visu mokiniu pazymius." << endl;
    cout << "3. Perziureti konkretaus mokinio pazymius." << endl;
    cout << "4. Atnaujinti pazymi." << endl;
    cout << "5. Apskaiciuoti mokinio vidurki." << endl;
    cout << "6. Pasalinti mokini." << endl;
    cout << "7. Iseiti." << endl;
    cout << "Prasome pasirinkti: ";
}

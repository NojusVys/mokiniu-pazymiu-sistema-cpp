#include <iostream>
#include <iomanip>

using namespace std;

void meniu();
int mokinioPaieska(int mokiniuKiekis, string *mokiniai);

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
                cout << "Iveskite mokinio varda: ";
                cin >> mokiniai[mokiniuKiekis];
                for (int i = 0; i < 10; i++) {
                    int ivestis;
                    cout << "Iveskite " << i+1 << " pazymi (1-10) (-1, kad baigti ivesti): ";
                    cin >> ivestis;
                    if (ivestis == -1) {
                        break;
                    }
                    while (ivestis < 1 || ivestis > 10) {
                        cout << "Ivestis neteisinga. Iveskite " << i+1 << " pazymi (1-10) (-1, kad baigti ivesti): ";
                        cin >> ivestis;
                        if (ivestis == -1) {
                            break;
                        }
                    }
                    if (ivestis == -1) {
                        break;
                    }
                    pazymiai[mokiniuKiekis][i] = ivestis;
                    pazymiuKiekis[mokiniuKiekis]++;
                }
                mokiniuKiekis++;
                break;
            case 2: {
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << left << setw(15) << mokiniai[i] << ":";
                    for (int j = 0; j < pazymiuKiekis[i]; j++){
                        cout << " " << pazymiai[i][j];
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                int y = mokinioPaieska(mokiniuKiekis,  mokiniai);
                while (y == -2) {
                    cout << "Mokinys nerastas." << endl;
                    y = mokinioPaieska(mokiniuKiekis,  mokiniai);
                    if(y == -1)
                        break;
                }
                if (y == -1)
                    break;
                cout << mokiniai[y] << ":";
                for (int j = 0; j < pazymiuKiekis[y]; j++){
                    cout << " " << pazymiai[y][j];
                }
                cout << endl;
                break;
            }
            case 4: {
                int y = mokinioPaieska(mokiniuKiekis, mokiniai);
                int x;
                while (y == -2) {
                    cout << "Mokinys nerastas." << endl;
                    y = mokinioPaieska(mokiniuKiekis,  mokiniai);
                    if(y == -1)
                        break;
                }
                if (y == -1)
                    break;
                cout << "Iveskite kuri pazymi norite atnaujinti (1-" << pazymiuKiekis[y] << "): ";
                cin >> x;
                while (x < 1 || x > pazymiuKiekis[y]) {
                    cout << "Ivestis neteisinga. Iveskite kuri pazymi norite atnaujinti (1-" << pazymiuKiekis[y] << "): ";
                    cin >> x;
                }
                x -= 1;
                cout << "Iveskite nauja pazymi (1-10): ";
                cin >> pazymiai[y][x];
                while (pazymiai[y][x] < 1 || pazymiai[y][x] > 10) {
                    cout << "Ivestis neteisinga. Iveskite nauja pazymi (1-10): ";
                    cin >> pazymiai[y][x];
                }
                break;
            }
            case 5: {
                double vidurkis = 0;
                int y = mokinioPaieska(mokiniuKiekis, mokiniai);
                while (y == -2) {
                    cout << "Mokinys nerastas." << endl;
                    y = mokinioPaieska(mokiniuKiekis,  mokiniai);
                    if(y == -1)
                        break;
                }
                if (y == -1)
                    break;
                if (pazymiuKiekis[y] > 0) {
                    for (int i = 0; i < pazymiuKiekis[y]; i++) {
                        vidurkis += static_cast<double>(pazymiai[y][i]);
                    }
                    cout << fixed << setprecision(2) << "Mokinio " << mokiniai[y] << " vidurkis: " << vidurkis / pazymiuKiekis[y] << endl;
                } else
                    cout << "Mokinys neturi pazymiu." << endl;
                break;
            }
            case 6: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu nera, operacija negalima." << endl;
                    break;
                }

                int y = mokinioPaieska(mokiniuKiekis, mokiniai);
                while (y == -2) {
                    cout << "Mokinys nerastas." << endl;
                    y = mokinioPaieska(mokiniuKiekis,  mokiniai);
                    if(y == -1)
                        break;
                }
                if (y == -1)
                    break;
                string laikinasVardas = mokiniai[y];
                for (int i = y; i < mokiniuKiekis - 1; i++) {
                    mokiniai[i] = mokiniai[i+1];
                    pazymiuKiekis[i] = pazymiuKiekis[i+1];

                    for (int j = 0; j < 10; j++) {
                        pazymiai[i][j] = pazymiai[i+1][j];
                    }
                }
                mokiniuKiekis--;
                cout << "Mokinys " << laikinasVardas << " sekmingai pasalintas." << endl;
                break;
            }
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

int mokinioPaieska (int mokiniuKiekis, string *mokiniai) {
    string mokinys;
    int y = -2;
    cout << "Iveskite mokinio kurio ieskote varda (norint atsaukti iveskite 'atsaukti'): ";
    cin >> mokinys;

    for (char &c : mokinys){
        c = toupper(c);
    }

    if (mokinys == "ATSAUKTI") {
        return -1;
    }

    for (int i = 0; i < mokiniuKiekis; i++) {
        string laikinasVardas = mokiniai[i];
        for (char &c : laikinasVardas){
            c = toupper(c);
        }
        if (laikinasVardas == mokinys) {
            y = i;
            return y;
        }
        if (laikinasVardas == "ATSAUKTI") {
            return -1;
        }
    }
    return -2;
}

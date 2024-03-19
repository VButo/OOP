#include <iostream>
#include <vector>
using namespace std;

class Pedalina {
public:
    string boja;
    int kapacitet;
};


class Lokacija {
public:
    string ime, prezime;
    double X, Y;
    vector<Pedalina> vPedalina;

    void dodaj(Pedalina _pedalina) {
        vPedalina.push_back(_pedalina);
    }
};

int main()
{
    int n;
    vector<Lokacija> lokacija;
    Pedalina tempP;
    Lokacija tempL;
    cout << "Unesite broj lokacija (N): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Unesite odgovornu osobu i GPS koordinate za " << i+1 << ". lokaciju:" << endl;
        cin >> tempL.ime >> tempL.prezime;
        cin >> tempL.X >> tempL.Y;

        lokacija.push_back(tempL);
    }
    int m;
    cout << "Unesite broj pedalina (M): ";
    cin >> m;
    int j = 0;

    for (int i = 0; i < m; i++) {
        cout << "Unesite redni broj lokacije kojoj pripada 1. pedalina: ";
        cin >> j;

        cout << "Unesite boju i kapacitet pedaline: ";
        cin >> tempP.boja >> tempP.kapacitet;

        lokacija[j - 1].dodaj(tempP);

    }
    cout << endl;
    cout << "Ispis lokacija i pedalina:" << endl;


    for (int i = 0; i < lokacija.size(); i++) {
        cout << i + 1 << ". " << lokacija[i].X << " " << lokacija[i].Y << " "
            << lokacija[i].ime << " " << lokacija[i].prezime << " - pedaline:";

        for (j = 0; j < lokacija[i].vPedalina.size(); j++) {
            cout << " " << lokacija[i].vPedalina[j].boja << " (" << lokacija[i].vPedalina[j].kapacitet << ")";
        }

        cout << endl;
    }

    return 0;
}

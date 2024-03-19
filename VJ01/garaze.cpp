//Tekst na: https://github.com/VButo/OOP/blob/44effabfb2a82b28ce87be848839433e659ac0e5/Tekstovi/garaza_tekst.png

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Kljuc {
public:
    string ime, prezime;
};

class Garaza {
public:
    int sirina, duljina, cijena;
    string lokacija;
    vector<Kljuc> vKljuc;
};

int main() {
    int n, m;
    vector<Garaza> vGaraza;
    Kljuc tempK;
    Garaza tempG;

    cout << "Unesite broj garaza (N):";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Unesite velicinu, lokaciju i cijenu za " << i + 1 << ". garazu:" << endl;
        cin >> tempG.sirina >> tempG.duljina;
        cin.ignore();
        getline(cin, tempG.lokacija);
        cin >> tempG.cijena;

        vGaraza.push_back(tempG);
    }

    cout << "Unesite broj kljuceva (M): ";
    cin >> m;
    int j = 0;
    for (int i = 0; i < m; i++) {
        cout << "Unesite redni broj garaze kojoj pripada 1. kljuc: ";
        cin >> j;
        cout << "Unesite ime vlasnika kljuca: ";
        cin >> tempK.ime >> tempK.prezime;
        vGaraza[j - 1].vKljuc.push_back(tempK);
    }
    
    cout << "\nIspis garaza i kljuceva:" << endl;
    for (int i = 0; i < vGaraza.size(); i++) {
        cout << i + 1 << ". " << vGaraza[i].lokacija << " " << vGaraza[i].sirina << "x" << vGaraza[i].duljina << " - kljucevi:";
        for (int j = 0; j < vGaraza[i].vKljuc.size(); j++) {
            cout << " " << vGaraza[i].vKljuc[j].ime << " " << vGaraza[i].vKljuc[j].prezime;
        }
        cout << endl;
    }

    return 0;
}

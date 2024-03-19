#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Artikl {
public:
    int kolicina;
    double cijena;
    string proizvod;

    Artikl(string _proizvod, int _kolicina, double _cijena) : proizvod(_proizvod), kolicina(_kolicina), cijena(_cijena) {}
};

class Racun {
public:
    int brRacun;
    Racun(int _brRacun) : brRacun(_brRacun) {}
    vector<Artikl> vArtikl;

    void dodaj(Artikl _Artikl) {
        vArtikl.push_back(_Artikl);
    }

    int ukupnaCijena() {
        int total = 0;
        for (int i = 0; i < vArtikl.size(); i++) {
            total += vArtikl[i].kolicina * vArtikl[i].cijena;
        }
        return total;
    }

    Artikl najskuplji() {
        int n = 0;
        Artikl max = vArtikl[0];
        for (int i = 0; i < vArtikl.size(); i++) {
            if (max.cijena*max.kolicina < vArtikl[i].cijena*vArtikl[i].kolicina) {
                max = vArtikl[i];
            }
        }
        return max;
    }

};

class Kupac {
public:
    Racun racun;

    Kupac(Racun _racun) : racun(_racun) {}
};

int main() {
    Kupac Ante(Racun(1)); // Ante ima račun broj 1

    Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
    Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
    Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca

    cout << "Ukupno: " << Ante.racun.ukupnaCijena() << " kn" << endl; // 41 kn

    
    cout << "Najskuplje placeni artikl je " << Ante.racun.najskuplji().proizvod << " (" << Ante.racun.najskuplji().cijena * Ante.racun.najskuplji().kolicina << "kn)" << endl;

    return 0;
}

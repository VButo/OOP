#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Igrac {
public:
    string ime, prezime;
    int broj, cijena;
    Igrac(string _ime, string _prezime): ime(_ime), prezime(_prezime){}

    void ispisi() {
        cout << ime << " " << prezime << " (" << broj << ") - Cijena: " << cijena << endl;
    }
};

class Ekipa{
public:
    string naziv;

    vector<Igrac> vIgrac;
    void dodajIgraca(Igrac igrac) {
        vIgrac.push_back(igrac);
    }

    void ispisi() {
        cout << naziv << ":" << endl;
        for (int i = 0; i < vIgrac.size(); i++) {
            vIgrac[i].ispisi();
        }
    }

    Igrac dohvatiNajskupljeg() {
        Igrac max = vIgrac[0];
        for (int i = 0; i < vIgrac.size(); i++) {
            if (max.cijena < vIgrac[i].cijena) {
                max = vIgrac[i];
            }
        }
        return max;
    }

    int ukupnaCijena() {
        int total = 0;
        for (int i = 0; i < vIgrac.size(); i++) {
            total += vIgrac[i].cijena;
        }
        return total;
    }

    int prosjecnaCijena() {
        int mid = ukupnaCijena() / vIgrac.size();
        return mid;
    }
};



int main() {
    Ekipa ekipa;
    ekipa.naziv = "Tim raketa";
    Igrac i1("Luka", "Modric");
    i1.broj = 10;
    i1.cijena = 50000000;
    ekipa.dodajIgraca(i1);
    Igrac i2("Mario", "Mandzukic");
    i2.broj = 9;
    i2.cijena = 27000000;
    ekipa.dodajIgraca(i2);
    Igrac i3("Darijo", "Srna");
    i3.broj = 11;
    i3.cijena = 14500000;
    ekipa.dodajIgraca(i3);

    ekipa.ispisi();

    Igrac najskuplji = ekipa.dohvatiNajskupljeg();
    cout << "Najskuplji igrac: ";
    najskuplji.ispisi();

    cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;
    cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;

}

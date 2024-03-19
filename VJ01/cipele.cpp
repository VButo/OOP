//Tekst na: https://github.com/VButo/OOP/blob/3d1b3f6593216057b864c9a7cc8fe25ad640535a/Tekstovi/cipele_tekst.png

#include <iostream>
#include <vector>
using namespace std;

class Cipela {
public:
    string materijal, boja;
    int velicina;

    Cipela(int _velicina, string _materijal, string _boja): velicina(_velicina), materijal(_materijal), boja(_boja){}

};

class Narudzba {
public:
    string narucitelj;
    vector<Cipela> vCipela;

    Narudzba(string _narucitelj): narucitelj(_narucitelj){}
    Narudzba() = default;

    void dodajCipelu(Cipela cipela) {
        vCipela.push_back(cipela);
    }
};


class Postolar {
public:
    vector<Narudzba> vNarudzbe;
    double preuzmiNarudzbu(Narudzba narudzba) {
        double ukupno = 0;
        for (int i = 0; i < narudzba.vCipela.size(); i++) {
            ukupno += (double)narudzba.vCipela[i].velicina * 10.5;
        }
        vNarudzbe.push_back(narudzba);
        return ukupno;
    }

    void ispisiNarudzbe() {
        cout << "Ispis narudzbi i narucitelja:" << endl;
        for (int i = 0; i < vNarudzbe.size(); i++) {
            cout << i + 1 << " " << vNarudzbe[i].narucitelj << " Cipele:";
            for (int j = 0; j < vNarudzbe[i].vCipela.size(); j++) {
                cout << " " << vNarudzbe[i].vCipela[j].materijal << " " << vNarudzbe[i].vCipela[j].boja << " (" << vNarudzbe[i].vCipela[j].velicina << ")";
            }
            cout << endl;
        }

    }

};


int main() {
    Postolar p;
    Narudzba n1;
    n1.narucitelj = "Susjed Mirko";

    //Cipela ima broj (velicinu), materijal i boju
    n1.dodajCipelu(Cipela(47, "Sky", "plava"));
    n1.dodajCipelu(Cipela(44, "Platno", "zelena"));

    //Cijena izrade jedne cipele se racuna na nacin da se velicina (broj cipele) pomnozi sa 10.5
    double c1 = p.preuzmiNarudzbu(n1);
    cout << "Ukupna cijena 1. narudzbe je " << c1 << endl;

    Narudzba n2("Barica");
    n2.dodajCipelu(Cipela(43, "Koza", "crna"));
    double c2 = p.preuzmiNarudzbu(n2);

    cout << "Ukupna cijena 2. narudzbe je " << c2 << endl;

    cout << endl;
    //Ispisuje sve narudzbe
    //Za svaku narudzbu ispisuje tko je narucitelj, te popis svih cipela koje su narucene
    p.ispisiNarudzbe();

    return 0;
}

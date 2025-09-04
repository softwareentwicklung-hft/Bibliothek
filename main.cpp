#include <iostream>
#include <vector>
using namespace std;

struct Erscheinungsdatum {
    int tag;
    int monat;
    int jahr;
};

class Medium {
public:
    string titel_;
    int seitenzahl_;

    Medium(string titel, int seitenzahl){
        titel_ = titel;
        seitenzahl_ = seitenzahl;
    }

    void anzeigen() {
        cout << "Medium: " << titel_ << ", Seiten: " << seitenzahl_ << endl;
    }
};

class Buch : public Medium {
public:
    string autor_;
    Erscheinungsdatum datum_;
    Buch(string titel, int seitenzahl, string autor, Erscheinungsdatum datum)
        : Medium(titel, seitenzahl) {
        autor_ = autor;
        datum_ = datum;
    }

    void anzeigen() {
        cout << "Buch: " << titel_ << " von " << autor_
                << " (" << datum_.tag << "." << datum_.monat << "." << datum_.jahr << ")"
                << endl;
    }
};

class Zeitschrift : public Medium {
public:
    int ausgabeNummer_;
    Zeitschrift(string titel, int seitenzahl, int ausgabeNummer) : Medium(titel, seitenzahl) {
        ausgabeNummer_ = ausgabeNummer;
    }

    void anzeigen() {
        cout << "Zeitschrift: " << titel_
                << ", Ausgabe: " << ausgabeNummer_ << endl;
    }
};

int main() {
    vector<Medium *> medien;

    Erscheinungsdatum datum2 = {10, 11, 2018};

    medien.push_back(new Buch("Programmieren in C++", 500, "A. Schneider", datum2));
    medien.push_back(new Zeitschrift("Tech Today", 60, 42));

    for (auto m: medien) {
        m->anzeigen();
    }

    return 0;
}

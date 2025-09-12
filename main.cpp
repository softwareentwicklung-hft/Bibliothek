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
    Medium(string titel, int seitenzahl){
        titel_ = titel;
        seitenzahl_ = seitenzahl;
        anzahlMedien_++;
    }
    virtual void anzeigen() {
        cout << "Medium: " << titel_ << ", Seiten: " << seitenzahl_;
    }

    int seitenzahl() {
        return seitenzahl_;
    }

    static int getAnzahlMedien() { return anzahlMedien_; }

protected:
    string titel_;

private:
    int seitenzahl_;
    static int anzahlMedien_;
};

int Medium::anzahlMedien_ = 0;

class Buch : public Medium {
public:
    Erscheinungsdatum datum_;
    Buch(string titel, int seitenzahl, string autor, Erscheinungsdatum datum)
        : Medium(titel, seitenzahl) {
        autor_ = autor;
        datum_ = datum;
    }

    void anzeigen() override {
        cout << "Buch: " << titel_ << " von " << autor_
                << " (" << datum_.tag << "." << datum_.monat << "." << datum_.jahr << ")"
                << endl;
    }

private:
    string autor_;
};

class Zeitschrift : public Medium {
public:
    Zeitschrift(string titel, int seitenzahl, int ausgabeNummer) : Medium(titel, seitenzahl) {
        ausgabeNummer_ = ausgabeNummer;
    }

    void anzeigen() override {
        Medium::anzeigen();
        cout << " Typ Zeitschrift"
                << ", Ausgabe: " << ausgabeNummer_ << endl;
    }
private:
    int ausgabeNummer_;
};

int main() {
    vector<Medium *> medien;

    Erscheinungsdatum datum2 = {10, 11, 2018};

    medien.push_back(new Buch("Programmieren in C++", 500, "A. Schneider", datum2));
    medien.push_back(new Zeitschrift("Tech Today", 60, 42));

    for (auto m: medien) {
        m->anzeigen();
    }

    cout << "\nGesamtanzahl Medien: " << Medium::getAnzahlMedien() << endl;

    for (auto m : medien) {
        delete m;
    }

    return 0;
}

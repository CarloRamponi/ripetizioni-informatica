#include <iostream>

using namespace std;

struct Studente {
    string nome;
    string cognome;
    string sesso;
    int anno;
    double italiano;
    double inglese;
    double matematica; 

    double media() {
        return (italiano + inglese + matematica) / 3;
    }

    string nomeCognome() {
        return nome + " " + cognome;
    }

    void stampa() {
        cout << nome + " " + cognome + ", " + sesso + ", " << anno << ", " << media() << endl;
    }
};

double media(Studente *s) {
    return (s->inglese + s->italiano + s->matematica) / 3;
}

int main() {

    Studente a = {
        "Mario",
        "Rossi",
        "M",
        1990,
        8.5,
        7.5,
        9.0
    };

    a.stampa();

    return 0;
}
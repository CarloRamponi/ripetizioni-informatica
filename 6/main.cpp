#include <iostream>

using namespace std;

/**
 * Dopo avere definito una struttura per la memorizzazione dei dati degli studenti di una classe (nominativo, sesso e anno di nascita)
 * e dei voti relativi alle varie discipline (Italiano, Inglese, Matematica), si scriva una funzione C++
 * string piuFacile(Studente studenti[], int n) che, a partire da un vettore di studenti e dalla dimensione di tale vettore forniti come argomenti,
 * determini la disciplina che ha la media dei voti più alta.
 */

struct Studente {
    string nome;
    string cognome;
    string sesso;
    int anno;
    double italiano;
    double inglese;
    double matematica; 
};

/**
 * @brief Trova la materia più facile in base alla media degli studenti
 * 
 * @param studenti Vettore di studenti
 * @param n Dimensione del vettore
 * @return string Il nome della materia più facile
 */
string piuFacile(Studente studenti[], int n) {
    double italiano = 0;
    double inglese = 0;
    double matematica = 0;
    for(int i = 0; i < 10; i++) {
        italiano += studenti[i].italiano;
        inglese += studenti[i].inglese;
        matematica += studenti[i].matematica;
    }
    italiano = italiano / n;
    inglese = inglese / n;
    matematica = matematica / n;

    if(italiano > inglese && italiano > matematica) {
        return "Italiano";
    } else if(inglese > italiano && inglese > matematica) {
        return "Inglese";
    } else {
        return "Matematica";
    }
}

int main() {

    Studente studenti[4] = {
        {"Mario", "Rossi", "M", 1990, 9.5, 8.5, 7.5},
        {"Giuseppe", "Verdi", "M", 1991, 9.5, 8.5, 7.5},
        {"Giovanni", "Bianchi", "M", 1992, 9.5, 8.5, 7.5},
        {"Paolo", "Neri", "M", 1993, 9.5, 8.5, 7.5}
    };

    cout << "La materia più facile è: " << piuFacile(studenti, 4) << endl;

    return 0;
}
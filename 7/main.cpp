#include <iostream>

using namespace std;

#define MAX_N 100

/**
 * Una biblioteca ha identificato tutti i libri della propria collezione mediante un codice numerico.
 * Si deve realizzare un programma C++ che consenta di effettuare le seguenti operazioni memorizzando
 * le informazioni relative a un libro (codice, titolo, autore, anno di pubblicazione, editore) in un vettore di strutture:
 * 
 * - aggiunta di un nuovo libro alla collezione;
 * - visualizzazione dell’elenco dei libri della collezione;
 * - visualizzazione delle informazioni relative a un libro a partire dal codice;
 * - visualizzazione delle informazioni relative a un libro a partire dal titolo.
 */

struct Libro {
    int codice;
    string titolo;
    string autore;
    int anno;
    string editore;
};

/**
 * @brief Crea un libro chiedendo all'utente i dati
 * 
 * @return Libro Il libro creato
 */
Libro creaLibro() {
    Libro libro;
    cout << "Inserisci il codice: ";
    cin >> libro.codice;
    cout << "Inserisci il titolo: ";
    cin >> libro.titolo;
    cout << "Inserisci l'autore: ";
    cin >> libro.autore;
    cout << "Inserisci l'anno di pubblicazione: ";
    cin >> libro.anno;
    cout << "Inserisci l'editore: ";
    cin >> libro.editore;
    return libro;
}


/**
 * @brief Stampa le informazioni di un libro
 * 
 * @param libro Il libro da stampare
 */
void stampaLibro(Libro libro) {
    cout << "Codice: " << libro.codice << endl;
    cout << "Titolo: " << libro.titolo << endl;
    cout << "Autore: " << libro.autore << endl;
    cout << "Anno di pubblicazione: " << libro.anno << endl;
    cout << "Editore: " << libro.editore << endl;
}

int main() {

    Libro libri[MAX_N];
    int n = 0;
    int scelta;

    int codice;
    string titolo;

    while(true) {
        cout << endl;
        cout << "1. Aggiungi un libro" << endl;
        cout << "2. Visualizza elenco libri" << endl;
        cout << "3. Visualizza informazioni libro a partire dal codice" << endl;
        cout << "4. Visualizza informazioni libro a partire dal titolo" << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch(scelta) {
            case 1:
                if(n < MAX_N) {
                    libri[n] = creaLibro();
                    n++;
                } else {
                    cout << "Non puoi aggiungere altri libri" << endl;
                }
                break;

            case 2:
                for(int i = 0; i < n; i++) {
                    cout << "(" << libri[i].codice << ") " << libri[i].titolo << endl;
                }
                break;

            case 3:
                
                cout << "Inserisci il codice: ";
                cin >> codice;
                for(int i = 0; i < n; i++) {
                    if(libri[i].codice == codice) {
                        stampaLibro(libri[i]);
                        break;
                    }
                }
                break;

            case 4:
                cout << "Inserisci il titolo: ";
                cin >> titolo;
                for(int i = 0; i < n; i++) {
                    if(libri[i].titolo == titolo) {
                        stampaLibro(libri[i]);
                        break;
                    }
                }
                break;

            case 0:
                cout << "Arrivederci!" << endl;
                return 0;

            default:
                cout << "Scelta non valida" << endl;
                break;
        }
    }

    return 0;
}
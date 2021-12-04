#include <iostream>

using namespace std;

/**
 * Definire la struttura dati Squadra che descrive una squadra di calcio ideale con il relativo allenatore.
 * Una squadra è identificata da nome, colore della maglia, punteggio corrente e allenatore.
 * L’allenatore è una persona caratterizzata da nome e cognome più il numero dei titoli vinti (un numero intero).
 * 
 * Scrivere un programma C++ che, dichiarata una tabella Fantacalcio di tipo Squadra (per comodità se ne fissi la dimensione a 10 elementi),
 * consenta di inserire da tastiera i dati delle squadre e dei relativi allenatori e di visualizzare il solo cognome degli allenatori di
 * squadre che hanno più di 30 punti in classifica, oltre al numero totale di allenatori che hanno vinto almeno un titolo.
 */

struct Squadra {
    string nome;
    string colore;
    int punti;
    struct {
        string nome;
        string cognome;
        int titoli;
    } allenatore;
};

/**
 * @brief Stampare il cognome degli allenatori di squadre che hanno più di 30 punti in classifica
 * 
 * @param squadre Vettore di Squadre
 * @param n Dimensione del vettore
 */
void stampaSquadreForti(Squadra squadre[], int n) {
    for(int i = 0; i < n; i++) {
        if(squadre[i].punti > 30) {
            cout << squadre[i].allenatore.cognome << endl;
        }
    }
}

/**
 * @brief Numero di allenatori che hanno vinto almeno un titolo
 * 
 * @param squadre Vettore di Squadre
 * @param n Dimensione del vettore
 * @return int Il numero di allenatori che hanno vinto almeno un titolo
 */
int allenatoriDecenti(Squadra squadre[], int n) {
    int totale = 0;
    for(int i = 0; i < n; i++) {
        if(squadre[i].allenatore.titoli > 0) {
            totale++;
        }
    }
    return totale;
}

int main() {

    Squadra fantacalcio[10];

    for(int i = 0; i < 10; i++) {
        cout << "Inserisci il nome della squadra: ";
        cin >> fantacalcio[i].nome;
        cout << "Inserisci il colore della maglia: ";
        cin >> fantacalcio[i].colore;
        cout << "Inserisci il punteggio corrente: ";
        cin >> fantacalcio[i].punti;
        cout << "Inserisci il nome dell'allenatore: ";
        cin >> fantacalcio[i].allenatore.nome;
        cout << "Inserisci il cognome dell'allenatore: ";
        cin >> fantacalcio[i].allenatore.cognome;
        cout << "Inserisci il numero di titoli vinti da " << fantacalcio[i].allenatore.nome << " " << fantacalcio[i].allenatore.cognome << ": ";
        cin >> fantacalcio[i].allenatore.titoli;
    }

    cout << "Squadre che hanno almeno 30 punti in classifica: " << endl;
    stampaSquadreForti(fantacalcio, 10);

    cout << "Numero di allenatori che hanno vinto almeno un titolo: " << allenatoriDecenti(fantacalcio, 10) << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

/**
 * Definire la struttura dati Auto che descrive un’automobile in base a marca, cilindrata, anno di immatricolazione
 * e acquirente (l’acquirente è carat-terizzato dai soli nome e cognome). Scrivere unprogramma C++ che, dichiarata
 * la tabella Autosalone di tipo Auto (per comodità se ne fissi ladimensione a 10 elementi), consenta di inserireda
 * tastiera i dati delle auto vendute e di visualizzare  il  solo  cognome  degli  acquirenti  di  auto di cilindrata
 * superiore a 1500 cc, oltre al numero totale di auto che sono state immatricolate in un anno richiesto all’utente.
 */

struct Auto {
    string marca;
    int cilindrata;
    int anno;
    struct {
        string nome;
        string cognome;
    } acquirente;
};


/**
 * @brief Stampa il cognome degli acquirenti di auto di cilindrata superiore a 1500 cc
 * 
 * @param autosalone Il vettore di Auto
 * @param n La dimensione del vettore
 */
void stampaAutoPotente(Auto autosalone[], int n) {
    for (int i = 0; i < n; i++) {
        if (autosalone[i].cilindrata > 1500) {
            cout << autosalone[i].acquirente.cognome << endl;
        }
    }
}

/**
 * @brief Numero di auto immatricolare nell anno "anno"
 * 
 * @param autosalone Vettore di Auto
 * @param n Dimensione del vettore
 * @param anno Anno di immatricolazione da ricercare
 * @return int Numero di auto immatricolate nell anno "anno"
 */
int autoPerAnno(Auto autosalone[], int n, int anno) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (autosalone[i].anno == anno) {
            cont++;
        }
    }
    return cont;
}

int main() {

    //Allocazione statica perchè sono richieste esattamente 10 auto
    Auto autosalone[10];

    for(int i = 0; i < 10; i++) {
        cout << "Inserire marca: ";
        cin >> autosalone[i].marca;
        cout << "Inserire cilindrata: ";
        cin >> autosalone[i].cilindrata;
        cout << "Inserire anno di immatricolazione: ";
        cin >> autosalone[i].anno;
        cout << "Inserire nome acquirente: ";
        cin >> autosalone[i].acquirente.nome;
        cout << "Inserire cognome acquirente: ";
        cin >> autosalone[i].acquirente.cognome;
    }

    cout << "Cognomi degli acquirenti di auto di cilindrata superiore a 1500 cc: " << endl;
    stampaAutoPotente(autosalone, 10);

    int anno;
    cout << "Inserisci anno di immatricolazione da ricercare: ";
    cin >> anno;

    cout << "Numero di auto immatricolare nell anno " << anno << ": " << autoPerAnno(autosalone, 10, anno) << endl;

    return 0;
}
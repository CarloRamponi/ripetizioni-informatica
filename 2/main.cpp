#include <iostream>

using namespace std;

/* 
 * NOTA: da questo esercizio in poi utilizzerò solo alloczione dinamica,
 * per l'allocazione statica vedere l'esercizio ../1/static.cpp
 */

/*
 * Scrivere una funzione C/C++ che restituisca true,se un valore numerico intero positivo fornito come argomento è presente
 * almeno una volta tragli elementi di un vettore fornito anch’esso come argomento, false altrimenti.
 * Scrivere un programma C++ che, utilizzando la funzione precedente e costruendo il vettore a partire da valori forniti da tastiera,
 * visualizzi, in risposta a singoli valori successivamente richiesti all’utente, «Vero» in caso di presenza nel vettore o «Falso»
 * altrimenti (la richiesta terminerà in corrispondenza dell’inserimento del valore 0)."
 */

/**
 * @brief Verifica se un valore è presente in un vettore
 * 
 * @param v Il vettore di interi
 * @param n La dimensione del vettore
 * @param x Il valore da verificare
 * @return true Se x è presente in v
 * @return false Se x non è presente in v
 */
bool isIn(int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {

    int *v;
    int n;
    int x;

    cout << "Inserisci la dimensione del vettore: ";
    cin >> n;

    if(n <= 0) {
        cout << "Dimensione non valida" << endl;
        return -1;
    }

    // Alloco memoria per il vettore
    v = new int[n];

    // Verifico che il vettore sia allocato
    if(v == NULL) {
        cout << "Errore nell'allocazione della memoria" << endl;
        return -1;
    }

    // Inserisco i valori nel vettore
    for(int i = 0; i < n; i++) {
        cout << "Inserisci il valore " << i + 1 << ": ";
        cin >> v[i];
    }

    // Ciclo infinito (a meno di un break o return al suo interno)
    while(true) {
        cout << "Inserisci il valore da verificare [0 per uscire]: ";
        cin >> x;

        if(x == 0) {
            cout << "Ciao ciao!" << endl;
            break;
        }

        if(isIn(v, n, x)) {
            cout << "Vero" << endl;
        } else {
            cout << "Falso" << endl;
        }

    }

    // Dealloco la memoria
    delete[] v;

    return 0;
}
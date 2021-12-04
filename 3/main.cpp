#include <iostream>

using namespace std;

/*
 * Dato un vettore di valori numerici, scrivere una funzione C++ che conti quanti elementi del vettore
 * sono compresi tra un valore minimo e un valore massimo forniti come argomenti alla funzione stessa
 * insieme alla dimensione del vettore. Scrivere un programma C++ che, utilizzando la funzione precedente
 * e costruendo il vettore a partire da valori acquisiti da tastiera, visualizzi il risultato del conteggio
 * dopo avere richiesto all’utente i valori minimo e massimo
 */

/**
 * @brief Alloca dinamicamente un vettore di interi e chiede all'utente di inserire i valori
 * 
 * @param n la dimensione del vettore
 * @return int* il puntatore al vettore
 */
int *array(int n) {
    int *v = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Inserisci il valore " << i + 1 << ": ";
        cin >> v[i];
    }
    return v;
}

/**
 * @brief Chiede all'utente la dimensione del vettore
 * 
 * @return int La dimensione del vettore
 */
int get_dim() {
    int n;

    cout << "Inserisci la dimensione del vettore: ";
    cin >> n;

    if(n <= 0) {
        cout << "Dimensione non valida" << endl;
        exit(-1);
    }
    return n;
}

/**
 * @brief Conta quanti valori di un vettore sono compresi in un intervallo dato
 * 
 * @param v Il vettore di interi
 * @param n La dimensione del vettore
 * @param a Il limite inferiore dell'intervallo
 * @param b Il limite superiore dell'intervallo
 * @return int Il numero di elementi in v compresi nell'intervallo [a,b]
 */
int how_many(int v[], int n, int a, int b) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] >= a && v[i] <= b) {
            count++;
        }
    }
    return count;
}

int main() {

    int n = get_dim();
    int *v = array(n);

    int a, b;
    cout << "Inserisci il limite inferiore dell'intervallo: ";
    cin >> a;
    cout << "Inserisci il limite superiore dell'intervallo: ";
    cin >> b;

    int x = how_many(v, n, a, b);
    cout << "Il numero di elementi compresi nell'intervallo [" << a << "," << b << "] è: " << x << endl;

    // Dealloca il vettore
    delete[] v;

    return 0;
}
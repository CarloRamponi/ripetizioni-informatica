#include <iostream>

#define MAXN 100

using namespace std;

/*
 * Scrivere un programma C++ che acquisisca da tastiera un vettore di interi di dimensione N e calcoli minimo, massimo e media degli elementi.
 */

int main() {

    int n;
    int v[MAXN];
    int max, min;
    double avg;

    cout << "Enter the number of elements: ";
    cin >> n;

    //Qui se N non è valido fermiamo il programma per semplicità
    if(n <= 0 || n > MAXN) {
        cout << "Invalid number of elements" << endl;
        return -1;
    }

    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> v[i];
    }

    //Inizializzo min e max al primo elemento
    max = min = v[0];

    //AVG verrà utilizzata come accumulatore e verrà poi diviso per n
    //0.0 e non 0 perchè il risultato sarà un double
    avg = 0.0;

    //Ciclo per calcolare max, min e avg
    for(int i = 0; i < n; i++) {
        if(v[i] > max)
            max = v[i];
        if(v[i] < min)
            min = v[i];
        avg += v[i];
    }
    avg /= n;

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Avg: " << avg << endl;

    return 0;
}
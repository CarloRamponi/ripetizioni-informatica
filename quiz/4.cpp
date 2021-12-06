#include <iostream>

using namespace std;

int main() {

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *p = v + 6;

    p[-4] = 100;

    //stampa l'array
    for (int i = 0; i < 10; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
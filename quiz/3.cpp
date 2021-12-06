#include <iostream>

using namespace std;

int main() {

    //questo è un po' complicato.
    //ricordatevi che sizeof(int) = 4 e sizeof(char) = 1

    int v[] = {1, 2, 3, 4, 5};
    int *p = v;
    char *q = (char *)p;
    q[4] = 10;

    //stampa l'array
    for (int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }


    return 0;
}
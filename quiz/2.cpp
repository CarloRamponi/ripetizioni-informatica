#include <iostream>

using namespace std;

int main() {

    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* p = &v[9];

    *(p+5) = 200;

    for(int i = 0; i < 10; i++) {
        cout << v[i] << endl;
    }

    cout << *p << endl;

    return 0;
}
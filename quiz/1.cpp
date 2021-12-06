#include <iostream>

using namespace std;

int main() {

    int a = 4;
    int b = 5;
    int *p = &a;
    int **q = &p;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    *q = &b;
    *(*q) = 10;
    *p = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
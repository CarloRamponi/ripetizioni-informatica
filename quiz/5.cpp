#include <iostream>

using namespace std;

int main() {

    int a = 1, b = 2, c = 3;

    int *p = &a;
    int *q = &b;
    int *r = &c;

    int **pp = &p;
    int **qq = &q;
    int **rr = &r;

    **rr = 100;
    *pp = q;
    **pp = 200;
    *rr = &a;
    **rr = 300;
    *qq = &c;
    **qq = 400;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}
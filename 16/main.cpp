#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x,y;

    void show() {
        cout << "[" << x << ", " << y << "]\n";
    }

    double dist(struct Point p) {
        return sqrt(pow(p.y-y, 2) + pow(p.x-x, 2));
    }

    bool equal(struct Point p) {
        return p.x == x && p.y == y;
    }
};

int main() {

    int n;

    cout << "Quanti punti ci sono?" << endl;
    cin >> n;

    struct Point *p = new struct Point[n];

    for(int i = 0; i < n; i++) {
        cout << "Inserisci la x: ";
        cin >> p[i].x;
        cout << "Inserisci la y: ";
        cin >> p[i].y;
    }

    for(int i = 0; i < n; i++) {
        cout << i << ": ";
        p[i].show();
    }

    //Avete un array di punti
    //Dovete trovare e stampare la coppia di punti con distanza massima

    return 0;
}
#include <iostream>
#include <cmath>
#include <fstream>

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

struct Rect {
    struct Point a;
    struct Point b;

    double width() {
        return abs(a.x - b.x);
    }

    double height() {
        return abs(a.y - b.y);
    }

    double area() {
        return width() * height();
    }

    bool contains(struct Point p) {
        return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) && p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
    }

    bool containsRect(struct Rect r) {
        return contains(r.a) && contains(r.b);
    }
};

int main() {

    int N;

    ifstream input("input.txt");

    input >> N;

    Rect *rects = new Rect[N];
    for(int i = 0; i < N; i++) {
        input >> rects[i].a.x >> rects[i].a.y >> rects[i].b.x >> rects[i].b.y;
    }

    input.close();

    ofstream output("output.txt");

    output << N << endl;
    for(int i = 0; i < N; i++) {
        output << rects[i].area() << endl;
    }

    output.close();

    return 0;
}
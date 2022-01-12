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

void POINTshow(struct Point p) {
    cout << "[" << p.x << ", " << p.y << "]\n";
}

int main() {
    struct Point p1 = { 3.5, -2.0 };
    struct Point p2 = { 0, 5 };

    cout << "P1: "; 
    p1.show();

    cout << "P2: ";
    p2.show();

    cout << "Distance between p1 and p2: " << p1.dist(p2) << endl;

    struct Rect r;
    r.a = p1;
    r.b = p2;

    cout << "Area of r: " << r.area() << endl;

    struct Point p3 = { 2.5, 0 };
    struct Point p4 = { 4.5, 0 };

    if(r.contains(p3)) {
        cout << "r contains p3" << endl;
    } else {
        cout << "r does not contain p3" << endl;
    }

    if(r.contains(p4)) {
        cout << "r contains p4" << endl;
    } else {
        cout << "r does not contain p4" << endl;
    }

    struct Rect r1 = {
        {2.5, 0},
        {3, 4}
    };

    struct Rect r2 = {
        {10, 10},
        {20, 20}
    };

    if(r.containsRect(r1)) {
        cout << "r contains r1" << endl;
    } else {
        cout << "r does not contain r1" << endl;
    }

    if(r.containsRect(r2)) {
        cout << "r contains r2" << endl;
    } else {
        cout << "r does not contain r2" << endl;
    }

    return 0;
}
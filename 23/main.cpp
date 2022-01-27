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

struct Line {
    double m, q;

    double y(double x) {
        return m * x + q;
    }

    bool contains(Point p) {
        return p.y == y(p.x);
    }

    void show() {
        cout << "y = " << m << "x + " << q << endl;
    }
};

Line passing(Point p1, Point p2) {
        Line l;
        l.m = (p2.y - p1.y) / (p2.x - p1.x);
        l.q = p1.y - l.m * p1.x;
        return l;
    }

int main() {

    Point p1 = {0, 0};
    Point p2 = {1, 1};

    Line l = passing(p1, p2);

    l.show();

    Point p3 = {0, 1};
    Point p4 = {3, 3};

    p3.show();
    if(l.contains(p3)) {
        cout << "is on the line" << endl;
    } else {
        cout << "is not on the line" << endl;
    }

    p4.show();
    if(l.contains(p4)) {
        cout << "is on the line" << endl;
    } else {
        cout << "is not on the line" << endl;
    }

    return 0;
}
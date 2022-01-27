#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct Point
{
    double x, y;

    void show()
    {
        cout << "[" << x << ", " << y << "]\n";
    }

    double dist(struct Point p)
    {
        return sqrt(pow(p.y - y, 2) + pow(p.x - x, 2));
    }

    bool equal(struct Point p)
    {
        return p.x == x && p.y == y;
    }
};

struct Line
{
    double m, q;

    double y(double x) const {
        return m * x + q;
    }

    bool contains(Point p) const {
        return p.y == y(p.x);
    }

    void show() const {
        cout << "y = " << m << "x + " << q << endl;
    }

    bool parallel(const Line &other) const {
        return m == other.m;
    }

    bool perpendicular(const Line &other) const {
        return m != 0 && other.m == -1/m;
    }

    Point intersection(const Line &other) const {
        if(parallel(other)) {
            return {};
        } else {
            return {
                (other.q - q)/(m - other.m),
                m * (other.q - q)/(m - other.m) + q
            };
        }
    }

    Line perpendicular(const Point &p) const {
        if(m != 0) {
            return {
                -1/m,
                p.y + p.x/m
            };
        } else {
            return {};
        }
    }

    double distance(const Line &other) const {
        if(!parallel(other)) {
            return 0.0;
        } else {
            Point p1 = {0.0, y(0.0)};
            p1.show();
            Line perp = perpendicular(p1);
            perp.show();
            Point p2 = other.intersection(perp);
            p2.show();
            return p1.dist(p2);
        }
    }
};

int main() {
    Line line1 = {1, 0};
    Line line2 = {1, 1};

    cout << "Line1: ";
    line1.show();
    cout << "Line2: ";
    line2.show();

    cout << "Distance between line1 and line2: " << line1.distance(line2) << endl;
}
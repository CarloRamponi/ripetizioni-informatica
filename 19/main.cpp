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

int main() {

    int N;

    ifstream input("input.txt");

    input >> N;

    Point *points = new Point[N];

    for (int i = 0; i < N; i++) {
        input >> points[i].x >> points[i].y;
    }

    input.close();

    double distance = 0;

    for(int i = 0; i < N; i++) {
        distance += points[i].dist(points[(i+1)%N]);
    }

    cout << "Total length: " << distance << endl;

    return 0;
}
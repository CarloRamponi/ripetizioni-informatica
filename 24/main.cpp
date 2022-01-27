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

    double y(double x)
    {
        return m * x + q;
    }

    bool contains(Point p)
    {
        return p.y == y(p.x);
    }

    void show()
    {
        cout << "y = " << m << "x + " << q << endl;
    }
};

Line passing(Point p1, Point p2)
{
    Line l;
    l.m = (p2.y - p1.y) / (p2.x - p1.x);
    l.q = p1.y - l.m * p1.x;
    return l;
}

int main()
{

    int N;

    ifstream input("input.txt");

    input >> N;

    Point *points = new Point[N];

    for (int i = 0; i < N; i++)
    {
        input >> points[i].x >> points[i].y;
    }

    input.close();

    Line l = passing(points[0], points[1]);

    for (int i = 2; i < N; i++)
    {
        if (!l.contains(points[i]))
        {
            cout << "Not all the points are on the same line!" << endl;
            return 0;
        }
    }

    cout << "All the given points are on the same line!" << endl;

    return 0;
}
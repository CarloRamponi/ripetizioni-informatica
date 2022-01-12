#include <iostream>
#include <cmath>

using namespace std;

struct Complex {
    double real;
    double imag;

    struct Complex sum(struct Complex b) {
        struct Complex res;
        res.real = real + b.real;
        res.imag = imag + b.imag;
        return res;
    }

    struct Complex mul(struct Complex b) {
        struct Complex res;

        //z1 = a1 + b1 i
        //(a1 a2 - b1 b2) + (a1 b2 + a2 b1)i

        res.real = b.real*real - imag*b.imag;
        res.imag = b.imag*real + imag*b.real;

        return res;
    }

    double mod() {
        // radice(a^2 + b^2)
        return sqrt(pow(real, 2) + pow(imag, 2));
    }

    void print() {
        std::cout << real << (imag > 0 ? " + ": " - ") << abs(imag) << "i [" << mod() << "]" << std::endl;
    }
};

struct Complex complexSum(struct Complex a, struct Complex b) {
    struct Complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

int main() {

    struct Complex a;
    struct Complex b;

    a.real = 1;
    a.imag = 2;

    b.real = 3;
    b.imag = 4;

    struct Complex c = complexSum(a, b);

    struct Complex d = a.sum(b);

    struct Complex e = a.mul(b);

    cout << "a: ";
    a.print();

    cout << "b: ";
    b.print();

    cout << "c: ";
    c.print();

    cout << "d: ";
    d.print();

    cout << "e: ";
    e.print();

    return 0;
}
#include <iostream>

using namespace std;

struct Person {
    string name;
    int age;
    string address;
};

int main() {

    Person a;
    Person *pa = &a;
    Person **pp = &pa;

    a.name = "Marco";
    cout << pa->name << endl;
    cout << (*pp)->name << endl;

    return 0;
}
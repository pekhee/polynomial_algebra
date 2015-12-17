#include <iostream>
#include "polynomial.h"
#include "split.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    std::string first;
    std::string second;

    cout << "Usage: Enter two polynomials one on each line." << endl;

    cout << "1> ";
    std::getline(cin, first);
    Polynomial a(split(first, ' '));

    cout << "2> ";
    std::getline(cin, second);
    Polynomial b(split(second, ' '));

    cout << "+> " << a.add(b).toString() << endl;
    cout << "-> " << a.subtract(b).toString() << endl;
    cout << "*> " << a.multiply(b).toString() << endl;
}

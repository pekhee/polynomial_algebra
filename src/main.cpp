#include <iostream>
#include "polynomial.h"
#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;

Polynomial getPoly() {
    std::string buffer;
    std::vector<int> tokens;

    getline(cin, buffer);
    tokens = split(buffer, ' ');
    Polynomial poly(tokens);

    return poly;
}

int main() {
    std::string second;

    cout << "Usage: Enter two polynomials one on each line." << endl;

    cout << "1> ";
    Polynomial a = getPoly();

    cout << "2> ";
    Polynomial b = getPoly();

    cout << "+> " << a.add(b).toString() << endl;
    cout << "-> " << a.subtract(b).toString() << endl;
    cout << "*> " << a.multiply(b).toString() << endl;

    return 0;
}

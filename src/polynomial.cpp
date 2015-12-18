#include "polynomial.h"
#include <iostream>

Polynomial::Polynomial(std::vector<int> _coefficients) {
    coefficients = _coefficients;
}

std::string Polynomial::toString() {
    std::stringstream ss;

    for(std::vector<int>::iterator it = coefficients.begin(); it != coefficients.end(); ++it) {
        ss << *it << " ";
    }

    return ss.str();
}

std::vector<int> zip_and_map(std::vector<int> fv, std::vector<int> sv, int (*mapper)(int, int)) {
    std::size_t biggest_size = fv.size() > sv.size() ? fv.size() : sv.size();
    std::vector<int> results;

    for(std::size_t i = 0; i < biggest_size; i++) {
        int fit, sit;
        if(i + 1 > fv.size()) {
            fit = 0;
        } else {
            fit = fv[i];
        }

        if(i + 1 > sv.size()) {
            sit = 0;
        } else {
            sit = sv[i];
        }

        results.push_back(mapper(fit, sit));
    }

    return results;
}

int Polynomial::add(int a, int b) {
    return a + b;
}

Polynomial Polynomial::add(Polynomial other) {
    return zip_and_map(coefficients, other.coefficients, add);
}

int Polynomial::subtract(int a, int b) {
    return a - b;
}

Polynomial Polynomial::subtract(Polynomial other) {
    return zip_and_map(coefficients, other.coefficients, subtract);
}

int Polynomial::multiply(int a, int b) {
    return a * b;
}

Polynomial Polynomial::multiply(Polynomial other) {
    return zip_and_map(coefficients, other.coefficients, multiply);
}

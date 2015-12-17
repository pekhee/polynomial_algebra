#include "polynomial.h"

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
    int fflag = 0;
    int sflag = 0;
    std::vector<int> results;

    std::vector<int>::iterator fvit = fv.begin();
    std::vector<int>::iterator svit = sv.begin();
    while(fvit != fv.end() && svit != sv.end()) {
        int fit = fflag ? 0 : *fvit;
        int sit = sflag ? 0 : *svit;

        results.push_back(mapper(fit, sit));

        if(fvit == fv.end()) {
            fflag = 1;
        } else {
            ++fvit;
        }

        if(svit == sv.end()) {
            sflag = 1;
        } else {
            ++svit;
        }
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

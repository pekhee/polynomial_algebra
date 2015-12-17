#include <vector>
#include <string>
#include <sstream>

class Polynomial {
    std::vector<int> coefficients;
public:
    Polynomial(std::vector<int>);
    Polynomial add(Polynomial);
    Polynomial subtract(Polynomial);
    Polynomial multiply(Polynomial);
    std::string toString();
private:
    static int add(int, int);
    static int subtract(int, int);
    static int multiply(int, int);
};

#include <string>
#include "split.h"

std::vector<int> &split(std::string &s, char delim, std::vector<int> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        if(!item.empty()) {
            elems.push_back(std::stoi(item));
        }
    }
    return elems;
}


std::vector<int> split(std::string &s, char delim) {
    std::vector<int> elems;
    split(s, delim, elems);
    return elems;
}

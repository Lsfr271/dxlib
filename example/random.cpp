#include "include/dx.h"

using namespace dxlib;
using namespace dxlib::dxlibRandom;
using namespace dxlib::dxlibPrint;

int main() {
    // RandomNumRange:
    // Accepts 3 arguments that are: int min, int max, std::string type
    // the min is the lowest number that the random number will start from
    // the max is the highest number that the random number will end from
    // the type is the data types. (only int, double, and float is supported)
    // example:

    int gen1 = RandomNumRange(0, 5, "int");
    varp("Random number: -gen1-", gen1);
    // this would print a random number. this goes the same for float and double

    // PrintRandomNum:
    // this one is very simmilar to RandomNumRange. It is the same thing but it just prints the type and the random number.
    // example:
    PrintRandomNum(0, 5, "int");

    // would print a random whole number
}

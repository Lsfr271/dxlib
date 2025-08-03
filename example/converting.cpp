#include "include/dx.h"

using namespace dxlib;
using namespace dxlib::dxlibConvert;
using namespace dxlib::dxlibPrint;

int main() {
    // Example, Converting a float to an int would be:
    float a = 3.14;
    int converted = dxlib::dxlibConvert::ConvertFloatToInt(a); // you need store it in a variable

    varp("New number: -converted-", converted);
    // would print: New number: 3

    // this goes the same for the other functions declared in dxlibConvert.
}

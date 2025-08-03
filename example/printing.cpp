#include "../include/dx.h"

using namespace dxlib;
using namespace dxlib::dxlibPrint;

int main() {
    // dxp:
    // print anything in the terminal
    // arguments:
    // string text, bool endl = false

    // example of dxp:
    dxp("Hello, World!", true); // true if you want a newline (not needed to specify)
    // or false if you dont want a new line (needed to specify)

    // varp:
    // its like printf(), but instead of {} you do --
    // arguments:
    // text, unordered_map, nl = true // nl = newline
    // the newline bool is the same as dxp's endl = true bool
    // example:
    int age = 20;
    varp("Dude is -age- years old!", age);

    // would print:
    // Dude is  20 years old!

    // dxi:
    // its std::cout & std::cin mashed up together.
    // how it works:
    std::string name = dxi<std::string>("What is your name?: ");
    varp("Gotten name: -name-", name);
    // note : dxi cannot be by itself, you have to assign it to a variable
    // its like pythons 'name = input()' std::cin but with <>. And another note
    // you have to specify which type in the < >, without that it might bug out.
}

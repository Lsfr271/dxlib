# This MD file is to explain all available functions.

## DXLIBMAIN:
- CinFail(): Checks if a cin failed. For an example a user might have entered a wrong datatype when asked for an int. Here is an example:
```cpp
#include "../include/dxlib.hpp"

using namespace dxlib::dxlibMain;

int main() {
   int age; // declare a integer variable called 'age' to take in input.

   std::cout << "What is your age?: " << '\n';
   std::cin >> age; // take in input from the age variable.

   // lets check if something went wrong, we will do this:
   if (CinFail()){
       std::cout << "Something went wrong!" << std::endl; // this can happen if the user entered a wrong datatype like letters instead of integers.
       return 1; // to end the process
  }

  // if it didnt trigger:
  std::cout << "Your age is " << age << "!" << '\n'; // print the age this means its successful.
}
```

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

- ClearBuffer(): Usually clears a newline left over from a std::endl or a std::cin >>, here is an example:
```cpp
#include "../include/dxlib.hpp"

using namespace dxlib::dxlibMain;

int main() {
    std::string name;
    std::string dad;

    std::cout << "Enter your name: " << std::endl;
    std::cin >> name; // this is the problem right here, it leavs a newline
    // so it will skip the "Enter your dad's name" process and leave it with a newline
    // so to fix it you must call the ClearBuffer() function to destroy that newline.

    ClearBuffer(); // now it should work.

    std::cout << "Enter your dad's name: " << std::endl;
    std::getline(std::cin, dad);

    std::cout << "Hello, " << name << " your dad is: " << dad << std::endl;
}
```

- Pause(): Pauses the program, think of it as like time. Without calling it time moves on, but when you call it time freezes until you unpause it. Heres an example:
```cpp
#include "../include/dxlib.hpp"

using namespace dxlib::dxlibMain;

int main() {
    std::cout << "Hello.." << '\n';
    Pause(); // call the Pause() function to pause the program, usually for debugging.
    std::cout << "World!" << '\n';
}
```

-

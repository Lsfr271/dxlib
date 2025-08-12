# Welcome to dxlib!
## v1.2 [Download dxlibPackage.zip](https://github.com/Lsfr271/dxlib/raw/main/dxlibPackage.zip)

**dxlib** is a lightweight, easy-to-use C++ header-only library that provides a collection of utilities and tools for:

- Mathematical calculations (geometry, trigonometry, volumes)
- File operations (reading, writing, copying, deleting)
- String and text manipulation (trimming, case changes, etc..)
- Time and date utilities
- Random number generation and string creation
- Console input/output helpers

---

### Why use dxlib?

- Organized: Clean namespaces for different functionalities
- Cross-platform support with Windows and Linux compatibility
- Simple API designed to speed up your terminal-only projects!

---

### Who is it for?

- dxlib is for beginners who want to get comfortable with C++
without writing verbose boilerplate. It wraps many features into a simple, beginner-friendly interface.
Then they can move on to learn `std::cin`, or `std::cout` or other functions. So basically its
training wheels and then move on to learn the actual stuff.

---

### Why did i create it?

- I built dxlib as a personal challenge to improve my C++.
It turned into a utility library that makes many common tasks much simpler.

---

### How to learn more about dxlib if you are stuck

- Please go to [dxHelp.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxHelp.h) in this github repository
you will find every function there explained.

---

### About me

- I have been learning C++ for about 2 months now
- My favourite programming language is C++ and second is Python

---

### How to use?
## Example snippet:

```cpp
#include "../include/dx.h"

using namespace dxlib;
using namespace dxlibPrint;

int main() {
    // print hello world
    printline("Hello, World!");

    // print variables in a print statement
    int age = 20;
    varPrint("Age is -age-", age);

    // get user input and print it
    // note: printline<>() directly asks for input and returns the value,
    // so the next time you print the value, you get a different result depending on what
    // the user entered on the input
    std::string name = askInput<std::string>("What is your name?: ");
    varPrint("Hello, -name-!", name);
}
```

---

### How to initialize fully?

Just include the header in your project:

```cpp
#include "../include/dx.h" // Adjust the path based on your project structure or compiler-type (it might be different)

using namespace dxlib;  
using namespace dxlibConvert;
// other namespaces nested in dxlib

int main() {
    // your code here.
}
```

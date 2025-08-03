# Welcome to dxlib!

**dxlib** is a lightweight, easy-to-use C++ header-only library that provides a collection of utilities and tools for:

- Mathematical calculations (geometry, trigonometry, volumes)
- File operations (reading, writing, copying, deleting)
- String and text manipulation (trimming, splitting, case changes)
- Time and date utilities
- Random number generation and string creation
- Console input/output helpers

---

### Why use dxlib?

- Header-only: Just include `dx.h` and you’re ready to go!
- Organized: Clean namespaces for different functionalities
- Cross-platform support with Windows and Linux compatibility
- Simple API designed to speed up your coding workflow

---

### Who is it for?

- dxlib is for beginners who want to get comfortable with C++
without writing verbose boilerplate. It wraps many features into a simple, beginner-friendly interface.

---

### Why did i create it?

- I built dxlib as a personal challenge to improve my C++.
It turned into a utility library that makes many common tasks much simpler.

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
using namespace dxlib::dxPrint;

int main() {
    // print hello world
    dxp("Hello, World!");

    // print variables in a print statement
    int age = 20;
    varp("Age is -age-", age);

    // get user input and print it
    std::string name = dxi<std::string>("What is your name?: ");
    varp("Hello, -name-!", name);
}
```

---

### How to initialize fully?

Just include the header in your project:

```cpp
#include "../include/dx.h" // if you have dx.h in the include folder, else do #include "dx.h"
// or you might do this in other cases:
// #include "include/dx.h"
// the includes above depends on your compiler, so dont complain if you get include path errors

using namespace dxlib;  
using namespace dxlibConvert;
using namespace dxlibFileUtils;
using namespace dxlibFileOperations;
using namespace dxlibGen;
using namespace dxlibMain;
using namespace dxlibMath;
using namespace dxlibMathAdditions;
using namespace dxlibPower;
using namespace dxlibPrint;
using namespace dxlibRandom;
using namespace dxlibTime;
using namespace dxlibText;
using namespace dxlibShapesCalc;

int main() {
    // your code here.
}
```

### If you have questions please DM me: ._2afKeeper (discord)

# Welcome to dxlib!
## v1.0.1

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

---

### Why did i create it?

- I built dxlib as a personal challenge to improve my C++.
It turned into a utility library that makes many common tasks much simpler.

---

### How to learn more about dxlib if you are stuck

- Please go to ``include/dxHelp.h`` in this github repository
you will find every function there explained.

---

### About me

- I have been learning C++ for about 2 months now
- My favourite programming language is C++ and second is Python

---

### More explanation into the features:

- `dxlibMain` – Input stream handling
- `dxlibConvert` – Type conversions (e.g., double to int)
- `dxlibFileUtils` – File I/O helpers (check if exists, read, write, etc.)
- `dxlibMath` – Math + shape calculations
- `dxlibGen` – Random numbers and strings
- `dxlibTime` – Time handling and delays
- `dxlibPrint` – Easy variable printing
- `dxlibText` – String utilities (trim, split, join, case, etc.)
- `dxlibDebug` - Debug Utilities (log, assertLog, etc..)

---

### How to use?
## Example snippet:

```cpp
#include "../include/dx.h"

using namespace dxlib;
using namespace dxlibPrint;

int main() {
    // print hello world
    dxp("Hello, World!");

    // print variables in a print statement
    int age = 20;
    varp("Age is -age-", age);

    // get user input and print it
    // note: dxi<>() directly asks for input and returns the value,
    // so the next time you print the value, you get a different result depending on what
    // the user entered on the input
    std::string name = dxi<std::string>("What is your name?: ");
    varp("Hello, -name-!", name);
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

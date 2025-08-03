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

- Dxlib is for beginners who want to get used to C++ but
- without the verbose code. And dxlib wraps all of that to
- be very simple.

---

### Why did i create it?

- i am an amateur programmer myself
- i created it as a project to test my self
- and guess what, i created an API that makes
- everything (not everything but you get what i mean) simpler!

---

### About me

- I have been learning C++ for about 2 months now
- My favourite programming language is C++ and second is Python

---

### How to use?

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

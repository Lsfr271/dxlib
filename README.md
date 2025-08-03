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

### How to use?

Just include the header in your project:

```cpp
#include "../include/dx.h" // if you have dx.h in the include folder, else do #include "dx.h" (important to put .. before / in the beginning)

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

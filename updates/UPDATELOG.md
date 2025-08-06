### Updates

- **Added helper file:** `dxHelp.h`  
  This file explains all functions in the library for users who get stuck.  
  Location: `include/dxHelp.h`

- **2025/08/01**

---

- **Introduced new namespace:** `dxlibDebug`  
  This namespace provides easy-to-use debugging utilities that wrap verbose C++ debug code into simpler functions.  
  For details, see `dxHelp.h`.

- **2025/08/04**

---

- **Created example file:** `dxlibusage.cpp`  
  Located in `examples/dxlibusage.cpp`, this file demonstrates how to use dxlib and covers multiple namespaces.  
  File: `examples/dxlibusage.cpp`

- **2025/08/04**

---

### Minor Bug Fix

- **Fixed division-by-zero issue:**  
  In `dxlibMathAdditions::OperatorNums`, division by zero was not handled in the `"/"` operation.  
  A check was added to prevent this.

- **2025/08/04**

---

## **New Addition**
- Added a new type in **ChangeCase** in *dxlibText*
  This allows you to uppercase/lowercase a string randomly
- Example:

```cpp
#include "../include/dx.h"

using namespace dxlib;
using namespace dxlibText;
using namespace dxlibPrint;

int main() {
    std::string word = "Hello!";
    ChangeCase(word, "randomized");

    varp("New word: -word-", word);
}

// Output: hElLo // or something different because its randomized
```

- **2025/08/05**

---

## **Name fixes**
- In `dxlibMain::dxClearBuf` the dxClearBuf is not understandable to especially
  Beginners, so it was changed to `ClearBuffer`

- Originally, main dxlib .h file was named `dx.h`, now its named `dxlib.h` for clarity

- Printing Lines would usually need you to call `dxp` or `varp`, but now it has been changed
  dxp is now `printline` and varp is now `varPrint`, this change has been done to make it
  easier for beginners to understand

- Asking for input was usually needed for you to call `dxi` function. It has been renamed to
  `askInput` to make it more clearer for beginners.

- **2025/08/05**

---

## **Minor bug fix**
- In `dxlibRandom::PrintRandomNum` usually printed "Int: " and with the random number chosen. Now that is gone and only prints
  The random number only
  
- **2025/08/06**

---

## **File structure changes**

- Before, there was a `src/` folder in `include/`, now its in its seperate directory `examples/`
  In the `examples/` directory you can find dxlibusage.cpp, it demonstrates how to use some dxlib namespaces.

- **2025/08/06**

---

### More updates coming soon!

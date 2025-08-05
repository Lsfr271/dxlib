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

- **Created example file:** `dxlibExample.cpp`  
  Located in `include/src/`, this file demonstrates how to use dxlib and covers multiple namespaces.  
  File: `include/src/dxlibExample.cpp`

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
    ChangeCase(word, "middle");

    varp("New word: -word-", word);
}

// Output: hElLo // or something different because its randomized
```

- **2025/08/05**

---

### More updates coming soon!

### Updates

- **Added helper file:** `dxHelp.h`
  This file explains all functions in the library for users who get stuck.  
  Location: `include/dxHelp.h`

- **2025/08/01**

---

- **Introduced new namespace:** `dxlibDebug ` 
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
- Added a new type in **ChangeCase** in `dxlibText`
  This allows you to `uppercase/lowercase` a string randomly
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
- In `dxlibMain::dxClearBuf` the `dxClearBuf` is not understandable to especially
  Beginners, so it was changed to `ClearBuffer`

- Originally, main dxlib .h file was named `dx.h`, now its named `dxlib.h` for clarity

- Printing Lines would usually need you to call `dxp` or `varp`, but now it has been changed
  `dxp` is now `printline` and `varp` is now `varPrint`, this change has been done to make it
  easier for beginners to understand

- Asking for input was usually needed for you to call `dxi` function. It has been renamed to
  `askInput` to make it more clearer for beginners.

- **2025/08/05**

---

## **File structure changes**

- Before, there was a `src/` folder in `include/`, now its in its seperate directory `examples/`
  In the `examples/` directory you can find `dxlibusage.cpp`, it demonstrates how to use some `dxlib` namespaces.

- **2025/08/06**

---

## **New Addition**
- In `dxlibRandom::RandomNumRange()` It supported only integers, now it supports:
  `float`, `double`, `long`, and `long long`

#### How you would use it:
```cpp
#include "../include/dx.h" // change this depending on your project structure

using namespace dxlib::dxlibRandom; // prevent typing dxlib::dxlibRandom::RandomNumRange()

int main() {
    int a = RandomNumRange(0, 5); // pick from 0 to 5 (int)
    double b = RandomNumRange(1.5, 10.5); // pick from 1.5 to 10.5 (double/float)

    std::cout << a << std::endl; // print the int
    std::cout << b << std::endl; // print the double
}
```

`// Output should be an integer for the a value and a floating point number for the b value.`


- **2025/08/07**

---

## **Removed Functions/namespaces**
- In `dxlib::dxlibRandom` there used to be a `PrintRandomNum()` function, now that is removed since
  It is **redundant**.

- There used to be a `dxlib::dxlibGen`, its now deleted and all its `functions` are moved to: `dxlib::dxlibRandom` since it
  Makes more sense.

- There used to be a nested namespace `dxlib::dxlibMath::dxlibPower`, its now deleted and its function has been stored in `dxlib::dxlibMath`

- There was a namespace called `dxlibMathAdditions` in `dxlibMath`, now its removed and its functions are in `dxlibMath`

- **2025/08/07**

---

## **New Additions**

- `OperatorNums()` in `dxlibMath` has been reworked to support `int`, `float`, `long`, `double`, and `long long`

### Example:

```cpp
#include "../include/dx.h" // adjust depending on your project structure

using namespace dxlib::dxlibMath; // no need to type 'dxlib::dxlibMath::OperatorNums'

int main() {
    std::cout << OperatorNums(10, 2, "+") << "\n"; // pick an int
    std::cout << OperatorNums(10.55f, 2.5f, "+") << "\n"; // pick a float specifically (with f)
    std::cout << OperatorNums(10.693, 5.212, "+") << "\n"; // pick a double
}
```

`Would output: 12 13.05 15.905`

- Added a new namespace in `dxlib`, its called `dxlibCheck`, it checks for various cases like if a string is alphanumeric
  or a number is a prime number and so much more. You can check the updated `dxHelp.h` for the new namespace and its contents.
  Or the `dxlib.h` main source file.

- **2025/08/07**
  
---

## **File structure Change**
- Before there was a `include` directory in this repository. Now it has been replaced with: `dxlibPackage.zip/include/`
  `include/` includes: `dxlib.h`, `dxHelp.h`, `DXHELP.md`

- **2025/08/07**

---

### More updates coming soon!

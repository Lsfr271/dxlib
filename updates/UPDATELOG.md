### Updates

- **Added helper file:** `dxHelp.h`
  This file explains all functions in the library for users who get stuck.  
  Location: [dxHelp.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxHelp.h)

- **2025/08/01**

---

- **Introduced new namespace:** `dxlibDebug ` 
  This namespace provides easy-to-use debugging utilities that wrap verbose C++ debug code into simpler functions.  
  For details, see [dxHelp.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxHelp.h).

- **2025/08/04**

---

- **Created example file:** `dxlibusage.cpp`  
  Located in `examples/dxlibusage.cpp`, this file demonstrates how to use dxlib and covers multiple namespaces.  
  File: [dxlibUsage](https://github.com/Lsfr271/dxlib/blob/main/examples/dxlibusage.cpp)

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

    printVar("New word: -word-", word);
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
  In the `examples/` directory you can find [dxlibUsage](https://github.com/Lsfr271/dxlib/blob/main/examples/dxlibusage.cpp), it demonstrates how to use some `dxlib` namespaces.

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
    std::srand(std::time(0)); // for random number each time
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
  or a number is a prime number and so much more. You can check the updated [dxHelp.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxHelp.h) for the new namespace and its contents.
  Or the [dxlib.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxlib.h) main source file.

- **2025/08/07**
  
---

## **File structure Change**
- Before there was a `include` directory in this repository. Now it has been replaced with: `dxlibPackage.zip/include/`
  `include/` includes: `dxlib.h`, `dxHelp.h`, `DXHELP.md`

- **2025/08/07**

---

## **CMAKE Support**
- CMake support has been added, please navigate to [HELP](https://github.com/Lsfr271/dxlib/tree/main/HELP) in this repository.
  Collab with: [ripcode](https://github.com/ripcode0)

- **2025/08/07**

---

## **New Addition**
- 3 New functions has been added in `dxlibMath`, go to `dxHelp.h` to see them.

- **2025/08/07**

---

## **New Addition**
- New namespace has been added `dxlibProbability`, this is just a random generator for multiple functions. If you are interested
  Please check in [dxHelp.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxHelp.h)

- More functions has been added to `dxlibMain`, these being are:
- `Pause()`
- `YesNoPrompt()`
- `ClearScreen()`

- Please go to [dxHelp.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxHelp.h) to learn more about these new additions.

### Here is how you would use **YesNoPrompt()**:
```cpp
#include "../include/dxlib.h" // can be different depending on your project structure

using namespace dxlib; // avoid typing a bunch of namespaces to get to a function
using namespace dxlibMain;

int main() {
    while (true){
        // How to use YesNoPrompt()
        bool chosen = YesNoPrompt("Is burgers your favourite food? (y/n): "); // assign to a boolean

        if (chosen){ // if it returns true:
            std::cout << "I like burgers as well!" << std::endl;
            break;
        }
        else { // if it returns false: (two cases)
            std::cout << "Either you dont like it or you are dumb. Please try again." << "\n";
            continue;
        }
    }
}
```

- **2025/08/08**

---

## **Minor bug fix**
- printline in `dxlibPrint` takes in two arguments: `text` and `endl`, endl stands for new line. And endl is a `bool` datatype
  the problem is that if it was false it still printed a new line:

```cpp
void printline(std::string text, bool endl=true){
    if (endl){ // this says if endl is TRUE (newline printed)
        std::cout << text << std::endl;
    }
    else if (!endl){ // this says if endl is FALSE
        std::cout << text << "\n"; // this is the problem here, it would print a new line anyway
    }
    else {
        throw std::invalid_argument("Please enter true or false on the second argument.");
    }
}
```
- So it has been fixed to NOT print a newline.

- **2025/08/08**

---

## **New addition**
- Usually in [dxHelp.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxHelp.h) it used to make you call seperate functions to
  Understand what each namespace did, but theres now a new function that calls all the functions in the [dxHelp.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxHelp.h):

```cpp
void AllHelp() {
    // Calls everything
    dxlibMainUtil();
    dxlibRandUtil();
    dxlibConvertUtil();
    dxlibFileUtil();
    dxlibMathUtil();
    dxlibTimeUtil();
    dxlibPrintUtil();
    dxlibTextUtil();
    dxlibDebugUtil();
    dxlibCheckUtil();
    dxlibProbUtil();
}
```

- **2025/08/08**

---

## **Source file addition**
- In [dxlib.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxlib.h), there wasn't any `#pragma once` included.
  Now its included to prevent duplicates of includes.

- **2025/08/08**

---

## **Minor bug fix**
- In `dxlibMath::Factorial()` it used to do this:

```cpp
unsigned long long Factorial(unsigned int n){
    unsigned long long result = 1;

    for (unsigned int i = 2; i <= n; ++i){
        result *= 1; // this is the problem
    }

    return result;
}
```

- You see, `result *= 1` basically does nothing. So to fix it, it was changed to `result *= i`

- **2025/08/09**

---

## **New Addition**
- 7 new functions has been added in dxlibMain, please go to [dxHelp.h](https://github.com/Lsfr271/dxlib/blob/main/dxlibPackage.zip/include/dxHelp.h)
  To check whats new.
  
- I will cover one of them, its called `mVect()`, all it does it multiplies all the elements in a vector. (only integers are supported)

### **Example:**
```cpp
#include "../include/dxlib.h"

using namespace dxlib::dxlibMain;

int main() {
    std::vector<int> ex = {10, 20, 30, 40, 50};

    // note: mVect means multiply vector.
    mVect(ex, 2); // first argument is the vector which is 'ex' and the second is how much it should be multiplied
    // so if its 2, it multiples all elements by 2, if its 3 it multiplies all elements by 3, and so on.

    // print the result by looping through each element:
    for (int numbers : ex){
        std::cout << numbers << " ";
    }

    return 0;
}
```

`output: 20, 40, 60, 80, 100`

- **2025/08/09**

---

### More updates coming soon!

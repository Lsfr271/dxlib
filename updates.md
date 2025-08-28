# Updates

## DELETIONS AND NEW FEATURES
## GO TO **functions.md** OR THE SOURCE CODE **dxlib.hpp** to check the explanations.

## **Deletions**
- Deleted the `dxlibLoops` namespace. Only kept `vectorLoop()` and placed it in `dxlibMain()`
- Deleted the `dxlibProbability` namespace and moved all its functions to the `dxlibRandom` namespace since its **redundant**
- Deleted the inner namespace in `dxlibFileUtils` that used to be called `dxlibFileOperations` and moved all its functions into `dxlibFileUtils`
- Deleted `dxlibShapesCalc` namespace since its **redundant** and probably wont be used in code.

---

## **New Additions**
- Added a new convert function in `dxlibConvert`, the name is `ConvertIntToFloat`, Pretty simple it just converts an int to a float
- Added four new functions in `dxlibCheck`, these being are `isZero()`, `isHalf()`, `isMultTwo()`, and `isEqual()`.
- Added two new functions in `dxlibCheck`, these being are `isOverTwoNumbersCombined()` and `isLessThanTwoNumbersCombined()`.
- Added Doxygen comments in every function.

---

### More updates coming soon!

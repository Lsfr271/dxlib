# Updates

## DELETIONS AND NEW FEATURES
## GO TO **functions.md** OR THE SOURCE CODE **dxlib.hpp** to check the explanations.

## **Deletions**
- Deleted the `dxlibLoops` namespace. Only kept `vectorLoop()` and placed it in `dxlibMain()`
- Deleted the `dxlibProbability` namespace and moved all its functions to the `dxlibRandom` namespace since its **redundant**
- Deleted the inner namespace in `dxlibFileUtils` that used to be called `dxlibFileOperations` and moved all its functions into `dxlibFileUtils`
- Deleted `dxlibShapesCalc` namespace since its **redundant** and probably wont be used in code.
- Deleted `CreatePtr()` in `dxlibMain` since its redundant and no one would use it.
- Deleted namespace `dxlibUtility` since its really redundant and moved all its functions into namespace `dxlibMain`
---

## **New Additions**
- Added a new convert function in `dxlibConvert`, the name is `ConvertIntToFloat`, Pretty simple it just converts an int to a float
- Added four new functions in `dxlibCheck`, these being are `isZero()`, `isHalf()`, `isMultTwo()`, and `isEqual()`.
- Added two new functions in `dxlibCheck`, these being are `isOverTwoNumbersCombined()` and `isLessThanTwoNumbersCombined()`.
- Added Doxygen comments in every function.
- Added new convert functions in `dxlibConvert` you can check them in the source code `dxlib.hpp` file.
- Added new function in `dxlibFileUtils`, the function being is `GetExtension()`, for more informations go to `functions.md` or `dxlib.hpp`
- Added 2 new functions in `dxlibRandom`, being are: `_add_RandomNumberOffset()`, and `_sub_RandomNumberOffset()`. For
- more information please go to `functions.md` or `dxlib.hpp`
- Added a new function in `dxlibCheck`, function: `VectorCheck()`, for more information go to `functions.md` or
- `dxlib.hpp`
- Added a new function in `dxlibCheck`, function: `isNeg()`, for more information go to `functions.md` or `dxlib.hpp`
- Added a new function in `dxlibMain`, function: `IsInVec()`, for more information go to `functions.md` or `dxlib.hpp`
- Added a new function in `dxlibTime`, function: `ProgressBar()`, for more information go to `functions.md` or `dxlb.hpp`
- Added a new namespace called `dxlibUtility`. functions: `VectContains()`, and `GetType()`, for more information go to `functions.md`
or `dxlib.hpp`

---

### More updates coming soon!

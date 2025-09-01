# DXLIB Function Documentation
# VISIT THE SOURCE CODE AND LOOK AT THE DOXYGEN COMMENTS FOR MORE EXPLANATION

## DXLIBMAIN:

- `CinFail()`: Checks if a cin failed (wrong datatype input). Example: `int age; std::cin >> age; if (CinFail()){ std::cout << "Something went wrong!" << std::endl; }`
- `ClearBuffer()`: Clears leftover newline from cin/endl. Example: `std::string name,dad; std::cin >> name; ClearBuffer(); std::getline(std::cin,dad);`
- `Pause()`: Pauses program execution. Example: `Pause();`
- `YesNoPrompt(msg,newline=true)`: Prompts user with yes/no. Returns true for yes. Example: `bool result = YesNoPrompt("Do you like programming?(y/n): ");`
- `ClearScreen()`: Clears the console screen. Example: `ClearScreen();`
- `mVect(vec,mult)`: Multiplies all vector elements by a number. Example: `std::vector<int> nums={1,2,3}; mVect(nums,2);`
- `PrintVector(vec,newline=true)`: Prints all the vector elements. Example: `PrintVector(nums);`
- `swap(a,b)`: Swaps two variables. Example: `int a=10,b=20; swap(a,b); std::cout << a << " " << b;`
- `CountChar(str,c)`: Counts a character in a string. Example: `int c = CountChar("hello",'l');`
- `IsPowerOfTwo(n)`: Checks if number is a power of two. Example: `bool p = IsPowerOfTwo(8);`
- `ReverseVector(vec)`: Reverses vector in place. Example: `std::vector<int> nums = {1, 2, 3}; ReverseVector(nums);`
- `SortVector(vec,order="asc")`: Sorts vector ascending/descending. Example: `std::vector<int> nums = {3, 2, 1}; SortVector(nums,"asc");`
- `SumVector(vec)`: Sums vector elements. Example: `std::vector<int> nums = {1, 2, 3, 4}; int s = SumVector(nums);`
- `AbsVal(x)`: Returns absolute value. Example: `int a = AbsVal(-5);`
- `GenerateRandomVector(size,min=0,max=100)`: Generates a random vector of integers. Example: `auto r = GenerateRandomVector(5,1,10);`
- `vectorLoop(vec,val,mode="add")`: Loops through vector to add/subtract value. Example: `std::vector<int> nums = {3, 3, 3}; vectorLoop(nums,2,"add");`

## DXLIBRANDOM:

- `_add_RandomNumberOffset(a, b, add)`: Takes in two arguments and a add factor and adds b + add and picks
- a random number from that.
- `_sub_RandomNumberOffset(a, b, sub)`: Same as `_add_RandomNumberOffset(a, b, add)` but opposite, instead of adding,
- it subtracts b - sub.
- `RandomNumRange(min,max)`: Random number between min/max. Example: `int r = RandomNumRange(1,6);`
- `RandomStr(len)`: Random string of length len. Example: `std::string s = RandomStr(5);`
- `ShuffleVect(vec)`: Shuffles a vector. Example: `std::vector<int> nums = {1, 2, 3, 4}; ShuffleVect(nums);`
- `Probability(start,end)`: Random number between start/end. Example: `double p = Probability(0,10);`
- `FlipCoin()`: Returns 0=head, 1=tail. Example: `int f = FlipCoin();`
- `RollDice(sides)`: Returns random number 1 to sides. Example: `int d = RollDice(6);`
- `Chance()`: Random float 0-1. Example: `double c = Chance();`
- `SampleFromVector(vec)`: Random element from vector. Example: `std::vector<int> nums = {5, 2, 1, 7, 9}; int e = SampleFromVector(nums);`

## DXLIBCONVERT:

- `ConvertDoubleToInt(i)`: Converts double to int. Example: `double i = 10.593; ConvertDoubleToInt(i)`
- `ConvertIntToDouble(i)`: Converts a int to double. Example: `int i = 30; ConvertIntToDouble(i);`
- `ConvertFloatToDouble(i)`: Converts a float to a double. Example: `float i = 3.49501; ConvertFloatToDouble(i);`
- `ConvertDoubleToFloat(i)`: Converts a Double to a float. Example: `double i = 3.59581010199; ConvertDoubleToFloat(i);`
- `ConvertAnyNumToString(num)`: Converts any arithmetic type to a stirng. Example: `int a = 10; std::cout << "Number is: " + ConvertAnyNumToString(a);`
- There are much more functions that are simmilar, if you are interested please look into the source code and find `dxlibConvert`.

## DXLIBFILE:

- `FileExists(filename)`: Check if file exists. Example: `if(FileExists("file.txt")) std::cout << "Yes";`
- `FileToString(filename)`: Read file as string. Example: `std::string content = FileToString("file.txt");`
- `WriteString_ToFileAndOverWrite(filename,string)`: Overwrite file. Example: `WriteString_ToFileAndOverWrite("file.txt","Hello");`
- `WriteVectorToFileAnd_OverWrite(filename,vector<char>)`: Write vector to file. Example: `std::vector<char> v={'a','b'}; WriteVectorToFileAnd_OverWrite("file.txt",v);`
- `CreateFile(filename,extension)`: Create file. Example: `CreateFile("example","txt");`
- `DeleteFile(filename)`: Delete file. Example: `DeleteFile("example.txt");`
- `CopyFile(src,dest)`: Copy file. Example: `CopyFile("a.txt","b.txt");`
- `RenameFile(oldname,newname)`: Rename file. Example: `RenameFile("b.txt","c.txt");`
- `GetExtension(filename)`: Gets the extension of a filename. Example: `GetExtension("testing.hpp"); // returns .hpp`

## DXLIBMATH:

- `Operators(a,b,op)`: Perform '+','-','*','/' or special '/*-' operation. Example: `int res = Operators(2,3,'+');`
- `MultNums(vector)`: Multiply all vector elements. Example: `std::vector<int> nums = {2, 4}; int m = MultNums(nums);`
- `pwr(a,b)`: Returns a^b. Example: `int x = pwr(2,3);`
- `Factorial(n)`: Factorial of n. Example: `int f = Factorial(5);`
- `GCD(a,b)`: Greatest common divisor. Example: `int g = GCD(12,18);`
- `LCM(a,b)`: Least common multiple. Example: `int l = LCM(4,6);`

## DXLIBTIME:

- `FormatDate(tm)`: Convert time to string. Example: `std::string s = FormatDate(std::tm{});`
- `sleepfor(type,value)`: Sleep for seconds/minutes. Example: `sleepfor("s",1);`
- `GetLocalTime():` Get current local time. Example: `std::cout << GetLocalTime();`
- `AddSecToTime(tm,seconds)`: Add seconds to time. Example: `AddSecToTime(t,60);`

## DXLIBPRINT:

## NOTE: FOR PRINTVAR() FUNCTION YOU HAVE TO PUT THE ARGUMENTS IN ORDER OR ELSE IT WONT WORK AS YOU EXPECT.

- `printline(string)`: Print string. Example: `printline("Hello");`
- `printVar(template,vars...)`: Insert variables into string. Example: `int a=10; printVar("Value is -a-",a);`
- `askInput<Type>(prompt)`: Ask input from user. Example: `std::string n = askInput<std::string>("Name?: "); std::cout << "Hello, " << n << '\n';`

## DXLIBTEXT:

- `startsWith(string,prefix)`: True if string starts with prefix. Example: `bool b = startsWith("Hello","He");`
- `endsWith(string,suffix)`: True if string ends with suffix. Example: `bool b = endsWith("Hello","lo");`
- `ChangeCase(string,type)`: Change case. Example: `ChangeCase("Hello","upper");`
- `Split(string,delimiter)`: Split string. Example: `auto parts = Split("a,b,c",',');`
- `Join(vector<string>)`: Join strings. Example: `std::string s = Join({"a","b"});`
- `TrimString(string)`: Remove all whitespace. Example: `std::string s = TrimString(" h e l l o ");`
- `ReverseString(string)`: Reverse string. Example: `std::string r = ReverseString("Hello");`
- `LTrim(string)`: Trim left whitespace. Example: `std::string l = LTrim("  Hello");`
- `RTrim(string)`: Trim right whitespace. Example: `std::string r = RTrim("Hello  ");`
- `CapitalizeWords(string)`: Capitalize first letter of each word. Example: `std::string c = CapitalizeWords("hello world");`

## DXLIBDEBUG:

- `log(msg,type):` Log message. Example: `log("Started","INFO");`
- `debugBreak()`: Break code execution. Example: `debugBreak();`
- `assertLog(value)`: Assert value != 0. Example: `assertLog(5);`
- `timeLog(block)`: Measure execution time. Example: `timeLog([](){ /* code */ });`

## DXLIBCHECK:

- `isEven(n)`: True if even. Example: `bool e = isEven(4);`
- `isOdd(n)`: True if odd. Example: `bool o = isOdd(5);`
- `isNumeric(string)`: True if numeric. Example: `bool n = isNumeric("123");`
- `isAlpha(string)`: True if alphabetic. Example: `bool a = isAlpha("abc");`
- `isAllNum(string)`: True if alphanumeric. Example: `bool an = isAllNum("a1b2");`
- `isFloatString(string)`: True if valid float. Example: `bool f = isFloatString("3.14");`
- `isDoubleString(string)`: True if valid double. Example: `bool d = isDoubleString("3.1415");`
- `isInRange(num,min,max)`: True if number in range. Example: `bool r = isInRange(5,1,10);`
- `isPrime(n)`: True if prime. Example: `bool p = isPrime(7);`
- `isPalindrome(n)`: True if palindrome. Example: `bool pal = isPalindrome(121);`
- `isWhiteSpaceOnly(string)`: True if string is only spaces. Example: `bool ws = isWhiteSpaceOnly("   ");`
- `isZero(n)`: True if number is zero. Example: `bool z = isZero(0);`
- `isHalf(num,other)`: True if num/2 == other. Example: `bool h = isHalf(10,5);`
- `isMultTwo(num,other)`: True if num*2 == other. Example: `bool m = isMultTwo(5,10);`
- `isEqual(a,b)`: True if a==b. Example: `bool eq = isEqual(3,3);`
- `isOverTwoNumbersCombined(std::string what, n1, n2, n3)`: Returns true if n1 is greater than n2 & n3 in a specific operator, the operator depends on the 'what' argument.
- `isLessThanTwoNumbersCombined(std::string what, n1, n2, n3)`: Returns true if n1 is lower than n2 & n3 in a specific operator, the operator depends on the 'what' argument.
- `VectorCheck(std::vector<T>& vec, int num, std::string op)`: Checks if all elements in a vector summed-up is
- lower or higher than `int num`.
- `isNeg(a)`: Checks if a number is below 0
- `isNeg(a, rest...)(infinite args version)`: Checks if a number subtracted by how much other numbers IS below 0

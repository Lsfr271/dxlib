#ifndef DX_HELP
#define DX_HELP

#include <iostream>
#include <string>

namespace dxlibHelp {

    void dxlibMainUtil() {
        std::cout << "CinFail(): Checks if std::cin failed (likely due to an invalid data type)." << std::endl;
        std::cout << "ClearBuffer(): After std::endl, a buffer is added, which can auto-submit the next input."
                     " This function clears that buffer." << std::endl;
        std::cout << "Pause(): Pauses the program" << std::endl;
        std::cout << "YesNoPrompt(): Gets two arguments, a question and a newline boolean. Returns true if 'y' or 'Y' was"
                     " chosen, else false if 'n'/'N' or something else was chosen." << std::endl;
        std::cout << "ClearScreen(): Clears the console screen" << std::endl;
        std::cout << "mVect(): Multiplies all the elements in a vector by a multiplied argument" << std::endl;
        std::cout << "PrintVector(): Prints all elements of a vector" << std::endl;
        std::cout << "swap(): swaps two variables" << std::endl;
        std::cout << "CountChar(): Counts how much a specific char has appeared in a string" << std::endl;
        std::cout << "IsPowerOfTwo(): Checks if a number is a power of two" << std::endl;
        std::cout << "ReverseVector(): Reverses a vector in place" << std::endl;
        std::cout << "SortVector(): Sorts a vectors element from lowest to highest or vice-versa depending on an argument" << std::endl;
        std::cout << "SumVector(): Sums all the elements in a vector" << std::endl;
        std::cout << "AbsVal(): Gets the absolute value of a number" << std::endl;
        std::cout << "GenerateRandomVector(): Generates a random vector and its size depends on the argument: vectorSize" << std::endl;
        std::cout << "vectorLoop(): Loops through a vectors elements and either adds or decreases the elements based on a choice" << std::endl;
        std::cout << "CreatePtr(): Creates a pointer by taking in an argument of a variable" << std::endl;
    }

    void dxlibRandUtil() {
        std::cout << "RandomNumRange(): Takes two arguments (min and max) and returns a random number between them." << std::endl;
        std::cout << "RandomStr(): Generates a random string based on the len argument" << std::endl;
        std::cout << "ShuffleVect(): Shuffles the elements of a vector randomly" << std::endl;
        std::cout << "Probability(): Gets a random number from two arguments: Start, end" << std::endl;
        std::cout << "FlipCoin(): Flips either a head or a tails. Returns 0 if its a head, 1 if its a tail" << std::endl;
        std::cout << "RollDice(): Gets a random number from the given amount of sides" << std::endl;
        std::cout << "Chance(): Rolls a number from 0 to 1" << std::endl;
        std::cout << "SampleFromVector(): Gets a random element from a vector given" << std::endl;
    }

    void dxlibConvertUtil() {
        std::cout << "dxlibConvert has 5 functions for converting between data types. Here's one as an example:" << std::endl;

        std::cout << "ConvertDoubleToInt(): Takes a double (e.g., 3.14) and converts it to an int (3)." << std::endl;
        std::cout << "ConvertAnyNumToString(): It converts only integer data types like int, float, double, long, long long to strings." << std::endl;
        std::cout << "The rest are similar. If you're unfamiliar with data types, look up a beginner tutorial." << std::endl;
    }

    void dxlibFileUtil() {
        std::cout << "FileExists(): Checks if a file exists by its name." << std::endl;
        std::cout << "FileToString(): Reads an entire file and returns its contents as a string." << std::endl;
        std::cout << "WriteString_ToFileAndOverWrite(): Takes a filename and a string, then writes the string to the file." << std::endl;
        std::cout << "WriteVectorToFileAnd_OverWrite(): Takes a filename and a vector of characters, writing them to the file." << std::endl;
        std::cout << "CreateFile(): Takes a filename and file extension, and creates the file (e.g., example.txt)." << std::endl;
        std::cout << "DeleteFile(): Deletes an existing file; throws an error if it doesn't exist." << std::endl;
        std::cout << "CopyFile(): Copies a file to a new destination using the arguments provided." << std::endl;
        std::cout << "RenameFile(): Renames an existing file; throws an error if the file doesn't exist." << std::endl;
    }

    void dxlibMathUtil() {
        std::cout << "The first few functions are harder to explain, but if you understand sin, cos, and tan, they should make sense." << std::endl;
        std::cout << "OperatorNums(): Takes two integers/floating numbers and a character. For example, '+' adds them. For the special type \"/*-\","
                     " it runs: a / b * b * pow(a, 2) - (a - b). Be cautious with that." << std::endl;
        std::cout << "MultNums(): Takes a vector of numbers and multiplies all its elements together." << std::endl;
        std::cout << "ReturnPower(): returns the result." << std::endl;
        std::cout << "There are also shape-related functions — check the dxlib.h source for those." << std::endl;
        std::cout << "Factorial(): returns the product of all positive integers less than or equal to a given non-negative integer" << std::endl;
        std::cout << "GCD(): Returns the greatest common divider between two arguments (a, b)" << std::endl;
        std::cout << "LCM(): Opposite of GCD() and accepts two arguments (a, b)" << std::endl;
    }

    void dxlibTimeUtil() {
        std::cout << "FormatDate(): Converts a time structure (tm) into a formatted string." << std::endl;
        std::cout << "sleepfor(): Takes a type (e.g., 's') and an integer. If type is 's' and value is 1, it waits 1 second."
                     " You can check the source or pass an invalid type to learn more." << std::endl;
        std::cout << "GetLocalTime(): Returns your system’s current local time." << std::endl;
        std::cout << "AddSecToTime(): Adds seconds to a time structure by converting it to a numeric value and back." << std::endl;
    }

    void dxlibPrintUtil() {
        std::cout << "printline(): Prints a string to the screen. (Only string is supported)" << std::endl;
        std::cout << "printVar(): Prints a variable inside a string. Example:"
                     " int a = 20; printVar(\"Something is -a- years old\", a)."
                     " Use - - around the variable name in the string and pass the variable as an argument." << std::endl;
        std::cout << "askInput(): Asks for input in the terminal. For example: "
                     " std::string name = askInput<std::string>(\"What is your name?\")" << std::endl;
    }

    void dxlibTextUtil() {
        std::cout << "startsWith(): Returns true if a string starts with the given prefix." << std::endl;
        std::cout << "endsWith(): Returns true if a string ends with the given suffix." << std::endl;
        std::cout << "ChangeCase(): Changes a string to uppercase, lowercase, or randomized." << std::endl;
        std::cout << "Split(): Splits a string using a delimiter and returns parts as separate strings." << std::endl;
        std::cout << "Join(): Joins strings together." << std::endl;
        std::cout << "TrimString(): Removes all whitespace from a string." << std::endl;
        std::cout << "ReverseString(): Reverses a string. E.g., \"Hello\" becomes \"olleH\"." << std::endl;
        std::cout << "LTrim(): Removes whitespace on the left side of a string." << std::endl;
        std::cout << "RTrim(): Removes whitespace on the right side of a string." << std::endl;
        std::cout << "CapitalizeWords(): Capitalizes the first letter of each word in a string." << std::endl;
    }

    void dxlibDebugUtil() {
        std::cout << "log(): Logs a message and gives either a [INFO], [WARN], or [ERRORS]" << std::endl;
        std::cout << "debugBreak(): Breaks the code immediately if something went wrong. Supports both Windows And Linux" << std::endl;
        std::cout << "assertLog(): Makes something not 0." << std::endl;
        std::cout << "timeLog(): Measures how much time has passed during some block of code execution" << std::endl;
    }

    void dxlibCheckUtil() {
        std::cout << "isEven(): Checks if a number is even" << std::endl;
        std::cout << "isOdd(): Checks if a number is odd" << std::endl;
        std::cout << "isNumeric(): Checks if a string is numeric" << std::endl;
        std::cout << "isAlpha(): Checks if a string is alphabetic" << std::endl;
        std::cout << "isAllNum(): Checks if a string is alphanumeric" << std::endl;
        std::cout << "isFloatString(): Checks if a string is a valid float" << std::endl;
        std::cout << "isDoubleString(): Checks if a string is a valid double" << std::endl;
        std::cout << "isInRange(): Checks if a number is in a closed range" << std::endl;
        std::cout << "isPrime(): Checks if a number is a prime number" << std::endl;
        std::cout << "isPalindrome(): Checks if a number is a palindrome" << std::endl;
        std::cout << "isWhiteSpaceOnly(): Checks if a string is completely whitespaces" << std::endl;
        std::cout << "isZero(): Checks if a number is zero." << std::endl;
        std::cout << "isHalf(): Checks if a number divided by half is equal to another number." << std::endl;
        std::cout << "isMultTwo(): Checks if a number multiplied by 2 is equal to another number" << std::endl;
        std::cout << "isEqual(): Checks if two numbers are equal to each other." << std::endl;
    }

    void AllHelp() {
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
    }

}

#endif // DX_HELP

#ifndef DX_HELP
#define DX_HELP

#include <iostream>
#include <string>

namespace dxlibHelp {

    void dxlibMainUtil() { 
        std::cout << "dxlibMain has 2 functions: CinFail() and ClearBuffer()" << std::endl;

        std::cout << "CinFail(): Checks if std::cin failed (likely due to an invalid data type)." << std::endl;
        std::cout << "ClearBuffer(): After std::endl, a buffer is added, which can auto-submit the next input."
                     " This function clears that buffer." << std::endl;
    }

    void dxlibRandUtil() {
        std::cout << "dxlibRandom has 2 functions: RandomNumRange() and PrintRandomNum()" << std::endl;
        
        std::cout << "RandomNumRange(): Takes two arguments (min and max) and returns a random number between them." << std::endl;
        std::cout << "PrintRandomNum(): Similar to RandomNumRange(), but directly prints the random number instead of returning it." << std::endl;
    }

    void dxlibConvertUtil() {
        std::cout << "dxlibConvert has 5 functions for converting between data types. Here's one as an example:" << std::endl;

        std::cout << "ConvertDoubleToInt(): Takes a double (e.g., 3.14) and converts it to an int (3)." << std::endl;
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
        std::cout << "OperatorNums(): Takes two integers and a character. For example, '+' adds them. For the special type \"/*-\","
                     " it runs: a / b * b * pow(a, 2) - (a - b). Be cautious with that." << std::endl;
        std::cout << "MultNums(): Takes a vector of numbers and multiplies all its elements together." << std::endl;
        std::cout << "PrintPower(): Takes a base, exponent, and a twist boolean. If twist is false, it works normally."
                     " If true, it runs a unique algorithm and prints the result." << std::endl;
        std::cout << "ReturnPower(): Same as PrintPower(), but returns the result instead of printing it." << std::endl;
        std::cout << "There are also shape-related functions — check the dx.h source for those." << std::endl;
    }

    void dxlibTimeUtil() {
        std::cout << "FormatDate(): Converts a time structure (tm) into a formatted string." << std::endl;
        std::cout << "sleepfor(): Takes a type (e.g., 's') and an integer. If type is 's' and value is 1, it waits 1 second."
                     " You can check the source or pass an invalid type to learn more." << std::endl;
        std::cout << "GetLocalTime(): Returns your system’s current local time." << std::endl;
        std::cout << "AddSecToTime(): Adds seconds to a time structure by converting it to a numeric value and back." << std::endl;
    }

    void dxlibGenUtil() {
        std::cout << "RandomStr(): Generates a password-like random string. The length depends on the value passed." << std::endl;
        std::cout << "ShuffleVect(): Shuffles a vector. For example: std::vector<char> ex = {'a', 'b', 'c'};"
                     " ShuffleVect(ex) might become {'a', 'c', 'b'}." << std::endl;
    }

    void dxlibPrintUtil() {
        std::cout << "dxp(): Prints a string to the screen. (Only string is supported)" << std::endl;
        std::cout << "varp(): Prints a variable inside a string. Example:"
                     " int a = 20; varp(\"Something is -a- years old\", a)."
                     " Use - - around the variable name in the string and pass the variable as an argument." << std::endl;
    }

    void dxlibTextUtil() {
        std::cout << "startsWith(): Returns true if a string starts with the given prefix." << std::endl;
        std::cout << "endsWith(): Returns true if a string ends with the given suffix." << std::endl;
        std::cout << "ChangeCase(): Changes a string to uppercase or lowercase." << std::endl;
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
}

#endif // DX_HELP

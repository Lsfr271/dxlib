#ifndef DX_HELP
#define DX_HELP

#include <iostream>
#include <string>

namespace dxlibHelp {

    void dxlibMainUtil() { 
        std::cout << "dxlibMain has 2 functions, being CinFail() and dxClearBuf()" << std::endl;

        std::cout << "CinFail(): Checks if any std::cin has failed (likely to invalid data type)" << std::endl;
        std::cout << "dxClearBuf(): When you do a std::endl it adds a buffer, so on the next input"
                     " it would automatically enter as a new line. This is why dxClearBuf() exists." << std::endl;
    }

    void dxlibRandUtil() {
        std::cout << "dxlibRandom has 2 functions, being RandomNumRange() and PrintRandomNum()" << std::endl;
        
        std::cout << "RandomNumRange(): It takes in 2 arguments, being the min and max. Min is where the computer starts"
                     " the lowest, and max being where the computer ends. And in between that, it picks a random number." << std::endl;
        std::cout << "PrintRandomNum(): It is very simmilar to RandomNumRange, instead of returning it directly prints the random number." << std::endl;
    }

    void dxlibConvertUtil() {
        std::cout << "dxlibConvert has 5 functions. They are about converting data types, lets explain one." << std::endl;

        std::cout << "ConvertDoubleToInt(): It takes in a double parameter and converts it to an int."
                     " Imagine you have this: 'double a = 3.14', ConvertDoubleToInt(double) converts 3.14 to 3" << std::endl;
        std::cout << "For the other functions its very simmilar. I wont explain them but if you do not know datatypes"
                     " go watch a tutorial explaining them." << std::endl;
    }

    void dxlibFileUtil() {
        std::cout << "FileExists(): Checks if a file exists by checking the filename argument passed" << std::endl;
        std::cout << "FileToString(): Checks the files name passed and reads the file and returns a string of everything" << std::endl;
        std::cout << "WriteString_ToFileAndOverWrite(): Takes in a filename and a string then puts that string in the file." << std::endl;
        std::cout << "WriteVectorToFileAnd_OverWrite(): Takes in a file name and a vector of characters and puts that vector of chars"
                     " in the file" << std::endl;
        std::cout << "CreateFile(): Takes in a filename and a filetype and creates it. For example: example.txt, the .txt"
                     " is the filetype, and the example is the filename" << std::endl;
        std::cout << "DeleteFile(): Deletes an existing file, otherwise throws an error" << std::endl;
        std::cout << "CopyFile(): Copies the contents of the file and its name and takes in arguments to where it should be" << std::endl;
        std::cout << "RenameFile(): Renames an exising file, otherwise throws an error." << std::endl;
    }

    void dxlibMathUtil() {
        std::cout << "The first functions is very difficult to explain, but if you know sin, cos, tan it should be easy." << std::endl;
        std::cout << "OperatorNums(): Takes in 2 integers and a type. If its + it adds the 2 integers and so on"
                     " theres one type you should be aware about, its \"/*-\", this type has the formula of: "
                     " return a / b * b * pow(a, 2) - (a - b), so be aware." << std::endl;
        std::cout << "MultNums(): Takes in a vector and iterates through each element and multiplies the element." << std::endl;
        std::cout << "PrintPower(): Takes in 3 arguments, a base & exponent and a boolean twist, if the twist is false"
                     " it calculates it nomrally, but its off it does some weird algorithm. So be aware. And it prints the result" << std::endl;
        std::cout << "ReturnPower(): This is the same as PrintPower() but returns it instead of printing it, giving you more control" << std::endl;
        std::cout << "The other functions are for shapes, if your interested you can take a look at the source code in dx.h" << std::endl;
    }

    void dxlibTimeUtil() {
        std::cout << "FormatDate(): Converts a time structure (tm) into a formatted string." << std::endl;
        std::cout << "sleepfor(): Takes in two arguments, a type and an integer, if the type is \"s\" and the type"
                     " is 1, it waits for 1 second and then runs the code below in your program, you can look"
                     " at the source code for more information or enter an invalid type to get more information" << std::endl;
        std::cout << "GetLocalTime(): Gets the local time of your country." << std::endl;
        std::cout << "AddSecToTime(): Adds a specified number of seconds to a time structure, converts into numeric value"
                     " then converts it back." << std::endl;
    }

    void dxlibGenUtil() {
        std::cout << "RandomStr(): Generates a random password-like string and depends on what length is passed on how long it is" << std::endl;
        std::cout << "ShuffleVect(): Shuffles a vector. For example: std::vector<std::char> ex = {'a', 'b', 'c'}"
                     " ShuffleVect(ex), it might become like: {'a', 'c', 'b'} or some different places." << std::endl;
    }

    void dxlibPrintUtil() {
        std::cout << "dxp(): Prints something to the screen. (only string is supporte)" << std::endl;
        std::cout << "varp(): Prints a variable plus a string onto the screen, here is an example: "
                     " int a = 20; varp(\"Something is -a- years old\", a) what it basically does it gets the value of the"
                     " integer and puts it in the string. Note: Use - - around something and PASS the variable as an argument" << std::endl;
    }

    void dxlibTextUtil() {
        std::cout << "startsWith(): Returns true if the prefix of a word starts with whatever string is passed. Otherwise false" << std::endl;
        std::cout << "endsWith(): Same logic as startsWith()" << std::endl;
        std::cout << "ChangeCase(): Changes a string from uppercase or lowercase." << std::endl;
        std::cout << "Split(): Splits a string into smaller strings using a delimiter" << std::endl;
        std::cout << "Join(): Joins two strings together" << std::endl;
        std::cout << "TrimString(): Removes any whitespace in a string." << std::endl;
        std::cout << "ReverseString(): Reverses the string. For example: \"Hello\" would be \"olleH\" if you called the Function with it" << std::endl;
        std::cout << "LTrim(): Same logic as TrimString() but removes any whitespace on the left side of a string." << std::endl;
        std::cout << "RTrim(): Same logic as LTrim but removes the any whitespace on the right side of a string." << std::endl;
        std::cout << "CapitalizeWords(): Capitalizes the first letter of a word." << std::endl;
    }
}

#endif // DX_HELP

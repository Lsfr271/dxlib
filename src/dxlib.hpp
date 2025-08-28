#ifndef DX_H
#define DX_H

#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
#include <thread>
#include <fstream>
#include <filesystem>
#include <random>
#include <unordered_map>
#include <functional>
#include <type_traits>
#include <numeric>
#include <istream>

// ================== dxlib ==================
namespace dxlib {
    // ================== dxlibMain ==================
    namespace dxlibMain {
        /**
         * @brief Checks if std::cin failed
         * @return true if cin failed, false otherwise
         * @example
         * if (CinFail()) { std::cout << "Input failed\n"; }
         */
        bool CinFail(){
            if (std::cin.fail()){
                return true;
            }
            else {
                return false;
            }
        }

        /**
         * @brief Clears leftover buffer from std::cin
         * @example
         * ClearBuffer(); // clears anything left in the input buffer
         */
        void ClearBuffer(){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        /**
         * @brief Pauses the program until user presses enter
         * @param msg = Message displayed to the user before pausing
         * @example
         * Pause("Press enter to continue..."); // waits for user input
         */
        void Pause(const std::string&msg = "Press enter to continue...."){
            std::cout << msg;
            ClearBuffer();
            std::cin.get();
        }

        /**
         * @brief Asks for a yes/no question from the user
         * @param ques = Question displayed to the user
         * @param newline = Whether to print the question on a new line
         * @return true if user inputs 'y' or 'Y', false otherwise
         * @example
         * bool ans = YesNoPrompt("Continue?"); // returns true if user types y/Y
         */
        bool YesNoPrompt(const std::string& ques, bool newline=true){
            std::string input;

            if (newline){
                std::cout << ques << "\n";
                std::getline(std::cin, input);

                if (input == "y" || input == "Y"){
                    return true;
                }
                else if (input == "n" || input == "N"){
                    return false;
                }
                else {
                    return false;
                }
            }
            else {
                std::cout << ques;
                std::getline(std::cin, input);

                if (input == "y" || input == "Y"){
                    return true;
                }
                else if (input == "n" || input == "N"){
                    return false;
                }
                else {
                    return false;
                }
            }
        }

        /**
         * @brief Clears the console screen
         * @example
         * ClearScreen(); // clears terminal output
         */
        void ClearScreen() {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
        }

        /**
         * @brief Multiplies all elements in a vector by a value
         * @param vec = Vector to be multiplied
         * @param mult = Multiplier value (must be > 0)
         * @return Returns the modified vector
         * @example
         * std::vector<int> v = {1,2,3};
         * mVect(v, 2); // v = {2,4,6}
         */
        std::vector<int> mVect(std::vector<int>& vec, int mult){
            if (mult <= 0){
                throw std::invalid_argument("The multiplier cannot <= 0");
            }

            for (size_t i = 0; i < vec.size(); ++i){
                vec[i] *= mult;
            }

            return vec;
        }

        /**
         * @brief Prints all elements in a vector
         * @param vec = Vector to print
         * @param newline = Whether to add a newline after printing
         * @example
         * std::vector<int> v = {1,2,3};
         * PrintVector(v); // prints "1 2 3"
         */
        void PrintVector(const std::vector<int>& vec, bool newline=true){
            for (const auto& v : vec){
                std::cout << v << " ";
            }

            if (newline) std::cout << "\n";
        }

        /**
         * @brief Swaps two values
         * @tparam V = Type of the values
         * @param a = first value
         * @param b = second value
         * @example
         * int x = 5, y = 10;
         * swap(x, y); // x=10, y=5
         */
        template<typename V>
        void swap(V&a, V&b){
            V temp = a;
            a = b;
            b = temp;
        }

        /**
         * @brief Counts occurrences of a character in a string
         * @param str = String to search
         * @param c = Character to count
         * @return Number of occurrences of c in str
         * @example
         * CountChar("hello", 'l'); // returns 2
         */
        int CountChar(const std::string& str, char c){
            return std::count(str.begin(), str.end(), c);
        }

        /**
         * @brief Checks if a number is a power of two
         * @tparam T = Numeric type
         * @param n = Number to check
         * @return true if n is a power of two, false otherwise
         * @example
         * IsPowerOfTwo(8); // returns true
         */
        template<typename T>
        bool IsPowerOfTwo(T n){
            return n > 0 && (n & (n -1)) == 0;
        }

        /**
         * @brief Reverses a vector in place
         * @tparam T = Type of vector elements
         * @param vec = Vector to reverse
         * @example
         * std::vector<int> v = {1,2,3};
         * ReverseVector(v); // v = {3,2,1}
         */
        template<typename T>
        void ReverseVector(std::vector<T>& vec){
            std::reverse(vec.begin(), vec.end());
        }

        /**
         * @brief Sorts a vector in ascending or descending order
         * @param vec = Vector to sort
         * @param arrange = "lth" = lowest to highest, "htl" = highest to lowest
         * @example
         * std::vector<int> v = {3,1,2};
         * SortVector(v, "lth"); // v = {1,2,3}
         */
        void SortVector(std::vector<int>& vec, std::string arrange){
            if (arrange == "lth"){
                std::sort(vec.begin(), vec.end());
            }
            else if (arrange == "htl"){
                std::sort(vec.begin(), vec.end(), std::greater<int>());
            }
            else {
                throw std::invalid_argument("Please enter either 'lth' or 'htl' on the arrange argument");
            }
        }

        /**
         * @brief Sums all elements in a vector
         * @param vec = Vector to sum
         * @return Sum of all elements
         * @example
         * std::vector<int> v = {1,2,3};
         * SumVector(v); // returns 6
         */
        int SumVector(const std::vector<int>& vec){
            return std::accumulate(vec.begin(), vec.end(), 0);
        }

        /**
         * @brief Returns the absolute value of a number
         * @tparam A = Numeric type
         * @param x = Value to get absolute
         * @return Absolute value of x
         * @example
         * AbsVal(-5); // returns 5
         */
        template<typename A>
        A AbsVal(A x){
            return (x < 0) ? -x : x;
        }

        /**
         * @brief Generates a random string of a given length
         * @param length = Length of the string
         * @return Randomly generated string
         * @example
         * random_string(5); // might return "aZxPl"
         */
        std::string random_string(size_t length){
            const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, chars.size() -1);

            std::string result;
            for (size_t i = 0; i < length; ++i) result += chars[dist(gen)];
            return result;
        }

        /**
         * @brief Generates a random vector of integers, floats, or strings
         * @tparam T = Type of elements (int, float, string)
         * @param vectorSize = Number of elements
         * @return Randomly generated vector
         * @example
         * GenerateRandomVector<int>(5); // returns vector of 5 random integers
         */
        template<typename T>
        std::vector<T> GenerateRandomVector(size_t vectorSize){
            std::vector<T> vec;
            vec.reserve(vectorSize);

            std::random_device rd;
            std::mt19937 gen(rd());

            if constexpr (std::is_integral<T>::value){
                std::uniform_int_distribution<T> dist(0, 100);
                for (size_t i = 0; i < vectorSize; ++i) vec.push_back(dist(gen));
            }
            else if constexpr (std::is_floating_point<T>::value){
                std::uniform_real_distribution<T> dist(0.0, 100.0);
                for (size_t i = 0; i < vectorSize; ++i) vec.push_back(dist(gen));
            }
            else if constexpr (std::is_same<T, std::string>::value){
                for (size_t i = 0; i < vectorSize; ++i) vec.push_back(random_string(5));
            }
            else throw std::invalid_argument("Unsupported type.");

            return vec;
        }

        /**
         * @brief Creates a pointer to a value
         * @tparam T = Type of the value
         * @param num = Value to create a pointer for
         * @return Pointer to the value
         * @example
         * int* p = CreatePtr(5); // p points to an int with value 5
         */
        template<typename T>
        T* CreatePtr(const T& num){
            return new T(num);
        }

        /**
         * @brief Loops through a vector and either increments or decrements each element
         * @param vec = Vector to modify
         * @param c = "increment" or "decrement"
         * @param i = Amount to add or subtract (must be > 0)
         * @example
         * std::vector<int> v = {1,2,3};
         * vectorLoop(v, "increment", 2); // v = {3,4,5}
         */
        void vectorLoop(std::vector<int>& vec, std::string c, int i){
            if (i <= 0){
                throw std::invalid_argument("The adding/subtracting factor cannot be lower or equal to 0!");
            }

            if (vec.empty()){
                throw std::invalid_argument("The vector shall not be empty!");
            }

            if (c == "increment"){
                for (int& number : vec){
                    number += i;
                }
            }
            else if (c == "decrement"){
                for (int& number : vec){
                    number -= i;
                }
            }
        }
    }

    // ================== dxlibRandom ==================
    namespace dxlibRandom {
        /**
         * @brief Generates a random integral number within a range [min, max].
         *
         * @tparam T Integral type (int, long, etc.)
         * @param T min = Minimum value
         * @param T max = Maximum value
         * @return T = Random integral number in the range
         * @example
         * int n = RandomNumRange(1, 6); // returns a number between 1 and 6
         */
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value, T>::type
        RandomNumRange(T min, T max) {
            if (max < min) std::swap(min, max);
            return min + rand() % (max - min + 1);
        }

        /**
         * @brief Generates a random floating-point number within a range [min, max].
         *
         * @tparam T Floating-point type (float, double)
         * @param T min = Minimum value
         * @param T max = Maximum value
         * @return T = Random floating-point number in the range
         * @example
         * double d = RandomNumRange(0.0, 1.0); // returns a number between 0.0 and 1.0
         */
        template<typename T>
        typename std::enable_if<std::is_floating_point<T>::value, T>::type
        RandomNumRange(T min, T max) {
            if (max < min) std::swap(min, max);
            return min + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX) / (max - min));
        }

        /**
         * @brief Generates a random alphanumeric string of given length.
         *
         * @param size_t len = Length of the string
         * @return string = Randomly generated string
         * @example
         * std::string s = RandomStr(10); // returns e.g., "A1b3C4dEfG"
         */
        std::string RandomStr(size_t len) {
            static const std::string chars =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";

            static std::random_device rd;
            static std::mt19937 generator(rd());
            static std::uniform_int_distribution<> distrib(0, chars.size() - 1);

            std::string result;
            result.reserve(len);

            for (size_t i = 0; i < len; i++) {
                result += chars[distrib(generator)];
            }

            return result;
        }

        /**
         * @brief Shuffles the elements of a vector.
         *
         * @tparam T Type of elements in the vector
         * @param vector<T>& vec = Vector to shuffle
         * @example
         * std::vector<int> v = {1,2,3};
         * ShuffleVect(v); // v is now randomly shuffled
         */
        template<typename T>
        void ShuffleVect(std::vector<T>& vec) {
            static std::random_device rd;
            static std::mt19937 generator(rd());
            std::shuffle(vec.begin(), vec.end(), generator);
        }

        /**
         * @brief Returns a random integral number between start and end (inclusive).
         *
         * @tparam P Integral type
         * @param P start = Start of range
         * @param P end = End of range
         * @return P = Random number in the range
         * @throws invalid_argument if start > end or type is not integral
         * @example
         * int n = Probability(1, 100); // returns a number between 1 and 100
         */
        template<typename P>
        P Probability(P start, P end) {
            if (start > end) {
                throw std::invalid_argument("Invalid Argument: (start > end)");
            } else {
                if constexpr (std::is_integral_v<P>) {
                    static std::random_device rd;
                    static std::mt19937 gen(rd());
                    std::uniform_int_distribution<P> dist(start, end);
                    return dist(gen);
                } else {
                    throw std::invalid_argument("Integral Types only.");
                }
            }
        }

        /**
         * @brief Simulates a coin flip.
         *
         * @return int = 0 for tails, 1 for heads
         * @example
         * int flip = FlipCoin(); // returns 0 or 1
         */
        int FlipCoin() {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, 1);
            return dist(gen);
        }

        /**
         * @brief Rolls a dice with a given number of sides.
         *
         * @tparam P Integral type
         * @param P sides = Number of sides on the dice
         * @return P = Result of dice roll (1 to sides)
         * @throws invalid_argument if sides <= 0
         * @example
         * int roll = RollDice(6); // returns 1..6
         */
        template<typename P>
        P RollDice(P sides) {
            if (sides <= 0) throw std::invalid_argument("Sides must be greater than 0.");

            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<P> dist(1, sides);

            return dist(gen);
        }

        /**
         * @brief Returns true with probability p.
         *
         * @param double p = Probability between 0.0 and 1.0
         * @return bool = true with probability p, false otherwise
         * @throws invalid_argument if p < 0 or p > 1
         * @example
         * bool success = Chance(0.3); // 30% chance of returning true
         */
        bool Chance(double p) {
            if (p < 0.0 || p > 1.0) throw std::invalid_argument("Chance must be between 0 and 1");

            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::bernoulli_distribution dist(p);

            return dist(gen);
        }

        /**
         * @brief Selects a random element from a vector.
         *
         * @tparam T Type of elements in the vector
         * @param const vector<T>& vec = Vector to sample from
         * @return T = Random element from the vector
         * @throws invalid_argument if the vector is empty
         * @example
         * std::vector<int> v = {1,2,3};
         * int n = SampleFromVector(v); // returns 1, 2, or 3 randomly
         */
        template<typename T>
        T SampleFromVector(const std::vector<T>& vec) {
            if (vec.empty()) throw std::invalid_argument("Vector passed should not be empty.");

            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<size_t> dist(0, vec.size() - 1);

            return vec[dist(gen)];
        }

    }


    // ================== dxlibConvert ==================
    namespace dxlibConvert {
        /**
         * @brief Converts a double to an int.
         *
         * @param const double& i = Value to convert
         * @return int = Converted integer
         * @example
         * int x = ConvertDoubleToInt(3.14); // x = 3
         */
        int ConvertDoubleToInt(const double &i) {
            return static_cast<int>(i);
        }

        /**
         * @brief Converts an int to a double.
         *
         * @param const int& i = Value to convert
         * @return double = Converted double
         * @example
         * double d = ConverIntToDouble(5); // d = 5.0
         */
        double ConverIntToDouble(const int &i) {
            return static_cast<double>(i);
        }

        /**
         * @brief Converts a float to a double.
         *
         * @param const float& i = Value to convert
         * @return double = Converted double
         * @example
         * double d = ConvertFloatToDouble(2.5f); // d = 2.5
         */
        double ConvertFloatToDouble(const float &i) {
            return static_cast<double>(i);
        }

        /**
         * @brief Converts a double to a float.
         *
         * @param const double& i = Value to convert
         * @return float = Converted float
         * @example
         * float f = ConvertDoubleToFloat(3.14); // f = 3.14f
         */
        float ConvertDoubleToFloat(const double &i) {
            return static_cast<float>(i);
        }

        /**
         * @brief Converts a float to an int.
         *
         * @param const float& i = Value to convert
         * @return int = Converted integer
         * @example
         * int x = ConvertFloatToInt(2.7f); // x = 2
         */
        int ConvertFloatToInt(const float &i) {
            return static_cast<int>(i);
        }

        /**
         * @brief Converts an int to a float.
         *
         * @param const int& i = Value to convert
         * @return float = Converted float
         * @example
         * float f = ConvertIntToFloat(5); // f = 5.0f
         */
        float ConvertIntToFloat(const int &i) {
            return static_cast<float>(i);
        }

        /**
         * @brief Converts a long to a long double.
         *
         * @param const long& i = Value to convert
         * @return long double = Converted value
         * @example
         * long double ld = ConvertLongToLongDouble(100L);
         */
        long double ConvertLongToLongDouble(const long& i) {
            return static_cast<long double>(i);
        }

        /**
         * @brief Converts a long double to a long.
         *
         * @param const long double& i = Value to convert
         * @return long = Converted value
         * @example
         * long l = ConvertLongDoubleToLong(100.5L);
         */
        long ConvertLongDoubleToLong(const long double& i) {
            return static_cast<long>(i);
        }

        /**
         * @brief Converts an int to an unsigned int.
         *
         * @param const int& i = Value to convert
         * @return unsigned int = Converted value
         * @example
         * unsigned int u = ConvertIntToUnsigned(5); // u = 5
         */
        unsigned int ConvertIntToUnsigned(const int& i) {
            return static_cast<unsigned int>(i);
        }

        /**
         * @brief Converts a const char to char.
         *
         * @param const char& i = Value to convert
         * @return char = Converted value
         * @example
         * char c = ConvertConstCharToChar('A'); // c = 'A'
         */
        char ConvertConstCharToChar(const char& i) {
            return static_cast<char>(i);
        }

        /**
         * @brief Converts a char to const char.
         *
         * @param const char& i = Value to convert
         * @return const char = Converted value
         * @example
         * const char c = ConvertCharToConstChar('A'); // c = 'A'
         */
        const char ConvertCharToConstChar(const char& i) {
            return static_cast<const char>(i);
        }

        /**
         * @brief Converts any arithmetic type to a std::string.
         *
         * @tparam T Arithmetic type (int, float, double, long, etc.)
         * @param T num = Value to convert
         * @return string = Converted string
         * @example
         * std::string s = ConvertAnyNumToString(123); // s = "123"
         */
        template<typename T>
        std::string ConvertAnyNumToString(T num) {
            return std::to_string(num);
        }

    }


    // ================== dxlibFileUtils ==================
    namespace dxlibFileUtils {
        /**
         * @brief Checks if a file exists.
         *
         * @param string filename = Path to the file
         * @return bool = True if the file exists, false otherwise
         * @example
         * bool exists = File_Exists("example.txt"); // returns true if the file exists
         */
        bool File_Exists(const std::string &filename) {
            return std::filesystem::exists(filename);
        }

        /**
         * @brief Reads the entire contents of a file into a string.
         *
         * @param string filename = Path to the file
         * @return string = Contents of the file
         * @throws runtime_error if the file cannot be opened
         * @example
         * std::string content = FileToString("example.txt");
         */
        std::string FileToString(const std::string &filename) {
            std::ifstream file(filename, std::ios::in | std::ios::binary);

            if (!file) {
                throw std::runtime_error("Failed to open file: " + filename);
            }

            std::ostringstream contents;
            contents << file.rdbuf();

            return contents.str();
        }

        /**
         * @brief Writes a string to a file, overwriting any existing content.
         *
         * @param string filename = Path to the file
         * @param string content = Content to write
         * @throws runtime_error if the file cannot be opened
         * @example
         * WriteString_ToFileAndOverWrite("example.txt", "Hello World");
         */
        void WriteString_ToFileAndOverWrite(const std::string &filename, const std::string &content) {
            std::ofstream file(filename, std::ios::out | std::ios::binary);

            if (!file) {
                throw std::runtime_error("Failed to open file for writing: " + filename);
            }

            file << content;
        }

        /**
         * @brief Writes a vector of bytes to a file, overwriting any existing content.
         *
         * @param string filename = Path to the file
         * @param vector<char>& data = Data to write
         * @throws runtime_error if the file cannot be opened
         * @example
         * std::vector<char> data = {'H','i'};
         * WriteVectorToFileAnd_Overwrite("example.bin", data);
         */
        void WriteVectorToFileAnd_Overwrite(const std::string &filename, const std::vector<char>& data) {
            std::ofstream file(filename, std::ios::out | std::ios::binary);

            if (!file) {
                throw std::runtime_error("Failed to open file for writing: " + filename);
            }

            file.write(data.data(), data.size());
        }

        /**
         * @brief Creates a new file with a given name and extension.
         *
         * @param string filename = Name of the file without extension
         * @param string filetype = File extension (e.g., "txt")
         * @throws runtime_error if the file cannot be created
         * @example
         * CreateFile("example", "txt"); // Creates "example.txt"
         */
        void CreateFile(const std::string &filename, const std::string &filetype) {
            std::string fullName = filename + "." + filetype;

            std::ofstream file(fullName);

            if (!file) {
                throw std::runtime_error("Failed to create file: " + fullName);
            }
        }

        /**
         * @brief Deletes an existing file.
         *
         * @param string filename = Path to the file
         * @throws runtime_error if the file does not exist or cannot be deleted
         * @example
         * DeleteFile("example.txt");
         */
        void DeleteFile(const std::string &filename) {
            if (!std::filesystem::remove(filename)) {
                throw std::runtime_error("Failed to delete file or file does not exist: " + filename);
            }
        }

        /**
         * @brief Copies a file to a new location, overwriting if it already exists.
         *
         * @param string source = Source file path
         * @param string destination = Destination file path
         * @throws runtime_error if the file cannot be copied
         * @example
         * CopyFile("example.txt", "backup.txt");
         */
        void CopyFile(const std::string &source, const std::string &destination) {
            try {
                std::filesystem::copy_file(source, destination, std::filesystem::copy_options::overwrite_existing);
            } catch (const std::filesystem::filesystem_error &e) {
                throw std::runtime_error("Failed to copy file: " + std::string(e.what()));
            }
        }

        /**
         * @brief Renames an existing file.
         *
         * @param string oldName = Current file path
         * @param string newName = New file path
         * @throws runtime_error if the file cannot be renamed
         * @example
         * RenameFile("example.txt", "example_old.txt");
         */
        void RenameFile(const std::string& oldName, const std::string &newName) {
            try {
                std::filesystem::rename(oldName, newName);
            } catch (const std::filesystem::filesystem_error &e) {
                throw std::runtime_error("Failed to rename file: " + std::string(e.what()));
            }
        }

    }


    // ================== dxlibMath ==================
    namespace dxlibMath {
        /// @brief Constant value of Pi
        constexpr double PI = 3.14159265358979323846;

        /**
         * @brief Converts degrees to radians.
         *
         * @param double deg = Angle in degrees
         * @return double = Angle in radians
         * @example
         * double rad = DegToRad(180); // returns 3.141592653589793
         */
        double DegToRad(double deg) {
            return deg * PI / 180.0;
        }

        /**
         * @brief Computes the sine of an angle in degrees.
         *
         * @param double aid = Angle in degrees
         * @return double = Sine of the angle
         * @example
         * double s = Sin(30); // returns 0.5
         */
        double Sin(double aid) {
            return std::sin(DegToRad(aid));
        }

        /**
         * @brief Computes the cosine of an angle in degrees.
         *
         * @param double aid = Angle in degrees
         * @return double = Cosine of the angle
         * @example
         * double c = Cos(60); // returns 0.5
         */
        double Cos(double aid) {
            return std::cos(DegToRad(aid));
        }

        /**
         * @brief Computes the tangent of an angle in degrees.
         *
         * @param double aid = Angle in degrees
         * @return double = Tangent of the angle
         * @example
         * double t = Tan(45); // returns 1
         */
        double Tan(double aid) {
            return std::tan(DegToRad(aid));
        }

        /**
         * @brief Performs arithmetic operations between two numbers.
         *
         * Supports addition (+), subtraction (-), multiplication (*), division (/),
         * and a special operation "/*-".
         *
         * @tparam T Arithmetic type (int, float, double, etc.)
         * @param T a = First operand
         * @param T b = Second operand
         * @param string type = Operator type: "+", "-", "*", "/", or "/*-"
         * @return T = Result of the operation
         * @example
         * int result = Operators(4, 2, "+"); // returns 6
         */
        template<typename T>
        typename std::enable_if<std::is_arithmetic<T>::value, T>::type
        Operators(T a, T b, const std::string& type) {
            if (type == "+") return a + b;
            else if (type == "-") return a - b;
            else if (type == "*") return a * b;
            else if (type == "/") {
                if (b == 0)
                    throw std::invalid_argument("Division by zero '/' operation invalid.");
                return a / b;
            } else if (type == "/*-") {
                if (b == 0)
                    throw std::invalid_argument("Division by zero '/*-' operation invalid.");
                double result = static_cast<double>(a / b) * b * std::pow(static_cast<double>(a), 2) - (a - b);
                return static_cast<T>(result);
            }

            throw std::invalid_argument("Invalid operator type. Enter +, -, *, /, or /*-");
        }

        /**
         * @brief Multiplies all numbers in a vector.
         *
         * @param const vector<double>& numbers = Vector of numbers
         * @return double = Product of all numbers
         * @example
         * double prod = MultNums({2.0, 3.0, 4.0}); // returns 24.0
         */
        double MultNums(const std::vector<double> &numbers) {
            double result = 1;
            for (double num : numbers) {
                result *= num;
            }
            return result;
        }

        /**
         * @brief Raises a number to an integer power.
         *
         * @param double b = Base
         * @param int e = Exponent
         * @return double = b raised to the power e
         * @example
         * double r = pwr(2, 3); // returns 8
         */
        double pwr(double b, int e) {
            double r = 1;
            for (int i = 0; i < e; i++) {
                r *= b;
            }
            return r;
        }

        /**
         * @brief Computes the factorial of a number.
         *
         * @param unsigned int n = Number to compute factorial of
         * @return unsigned long long = Factorial result
         * @example
         * unsigned long long f = Factorial(5); // returns 120
         */
        unsigned long long Factorial(unsigned int n) {
            unsigned long long result = 1;
            for (unsigned int i = 2; i <= n; ++i) {
                result *= i;
            }
            return result;
        }

        /**
         * @brief Computes the greatest common divisor (GCD) of two integers.
         *
         * @param int a = First integer
         * @param int b = Second integer
         * @return int = Greatest common divisor
         * @example
         * int g = GCD(12, 18); // returns 6
         */
        int GCD(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        /**
         * @brief Computes the least common multiple (LCM) of two integers.
         *
         * @param int a = First integer
         * @param int b = Second integer
         * @return int = Least common multiple
         * @example
         * int l = LCM(4, 6); // returns 12
         */
        int LCM(int a, int b) {
            return (a / GCD(a, b)) * b;
        }

    }

    // ================== dxlibTime ==================
    namespace dxlibTime {
        /**
         * @brief Formats a std::tm structure into a string according to a given format.
         *
         * @param const std::tm& tm = Time structure to format
         * @param string format = Format string (default: "%Y-%m-%d : %H:%M:%S")
         * @return string = Formatted date/time string
         * @example
         * std::tm t{};
         * std::string formatted = FormatDate(t, "%Y/%m/%d %H:%M");
         * // returns "1970/01/01 00:00" if t is initialized to zero
         */
        std::string FormatDate(const std::tm& tm, const std::string &format = "%Y-%m-%d : %H:%M:%S") {
            std::ostringstream oss;
            oss << std::put_time(&tm, format.c_str());
            return oss.str();
        }

        /**
         * @brief Pauses execution for a given amount of time.
         *
         * @param string type = Unit of time: "s" for seconds, "ms" for milliseconds, "mc" for microseconds, "nms" for nanoseconds
         * @param int global_sec = Amount of time to sleep
         * @example
         * sleepfor("s", 2); // Sleeps for 2 seconds
         * sleepfor("ms", 500); // Sleeps for 500 milliseconds
         */
        void sleepfor(std::string type, int global_sec) {
            if (type == "s") {
                std::this_thread::sleep_for(std::chrono::seconds(global_sec));
            } else if (type == "ms") {
                std::this_thread::sleep_for(std::chrono::milliseconds(global_sec));
            } else if (type == "nms") {
                std::this_thread::sleep_for(std::chrono::nanoseconds(global_sec));
            } else if (type == "mc") {
                std::this_thread::sleep_for(std::chrono::microseconds(global_sec));
            } else {
                throw std::invalid_argument("Invalid type. Please enter 's', 'ms', 'nms', or 'mc'");
            }
        }

        /**
         * @brief Retrieves the current local time of the system as a formatted string.
         *
         * @return string = Current local time formatted as "%Y-%m-%d : %H:%M:%S"
         * @example
         * std::string now = GetLocalTime();
         * // returns e.g., "2025-08-28 : 14:35:42"
         */
        std::string GetLocalTime() {
            auto now = std::chrono::system_clock::now();
            std::time_t now_time = std::chrono::system_clock::to_time_t(now);
            std::tm local_tm;

            #ifdef _WIN32
                localtime_s(&local_tm, &now_time);
            #else
                localtime_r(&now_time, &local_tm);
            #endif

            std::ostringstream oss;
            oss << std::put_time(&local_tm, "%Y-%m-%d : %H:%M:%S");
            return oss.str();
        }

        /**
         * @brief Adds a number of seconds to a given time structure.
         *
         * @param const std::tm& tm = Original time structure
         * @param int secondsToAdd = Number of seconds to add
         * @return std::tm = New time structure with added seconds
         * @example
         * std::tm t{};
         * std::tm new_t = AddSecToTime(t, 3600); // Adds 1 hour
         */
        std::tm AddSecToTime(const std::tm& tm, int secondsToAdd) {
            std::time_t time = std::mktime(const_cast<std::tm*>(&tm));
            time += secondsToAdd;
            std::tm new_tm;

            #ifdef _WIN32
                localtime_s(&new_tm, &time);
            #else
                localtime_r(&time, &new_tm);
            #endif

            return new_tm;
        }

    }

    // ================== dxlibPrint ==================
    namespace dxlibPrint {
        /**
         * @brief Prints a message to the terminal.
         *
         * @param string text = Message to print
         * @param bool endl = Whether to add a newline at the end (default: true)
         * @example
         * printline("Hello World"); // Outputs "Hello World" with a newline
         * printline("Hello", false); // Outputs "Hello" without a newline
         */
        void printline(std::string text, bool endl = true) {
            if (endl) {
                std::cout << text << std::endl;
            } else if (!endl) {
                std::cout << text;
            } else {
                throw std::invalid_argument("Please enter true or false on the second argument.");
            }
        }

        /**
         * @brief Prints a string with placeholders replaced using a map of key-value pairs.
         *
         * Placeholders are wrapped with '-' characters. The map specifies the replacement values
         * for each placeholder key.
         *
         * @param string text = String containing placeholders
         * @param unordered_map<string, string>& vars = Map of placeholder keys and their replacements
         * @param bool nl = Whether to add a newline after printing (default: true)
         * @example
         * std::unordered_map<std::string, std::string> vars = {{"name", "Alice"}};
         * printVar("Hello, -name-!", vars); // Outputs "Hello, Alice!"
         */
        void printVar(std::string text, const std::unordered_map<std::string, std::string>& vars, bool nl = true) {
            size_t pos = 0;

            while ((pos = text.find('-', pos)) != std::string::npos) {
                size_t end = text.find('-', pos + 1);
                if (end == std::string::npos) break;

                std::string key = text.substr(pos + 1, end - pos - 1);

                auto it = vars.find(key);
                if (it != vars.end()) {
                    text.replace(pos, end - pos + 1, it->second);
                    pos += it->second.length();
                } else {
                    pos = end + 1;
                }
            }

            if (nl) {
                std::cout << text << std::endl;
            } else {
                std::cout << text;
            }
        }

        // Variadic template helper (internal)
        namespace {
            void printVar_helper(std::string& text) {
                std::cout << text << std::endl;
            }

            template<typename T, typename... Args>
            void printVar_helper(std::string& text, T&& firstArg, Args&&... restArgs) {
                size_t start = text.find('-');
                if (start == std::string::npos) {
                    std::cout << text << std::endl;
                    return;
                }

                size_t end = text.find('-', start + 1);
                if (end == std::string::npos) {
                    std::cout << text << std::endl;
                    return;
                }

                std::string before = text.substr(0, start);
                std::string after = text.substr(end + 1);

                std::ostringstream oss;
                oss << firstArg;
                std::string replacement = oss.str();

                text = before + replacement + after;

                printVar_helper(text, std::forward<Args>(restArgs)...);
            }
        }

        /**
         * @brief Prints a string with placeholders replaced by provided variables.
         *
         * Placeholders are wrapped with '-' characters. Variables are inserted sequentially
         * into each placeholder.
         *
         * @tparam Args Variadic arguments to replace placeholders
         * @param string text = String containing placeholders
         * @param Args&&... args = Variables to replace placeholders
         * @example
         * std::string name = "Alice";
         * printVar("Hello, -name-!", name); // Outputs "Hello, Alice!"
         */
        template<typename... Args>
        void printVar(std::string text, Args&&... args) {
            printVar_helper(text, std::forward<Args>(args)...);
        }

        /**
         * @brief Asks the user for input of any type and validates it.
         *
         * Keeps prompting until valid input is entered.
         *
         * @tparam T Type of input to request
         * @param string ques = Question to display to the user
         * @param bool nl = Whether to add a newline after the question (default: true)
         * @return T = User input of type T
         * @example
         * int age = askInput<int>("Enter your age: "); // Prompts user until a valid integer is entered
         */
        template<typename T>
        T askInput(const std::string& ques, bool nl = true) {
            T input{};

            while (true) {
                if (nl) std::cout << ques << std::endl;
                else std::cout << ques;

                std::cin >> input;

                if (dxlibMain::CinFail()) {
                    std::cin.clear(); // reset failbit
                    dxlibMain::ClearBuffer(); // flush input
                    std::cout << "Invalid input. Please try again.\n";
                } else {
                    dxlibMain::ClearBuffer(); // flush remaining
                    return input;
                }
            }
        }

    }


    // ================== dxlibText ==================
    namespace dxlibText {
        /**
         * @brief Checks if a string starts with a given prefix.
         *
         * @param string str = String to check
         * @param string prefix = Prefix to search for
         * @example
         * startsWith("hello world", "hello"); returns true
         * startsWith("hello world", "world"); returns false
         */
        bool startsWith(const std::string &str, const std::string &prefix){
            return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
        }

        /**
         * @brief Checks if a string ends with a given suffix.
         *
         * @param string str = String to check
         * @param string suffix = Suffix to search for
         * @example
         * endsWith("hello world", "world"); returns true
         * endsWith("hello world", "hello"); returns false
         */
        bool endsWith(const std::string &str, const std::string &suffix){
            return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
        }

        /**
         * @brief Changes the case of a string.
         *
         * @param string& s = String to modify
         * @param string type = Type of case change: "lower", "upper", or "randomized"
         * @example
         * std::string text = "Hello";
         * ChangeCase(text, "lower"); // text = "hello"
         * ChangeCase(text, "upper"); // text = "HELLO"
         */
        void ChangeCase(std::string& s, std::string type){
            if (type == "lower"){
                std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            }
            else if (type == "upper") {
                std::transform(s.begin(), s.end(), s.begin(), ::toupper);
            }
            else if (type == "randomized"){
                static std::random_device rd;
                static std::mt19937 gen(rd());
                static std::uniform_int_distribution<> dist(0, 1);

                for (auto& ch : s){
                    if (std::isalpha(static_cast<unsigned char>(ch))) {
                        if (dist(gen) == 0){
                            ch = static_cast<char>(std::tolower(ch));
                        }
                        else {
                            ch = static_cast<char>(std::toupper(ch));
                        }
                    }
                }
            }
            else {
                throw std::invalid_argument("Invalid Type. Enter either lower, upper, or randomized");
            }
        }

        /**
         * @brief Splits a string using a delimiter.
         *
         * @param string str = String to split
         * @param char delimiter = Character to split on
         * @example
         * Split("a,b,c", ','); returns {"a", "b", "c"}
         */
        std::vector<std::string> Split(const std::string& str, char delimiter){
            std::vector<std::string> tokens;
            std::stringstream ss(str);
            std::string token;

            while (std::getline(ss, token, delimiter)){
                tokens.push_back(token);
            }

            return tokens;
        }

        /**
         * @brief Joins a vector of strings using a delimiter.
         *
         * @param vector<string> parts = Parts to join
         * @param string delim = Delimiter to insert between parts
         * @example
         * Join({"a", "b", "c"}, "-"); returns "a-b-c"
         */
        std::string Join(const std::vector<std::string>& parts, const std::string& delim){
            std::ostringstream oss;

            for (size_t i = 0; i < parts.size(); i++){
                oss << parts[i];
                if (i < parts.size() - 1) oss << delim;
            }

            return oss.str();
        }

        /**
         * @brief Removes all leading and trailing whitespaces from a string.
         *
         * @param string& str = String to trim
         * @example
         * std::string text = "  hello  ";
         * TrimString(text); returns "hello"
         */
        std::string TrimString(std::string& str){
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {return !std::isspace(ch);}));
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch){return !std::isspace(ch);}).base(), str.end());
            return str;
        }

        /**
         * @brief Reverses the contents of a string.
         *
         * @param string& str = String to reverse
         * @example
         * std::string text = "abc";
         * ReverseString(text); returns "cba"
         */
        std::string ReverseString(std::string &str){
            std::reverse(str.begin(), str.end());
            return str;
        }

        /**
         * @brief Removes leading whitespaces from a string.
         *
         * @param string& str = String to trim
         * @example
         * std::string text = "  hello";
         * LTrim(text); returns "hello"
         */
        std::string LTrim(std::string& str){
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch){return !std::isspace(ch);}));
            return str;
        }

        /**
         * @brief Removes trailing whitespaces from a string.
         *
         * @param string& str = String to trim
         * @example
         * std::string text = "hello  ";
         * RTrim(text); returns "hello"
         */
        std::string RTrim(std::string& str){
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch){return !std::isspace(ch);}).base(), str.end());
            return str;
        }

        /**
         * @brief Capitalizes the first letter of every word in a string.
         *
         * @param string& str = String to modify
         * @example
         * std::string text = "hello world";
         * CapitalizeWords(text); text becomes "Hello World"
         */
        void CapitalizeWords(std::string& str) {
            bool capitalizeNext = true;

            for (char& c : str) {
                if (std::isspace(static_cast<unsigned char>(c))) {
                    capitalizeNext = true;
                } else if (capitalizeNext) {
                    c = std::toupper(static_cast<unsigned char>(c));
                    capitalizeNext = false;
                } else {
                    c = std::tolower(static_cast<unsigned char>(c));
                }
            }
        }

    }

    // ================== dxlibDebug ==================
    namespace dxlibDebug {
        /**
         * @enum LogLevel
         * @brief Defines the severity level of log messages.
         */
        enum class LogLevel {
            INFO,   /**< Informational messages */
            WARN,   /**< Warning messages */
            ERRORS  /**< Error messages */
        };

        /**
         * @brief Logs a message to the console with an optional severity level.
         *
         * @param string msg = Message to log
         * @param LogLevel level = Severity of the log (default: INFO)
         * @example
         * log("Application started"); outputs "[INFO] Application started"
         * log("File missing", LogLevel::WARN); outputs "[WARN] File missing"
         */
        void log(const std::string& msg, LogLevel level = LogLevel::INFO) {
            std::string prefix;

            switch (level) {
                case LogLevel::INFO: prefix = "[INFO]"; break;
                case LogLevel::WARN: prefix = "[WARN]"; break;
                case LogLevel::ERRORS: prefix = "[ERROR]"; break;
            }

            std::cout << prefix << " " << msg << std::endl;
        }

        /**
         * @brief Triggers a debugger break, stopping code execution if a debugger is attached.
         *
         * Works on both Windows and Linux.
         * @example
         * debugBreak(); // Breaks into debugger at this point
         */
        void debugBreak() {
        #ifdef _WIN32
            __debugbreak(); // MSVC
        #else
            std::raise(SIGTRAP); // Linux
        #endif
        }

        /**
         * @brief Checks a condition and logs an error if it fails, then exits the program.
         *
         * @param bool cond = Condition to check
         * @param string msg = Message to log if assertion fails
         * @example
         * assertLog(1 + 1 == 2, "Math failed"); // Does nothing
         * assertLog(1 + 1 == 3, "Math failed"); // Logs "[ASSERT FAIL] Math failed" and exits
         */
        void assertLog(bool cond, const std::string& msg) {
            if (!cond) {
                log("[ASSERT FAIL] " + msg, LogLevel::ERRORS);
                std::exit(EXIT_FAILURE);
            }
            // No action if condition passes
        }

        /**
         * @brief Measures and logs the time taken by a function in milliseconds.
         *
         * @param string label = Label to identify the timing log
         * @param function func = Function to execute and time
         * @example
         * timeLog("Heavy calculation", [](){
         *     for(int i = 0; i < 1000000; i++);
         * });
         * // Outputs something like "Heavy calculation took 12.345 ms"
         */
        void timeLog(const std::string& label, const std::function<void()>& func) {
            auto start = std::chrono::high_resolution_clock::now();
            func(); // run user function
            auto end = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            double ms = duration / 1000.0;

            log(label + " took " + std::to_string(ms) + " ms");
        }

    }

    // ================== dxlibCheck ==================
    namespace dxlibCheck {
        /**
         * @brief Checks if a number is even
         *
         * @tparam Template for flexibility
         * @param num = value to check if it is even
         * @example
         * isEven(2); returns true because 2 is an even number
         */
        template<typename T>
        bool isEven(T num){
            return num % 2 == 0;
        }

        /**
         * @brief Checks if a number is odd
         *
         * @tparam Template for flexibility
         * @param num = value to check if it is odd
         * @example
         * isOdd(3); returns true because 3 is an odd number
         */
        template<typename T>
        bool isOdd(T num){
            return num % 2 != 0;
        }

        /**
         * @brief Checks if a string contains only numeric characters
         *
         * @param string s = string to check for numeric content
         * @example
         * isNumeric("123"); returns true because all characters are digits
         */
        bool isNumeric(const std::string& s){
            return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
        }

        /**
         * @brief Checks if a string contains only alphabetic characters
         *
         * @param string s = string to check for letters only
         * @example
         * isAlpha("abcdef"); returns true because all characters are letters
         */
        bool isAlpha(const std::string& s){
            return !s.empty() && std::all_of(s.begin(), s.end(), ::isalpha);
        }

        /**
         * @brief Checks if a string is alphanumeric (letters and digits)
         *
         * @param string s = string to check for alphanumeric content
         * @example
         * isAllNum("password2904"); returns true because it contains letters and numbers
         */
        bool isAllNum(const std::string& s){
            return !s.empty() && std::all_of(s.begin(), s.end(), ::isalnum);
        }

        /**
         * @brief Checks if a string represents a valid float
         *
         * @param const std::string& s = string to check for float format
         * @example
         * isFloatString("3.14"); returns true because it is a valid float
         */
        bool isFloatString(const std::string& s){
            std::istringstream iss(s);
            float f;
            return (iss >> f) && iss.eof();
        }

        /**
         * @brief Checks if a string represents a valid double
         *
         * @param const std::string& s = string to check for double format
         * @example
         * isDoubleString("3.14159"); returns true because it is a valid double
         */
        bool isDoubleString(const std::string& s){
            std::istringstream iss(s);
            double d;
            return (iss >> d) && iss.eof();
        }

        /**
         * @brief Checks if a number is within a closed range [min, max]
         *
         * @tparam Template for flexibility
         * @param value = number to check
         * @param min = minimum bound
         * @param max = maximum bound
         * @example
         * isInRange(10, 5, 20); returns true because 10 is between 5 and 20
         */
        template<typename T>
        bool isInRange(T value, T min, T max){
            return value >= min && value <= max;
        }

        /**
         * @brief Checks if a number is prime
         *
         * @param n = number to check for primality
         * @example
         * isPrime(5); returns true because 5 is a prime number
         */
        bool isPrime(int n){
            if (n <= 1) return false;
            for (int i = 2; i * i <= n; ++i){
                if (n % i == 0) return false;
            }
            return true;
        }

        /**
         * @brief Checks if a string is a palindrome
         *
         * @param const std::string& s = string to check
         * @example
         * isPalindrome("level"); returns true because it reads the same forwards and backwards
         */
        bool isPalindrome(const std::string& s){
            return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
        }

        /**
         * @brief Checks if a string contains only whitespace characters
         *
         * @param const std::string& s = string to check
         */
        bool isWhiteSpaceOnly(const std::string& s){
            return std::all_of(s.begin(), s.end(), ::isspace);
        }

        /**
         * @brief Checks if a number is zero
         *
         * @tparam Template for flexibility
         * @param num = number to check
         * @example
         * int a = 0; isZero(a); returns true
         */
        template<typename T>
        bool isZero(T num){
            return num == 0;
        }

        /**
         * @brief Checks if one number is half of another
         *
         * @tparam Template for flexibility
         * @param num = first number
         * @param other = second number
         * @example
         * isHalf(10, 5); returns true because 10 / 2 = 5
         */
        template<typename T>
        bool isHalf(T num, T other){
            return static_cast<double>(num) / 2.0 == static_cast<double>(other);
        }

        /**
         * @brief Checks if a number multiplied by 2 equals another
         *
         * @tparam Template for flexibility
         * @param num = first number
         * @param other = second number
         * @example
         * isMultTwo(10, 20); returns true because 10 * 2 = 20
         */
        template<typename T>
        bool isMultTwo(T num, T other){
            return num * 2 == other;
        }

        /**
         * @brief Checks if two numbers are equal
         *
         * @tparam Template for flexibility
         * @param num = first number
         * @param other = second number
         * @example
         * int a = 10; int b = 10; isEqual(a, b); returns true
         */
        template<typename T>
        bool isEqual(T num, T other){
            return num == other;
        }

        /**
         * @brief Checks if a number is greater than the result of an operation on two others
         *
         * @tparam T = type of main number
         * @tparam A = type of operand numbers
         * @param what = operation: "add", "sub", "mult", or "div"
         * @param n1 = main number to compare
         * @param n2 = first operand
         * @param n3 = second operand
         * @example
         * isOverTwoNumbersCombined("add", 10, 4, 5); returns true because 10 > 9
         */
        template<typename T, typename A>
        bool isOverTwoNumbersCombined(const std::string& what, T n1, A n2, A n3){
            if (std::set<std::string>{"add","ad","addd","aad"}.count(what)){
                return n1 > n2 + n3;
            } else if (std::set<std::string>{"sub","sb","ssub","suub","subb"}.count(what)){
                return n1 > n2 - n3;
            } else if (std::set<std::string>{"mult","multiply","multiplication","mlt","multt"}.count(what)){
                return n1 > n2 * n3;
            } else if (std::set<std::string>{"div","divide","division","divv","diiv","ddiv"}.count(what)){
                if (n3 == 0) throw std::invalid_argument("Divide by 0 error.");
                return n1 > n2 / n3;
            } else {
                throw std::invalid_argument("Please enter \"add\", \"sub\", \"mult\", or \"div\".");
            }
        }

        /**
         * @brief Checks if a number is less than the result of an operation on two others
         *
         * @tparam T = type of main number
         * @tparam A = type of operand numbers
         * @param what = operation: "add", "sub", "mult", or "div"
         * @param n1 = main number to compare
         * @param n2 = first operand
         * @param n3 = second operand
         * @example
         * isLessThanTwoNumbersCombined("sub", 10, 30, 10); returns true because 10 < 20
         */
        template<typename T, typename A>
        bool isLessThanTwoNumbersCombined(const std::string& what, T n1, A n2, A n3){
            if (std::set<std::string>{"add","ad","addd","aad"}.count(what)){
                return n1 < n2 + n3;
            } else if (std::set<std::string>{"sub","sb","ssub","suub","subb"}.count(what)){
                return n1 < n2 - n3;
            } else if (std::set<std::string>{"mult","multiply","multiplication","mlt","multt"}.count(what)){
                return n1 < n2 * n3;
            } else if (std::set<std::string>{"div","divide","division","divv","diiv","ddiv"}.count(what)){
                if (n3 == 0) throw std::invalid_argument("Divide by 0 error.");
                return n1 < n2 / n3;
            } else {
                throw std::invalid_argument("Please enter \"add\", \"sub\", \"mult\", or \"div\".");
            }
        }
    }
}

#endif // DX_H

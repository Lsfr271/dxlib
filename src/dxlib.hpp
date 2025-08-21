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
        /*
        * CinFail(): Accepts no arguments, checks if a std::cin failed.
        */
        bool CinFail(){
            if (std::cin.fail()){
                return true;
            }
            else {
                return false;
            }
        }

        /*
        * ClearBuffer(): Clears left over buffer left from a std::endl
        */
        void ClearBuffer(){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        /* Pause(): Pauses the program */
        void Pause(const std::string&msg = "Press enter to continue...."){
            std::cout << msg;
            ClearBuffer();
            std::cin.get();
        }

        /* YesNoPrompt(): Asks for yes or no */
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

        /* ClearScreen(): clears console screen */
        void ClearScreen() {
            #ifdef _WIN32 // windows
                system("cls");
            #else
                system("clear"); // possibly linux/mac
            #endif
        }

        /* mVect: multiplies all elements in a vector. mVect = multiply vector */
        std::vector<int> mVect(std::vector<int>& vec, int mult){
            if (mult <= 0){
                throw std::invalid_argument("The multiplier cannot <= 0");
            }

            for (size_t i = 0; i < vec.size(); ++i){
                vec[i] *= mult;
            }

            return vec;
        }

        /* PrintVector(): Prints all the vectors elements */
        void PrintVector(const std::vector<int>& vec, bool newline=true){
            for (const auto& v : vec){
                std::cout << v << " ";
            }

            if (newline) std::cout << "\n";
        }

        template<typename V>
        void swap(V&a, V&b){
            V temp = a;
            a = b;
            b = temp;
        }

        /* CountChar(): Counts how many of a specific char has appeared in a string */
        int CountChar(const std::string& str, char c){
            return std::count(str.begin(), str.end(), c);
        }

        /* IsPowerOfTwo(): Returns true if a number is a power of two */
        template<typename T>
        bool IsPowerOfTwo(T n){
            return n > 0 && (n & (n -1)) == 0;
        }

        /* ReverseVector(): reverses a vector in place */
        template<typename T>
        void ReverseVector(std::vector<T>& vec){
            std::reverse(vec.begin(), vec.end());
        }

        /* SortVector(): Sorts a vector from lowest to highest or highest to lowest depending on an argument */
        void SortVector(std::vector<int>& vec, std::string arrange){
            if (arrange == "lth"){ // lth = lowest to highest
                std::sort(vec.begin(), vec.end());
            }
            else if (arrange == "htl"){ // htl == highest to lowest
                std::sort(vec.begin(), vec.end(), std::greater<int>());
            }
            else {
                throw std::invalid_argument("Please enter either 'lth' or 'htl' on the arrange argument");
            }
        }

        /* SumVector(): Sums all the elements in a vector */
        int SumVector(const std::vector<int>& vec){
            return std::accumulate(vec.begin(), vec.end(), 0);
        }

        /* AbsVal(): Gets the absoulute value of a number */
        template<typename A>
        A AbsVal(A x){
            return (x < 0) ? -x : x;
        }

        /* GenerateRandomVector(): Generates a random vector and its size depends on the argument (vectorSize) */
        // string generator helper because RandomStr() is in dxlibRandom which isnt declared yet
        std::string random_string(size_t length) {
            const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, chars.size() -1);

            std::string result;

            for (size_t i = 0; i < length; ++i) {
                result += chars[dist(gen)];
            }

            return result;
        }

        template<typename T>
        std::vector<T> GenerateRandomVector(size_t vectorSize){
            std::vector<T> vec;
            vec.reserve(vectorSize);

            std::random_device rd;
            std::mt19937 gen(rd());

            if constexpr (std::is_integral<T>::value){
                std::uniform_int_distribution<T> dist(0, 100);

                for (size_t i = 0; i < vectorSize; ++i){
                    vec.push_back(dist(gen));
                }
            }
            else if constexpr (std::is_floating_point<T>::value){
                std::uniform_int_distribution<T> dist(0.0, 100.0);

                for (size_t i = 0; i < vectorSize; ++i){
                    vec.push_back(dist(gen));
                }
            }
            else if constexpr (std::is_same<T, std::string>::value){
                for (size_t i = 0; i < vectorSize; ++i){
                    vec.push_back(random_string(5));
                }
            }
            else {
                throw std::invalid_argument("Unsupported type.");
            }

            return vec;
        }

        /* CreatePtr(): Creates a pointer (usually for memory handling) */
        template<typename T>
        T* CreatePtr(const T& num){
            return new T(num);
        }

        // vectorLoop(): Loops through a vector and either increments/decrement the values
        void vectorLoop(std::vector<int>& vec, std::string c, int i){
            // checks
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
        /*
        * RandomNumRange(): Picks a random number from a decimal number or a whole number and returns it
        */
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value, T>::type
        RandomNumRange(T min, T max){
            if (max < min) std::swap(min, max);
            return min + rand() % (max - min + 1);
        }

        template<typename T>
        typename std::enable_if<std::is_floating_point<T>::value, T>::type
        RandomNumRange(T min, T max){
            if (max < min) std::swap(min, max);
            return min + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX) / (max - min));
        }

        /*
        * RandomStr(): Generates a string depending on its length argument (len)
        */
        std::string RandomStr(size_t len){
            static const std::string chars =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";

            static std::random_device rd;
            static std::mt19937 generator(rd());
            static std::uniform_int_distribution<> distrib(0, chars.size() -1);

            std::string result;
            result.reserve(len);

            for (size_t i = 0; i < len; i++){
                result += chars[distrib(generator)];
            }

            return result;
        }

        /*
        * ShuffleVect(): Shuffles the elements of a vector.
        */
        template<typename T>
        void ShuffleVect(std::vector<T>& vec){
            static std::random_device rd;
            static std::mt19937 generator(rd());

            std::shuffle(vec.begin(), vec.end(), generator);
        }

        /* Gets a probability from the start to the end */
        template<typename P>
        P Probability(P start, P end){
            if (start > end){
                throw std::invalid_argument("Invalid Argument: (start > end)");
            }
            else {
                if constexpr (std::is_integral_v<P>){
                    static std::random_device rd;
                    static std::mt19937 gen(rd());
                    std::uniform_int_distribution<P> dist(start, end);

                    return dist(gen);
                }
                else {
                    throw std::invalid_argument("Integral Types only.");
                }
            }
        }

        /* FLips a coin either head/tails */
        int FlipCoin() {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, 1);

            return dist(gen);
        }

        /* rolls a dice depending on the given number of sides */
        template<typename P>
        P RollDice(P sides){
            if (sides <= 0) throw std::invalid_argument("Sides must be greater than 0.");

            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<P> dist(1, sides);

            return dist(gen);
        }

        /* Gets a random number from 0 to 1 (double) */
        bool Chance(double p){
            if (p < 0.0 || p > 1.0) throw std::invalid_argument("Chance must be between 0 and 1");

            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::bernoulli_distribution dist(p);

            return dist(gen);
        }

        /* Grabs a random element from a vector */
        template<typename T>
        T SampleFromVector(const std::vector<T>& vec){
            if (vec.empty()) throw std::invalid_argument("Vector passed should not be empty.");

            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<size_t> dist(0, vec.size() -1);

            return vec[dist(gen)];
        }
    }

    // ================== dxlibConvert ==================
    namespace dxlibConvert {
        // Converts a double to an int
        int ConvertDoubleToInt(const double &i){
            return static_cast<int>(i);
        }

        // Converts a int to an double
        double ConverIntToDouble(const int &i){
            return static_cast<double>(i);
        }

        // Converts a float to an double
        double ConvertFloatToDouble(const float &i){
            return static_cast<double>(i);
        }

        // Converts a double to an float
        float ConvertDoubleToFloat(const double &i){
            return static_cast<float>(i);
        }

        // Converts a float to an int
        int ConvertFloatToInt(const float &i){
            return static_cast<int>(i);
        }

        // converts a int to a float
        int ConvertIntToFloat(const int &i){
            return static_cast<float>(i);
        }

        // Converts any arithmetic type (int, float, double, long, long long, etc) to std::string
        template<typename T>
        std::string ConvertAnyNumToString(T num){
            return to_string(num);
        }
    }

    // ================== dxlibFileUtils ==================
    namespace dxlibFileUtils {
        // Checks if the file exists
        bool File_Exists(const std::string &filename){
            return std::filesystem::exists(filename);
        }

        // read entire file and convert to string
        std::string FileToString(const std::string &filename){
            std::ifstream file(filename, std::ios::in | std::ios::binary);

            if (!file){
                throw std::runtime_error("Failed to open file: " + filename);
            }

            std::ostringstream contents;
            contents << file.rdbuf();

            return contents.str();
        }

        // write a string to file (overwrite)
        void WriteString_ToFileAndOverWrite(const std::string &filename, const std::string &content){
            std::ofstream file(filename, std::ios::out | std::ios::binary);

            if (!file){
                throw std::runtime_error("Failed to open file for writing: " + filename);
            }

            file << content;
        }

        // write a vector<char> to a file (overwrite)
        void WriteVectorToFileAnd_Overwrite(const std::string &filename, const std::vector<char>&data){
            std::ofstream file(filename, std::ios::out | std::ios::binary);

            if (!file){
                throw std::runtime_error("Failed to open file for writing: " + filename);
            }

            file.write(data.data(), data.size());
        }

        // ================== dxlibFileOperations ==================
        namespace dxlibFileOperations {
            // creates a file
            void CreateFile(const std::string &filename, const std::string &filetype){
                std::string fullName = filename + "." + filetype;

                std::ofstream file(fullName);

                if (!file){
                    throw std::runtime_error("Failed to create file: " + fullName);
                }
                // file created and closes, so no extra code needed
            }

            // deletes an existing file
            void DeleteFile(const std::string &filename){
                if (!std::filesystem::remove(filename)){
                    throw std::runtime_error("Failed to delete file or file does not exist: " + filename);
                }
            }

            // copies a files contents
            void CopyFile(const std::string &source, const std::string &destination){
                try {
                    std::filesystem::copy_file(source, destination, std::filesystem::copy_options::overwrite_existing);
                } catch (const std::filesystem::filesystem_error &e){
                    throw std::runtime_error("Failed to copy file: " + std::string(e.what()));
                }
            }

            // renames an existing file
            void RenameFile(const std::string& oldName, const std::string &newName){
                try {
                    std::filesystem::rename(oldName, newName);
                } catch (const std::filesystem::filesystem_error &e){
                    throw std::runtime_error("Failed to rename file: " + std::string(e.what()));
                }
            }
        }
    }

    // ================== dxlibMath ==================
    namespace dxlibMath {
        constexpr double PI = 3.14159265358979323846;

        double DegToRad(double deg){
            return deg * PI / 180.0;
        }

        double Sin(double aid){
            return std::sin(DegToRad(aid));
        }

        double Cos(double aid){
            return std::cos(DegToRad(aid));
        }

        double Tan(double aid){
            return std::tan(DegToRad(aid));
        }

        // operates addition, subtraction, multiplication, division, and a special type /*-
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
            }
            else if (type == "/*-") {
                if (b == 0)
                    throw std::invalid_argument("Division by zero '/*-' operation invalid.");
                // Use pow(a, 2) but cast to double to avoid overflow for ints
                double result = static_cast<double>(a / b) * b * std::pow(static_cast<double>(a), 2) - (a - b);
                return static_cast<T>(result);
            }

            throw std::invalid_argument("Invalid operator type. Enter +, -, *, /, or /*-");
        }

        // multiplies a vector of numbers
        double MultNums(const std::vector<double> &numbers){
            double result = 1;

            for (double num : numbers){
                result *= num;
            }

            return result;
        }

        double ReturnPower(double b, int e){
            double r = 1;

            for (int i = 0; i < e; i++){
                r = r * b;
            }

            return r;
        }

        // Factorial(): gets the factorial result (i dont know just guessing)
        // note: searched up the algorithm
        unsigned long long Factorial(unsigned int n){
            unsigned long long result = 1;

            for (unsigned int i = 2; i <= n; ++i){
                result *= i;
            }

            return result;
        }

        // GCD(): returns greatest common divider (GCD)
        int GCD(int a, int b){
            while (b != 0){
                int temp = b;
                b = a % b;
                a = temp;
            }

            return a;
        }

        // LCM(): Opposite of GCD
        int LCM(int a, int b){
            return (a / GCD(a, b)) * b;
        }

        namespace dxlibShapesCalc {
            double volumeCube(double side){
                return side * side * side;
            }

            double Rectprism(double len, double wid, double hei){
                return len * wid * hei;
            }

            // (4/3) * pi * r^3
            double VolSphere(double rad){
                return (4.0 / 3.0) * PI * rad * rad * rad;
            }

            // pi * r^2 * height
            double VolCyl(double rad, double hei){
                return PI * rad * rad * hei;
            }

            // (1/3) * pi * r^2 * height
            double VolCone(double rad, double hei){
                return (1.0 / 3.0) * PI * rad * rad * hei;
            }

            double VolTrigPrism(double b, double h, double l){
                return 0.5 * b * h * l;
            }

            // (1/3) * base * height
            double VolPyr(double bl, double bw, double hei){
                return (1.0 / 3.0) * bl * bw * hei;
            }

            // (4/3) * pi * a * b * c (a,b,c = semi-axes)
            double VolElip(double a, double b, double c){
                return (4.0 / 3.0) * PI * a * b *c;
            }
        }
    }

    // ================== dxlibTime ==================
    namespace dxlibTime {
        // format a time structure
        std::string FormatDate(const std::tm& tm, const std::string &format = "%Y-%m-%d : %H:%M:%S"){
            std::ostringstream oss;
            oss << std::put_time(&tm, format.c_str());

            return oss.str();
        }

        // sleep for a given time.
        void sleepfor(std::string type, int global_sec){
            if (type == "s"){
                std::this_thread::sleep_for(std::chrono::seconds(global_sec));
            }
            else if (type == "ms"){
                std::this_thread::sleep_for(std::chrono::milliseconds(global_sec));
            }
            else if (type == "nms"){
                std::this_thread::sleep_for(std::chrono::nanoseconds(global_sec));
            }
            else if (type == "mc"){
                std::this_thread::sleep_for(std::chrono::microseconds(global_sec));
            }
            else {
                throw std::invalid_argument("Invalid type. Please enter 's', 'ms', 'nms', or 'mc'");
            }
        }

        // get the time of the USER(S) system
        std::string GetLocalTime(){
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

        // adds seconds to a time structure
        std::tm AddSecToTime(const std::tm& tm, int secondsToAdd){
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
        // print a message onto the terminal
        void printline(std::string text, bool endl=true){
            if (endl){
                std::cout << text << std::endl;
            }
            else if (!endl){
                std::cout << text;
            }
            else {
                throw std::invalid_argument("Please enter true or false on the second argument.");
            }
        }

        // print a variable in a string
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

        template<typename... Args>
        void printVar(std::string text, Args&&... args) {
            printVar_helper(text, std::forward<Args>(args)...);
        }

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
        bool startsWith(const std::string &str, const std::string &prefix){
            return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
        }

        bool endsWith(const std::string &str, const std::string &suffix){
            return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
        }

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

        // split a string using a delim
        std::vector<std::string> Split(const std::string& str, char delimiter){
            std::vector<std::string> tokens;
            std::stringstream ss(str);
            std::string token;

            while (std::getline(ss, token, delimiter)){
                tokens.push_back(token);
            }

            return tokens;
        }

        // join parts of a string
        std::string Join(const std::vector<std::string>& parts, const std::string& delim){
            std::ostringstream oss;

            for (size_t i = 0; i < parts.size(); i++){
                oss << parts[i];

                if (i < parts.size() - 1) oss << delim;
            }

            return oss.str();
        }

        // remove all whitespaces
        std::string TrimString(std::string& str){
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {return !std::isspace(ch);}));

            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch){return !std::isspace(ch);}).base(), str.end());

            return str;
        }

        // reverse the strings content
        std::string ReverseString(std::string &str){
            std::reverse(str.begin(), str.end());

            return str;
        }

        // remove the whitespaces on the left side
        std::string LTrim(std::string& str){
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch){return !std::isspace(ch);}));

            return str;
        }

        // remove the whitespaces on the right side
        std::string RTrim(std::string& str){
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch){return !std::isspace(ch);}).base(), str.end());

            return str;
        }

        // capitalize the first letter on every word found in a string
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
        // create a class for logging
        enum class LogLevel {INFO, WARN, ERRORS};

        void log(const std::string& msg, LogLevel level = LogLevel::INFO){
            std::string prefix;

            switch (level){
                case LogLevel::INFO: prefix = "[INFO]"; break;
                case LogLevel::WARN: prefix = "[WARN]"; break;
                case LogLevel::ERRORS: prefix = "[ERROR]"; break;
            }

            std::cout << prefix << " " << msg << std::endl;
        }

        // stop the code
        void debugBreak() {
            #ifdef _WIN32
                __debugbreak(); //MSVC
            #else
                std::raise(SIGTRAP); //linux
            #endif // _WIN32
        }

        // make something not equal to 0
        void assertLog(bool cond, const std::string& msg){
            if (!cond) {
                log("[ASSERT FAIL]" + msg, LogLevel::ERRORS);
                std::exit(EXIT_FAILURE);
            }
            // do nothing if cond passed
        }

        // record how much seconds have passed during a code execution.
        void timeLog(const std::string& label, const std::function<void()>&func){
            auto start = std::chrono::high_resolution_clock::now();
            func(); // run user func
            auto end = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            double ms = duration / 1000.0;

            log(label + " took " + std::to_string(ms) + " ms");
        }
    }

    // ================== dxlibCheck ==================
    namespace dxlibCheck {
        // check if a number is even
        template<typename T>
        bool isEven(T num){
            return num % 2 == 0;
        }

        // check if a number is odd
        template<typename T>
        bool isOdd(T num){
            return num % 2 != 0;
        }

        // check if a string is numeric
        bool isNumeric(const std::string& s){
            return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
        }

        // check if all characters are alphabetic
        bool isAlpha(const std::string& s){
            return !s.empty() && std::all_of(s.begin(), s.end(), ::isalpha);
        }

        // check if all characters are alphanumeric
        bool isAllNum(const std::string& s){
            return !s.empty() && std::all_of(s.begin(), s.end(), ::isalnum);
        }

        // check if a string is a valid float
        bool isFloatString(const std::string& s){
            std::istringstream iss(s);
            float f;

            return (iss >> f) && iss.eof();
        }

        // check if a string is a valid double
        bool isDoubleString(const std::string& s){
            std::istringstream iss(s);
            double d;

            return (iss >> d) && iss.eof();
        }

        // check if a number is within a closed range
        template<typename T>
        bool isInRange(T value, T min, T max){
            return value >= min && value <= max;
        }

        // check if a number is prime
        bool isPrime(int n){
            if (n <= 1) return false;

            for (int i = 2; i * i <= n; ++i){
                if (n % i == 0) return false;
            }

            return true;
        }

        // check if a number is a palindrome
        bool isPalindrome(const std::string& s){
            return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
        }

        // check if a string is only whitespaces
        bool isWhiteSpaceOnly(const std::string& s){
            return std::all_of(s.begin(), s.end(), ::isspace);
        }

        // check if a number is zero
        template<typename T>
        bool isZero(T num){
            return num == 0;
        }

        // check if a number halfed is equal to another number
        template<typename T>
        bool isHalf(T num, T other){
         // avoid a bug where if you divide an int by a double it shows as an int
            return static_cast<double>(num) / 2.0 == static_cast<double>(other);
        }

        // check if a number multiplied by 2 is equal to another number
        template<typename T>
        bool isMultTwo(T num, T other){
            return num * 2 == other;
        }

        template<typename T>
        bool isEqual(T num, T other){
            return num == other;
        }
    }
}

#endif // DX_H

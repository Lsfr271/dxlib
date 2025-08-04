#ifndef DX_H
#define DX_H

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

#ifdef _WIN32
    #include <windows.h>
    #include <Lmcons.h>
#else
    #include <unistd.h>
    #include <sys/sysinfo.h>
    #include <sys/utsname.h>
    #include <pwd.h>
    #include <limits.h>
#endif
#include <functional>

namespace dxlib {
    namespace dxlibMain {
        bool CinFail(){
            if (std::cin.fail()){
                return false;
            }
            else {
                return true;
            }
        }

        void dxClearBuf(){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    namespace dxlibRandom {
        double RandomNumRange(int min, int max){
            return min + rand() % (max - min + 1);
        }

        void PrintRandomNum(int min, int max){
            std::cout << "Int: " << min + rand() % (max - min + 1);
        }
    } 

    namespace dxlibConvert {
        int ConvertDoubleToInt(const double &i){
            return static_cast<int>(i);
        }

        double ConverIntToDouble(const int &i){
            return static_cast<double>(i);
        }

        double ConvertFloatToDouble(const float &i){
            return static_cast<double>(i);
        }

        float ConvertDoubleToFloat(const double &i){
            return static_cast<float>(i);
        }
        
        int ConvertFloatToInt(const float &i){
            return static_cast<int>(i);
        }
    }

    namespace dxlibFileUtils {
        bool File_Exists(const std::string &filename){
            return std::filesystem::exists(filename);
        }

        // read entire file & convert to string
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

        namespace dxlibFileOperations {
            void CreateFile(const std::string &filename, const std::string &filetype){
                std::string fullName = filename + "." + filetype;

                std::ofstream file(fullName);
                
                if (!file){
                    throw std::runtime_error("Failed to create file: " + fullName);
                }
                // file created and closes, so no extra code needed
            }

            void DeleteFile(const std::string &filename){
                if (!std::filesystem::remove(filename)){
                    throw std::runtime_error("Failed to delete file or file does not exist: " + filename);
                }
            }

            void CopyFile(const std::string &source, const std::string &destination){
                try {
                    std::filesystem::copy_file(source, destination, std::filesystem::copy_options::overwrite_existing);
                } catch (const std::filesystem::filesystem_error &e){
                    throw std::runtime_error("Failed to copy file: " + std::string(e.what()));
                }
            }

            void RenameFile(const std::string& oldName, const std::string &newName){
                try {
                    std::filesystem::rename(oldName, newName);
                } catch (const std::filesystem::filesystem_error &e){
                    throw std::runtime_error("Failed to rename file: " + std::string(e.what()));
                }
            }
        }
    }

    namespace dxlibMath {
        constexpr double PI = 3.14159265358979323846;

        double DegToRad(double deg){
            return deg * PI / 180.0;
        }

        double dlibSin(double aid){
            return std::sin(DegToRad(aid));
        }

        double dlibCos(double aid){
            return std::cos(DegToRad(aid));
        }

        double dlibTan(double aid){
            return std::tan(DegToRad(aid));
        }

        namespace dxlibMathAdditions {
            int OperatorNums(int a, int b, std::string type){
                if (type == "+") return a + b;
                else if (type == "-") return a - b;
                else if (type == "*") return a * b;
                else if (type == "/") {
                    if (b == 0){
                        throw std::invalid_argument("Divison by zero '/' operation invalid.");
                    }
                    else {
                        return a / b
                    }
                }
                else if (type == "/*-") {
                    if (b == 0){
                        throw std::invalid_argument("Divison by zero '/*-' operation Invalid.");
                    }
                    else {
                        return a / b * b * pow(a, 2) - (a - b); // pow (a, 2) hardcoded (because if user enters)
                                                                                // something like 150 as a. it will be pow (a, a) which
                                                                                // is extremely large.
                    }
                }
            
                throw std::invalid_argument("Invalid operator type. Enter +, -, /, *, or /*-");
            }

            double MultNums(const std::vector<double> &numbers){
                double result = 1;

                for (double num : numbers){
                    result *= num;
                }

                return result;
            }
        }

        namespace dxlibPower {
            void PrintPower(double base, int exponent, bool twist=false){
                if (!twist){
                    double result = 1;

                    for (int i = 0; i < exponent; i++){
                        result = result * base;
                    }

                    std::cout << "Final Value: " << result << std::endl;
                }
                else {
                    double resultTwist = 1;

                    for (int j = 0; j < exponent + 2; j++){ // the twist is right here
                        resultTwist = resultTwist * exponent + base;
                    }

                    std::cout << "Final Value: " << resultTwist << std::endl;
                }
            }

            double ReturnPower(double b, int e){
                double r = 1;

                for (int i = 0; i < e; i++){
                    r = r * b;
                }

                return r;
            }
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

    namespace dxlibTime {
        std::string FormatDate(const std::tm& tm, const std::string &format = "%Y-%m-%d : %H:%M:%S"){
            std::ostringstream oss;
            oss << std::put_time(&tm, format.c_str());

            return oss.str();
        }

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

        // adds seconds to std::tm
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

    namespace dxlibGen {
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

        // shuffles elems
        template<typename T>
        void ShuffleVect(std::vector<T>& vec){
            static std::random_device rd;
            static std::mt19937 generator(rd());
            
            std::shuffle(vec.begin(), vec.end(), generator);
        }
    }

    namespace dxlibPrint {
        void dxp(std::string text, bool endl=true){
            if (endl){
                std::cout << text << std::endl;
            }
            else if (!endl){
                std::cout << text << "\n";
            }
            else {
                throw std::invalid_argument("Please enter true or false on the second argument.");
            }
        }
        
        void varp(std::string text, const std::unordered_map<std::string, std::string>& vars, bool nl = true) {
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
            void varp_helper(std::string& text) {
                std::cout << text << std::endl;
            }

            template<typename T, typename... Args>
            void varp_helper(std::string& text, T&& firstArg, Args&&... restArgs) {
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

                varp_helper(text, std::forward<Args>(restArgs)...);
            }
        }

        template<typename... Args>
        void varp(std::string text, Args&&... args) {
            varp_helper(text, std::forward<Args>(args)...);
        }


        template<typename T>
        T dxi(const std::string& ques, bool nl = true) {
            T input{};

            while (true) {
                if (nl) std::cout << ques << std::endl;
                else std::cout << ques;

                std::cin >> input;

                if (std::cin.fail()) {
                    std::cin.clear(); // reset failbit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush input
                    std::cout << "Invalid input. Please try again.\n";
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush remaining
                    return input;
                }
            }
        }
    }

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
            else {
                throw std::invalid_argument("Invalid Type. Enter either lower or upper");
            }
        }

        std::vector<std::string> Split(const std::string& str, char delimiter){
            std::vector<std::string> tokens;
            std::stringstream ss(str);
            std::string token;

            while (std::getline(ss, token, delimiter)){
                tokens.push_back(token);
            }

            return tokens;
        }

        std::string Join(const std::vector<std::string>& parts, const std::string& delim){
            std::ostringstream oss;

            for (size_t i = 0; i < parts.size(); i++){
                oss << parts[i];
                
                if (i < parts.size() - 1) oss << delim;
            }

            return oss.str();
        }

        std::string TrimString(std::string& str){
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {return !std::isspace(ch);}));

            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch){return !std::isspace(ch);}).base(), str.end());

            return str;
        }

        std::string ReverseString(std::string &str){
            std::reverse(str.begin(), str.end());

            return str;
        }

        std::string LTrim(std::string& str){
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch){return !std::isspace(ch);}));

            return str;
        }

        std::string RTrim(std::string& str){
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch){return !std::isspace(ch);}).base(), str.end());

            return str;
        }

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

    namespace dxlibDebug {
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

        void debugBreak() {
            #ifdef _WIN32
                __debugbreak(); //MSVC
            #else
                std::raise(SIGTRAP); //linux
            #endif // _WIN32
        }

        void assertLog(bool cond, const std::string& msg){
            if (!cond) {
                log("[ASSERT FAIL]" + msg, LogLevel::ERRORS);
                std::exit(EXIT_FAILURE);
            }
            // do nothing if cond passed
        }

        void timeLog(const std::string& label, const std::function<void()>&func){
            auto start = std::chrono::high_resolution_clock::now();
            func(); // run user func
            auto end = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            double ms = duration / 1000.0;

            log(label + " took " + std::to_string(ms) + " ms");
        }
    }
}

#endif // DX_H


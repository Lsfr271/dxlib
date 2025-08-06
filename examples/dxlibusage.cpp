/*
This file is used to show how dxlib is used.
*/
#include "../include/dx.h"

// make the namespaces easier to use
using namespace dxlib;
using namespace dxlibPrint;
using namespace dxlibTime;
using namespace dxlibRandom;
using namespace dxlibText;

// global vars
int userMoney = 0;
const int maxMoney = 65;

int main() {
    printline("Welcome to money game! Your goal is to reach 65$, Good luck!");
    sleepfor("s", 1);

    // game loop
    while (true) {
        std::string choice = askInput<std::string>("What will be your choice? (l = left, r = right): ");
        ChangeCase(choice, "lower");

        // Winning condition
        if (userMoney >= maxMoney){
            printline("You won!");
            sleepfor("s", 1);

            break;
        }
        
        if (choice == "l"){
            int randomAction = RandomNumRange(0, 2); // set a random number to (0 -> 2)

            if (randomAction == 0){
                int moneyGain = RandomNumRange(2, 20);

                printline("It looks like you found some coins!");
                printVar("You found: -moneyGain- coins!", moneyGain);
                userMoney += moneyGain;
                sleepfor("s", 1);

                continue;
            }
            else if (randomAction == 1){
                printline("You found nothing..");
                sleepfor("s", 1);

                continue;
            }
            else {
                std::string word = "amazing";
                std::string reversed_word = ReverseString(word);

                printline("It seems you found something on the wall, you cant read it though..");
                sleepfor("s", 1);
                printVar("Its says: -reversed_word-", reversed_word);

                std::string guessWord = askInput<std::string>("What is the original Word?: ");
                ChangeCase(guessWord, "lower");
                TrimString(guessWord);

                if (guessWord == "amazing"){
                    printline("Correct! +20 Coins!");
                    userMoney += 20;
                    sleepfor("s", 1);

                    continue;
                }
                else {
                    printline("Nothing happened..");
                    sleepfor("s", 1);

                    continue;
                }
            }
        }
        else if (choice == "r"){
            int greatMoney = RandomNumRange(2, 20);
            
            if (greatMoney == 14){
                int tooMuchMoney = RandomNumRange(10, 100);

                printline("You found: -tooMuchMoney- Coins!", tooMuchMoney);
                sleepfor("s", 1);
                userMoney += tooMuchMoney;
                continue;
            }
            else {
                printline("You didnt find anything..");
                sleepfor("s", 1);

                continue;
            }
        }
        else {
            printline("Invalid choice.");
            sleepfor("s", 1);

            continue;
        }
    }
}

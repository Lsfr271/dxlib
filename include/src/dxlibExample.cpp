/*
This file is used to show how dxlib is used.
*/
#include "include/dx.h"

/*
dxi: Takes in user input
varp: Prints variables in a string
dxp: Prints a message

RandomNumRange: Picks a random number range between the min and max arguments
sleepfor: Sleeps for a given amount of time by doing either "s" for seconds or other types
ChangeCase: Changes strings to either lower or upper
TrimString: Removes every whitespace in a string
*/

// make the namespaces easier to use
using namespace dxlib;
using namespace dxlib::dxlibPrint;
using namespace dxlib::dxlibTime;
using namespace dxlib::dxlibRandom;
using namespace dxlib::dxlibText;

// global vars
int userMoney = 0;
const int maxMoney = 65;

// function to show money so we can reuse it!
void showMoney() {
    varp("Money: -userMoney-$", userMoney);
}

int main() {
    dxp("Welcome to money game! Your goal is to reach 65$, Good luck!");
    sleepfor("s", 1);

    // game loop
    while (true) {
        std::string choice = dxi<std::string>("What will be your choice? (l = left, r = right): "); // read input
        ChangeCase(choice, "lower"); // change to lower

        // Winning condition
        if (userMoney >= maxMoney){ // check if the users money is greater or equal to the maxMoney
            dxp("You won!");
            sleepfor("s", 1);

            break;
        }
        
        if (choice == "l"){ // see if the user entered 'l'
            int randomAction = RandomNumRange(0, 2); // set a random number to (0 -> 2)

            if (randomAction == 0){ // check if randomAction is 0
                int moneyGain = RandomNumRange(2, 20); // randomize coins and add to users money

                dxp("It looks like you found some coins!");
                varp("You found: -moneyGain-$ coins!", moneyGain); // show the amount of money
                userMoney += moneyGain;
                showMoney();
                sleepfor("s", 1);

                continue;
            }
            else if (randomAction == 1){ // check if randomAction is 1
                dxp("You found nothing..");
                sleepfor("s", 1);

                continue;
            }
            else { // check if random action is 2. (no else if is needed because the end is 2 in the RandomNumRange())
                std::string word = "amazing";
                std::string reversed_word = ReverseString(word);

                dxp("It seems you found something on the wall, you cant read it though..");
                sleepfor("s", 1);
                varp("Its says: -reversed_word-", reversed_word);

                std::string guessWord = dxi<std::string>("What is the original Word?: ");
                ChangeCase(guessWord, "lower");
                TrimString(guessWord);

                if (guessWord == "amazing"){
                    dxp("Correct! +20 Coins!");
                    userMoney += 20;
                    showMoney();
                    sleepfor("s", 1);

                    continue;
                }
                else {
                    dxp("Nothing happened..");
                    sleepfor("s", 1);

                    continue;
                }
            }
        }
        else if (choice == "r"){ // check if they entered r
            int greatMoney = RandomNumRange(2, 20); // randomize a choice
            
            if (greatMoney == 14){ // if greatmoney is 14, give the user a large amount of money (super rare)
                int tooMuchMoney = RandomNumRange(10, 100);

                varp("You found: -tooMuchMoney-$ Coins!", tooMuchMoney);
                sleepfor("s", 1);
                userMoney += tooMuchMoney;
                showMoney();
                continue;
            }
            else {
                dxp("You didnt find anything..");
                sleepfor("s", 1);

                continue;
            }
        }
        else {
            dxp("Invalid choice.");
            sleepfor("s", 1);

            continue;
        }
    }
}

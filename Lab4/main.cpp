#include <iostream>
#include "game.hpp"

using namespace std;

int main() {
    char ans;
    bool done = false;
    int wager = 0;
    bool enoughCredits = false;

    while (!done) {
        while (!enoughCredits) {
            cout << "You have " << credits << " credits. How much do you wager? ";
            cin >> wager;

            if (wager > credits) {
                cout << "Your wager exceeds your balance. Try again.\n";
                enoughCredits = false;
            }
            else {
                enoughCredits = true;
            }
        }

        enoughCredits = false;

        playGame(die(), wager);

        if (credits == 0) {
            cout << " You are out of credits - game over!\n";
            break;
        }
        else {
            cout << "Your new balance is " << credits << " credits\n";
        }

        cout << "\nPlay again (y/n)? \n";
        cin >> ans;

        if (ans == 'n' || ans == 'N') {
            done = true;
        }
        else {
            done = false;
        }
    }

    return 0;
}

#include "game.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int credits = 100;
int dieOne;
int dieTwo;

int die() {
    dieOne = rand() % 6 + 1; 
    dieTwo = rand() % 6 + 1;
    return dieOne + dieTwo;
}

void playGame(int dieThrow, int wager) {
    int point;
    cout << "\nPlayer rolled " << dieOne << " + " << dieTwo << " = " << dieOne + dieTwo << "\n";

    if (dieThrow == 7 || dieThrow == 11) {
        cout << "Player wins!: " << dieThrow << " \n";
        credits += wager;
        cout << "\nYou won " << wager << " credits";
    }
    else if (dieThrow == 2 || dieThrow == 3 || dieThrow == 12) {
        cout << "Player loses!: " << dieThrow << " \n";
        credits -= wager;
        cout << "\nYou lost " << wager << " credits.";
    }
    else {
        point = dieThrow;
        int secondThrow = 0;
        cout << "Point is " << point << "\n";

        while (secondThrow != point) {
            secondThrow = die();
            cout << "Player rolled " << dieOne << " + " << dieTwo << " = " << dieOne + dieTwo << "\n";

            if (secondThrow == 7) {
                cout << "Player loses!: " << secondThrow << " \n";
                credits -= wager;
                cout << "\nYou lost " << wager << " credits.";
                break;
            }

            if (secondThrow == point) {
                cout << "Player wins!: " << secondThrow << " \n";
                credits += wager;
                cout << "\nYou won " << wager << " credits.";
                break;
            }
        }
    }
}

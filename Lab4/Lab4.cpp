#include <iostream>
#include <cstdlib>
    
using namespace std;

int credits = 100;
int dieOne;
int dieTwo;

int die() {
    dieOne = rand()%5+1;
    dieTwo = rand() % 5 + 1;
    return dieOne + dieTwo;
}

void playGame(int dieThrow, int wager) {
    int point;
    cout << "\nplayer rolled " << dieOne << " + " << dieTwo << " = " << dieOne + dieTwo << "\n";

    if (dieThrow == 7 || dieThrow == 11) {
        cout << "Player wins!: " << dieThrow << " \n";
        credits += wager;
        cout << "\nyou won " << wager << " credits. Your new balance is " << credits << " credits";
    }
    else if (dieThrow == 2 || dieThrow == 3 || dieThrow == 12) {
        cout << "Player loses!: " << dieThrow << " \n";
        credits -= wager;
        cout << "\nyou lost " << wager << " credits. Your new balance is " << credits << " credits";
    }
    else{
        point = dieThrow;
        int secondThrow = 0;

;        while (secondThrow != point) {

            if (secondThrow != 7 && secondThrow != point) {
                secondThrow = die();
            }
            
            if (secondThrow == 7) {
                cout << "Player loses!: " << secondThrow << " \n";
                credits -= wager;
                cout << "\nyou lost " << wager << " credits. Your new balance is " << credits << " credits";
                break;
            }

            if (secondThrow == point) {
                cout << "Player Wins!: " << secondThrow << " \n";
                credits += wager;
                cout << "\nyou won " << wager << " credits. Your new balance is " << credits << " credits";
                break;
            }

        }

    }
}

int main() {
    char ans;
    bool done = false;
    int wager = 0;
    bool enoughCredits = false;

    while (!done) {  // YOU MUST WRITE THIS FUNCTION

        while (!enoughCredits) {
            cout << "You have " << credits << " credits.How much do you wager ? ";
            cin >> wager;

            if (wager > credits) {
                cout << "your wager exceeds your balance.Try again.\n";
                enoughCredits = false;
            }
            else enoughCredits = true;
        }

        enoughCredits = false;

        playGame(die(), wager);

        cout << "\nPlay again (y/n) ? \n";
        cin >> ans;

        if (ans == 'n' || ans == 'N') {
            done = true; 
        }
        else done = false;
        
    }
    
    return 0;
}




#include <iostream>
#include <cstdlib>
    
using namespace std;

int die() {
    int dieOne = rand()%5+1;
    int dieTwo = rand() % 5 + 1;
    return dieOne + dieTwo;
}

void playGame(int dieThrow) {
    int point;

    if (dieThrow == 7 || dieThrow == 11) {
        cout << "Player wins!\n";
        point = dieThrow;
    }
    if (dieThrow == 2 || dieThrow == 3 || dieThrow == 12) {
        cout << "Craps!\n";
        point = dieThrow;
    }
    else{
        point = dieThrow;
        int secondThrow = die();

       

;        while (secondThrow != point) {
            cout << "Rolling again!\n";
            secondThrow = die();

            if (secondThrow == 7) {
                cout << "Player loses!\n";
            }

            if (secondThrow == point) {
                cout << "Player Wins!\n";
            }

            
        }

    }
}

int main() {
    char ans;
    bool done = false;
    while (!done) {  // YOU MUST WRITE THIS FUNCTION
        cout << " Play again (y/n) ? \n";
        cin >> ans;
        if (ans == 'n' || ans == 'N') done = true;
        else {
         done = false;
         playGame(die());
        }
    }

    
    return 0;
}




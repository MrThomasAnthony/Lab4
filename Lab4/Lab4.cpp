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
    cout << "Player threw: "<< dieThrow << " \n\n";

    if (dieThrow == 7 || dieThrow == 11) {
        cout << "Player wins!: " << dieThrow << " \n";
    }
    else if (dieThrow == 2 || dieThrow == 3 || dieThrow == 12) {
        cout << "Craps!: " << dieThrow << " \n";
    }
    else{
        point = dieThrow;
        int secondThrow = 0;

;        while (secondThrow != point) {

            if (secondThrow != 7 && secondThrow != point) {
                cout << "Rolling again!\n";
                secondThrow = die();
                cout << "Player threw: " << secondThrow << " \n";
            }
            
            if (secondThrow == 7) {
                cout << "Player loses!: " << secondThrow << " \n";
                break;
            }

            if (secondThrow == point) {
                cout << "Player Wins!: " << secondThrow << " \n";
                break;
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




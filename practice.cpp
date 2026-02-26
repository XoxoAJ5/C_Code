#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // seed random number

    cout << "Welcome! What's your name? ";
    string name;
    cin >> name;

    cout << "Hello " << name << "! I'm thinking of a number between 1 and 50.\n";

    int secret = rand() % 50 + 1;
    int guess = 0;
    int attempts = 0;

    while (true) {
        cout << "What is your guess";
        cin >> guess;
        if (guess > secret) {
            cout << "your guess is too high";
        } if ()
    }
    // ask for a guess
    // increase attempt count
    // if guess is too high print message
    // if guess is too low print message
    // if correct break loop

    cout << "You got it in ___ attempts!\n"; // replace blanks
    return 0;
}

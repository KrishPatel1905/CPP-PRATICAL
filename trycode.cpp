#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // Seed for random number generation
    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "🎮 Welcome to the Number Guessing Game!" << endl;
    cout << "Guess the number (between 1 and 100): ";

    do {
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again: ";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again: ";
        } else {
            cout << "🎉 Congratulations! You guessed it in " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}

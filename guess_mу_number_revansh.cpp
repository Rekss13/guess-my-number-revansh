#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    cout << "\tWelcom to Guess My Number:Revansh\n\n";
    int secretNumber;
    int min = 1;
    int max = 100;
    cout << "Enter the number that the computer will guess (from " << min << " to " << max << "): ";
    cin >> secretNumber;

    while (secretNumber < 1 || secretNumber > 100) {
        cout << "\n\n! The entered number does not match the requested range.\n\n";
        cout << "Try again: ";
        cin >> secretNumber;
    }

    cout << endl;

    int guess;
    int tries = 0;
    srand(static_cast<unsigned int>(time(0)));
    do {
        if (min == max) {
            cout << "The computer entered the number: " << guess << endl;
            guess = min;
        }
        else {
            cout << "Generating a number (from " << min << " to " << max <<")\n\n";
            guess = rand() % max + min;
            if (guess > max) guess = max;
            cout << "The computer entered the number: " << guess << endl;
            if (guess > secretNumber) {
                cout << "\nToo high.\n\n";
                if (guess <= max) max = guess - 1;
            }
            else if (guess < secretNumber) {
                cout << "\nToo low.\n\n";
                if (guess >= min) min = guess + 1;
            }
        }
        ++tries;
    } while (guess != secretNumber);

    cout << "\nThe computer picked up the number in " << tries << " attempts.";

    return 0;
}
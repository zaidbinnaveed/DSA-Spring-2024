#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int guessNumber(int number, int player) {
    int guess;
    cout << "Player " << player << ", enter your guess: ";
    cin >> guess;

    if (guess == number) {
        cout << "Player " << player << " wins!\n";
        return 1;
    }

    cout << "Your guess is " << (guess < number ? "too low.\n" : "too high.\n");
    return guessNumber(number, player % 2 + 1);
}

int main() {
    srand(time(0));
    int number = rand() % 100 + 1;
    guessNumber(number, 1);
    return 0;
}

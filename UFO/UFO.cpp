// UFO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ufo_functions.hpp"

int main() {

    greet();

    std::string codeword = "codecademy";
    std::string answer = "__________";
    int misses = 0;

    std::vector<char> incorrect;
    bool guess = false; // Tracks whether player guessed correct letter
    char letter; // Stores the guessed letter

    while (answer != codeword && misses < 7) {
        guess = false;
        display_misses(misses); // Displays number of misses
        display_status(incorrect, answer);
        std::cout << "Please enter your guess";
        std::cin >> letter;
        for (int i = 0; i < codeword.length(); i++) {
            if (letter == codeword[i]) {
                answer[i] = letter;
                guess = true;
            }
        }
        if (guess == true) {
            std::cout << "Correct\n";
        }
        else {
            std::cout << "Incorrect! The tractor beam pulls the person in further.";
            incorrect.push_back(letter);
            misses++;
        }
    }
    end_game(answer, codeword);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

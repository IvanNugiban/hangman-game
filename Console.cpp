
#include "Console.h"
#include "Game.h"
#include "iostream"
#include "Constants.h"

void Console::DrawGame(const Game &game) {

    std::cout << hangmanDrawings[Constants::maxAttempts - game.m_attemptsLeft];

    if (game.m_attemptsLeft > 0)  DrawWordToGuess(game.guessedWord);
    else {
        std::cout << "Correct word was: " << game.m_pickedWorld;
    }

    std::cout << std::endl;
}

void Console::DrawWordToGuess(const std::vector<char>& word) {

    std::cout << "Word to guess: ";

    for (auto letter : word) {
        std::cout << letter;
    }
}

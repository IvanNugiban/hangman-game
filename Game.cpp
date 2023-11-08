//
// Created by Ivan on 10/30/2023.
//

#include "Game.h"
#include "Random.h"
#include "string_view"
#include "iostream"


Game::Game() {
    StartGame();
}

void Game::StartGame() {

    m_pickedWorld = PickRandomWorld();

    guessedWord = std::vector<char>(m_pickedWorld.size(), '*');

    DrawCurrentGame();

    do {

       char newLetter = AskForLetter();
       ProceedLetter(newLetter);
       if (!m_bWordGuessed) DrawCurrentGame();

    } while (!m_bWordGuessed && m_attemptsLeft > 0);
}


std::string_view  Game::PickRandomWorld() {
    return words[Random::get(0, static_cast<int>(words.size()) - 1)];
}

void Game::DrawCurrentGame() const {
    Console::DrawGame(*this);
}

char Game::AskForLetter()  {

    char letter{};

    bool bIsCorrectLetter{false};

    while (!bIsCorrectLetter) {
        std::cout << "Guess a letter:";
        std::cin >> letter;

        auto iterator = std::find(guessedLetters.begin(), guessedLetters.end(), letter);

        if (iterator != guessedLetters.end()) {
            std::cout << "You've already used letter " << letter << '\n';
            continue;
        }

        bIsCorrectLetter = true;
    }


    return letter;
}

void Game::ProceedLetter(char newLetter) {

    guessedLetters.insert(guessedLetters.begin(), newLetter);

    auto letterInTheWord = std::find(m_pickedWorld.begin(), m_pickedWorld.end(), newLetter);

    if (letterInTheWord != m_pickedWorld.end()) {
        std::cout << "Letter exists!\n";

        ReplaceLettersInWord(GetCorrectLetterIndexes(newLetter), newLetter);

        CheckForGameEnd();
    }

    else {
        m_attemptsLeft--;
    }
}

void Game::CheckForGameEnd() {

    for (auto letter : guessedWord) {
        if (letter == '*') return;
    }

    m_bWordGuessed = true;

    std::cout << "You won!";
}

std::vector<int> Game::GetCorrectLetterIndexes(char correctLetter) {
    std::vector<int> indexes{};

    for (int i{0}; i < m_pickedWorld.size(); i++) {
        if (m_pickedWorld[i] == correctLetter) indexes.insert(indexes.begn(), i);
    }i

    return indexes;
}

void Game::ReplaceLettersInWord(const std::vector<int>& indexes, char letter) {
    for (int index : indexes) {
        guessedWord[index] = letter;
    }
}


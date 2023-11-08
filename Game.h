#include <array>
#include <vector>
#include <string_view>
#include <string>

#ifndef GAME_H
#define GAME_H

#include "Console.h"
#include "Constants.h"

class Game {

public:

    Game();

    void StartGame();

private:

    const std::array<std::string_view, 5> words {"salad", "fisherman", "headphones",
                                                 "airplane", "ocean"};

    std::vector<char> guessedLetters{};
    std::vector<char> guessedWord{};

    int m_attemptsLeft{Constants::maxAttempts};

    bool m_bWordGuessed = false;

    std::string m_pickedWorld{};

    std::string_view PickRandomWorld();

    void DrawCurrentGame() const;

    char AskForLetter();

    void ProceedLetter(char newLetter);

    std::vector<int> GetCorrectLetterIndexes(char correctLetter);

    void ReplaceLettersInWord(const std::vector<int>& indexes, char letter);

    void CheckForGameEnd();

    friend void Console::DrawGame(const Game &game);
};


#endif

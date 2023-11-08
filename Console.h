

#ifndef CONSOLE_H
#define CONSOLE_H

#include "Constants.h"
#include <vector>
#include <string_view>
#include <array>

class Game;


namespace Console {

    constexpr std::array<std::string_view, Constants::maxAttempts + 1> hangmanDrawings {
        "|\n"
        "|\n"
        "|\n"
        "|\n"
        "|\n"
        "====\n",
        "|+-----+\n"
        "|\n"
        "|\n"
        "|\n"
        "|\n"
        "====\n",
        "|+-----+\n"
        "|      0 \n"
        "|\n"
        "|\n"
        "|\n"
        "====\n",
        "|+-----+\n"
        "|      0 \n"
        "|      | \n"
        "|\n"
        "|\n"
        "====\n",
        "|+-----+\n"
        "|      0 \n"
        "|    / | \n"
        "|\n"
        "|\n"
        "====\n",
        "|+-----+\n"
        "|      0 \n"
        "|    / | \\ \n"
        "|\n"
        "|\n"
        "====\n",
        "|+-----+\n"
        "|      0 \n"
        "|    / | \\ \n"
        "|     /     \n"
        "|\n"
        "====\n",
        "|+-----+\n"
        "|      0 \n"
        "|    / | \\ \n"
        "|     / \\   \n"
        "|\n"
        "====\n"

        "You lost! ",};

    void DrawGame(const Game& game);
    void DrawWordToGuess(const std::vector<char>& word);
}


#endif

#include <iostream>
#include <string>

bool allLettersGuessed(bool guessedWord[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (!guessedWord[i])
        {
            return false;
        }
    }
    return true;
}

void drawHangmanFigure(std::string figure[], int incorrectGuesses)
{
    for (int i = 0; i < 7; i++)
    {
        std::cout << figure[i];
        if (i == 1 && incorrectGuesses > 0)
        {
            std::cout << "   O";
        }
        else if (i == 2 && incorrectGuesses > 1)
        {
            std::cout << "  /";
            if (incorrectGuesses > 2)
            {
                std::cout << "|";
            }
            std::cout << "\\";
        }
        else if (i == 3 && incorrectGuesses > 3)
        {
            std::cout << "   |";
        }
        else if (i == 4 && incorrectGuesses > 4)
        {
            std::cout << "  /";
            if (incorrectGuesses > 5)
            {
                std::cout << " \\";
            }
        }
        std::cout << std::endl;
    }
}

void drawHiddenWord(std::string word, bool guessedWord[])
{
    for (int i = 0; i < word.length(); i++)
    {
        if (guessedWord[i])
        {
            std::cout << word[i] << " ";
        }
        else
        {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

std::string word;

int main()
{
    std::cout << "Enter the secret word: ";
    std::cin >> word;

// Clear the screen
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix-based systems
#endif

    ///std::string word = "hello";
    int incorrectGuesses = 0;
    bool guessedWord[word.length()] = {false}; // true if the corresponding letter has been guessed

    std::string hangmanFigure[] =
    {
        "  ______",
        "  |    |",
        "  |     ",
        "  |     ",
        "  |     ",
        "  |     ",
        "  |_____"
    };

    while (incorrectGuesses < 6 && !allLettersGuessed(guessedWord, word.length()))
    {
        system("cls"); // clear the screen
        drawHangmanFigure(hangmanFigure, incorrectGuesses); // draw the hangman figure
        drawHiddenWord(word, guessedWord); // draw the hidden word
        std::cout << "Incorrect guesses: " << incorrectGuesses << std::endl;
        char guess;
        std::cout << "Enter a guess: ";
        std::cin >> guess;
        bool found = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == guess)
            {
                guessedWord[i] = true;
                found = true;
            }
        }
        if (!found)
        {
            incorrectGuesses++;
        }
    }

    system("cls"); // clear the screen one last time
    drawHangmanFigure(hangmanFigure, incorrectGuesses); // draw the final hangman figure
    if (incorrectGuesses == 6)
    {
        std::cout << "You lose! The word was " << word << "." << std::endl;
    }
    else
    {
        std::cout << "You win! The word was " << word << "!" << std::endl;
    }

    system("pause");
}

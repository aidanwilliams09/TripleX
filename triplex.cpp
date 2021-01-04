#include <iostream>
#include <ctime>

void PrintIntroduction() {

//Tell user how to play
    std::cout << "The year is 1962. The United States is in the middle of the Cuban Missile Crisis \nand you are a top secret CIA agent operating in Moscow.\nYour task is to break into their command center and destroy their launch system.\n";
    std::cout << "You must enter the codes to get into their system.\n";

}

bool PlayGameWithDifficulty(int Difficulty) {

    //answer value
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //clue values
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProd = CodeA * CodeB * CodeC;

    std::cout << "There are 3 numbers in the code for their Level " << Difficulty << " defenses.\n";
    std::cout << "+ The numbers add up to " << CodeSum << std::endl;
    std::cout << "+ The numbers multiply to " << CodeProd << std::endl;

    //store guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProd = GuessA * GuessB * GuessC;

    //check guesses
    if (GuessSum == CodeSum && GuessProd == CodeProd) {
        std::cout << "Good job, you've made it past some of their defenses.\nYou are that much closer to destroying their systems.\n";
        return true;
    } else {
        std::cout << "That's not the correct code, try it again.\n";
        return false;
    }
}

int main() {
    srand(time(NULL));
    int Difficulty = 1;
    int MaxDifficulty = 5;

    PrintIntroduction();

    while (Difficulty <= MaxDifficulty) {
        bool bLevelComplete;
        bLevelComplete = PlayGameWithDifficulty(Difficulty);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelComplete) ++Difficulty;
    }

    std::cout << "Congratulations Agent. The Free World is safer because of your work.";

    return 0;
}
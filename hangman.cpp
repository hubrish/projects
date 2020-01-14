#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;
class Hangman {
public:
    Hangman(string inputWord, string sWord) : word(inputWord), shadowWord(sWord) {}
    void printTree(int stage);
    bool checkEntry(char entry);
private:
    string word;
    string shadowWord;
};

static int tries = 0;
const int MAX_TRIES = 6
                               
int main() {
    cout << "\n                            __                           ";
    cout << "\n    I   I    /\\   I\\  I    /  `  I\\  /I    /\\    I\\  I";
    cout << "\n    I---I   /--\\  I \\ I   |  --  I \\/ I   /--\\   I \\ I";
    cout << "\n    I   I  /    \\ I  \\I    \\__/  I    I  /    \\  I  \\I";

    ifstream in;
    in.open("words.txt");
    srand(time(0)); // Current time seed
    int index = rand() % 100;
    string word;
    for (int i = 1; i<=index; i++)
        in >> word;
    in.close();

    string shadowWord(word.length(), '*');
    Hangman hMan(word, shadowWord);
    char entry;

    while (1) {
        hMan.printTree(tries);
        cout << "Enter the letter :";
        string guess;
        getline(cin, guess);
        entry = guess[0];
        entry = tolower(entry);
        if (hMan.checkEntry(entry) == true){
            return 0;
        }

        if (tries == MAX_TRIES){
            cout << "You ran out of tries!";
            return 0;
        }
    }
}

void Hangman::printTree(int stage) {
    switch(stage) {
    case 6:
        cout << "\n";
        cout << "     _______________\n";
        cout << "     |             |\n";
        cout << "     |             O\n";
        cout << "     |            /|\\\n";
        cout << "     |             |\n";
        cout << "     |            / \\\n";
        cout << "    ---\n";
        break;
 
    case 5:
        cout << "\n";
        cout << "     _______________\n";
        cout << "     |             |\n";
        cout << "     |             O\n";
        cout << "     |            /|\\\n";
        cout << "     |             |\n";
        cout << "     |            \n";
        cout << "    ---\n";
        break;
 
    case 4:
        cout << "\n";
        cout << "     _______________\n";
        cout << "     |             |\n";
        cout << "     |             O\n";
        cout << "     |            /|\\\n";
        cout << "     |             \n";
        cout << "     |            \n";
        cout << "    ---\n";
        break;
     case 3:
        cout << "\n";
        cout << "     _______________\n";
        cout << "     |             |\n";
        cout << "     |             O\n";
        cout << "     |            \n";
        cout << "     |             \n";
        cout << "     |            \n";
        cout << "    ---\n";
        break;
     case 2:
        cout << "\n";
        cout << "     _______________\n";
        cout << "     |             |\n";
        cout << "     |             \n";
        cout << "     |            \n";
        cout << "     |             \n";
        cout << "     |            \n";
        cout << "    ---\n";
        break;
     case 1:
        cout << "\n";
        cout << "     _______________\n";
        cout << "     |             \n";
        cout << "     |             \n";
        cout << "     |            \n";
        cout << "     |             \n";
        cout << "     |             \n";
        cout << "    ---\n";
        break;
 

    default :

        cout << "\n";
        cout << "This case should not be hit!\n";
        break;
    }
    cout << "\n";
    cout << "\nThe current status of the word is : " << shadowWord;
    cout << "\nYou have " << (MAX_TRIES - tries) << " guesses left!\n";
}

bool Hangman::checkEntry(char entry) {
    if (isalpha(entry)) {
        bool guessRight = false;

        for (int i = 0; i<word.length(); ++i) {
            if (word[i] == entry) {
                shadowWord[i] = entry;
                if (guessRight == false)
                    cout << "Congratulations! Correct!!" << endl;
                guessRight = true;
            }
        }


        if (shadowWord == word) {
            cout << "Congratulations! You found the word!!\n";
            return true;
        }
        if (guessRight == false)
            ++tries;
        return false;
    }
    else {
        cout << "Please enter a valid alphabet!\n";
        return false;
    }
}

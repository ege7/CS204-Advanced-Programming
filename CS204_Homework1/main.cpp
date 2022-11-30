#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//  ege 29299
// cs204 hw1
struct cell{

    char letter; // Letter inside the cell
    char color; // color of the cell
};

vector<vector<cell> > wordsMatrix; // game board

void initMatrix(int rowAmount, int colAmount){ // initializes the words in the matrix with empty cells
    cell empty;
    empty.letter = '-'; // empty karakterleri ..
    empty.color = '-';

    for(int i = 0; i < rowAmount; i++){ // before the game starts, fills the matrix(board) with empty cells
        vector<cell> temp; // temporary vector to push_back to wordsMatrix
        for(int j = 0; j < colAmount; j++){
            temp.push_back(empty);
        }
        wordsMatrix.push_back(temp);

    }
}

void displayMatrix(){ // displays the game board on terminal
    for(int i = 0; i < wordsMatrix.size();i++){
        for(int j = 0; j < wordsMatrix[i].size();j++){
            cout << "|| " << wordsMatrix[i][j].letter << " , " << wordsMatrix[i][j].color << " ";

        }
        cout << "||" << endl;
    }
}

bool contains(string word, char ch){ // checks whether the given word contains the given character or not
    for(int i = 0; i < word.length();i++){
        if(word[i] == ch){
            return true;
        }
        
    }
    return false;
}

bool checkIllegalWords(string word, string guess){ // checks whether capital or not
    for(int i = 0; i < guess.length();i++){
        if(!islower(guess[i])){
            cout << "Your input has illegal letters" << endl;
            return true;
        }
    }
    for(int i = 0;i < guess.length();i++){ // checks if the given word contains duplicate chars
        for(int j = i + 1; j < guess.length(); j++){
            if(guess[i] == guess[j]){
                cout << "Your input has a duplicate letter!"<< endl;
                return true;

            }
        }

    }
    return false;
}



bool greenCheck(string guess){ // checks whether the guess contains green characters (5th input check in hw pdf)
    for(int i = 0; i < wordsMatrix.size();i++){
        for(int j = 0; j < wordsMatrix[i].size();j++){
            if(wordsMatrix[i][j].color == 'G' && guess[j] != wordsMatrix[i][j].letter){
                return false;
            }
        }
    }
    return true;
}


bool searchVector(vector<string>triedWords, string guess){ // checks for duplicate guesses
    for(int i = 0; i < triedWords.size();i++){
        if(guess == triedWords[i]){
            return true;
        }
    }
    return false;
}

bool gameLoop(string word){ // this is our main game
    bool checkFailed; // if this is true, user has to give an input again
    vector<string> triedWords; // holds previous guesses to avoid multiple guessing of the same word
    string guess; // current guess of the user
    bool won = false; // not yet won :D
    for(int i = 0; i < wordsMatrix.size();i++){ // main game's loop
        checkFailed = false;
        do{
            // make a guess
            cout << "What's your guess? ";
            cin >> guess;
            // input checks
            // --check1
            if(guess.length() < word.length()){
                cout << "The word is too short!" << endl;
                checkFailed = true;
            }
            else if(guess.length() > word.length()){
                cout << "The word is too long!" << endl;
                checkFailed = true;
            }
            // check 2 and 3
            else if(checkIllegalWords(word, guess)){
                checkFailed = true;
            }
            // check4
            else if(searchVector(triedWords,guess)){
                cout << "You've already tried this word!" << endl;
                checkFailed = true;
            }
            // check 5
            else if(greenCheck(guess) == false){
                cout << "You did not use the green letter in your word!" << endl;
                checkFailed = true;
            }
            else if(guess == word){
                won = true; // user won
                checkFailed = false;

            }
            else{
                checkFailed = false;
            }
        }while(checkFailed == true);

        vector<cell> temp; // row
        for(int i = 0; i < word.length();i++){ // fills a row with the guess
            cell tempCell;
            tempCell.letter = guess[i];
            // coloring of the cell
            if(word[i] == guess[i]){
                tempCell.color = 'G';
            }
            else if(contains(word,guess[i])){
                tempCell.color = 'Y';
            }
            else{
                tempCell.color = 'B';

            }
            //---------------------------------------
            temp.push_back(tempCell);
        }

        wordsMatrix[i] = temp;
        triedWords.push_back(guess);
        displayMatrix();
        if(won == true){ // if player has won the game, break the game loop (game has ended before player ran out of guesses)
            return won;
        }
    }
    return won; // player has won if true;
}

int main(){
    string filename; // file to be opened
    int attempts; // the amount of characters of the word = attempts of the user
    string word; // the word
     
    // greeting
    cout << "Welcome to SWordle!" << endl;
    // get the filename
    cout << "Please Enter the file name: ";
    cin >> filename;
    ifstream input;
    input.open(filename); // opening then file
    while(!input.is_open()){ // if the file is not opened, try again until it does open
        cout << "Couldn't find the file!" << endl;
        cout << "Please Enter the file name: ";
        cin >> filename;
        input.open(filename);
    }

    // read the file
    input >> attempts; // first line of the file(attempt amount)
    input >> word; // second line of the file
    cout << "The word that you will guess has " << word.length() << " letters and you have " << attempts << " attempts." << endl;
    initMatrix(attempts, word.length()); // initialize the game
    //displayMatrix(); // display the initial game

    if(gameLoop(word)){
        cout << "You win!" << endl;
        //if the main game loop returns true, player has won
    }
    else{
        cout << "You lose!" << endl;
        // otherwise player loses the game
    }

    return 0;
}

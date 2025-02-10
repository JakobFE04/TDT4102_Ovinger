#include "mastermind.h"

// BEGIN: 4
//Oppgave 4a til 4j løses her forutenom 4e og 4f
void playMastermind(){
    constexpr int size = 4;
    constexpr int letters = 6;
    string code;
    string guess;
    code = randomizeString(size, 'A'+(letters-1), 'A');
    cout << "Koden er " << code << endl;
    guess = readInputToString(size, 'A'+(letters-1), 'A');
    cout << "Du fikk " << checkCharactersAndPosition(code, guess) << " bokstaver på rett plass og " << checkCharacters(code,guess) << " antall bokstaver som er en del av koden." << endl;
    int life = 5;
    while (checkCharactersAndPosition(code, guess) < size && life > 0){
        guess = readInputToString(size, 'A'+(letters-1), 'A');
        cout << "Du fikk " << checkCharactersAndPosition(code, guess) << " bokstaver på rett plass og " << checkCharacters(code,guess) << " antall bokstaver som er en del av koden." << endl;
        life -= 1;
    }
    if (life != 0){
        cout << "You win! The code was " << code << endl;
    }
    else{
        cout << "You lost" << endl;
    }
    bool playAgain;
    cout << "Would you like to play again? Press 1 to play again or 0 to quit. ";
    cin >> playAgain;
    if (playAgain){
        playMastermind(); 
    }
}
// END: 4

// BEGIN: 4e
///*returverdi*/ checkCharactersAndPosition(/*param 1: code, param 2: guess*/) {}
int checkCharactersAndPosition(string code, string guess){
    int counter = 0;
    for (int i=0; i < 4; i++){
        if (code.at(i) == guess.at(i)){
            counter += 1;
        }
    }
    return counter;
}
// END: 4e

// BEGIN: 4f
///*returverdi*/ checkCharacters(/*param 1: code, param 2: guess*/) {}
int checkCharacters(string code, string guess){
    int counter = 0;
    for (int i=0; i < 4; i++){
        counter += countChar(guess, static_cast<char>(code.at(i)));
    }
    return counter;
}
// END: 4f

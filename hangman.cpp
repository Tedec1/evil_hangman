/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author:

    last modified: 3/7/2019
*/

#include "hangman.h"

using namespace std;

// constructor
hangman::hangman() { 
    // TODO: Read in and store words from dictionary.txt
}


// start_new_game()
//
// Setup a new game of hangman.
void hangman::start_new_game(int num_guesses) {
    // TODO: Initialize game state variables
}


// process_guess()
//
// Process a player's guess - should return true/false depending on whether
// or not the guess was in the hidden word.  If the guess is incorrect, the
// remaining guess count is decreased.
bool hangman::process_guess(char c) {
    return false;
}


// get_display_word()
//
// Return a representation of the hidden word, with unguessed letters
// masked by '-' characters.
string hangman::get_display_word() {
    return "-a--ma-";
}


// get_guesses_remaining()
//
// Return the number of guesses remaining for the player.
int hangman::get_guesses_remaining() {
    return 4;
}


// get_guessed_chars()
//
// What letters has the player already guessed?  Return in alphabetic order.
string hangman::get_guessed_chars() {
    return "aemst";
}


// was_char_guessed()
//
// Return true if letter was already guessed.
bool hangman::was_char_guessed(char c) {
    return false;
}


// is_won()
//
// Return true if the game has been won by the player.
bool hangman::is_won() {
    return false;
}


// is_lost()
//
// Return true if the game has been lost.
bool hangman::is_lost() {
    return false;
}


// get_hidden_word
//
// Return the true hidden word to show the player.
string hangman::get_hidden_word() {
    return "hangman";
}



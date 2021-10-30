/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author:

    last modified: 3/7/2019
*/

#include <fstream>
#include "hangman.h"

using namespace std;

// constructor
hangman::hangman() {
    int l = 0;
    ifstream fin;
    fin.open("dictionary.txt");
    while(!fin.eof()){
        string s;
        getline(fin,s);
        if(s.length() > l) { l = s.length(); }
        if(word_list.count(s.length())){
            word_list[s.length()].push_back(s);
        } else {
            word_list[s.length()] = {s};
        }
    }
    LONGEST_WORD = l;
}


// start_new_game()
//
// Setup a new game of hangman.
void hangman::start_new_game(int num_guesses,int word_length, bool display_words) {
    unguessed_word = string(word_length,'-');
    display_for_tests = display_words;
    guesses_left = num_guesses;
    group = word_list[word_length];
}


// process_guess()
//
// Process a player's guess - should return true/false depending on whether
// or not the guess was in the hidden word.  If the guess is incorrect, the
// remaining guess count is decreased.
bool hangman::process_guess(char c) {
    //sort group into different guess groups
    unordered_map<string,vector<string>> groups;
    for (string s:group) {
        string key = get_hidden_word_key(s,c,unguessed_word);
        if(groups.count(key)){
            groups[key].push_back(s);
        } else {
            groups[key] = {s};
        }
    }
    //find the largest group

    //switch the unguessed word with the key

    //switch group with the largest group

}

string hangman::get_hidden_word_key(string word_to_hide, char guess, string current_hidden_word){
    for (int i = 0; i < word_to_hide.length(); i++) {
        if(current_hidden_word[i] == '-' && word_to_hide[i] == guess) {
            current_hidden_word[i] = guess;
        }
    }
    return current_hidden_word;
}

// get_display_word()
//
// Return a representation of the hidden word, with unguessed letters
// masked by '-' characters.
string hangman::get_display_word() {
    return unguessed_word;
}


// get_guesses_remaining()
//
// Return the number of guesses remaining for the player.
int hangman::get_guesses_remaining() {
    return guesses_left;
}


// get_guessed_chars()
//
// What letters has the player already guessed?  Return in alphabetic order.
string hangman::get_guessed_chars() {
    string result;
    for (int i = 0; i < 26; i++){
        if(chars_guessed[i]){
            result += char(97 + i);
        }
    }
    return result;
}


// was_char_guessed()
//
// Return true if letter was already guessed.
bool hangman::was_char_guessed(char c) {
    return chars_guessed[c - 97];
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
    return group[0];
}



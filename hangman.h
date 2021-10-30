#ifndef _HANGMAN_H
#define _HANGMAN_H

/*
    hangman.h
        
    Class definition for the hangman class.

    assignment: CSCI 262 Project - Evil Hangman        

    author: 

    last modified: 9/24/2017
*/

#include <string>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

/******************************************************************************
   class hangman

   Maintains game state for a game of hangman.

******************************************************************************/

class hangman {
public:
    int LONGEST_WORD; // the longest word in the dictionary file
    map<int,vector<string>> word_list; //list of all words by length
    int guesses_left;
    vector<string> group; //current group of possible words
    string unguessed_word; //
    bool display_for_tests;
    bool chars_guessed[26];

    hangman();
    //helper function to get a key for each group when sorting words
    string get_hidden_word_key(string word_to_hide, char guess, string current_hidden_word);
    // start a new game where player gets num_guesses unsuccessful tries
	void start_new_game(int num_guesses,int word_length, bool display_words);
    // player guesses letter c; return whether or not char is in word
    bool process_guess(char c);
    // display current state of word - guessed characters or '-'
    string get_display_word();

    // How many guesses remain?
	int get_guesses_remaining();

    // What characters have already been guessed (for display)?
    string get_guessed_chars();

    // Has this character already been guessed?
    bool was_char_guessed(char c);

    // Has the game been won/lost?  (Else, it continues.)
    bool is_won();
    bool is_lost();

    // Return the true hidden word.
    string get_hidden_word();

private:
    
};

#endif

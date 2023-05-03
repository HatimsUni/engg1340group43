#include <iostream>
#include <string>
#include <vector>
#include "../include/trump.h"
#include "../include/print_text.h"
#include "../include/card_dealer.h"
using namespace std;
vector<string> order = {"A", "K", "Q"};
vector<string> user_deck;
vector<string> comp1;
vector<string> comp2;
vector<string> comp3;


void start_game(int winner) {
    vector<string> deck = newDeck();
    user_deck = drawCard(deck, 5);
    comp1 = drawCard(deck, 5);
    comp2 = drawCard(deck, 5);
    comp3 = drawCard(deck, 5);
    if (winner == 0) {
        print_cards(user_deck, 5);
    }
    else {
        print_cards(user_deck, 5);
    }
}

void toss(vector<string> deck) {
    vector<string> draw4 = drawCard(deck, 4);
    print("This is a toss, the player with the highest number starts!", "magenta", true);
    print("Your card: ", "green", true, "  ");
    print("Computer 1:  Computer 2:  Computer 3:", "cyan");
    print_cards(draw4);
    int highest = 1;
    string value;
    int number = 0;
    int winner;
    for (int i = 0; i < 4; i++) {
        value = getValue(draw4[i]);
        if (value == "A") {
            number = 14;
        } else if (value == "K") {
            number = 13;
        } else if (value == "Q") {
            number = 12;
        } else if (value == "J") {
            number = 11;
        } else {
            number = stoi(value);
        }
        if (number > highest) {
            highest = number;
            winner = i;
        }
    }
    if (winner == 0) {
        print("You won the toss, please choose the trump", "magenta", true);
    }
    else {
        print("Computer " + to_string(winner) + " won the toss", "cyan");
    }
    start_game(winner);
}


void play_trump() {
    toss(newDeck());
}
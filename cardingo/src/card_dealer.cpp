#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "../include/card_dealer.h"
using namespace std;

string intToCard(int inputInt) { // inputInt: [1, 52]
    string suit, value;
    inputInt--;
    
    if (inputInt%4 == 0) suit = "D"; // diamond
    else if (inputInt%4 == 1) suit = "C"; // club
    else if (inputInt%4 == 2) suit = "H"; // heart
    else if (inputInt%4 == 3) suit = "S"; // spade
    else suit = "invalidSuit";
    
    if (inputInt/4 <= 8) value =  to_string(inputInt/4 + 2);
    else if (inputInt/4 == 9) value = "J";
    else if (inputInt/4 == 10) value = "Q";
    else if (inputInt/4 == 11) value = "K";
    else if (inputInt/4 == 12) value = "A";
    else value = "invalidValue";
    
    return suit + value; 
}

void printStringVector(vector<string> vec) { // debug purposes
    vector<string>::iterator itr = vec.begin();
    
    cout << "Card: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;
}

vector<string> newDeck(bool isShuffle) { // return a shuffled 52-Card vector
    vector<string> deck;
    for (int i = 1; i <= 52; i++) { // create vector with 52 Card, unshuffled
        deck.push_back(intToCard(i));
    }
    
    if (isShuffle) { // shuffle the vector
        random_device rd;
        mt19937 g(rd());
        shuffle(deck.begin(), deck.end(), g);
    }

    return deck;
}

vector<string> drawCard(vector<string> &deck, int n) { // draw n Card from top of the deck and return it as vector
    vector<string> cards;
    
    vector<string>::iterator itr = deck.begin();
    for (int i = 0; i < n; i++) {
        cards.push_back(*itr);
        deck.erase(itr);
    }
    
    return cards;
}

string getSuit(string card) {
    return card.substr(0, 1);
}

string getValue(string card) {
    return card.substr(1);
}

int test() {
    
    vector<string> deck = newDeck(false);
    cout << endl << "full unshuffled deck" << endl;
    printStringVector(deck);
    
    deck = newDeck();
    cout << endl << "full shuffled deck" << endl;
    printStringVector(deck);

    vector<string> hand1 = drawCard(deck, 3);
    cout << endl << "draw 3 cards" << endl;
    printStringVector(hand1);
    
    cout << endl << "card left in the deck" << endl;
    printStringVector(deck);

    return 0;
}
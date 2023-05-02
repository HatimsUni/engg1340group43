#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "../include/card_dealer.h"
using namespace std;

struct Card {
    int rank; // rank of card e.g. 4th-lowest, 17th-lowest, 39-th lowest, etc.
    string suit;
    string value;
    
    // empty card
    Card() { 
        rank = 0;
        suit = "NULLsuit";
        value = "NULLvalue";
    };
    
    // given the rank, it will determine the suit and value by itself
    Card(int inputRank) { // inputRank: [1, 52]
        rank = inputRank;
        // suit = rankToSuit(inputRank);
        // value = rankToValue(inputRank);
        
        inputRank--; // [0, 51]
        if (inputRank%4 == 0) {
            suit = "D"; // (♦)
        } else if (inputRank%4 == 1) {
            suit = "C"; // (♣)
        } else if (inputRank%4 == 2) {
            suit = "H"; // (♥)
        } else if (inputRank%4 == 3) {
            suit = "S"; // (♠)
        } else {
            value = "invalidSuit";
        }
        if (inputRank/4 <= 8) { // [0, 8]
            value =  to_string(inputRank/4 + 2);
        } else if (inputRank/4 == 9) {
            value = "J";
        } else if (inputRank/4 == 10) {
            value = "Q";
        } else if (inputRank/4 == 11) {
            value = "K";
        } else if (inputRank/4 == 12) {
            value = "A";
        } else {
            value = "invalidValue";
        }
    };
    
    // custom rank, suit, and value
    Card(int inputRank, string inputSuit, string inputValue) { // inputRank: [1, 52]
        rank = inputRank;
        suit = inputSuit;
        value = inputValue;
    };
};

void printCardVector(vector<Card> vec) { // debug purposes
    vector<Card>::iterator itr = vec.begin();
    
    cout << "Card: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << itr->suit << itr->value << " ";
        itr++;
    }
    cout << endl;
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
    vector<Card> deck;
    for (int i = 1; i <= 52; i++) { // create vector with 52 Card, unshuffled
        deck.push_back(Card(i));
    }
    
    if (isShuffle) { // shuffle the vector
        random_device rd;
        mt19937 g(rd());
        shuffle(deck.begin(), deck.end(), g);
    }
    
    vector<string> stringDeck;
    
    vector<Card>::iterator itr = deck.begin();
    for (int i = 0; i < deck.size(); i++) {
        string tempStringCard = itr->suit + itr->value;
        stringDeck.push_back(tempStringCard);
        itr++;
    }

    return stringDeck;
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

int test() { // testing purposes
    
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
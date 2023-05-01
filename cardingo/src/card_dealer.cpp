#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "../include/card_dealer.h"
using namespace std;

void printVector(vector<Card> vec) { // debug purposes
    vector<Card>::iterator itr = vec.begin();
    
    cout << "Card: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << itr->suit << itr->value << " ";
        itr++;
    }
    cout << endl;
}

vector<Card> newDeck(bool isShuffle = true) { // return a shuffled 52-Card vector
    vector<Card> deck;
    for (int i = 1; i <= 52; i++) { // create vector with 52 Card, unshuffled
        deck.push_back(Card(i));
    }
    
    if (isShuffle) { // shuffle the vector
        random_device rd;
        mt19937 g(rd());
        shuffle(deck.begin(), deck.end(), g);
    }

    return deck;
}

vector<Card> drawCard(vector<Card> &deck, int n) { // draw n Card from top of the deck and return it as vector
    vector<Card> cards;
    
    vector<Card>::iterator itr = deck.begin();
    for (int i = 0; i < n; i++) {
        cards.push_back(*itr);
        deck.erase(itr);
    }
    
    return cards;
}

int main() { // testing purposes
    
    vector<Card> deck = newDeck(false);
    cout << endl << "full unshuffled deck" << endl;
    printVector(deck);
    
    deck = newDeck();
    cout << endl << "full shuffled deck" << endl;
    printVector(deck);

    vector<Card> hand1 = drawCard(deck, 3);
    cout << endl << "draw 3 cards" << endl;
    printVector(hand1);
    
    cout << endl << "card left in the deck" << endl;
    printVector(deck);

    return 0;
}
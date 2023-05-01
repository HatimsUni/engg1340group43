#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

string rankToSuit(int inputInteger) { // determine suit from card rank; input: [1, 52]
    inputInteger--; // [0, 51]
    if (inputInteger%4 == 0) {
        return "D"; // (♦)
    } else if (inputInteger%4 == 1) {
        return "C"; // (♣)
    } else if (inputInteger%4 == 2) {
        return "H"; // (♥)
    } else if (inputInteger%4 == 3) {
        return "S"; // (♠)
    }
    return "invalidSuit";
}

string rankToValue(int inputInteger) { // determine value from card rank; input: [1, 52]
    inputInteger--; // [0, 51]
    if (inputInteger/4 <= 8) { // [0, 8]
        return to_string(inputInteger/4 + 2);
    } else if (inputInteger/4 == 9) {
        return "J";
    } else if (inputInteger/4 == 10) {
        return "Q";
    } else if (inputInteger/4 == 11) {
        return "K";
    } else if (inputInteger/4 == 12) {
        return "A";
    }
    return "invalidValue";
}

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
        suit = rankToSuit(inputRank);
        value = rankToValue(inputRank);
    };
    
    // custom rank, suit, and value
    Card(int inputRank, string inputSuit, string inputValue) { // inputRank: [1, 52]
        rank = inputRank;
        suit = inputSuit;
        value = inputValue;
    };
};

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
#ifndef CARD_DEALER_H
#define CARD_DEALER_H
#include <string>

//functions
void play_card_dealer();

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


#endif
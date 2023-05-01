#ifndef CARD_DEALER_H
#define CARD_DEALER_H

//struct
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

#endif
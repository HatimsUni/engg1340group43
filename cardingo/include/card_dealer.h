#ifndef CARD_DEALER_H
#define CARD_DEALER_H
#include <string>

// function

vector<string> newDeck(bool isShuffle = true);

vector<string> drawCard(vector<string> &deck, int n);

string getSuit(string card);

string getValue(string card);

#endif
#ifndef CARD_DEALER_H
#define CARD_DEALER_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// function

vector<string> newDeck(bool isShuffle);

vector<string> drawCard(vector<string> &deck, int n);

string getSuit(string card);

string getValue(string card);

#endif
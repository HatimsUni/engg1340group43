#ifndef CRAZY_EIGHTS_H
#define CRAZY_EIGHTS_H

#include <iostream>
#include <string>
#include <vector>
#include "../include/print_text.h"
#include "../include/sleep.h"

// class

class Human {
public:
    void handSetup(vector<string> &deck, int k);
    void printHand();
    bool isValidCard(string card, string &currentSuit, string &currentValue);
    bool isWinner();
    void pickSuit(string &currentSuit);
    void turn(vector<string> &deck, string &currentSuit, string &currentValue);

private:
    vector<string> hand;
    int handSize;
};

class Robot {
public:
    void handSetup(vector<string> &deck, int k);
    void printHand();
    bool isValidCard(string card, string &currentSuit, string &currentValue);
    bool isWinner();
    void pickSuit(string &currentSuit);
    void turn(vector<string> &deck, string &currentSuit, string &currentValue);
    
private:
    vector<string> hand;
    int seri;
};

class Deck {
public:
    void getStartingCard(vector<string> &deck, string &currentSuit, string &currentValue);
};

// function

int playCrazyEights();

#endif
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "../include/bigtwo.h"
using namespace std;

// struct Card
struct Card {
    int value;
    string suit;
};

// non-class function
bool operator<(const Card&a, const Card&b) {
	if (a.value < b.value) return true;
	if (a.value > b.value) return false;
	return a.suit < b.suit;
}
vector<vector<Card>> getAllCombinations(vector<Card> hand, int k) {
    vector<vector<Card>> combinations;
    sort(hand.begin(), hand.end(), [](Card& a, Card& b) {
        return a.value < b.value;
    });

    do {
        vector<Card> combination;
        for (int i = 0; i < k; i++) {
            combination.push_back(hand[i]);
        }
        combinations.push_back(combination);
    } while (next_permutation(hand.begin(), hand.end()));

    return combinations;
}


// Human class
class Human {
public:
    void handSetup(vector<string> &deck);
    void printHand();
    void combination();
    
private:
    vector<Card> hand;
};

void Human::handSetup(vector<string> &deck) {
    vector<string> temp = drawCard(deck, 13);
    vector<string>::iterator itr;
    for (itr = temp.begin(); itr != temp.end(); itr++) {
        Card newCard;
        newCard.suit = getSuit(*itr);
        newCard.value = getValueInt(*itr);
        hand.push_back(newCard);
    }
}
void Human::printHand() {
    vector<Card>::iterator itr;
    cout << "human: ";
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        cout << itr->value << itr->suit << " ";
    }
    cout << endl;
}
void Human::combination() {
    vector<vector<Card>> combinations = getAllCombinations(hand, 5);
    vector<vector<Card>>::iterator itr1;
    vector<Card>::iterator itr2;
    cout << "Ranking: " << endl;
    for (itr1 = combinations.begin(); itr1 != combinations.end(); itr1++) {
        for (itr2 = itr1->begin(); itr2 != itr1->end(); itr2++) {
            cout << itr2->value << itr2->suit << " ";
        }
        cout << endl;
    }
}


// Robot class
class Robot {
public:
    void handSetup(vector<string> &deck);
    void printHand();
    void setRobotID(int id);
    
private:
    vector<Card> hand;
    int seri;
};

void Robot::setRobotID(int id) {
    seri = id;
}
void Robot::handSetup(vector<string> &deck) {
    vector<string> temp = drawCard(deck, 13);
    vector<string>::iterator itr;
    for (itr = temp.begin(); itr != temp.end(); itr++) {
        Card newCard;
        newCard.suit = getSuit(*itr);
        newCard.value = getValueInt(*itr);
        hand.push_back(newCard);
    }
}
void Robot::printHand() {
    vector<Card>::iterator itr;
    cout << "rbt-" << seri << ": ";
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        cout << itr->value << itr->suit << " ";
    }
    cout << endl;
}


void play_bigtwo() {
    vector<string> deck = newDeck(false);
    printStringVector(deck);
    
    Human h;
    h.handSetup(deck);
    
    Robot r1;
    r1.setRobotID(1);
    r1.handSetup(deck);
    
    Robot r2;
    r2.setRobotID(2);
    r2.handSetup(deck);
    
    Robot r3;
    r3.setRobotID(3);
    r3.handSetup(deck);
    
    h.printHand(); r1.printHand(); r2.printHand(); r3.printHand(); printStringVector(deck); // debug
    
    h.combination();

}
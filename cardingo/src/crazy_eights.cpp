#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "../include/crazy_eights.h"
#include "../include/card_dealer.h"
#include "../include/print_text.h"
#include "../include/sleep.h"

using namespace std;

// Human class
void Human::handSetup(vector<string> &deck, int k) {
    hand = drawCard(deck, k);
}
void Human::printHand() {
    vector<string>::iterator itr;
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        cout << (*itr) << " ";
    }
    cout << endl;
}
bool Human::isValidCard(string card, string &currentSuit, string &currentValue) {
    if (currentValue == "8" && getSuit(card) == currentSuit) {
        return true;
    } else if (getSuit(card) == currentSuit || getValue(card) == currentValue || getValue(card) == "8") {
        return true;
    } else {
        return false;
    }
}
bool Human::isWinner() {
    if (hand.size() == 0) return true;
    else return false;
}
void Human::pickSuit(string &currentSuit) {
    
    int input;
    
    cout << endl;
    cout << "1:"; printSuit("D");
    cout << "\t2:"; printSuit("C");
    cout << "\t3:"; printSuit("H");
    cout << "\t4:"; printSuit("S");
    cout << endl;
    cout << "pick a suit [Enter 1 to 4]... ";
    print("Enter 1 to 4");
    
    bool isValidMove = false;
    while (!isValidMove) {
        cin >> input;
        if (1 <= input && input <= 4) {
            isValidMove = true;
        } else {
            cout << "\t1:D\t2:C\t3:H\t4:S" << endl;
            cout << "invalid move! pick a suit [Enter 1 to 4]... "; 
        }
    }
    
    if (input == 1) currentSuit = "D";
    else if (input == 2) currentSuit = "C";
    else if (input == 3) currentSuit = "H";
    else if (input == 4) currentSuit = "S";
    
    cout << endl;
    cout << "you pick suit ";
    printSuit(currentSuit);
    cout << endl;
}
void Human::turn(vector<string> &deck, string &currentSuit, string &currentValue) {
    
    cout << endl << endl << endl;
    if (currentValue == "8") {
        cout << "current suit:" << endl;
        printSuit(currentSuit); // cout << currentSuit << endl;
        cout << endl;
    } else {
        cout << "current card:" << endl;
        printCard(currentSuit+currentValue, false); // cout << currentSuit << currentValue << endl;
    }
    wait(750);
    
    cout << endl;
    cout << "your cards: " << endl;
    printCards(hand, 5, false); // printHand();
    
    if (currentValue == "8") {
        cout << "pick any ";
        printSuit(currentSuit);
        cout << " card [Enter 1 to " << hand.size() << "] or draw a card [Enter 0]... ";
    }
    else if (hand.size() > 1) {
        cout << "pick a card [Enter 1 to " << hand.size() << "] or draw a card [Enter 0]... ";
    } else if (hand.size() == 1) {
        cout << "pick a card [Enter 1] or draw a card [Enter 0]... ";
    }
    
    // check if there are move available
    bool isMoveAvail = false;
    vector<string>::iterator itr;
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        if (isValidCard(*itr, currentSuit, currentValue)) {
            isMoveAvail = true;
            break;
        }
    }
    
    int input;
    cin >> input;
    
    bool isValidMove = false;
    while (!isValidMove) {
        if (isMoveAvail == true) {
            while (!(0 < input && input <= hand.size()) || !isValidCard(hand[input-1], currentSuit, currentValue)) {
                if (currentValue == "8") {
                    cout << "invalid move! pick a " << currentSuit << " card [Enter 1 to " << hand.size() << "]... ";
                }
                else if (hand.size() > 1) {
                    cout << "invalid move! pick a card [Enter 1 to " << hand.size() << "]... ";
                } else if (hand.size() == 1) {
                    cout << "invalid move! pick a card [Enter 1]... ";
                }
                cin >> input;
            }
            isValidMove = true;
        } else if (isMoveAvail == false) {
            while (input != 0) {
                cout << "invalid move! draw a card [Enter 0]... ";
                cin >> input;
            }
            isValidMove = true;
        }
    }
    wait(300);
    cout << endl;
    
    if (input == 0) {
        vector<string> temp = drawCard(deck, 1);
        cout << "you draw.." << endl;
        wait(150);
        printSuit( getSuit(temp.front()) );
        cout << getValue(temp.front()) << endl;
        
        while (!isValidCard(temp.front(), currentSuit, currentValue)) {
            hand.push_back(temp.front());
            
            cout << "draw card again, you draw.. " << endl;
            wait(850);
            
            temp = drawCard(deck, 1);
            printSuit( getSuit(temp.front()) );
            cout << getValue(temp.front()) << endl;
        }
        wait(300);
        cout << "you pick.." << endl;
        printSuit( getSuit(temp.front()) );
        cout << getValue(temp.front()) << endl;
        
        currentSuit = getSuit(temp.front()); currentValue = getValue(temp.front());
        
        if (currentValue == "8") {
            printCards(hand, 5, false);
        }
    }
    else if (input > 0) {
        cout << "you pick.." << endl;
        printSuit( getSuit(hand[input-1]) );
        cout << getValue(hand[input-1]) << endl;
        currentSuit = getSuit(hand[input-1]); currentValue = getValue(hand[input-1]);
        hand.erase(hand.begin() + input-1);
    }
    
    if (currentValue == "8") {
        pickSuit(currentSuit);
    }
    wait(650);
    cout << endl;
}

// Robot class
void Robot::handSetup(vector<string> &deck, int k) {
    hand = drawCard(deck, k);
}
void Robot::printHand() {
    vector<string>::iterator itr;
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        cout << (*itr) << " ";
    }
    cout << endl;
}
bool Robot::isValidCard(string card, string &currentSuit, string &currentValue) {
    if (currentValue == "8" && getSuit(card) == currentSuit) {
        return true;
    } else if (getSuit(card) == currentSuit || getValue(card) == currentValue || getValue(card) == "8") {
        return true;
    } else {
        return false;
    }
}
bool Robot::isWinner() {
    if (hand.size() == 0) return true;
    else return false;
}
void Robot::pickSuit(string &currentSuit) {
    
    wait(250);
    cout << endl;
    
    int input = (rand() % 4) + 1;
    if (input == 1) currentSuit = "D";
    else if (input == 2) currentSuit = "C";
    else if (input == 3) currentSuit = "H";
    else if (input == 4) currentSuit = "S";
    
    cout << "robot pick suit "; 
    printSuit(currentSuit);
    cout << endl;
}
void Robot::turn(vector<string> &deck, string &currentSuit, string &currentValue) {
    
    cout << endl << endl << endl;
    
    bool isMoveAvail = false;
    vector<int> validInput;
    vector<string>::iterator itr; int i = 1;
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        if (isValidCard(*itr, currentSuit, currentValue)) {
            isMoveAvail = true;
            validInput.push_back(i);
        }
        i++;
    }
    if (!isMoveAvail) {
        validInput.push_back(0);
    }
    
    int random = rand() % validInput.size();
    int input = validInput[random];
    
    if (input == 0) {
        
        wait(750);
        vector<string> temp = drawCard(deck, 1);
        cout << "robot draw a card ";
        
        while (!isValidCard(temp.front(), currentSuit, currentValue)) {
            wait(900);
            hand.push_back(temp.front());
            cout << endl << "robot draw a card again ";
            temp = drawCard(deck, 1);
        }
        wait(150);
        cout << "[card left: " << hand.size() << "]" << endl;
        
        wait(200);
        cout << endl;
        cout << "robot pick.." << endl;
        printSuit( getSuit(temp.front()) );
        cout << getValue(temp.front()) << endl;
        
        currentSuit = getSuit(temp.front()); 
        currentValue = getValue(temp.front());
        wait(350);
        
    } else if (input > 0) {
        
        wait(750);
        cout << "robot pick.." << endl;
        
        wait(1050);
        printSuit( getSuit(hand[input-1]) );
        cout << getValue(hand[input-1]) << endl;
        
        currentSuit = getSuit(hand[input-1]); currentValue = getValue(hand[input-1]);
        hand.erase(hand.begin() + input-1);
        
        wait(150);
        cout << "[card left: " << hand.size() << "]" << endl;
        wait(1350);
    }
    
    if (currentValue == "8") {
        pickSuit(currentSuit);
    }
    cout << endl;
}

// Deck class
void Deck::getStartingCard(vector<string> &deck, string &currentSuit, string &currentValue) {
    vector<string>::iterator itr = deck.begin();
    while (getValue(*itr) == "8") {
        itr++;
    }
    currentValue = getValue(*itr);
    currentSuit = getSuit(*itr);
    deck.erase(itr);
}

void play_crazy_eights() {
    printGameHeading("crazyeights");
    wait(2100);
    
    vector<string> deck = newDeck(true);
    string currentValue;
    string currentSuit;
    
    Human h; h.handSetup(deck, 7);
    Robot r; r.handSetup(deck, 7);
    Deck d; d.getStartingCard(deck, currentSuit, currentValue);
    
    while (true) {
        if (deck.size() == 0) {
            cout << "tie!" << endl;
            break;
        }
        h.turn(deck, currentSuit, currentValue);
        if (h.isWinner()) {
            cout << "you win!" << endl;
            break;
        }
        
        if (deck.size() == 0) {
            cout << "tie!" << endl;
            break;
        }
        r.turn(deck, currentSuit, currentValue);
        if (r.isWinner()) {
            cout << "you lose!" << endl;
            break;
        }
    }

    cout << endl;
    cout << "\t--- GAME OVER ---" << endl;
}
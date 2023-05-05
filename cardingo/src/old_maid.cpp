#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include "../include/old_maid.h"
#include "../include/card_dealer.h"
#include "../include/print_text.h"
#include "../include/sleep.h"
using namespace std;

void shuffleHand(vector<string>& hand){
    //this function takes in the hand given and shuffles it randomly
    random_device rd;
    mt19937 g(rd());
    shuffle(hand.begin(), hand.end(), g);
}


void removePairs(vector<string>& discard_pile, vector<string>& hand, string current_player){
    //this function will remove any pairs held by the hand
    //this function takes in the discard_pile, hand, and current player;
    //if the current player is a human, it will print the current hand, throw out any pairs, copy those pairs into the discard_pile
    //and thrown pairs, and print the new hand
    //if the current player is a robot, it will just print out the thrown pairs the robot threw
    //if no pairs are found, it will print it out and continue the game
    //the discard_pile is not actually printed but was used for bug fixing
    vector<string> thrown_pairs;
    if(current_player == "human"){
        cout << "Your hand has:" << endl;
        wait();
        printCards(hand);
        wait();
        
        for(int i = 0; i < hand.size(); ++i){
            for(int j = 0; j < hand.size(); ++j){
                if((getValue(hand[i]) == getValue(hand[j])) && ((getSuit(hand[i]) == "H" && getSuit(hand[j]) == "D") || (getSuit(hand[i]) == "S" && getSuit(hand[j]) == "C"))){
                    discard_pile.push_back(hand[j]);
                    thrown_pairs.push_back(hand[j]);
                } else if((getValue(hand[i]) == getValue(hand[j])) && ((getSuit(hand[i]) == "D" && getSuit(hand[j]) == "H") || (getSuit(hand[i]) == "C" && getSuit(hand[j]) == "S"))){
                    discard_pile.push_back(hand[j]);
                    thrown_pairs.push_back(hand[j]);
                }
            }
        }
        vector<string>::iterator remover = hand.begin();
        while(remover != hand.end()){
            if(find(thrown_pairs.begin(), thrown_pairs.end(), *remover) != thrown_pairs.end()){
                remover = hand.erase(remover);
            } else{
                remover++;
            }
        }
        if(thrown_pairs.size() == 0){
            cout << "No pairs to throw" << endl;
            wait();
        } else {
            cout << "The thrown away cards are:" << endl;
            wait();
            printCards(thrown_pairs);
            wait();;
        }
        
        
        cout << "Your hand now is:" << endl;
        wait();
        printCards(hand);
    } else if (current_player == "robot"){
        for(int i = 0; i < hand.size(); ++i){
            for(int j = 0; j < hand.size(); ++j){
                if((getValue(hand[i]) == getValue(hand[j])) && ((getSuit(hand[i]) == "H" && getSuit(hand[j]) == "D") || (getSuit(hand[i]) == "S" && getSuit(hand[j]) == "C"))){
                    discard_pile.push_back(hand[j]);
                    thrown_pairs.push_back(hand[j]);
                } else if((getValue(hand[i]) == getValue(hand[j])) && ((getSuit(hand[i]) == "D" && getSuit(hand[j]) == "H") || (getSuit(hand[i]) == "C" && getSuit(hand[j]) == "S"))){
                    discard_pile.push_back(hand[j]);
                    thrown_pairs.push_back(hand[j]);
                }
            }
        }
        vector<string>::iterator remover = hand.begin();
        while(remover != hand.end()){
            if(find(thrown_pairs.begin(), thrown_pairs.end(), *remover) != thrown_pairs.end()){
                remover = hand.erase(remover);
            } else{
                remover++;
            }
        }
        if(thrown_pairs.size() == 0){
            cout << "No pairs to throw" << endl;
            wait();
        } else {
            cout << "The robot threw away the cards:" << endl;
            wait();
            printCards(thrown_pairs);
            wait();
        }
    }
}




void playTurn(vector<string>& discard_pile, vector<string>& human_hand, vector<string>& robot_hand, string current_player){
    //this function will play the turn
    //it takes in the discard_pile, human_hand, robot_hand, and current_player
    //if its the human's turn, it will print out the number of cards the robot has and ask the player to pick a card
    //once the user picks a card it will go through the remove_pair function
    //if its the robot's turn, it will just take a card from the player randomly and remove any pairs
    //if the opponent only has one card the game automatically takes it for the player
    //this function will be done recursively until the win conditon is met
    if(current_player == "human"){
        int choice;
        cout << "Its your turn" << endl;
        wait();
        cout << "The robot has " << robot_hand.size() << " card(s)" << endl;
        wait();
        while (true){
            if(robot_hand.size() == 1){
                cout << "You can only take one card" << endl;
                wait();
                choice = 1;
                break;
            } else {
                cout << "Please pick a card between 1 and " << robot_hand.size() << endl;
                wait();
                cin >> choice;
                if((choice < 1) || (choice > robot_hand.size())){
                    cout << "Invalid input. Please pick again" << endl;
                    wait();
                } else{
                    break;
                }
            }
            
        }
        cout << "You took the " << getSuit(robot_hand[choice - 1]) << getValue(robot_hand[choice - 1]) << endl;
        wait();
        human_hand.push_back(robot_hand[choice-1]);
        robot_hand.erase(robot_hand.begin() + (choice-1));
        removePairs(discard_pile, human_hand, "human");
        if(robot_hand.size()==0 && human_hand.size() == 1){
            cout << "The robot wins" << endl;
            wait();
            return;
        } else if (robot_hand.size() == 1 && human_hand.size() == 0){
            cout << "The player wins" << endl;
            wait();
            return;
        } else{
            playTurn(discard_pile, human_hand, robot_hand, "robot");
        }

    } else if (current_player == "robot"){
        int choice = rand() % human_hand.size();
        cout << "Its your opponents turn" << endl;
        wait();
        cout << "You have " << human_hand.size() << " cards" << endl;
        wait();
        cout << "The robot picked card number " << choice+1 << endl;
        wait();
        cout << "The robot took the " << getSuit(human_hand[choice]) << getValue(human_hand[choice]) << endl;
        wait();
        robot_hand.push_back(human_hand[choice]);
        human_hand.erase(human_hand.begin() + (choice));
        removePairs(discard_pile, robot_hand, "robot");
        if(robot_hand.size()==0 && human_hand.size() == 1){
            cout << "The robot wins" << endl;
            wait();
            return;
        } else if (robot_hand.size() == 1 && human_hand.size() == 0){
            cout << "The player wins" << endl;
            wait();
            return;
        } else{
            shuffleHand(robot_hand);
            playTurn(discard_pile, human_hand, robot_hand, "human");
        }
    }
}

void startOldMaid(vector<string>& discard_pile, vector<string>& human_hand, vector<string>& robot_hand, string current_player){
    //this function starts the game of old maid
    //it takes in the discard_pile, human_hand, robot_hand, and current_player
    //it removes any pairs that the human or robot has
    //then it will play the turns
    removePairs(discard_pile, human_hand, "human");
    removePairs(discard_pile, robot_hand, "robot");
    if(current_player == "human"){
        playTurn(discard_pile, human_hand, robot_hand, "human");
    } else if(current_player == "robot"){
        playTurn(discard_pile, human_hand, robot_hand, "robot");
    }
}

void playOldMaid(){
    //this function initializes all the variables (deck, discard_pile, human_hand, robot_hand, and current_player)
    //it will find the queen of clubs from both hands and throw it away
    //whoever had the queen of clubs in their initial hand will start second
    vector<string> deck = newDeck(true);
    vector<string> discard_pile;
    vector<string> human_hand(deck.begin(), deck.begin() + 26);
    vector<string> robot_hand(deck.begin() + 26, deck.end());
    string current_player;
    vector<string>::iterator queen_finder1 = human_hand.begin();

    while(queen_finder1 != human_hand.end()){
        if(getSuit(*queen_finder1) == "C" && getValue(*queen_finder1) == "Q"){
            queen_finder1 = human_hand.erase(queen_finder1);
        } else{
            ++queen_finder1;
        }
    }

    vector<string>::iterator queen_finder2 = robot_hand.begin();

    while(queen_finder2 != robot_hand.end()){
        if(getSuit(*queen_finder2) == "C" && getValue(*queen_finder2) == "Q"){
            queen_finder2 = robot_hand.erase(queen_finder2);
        } else{
            ++queen_finder2;
        }
    }

    if(human_hand.size() == 25){
        cout << "You got the queen of clubs so you threw it away and the robot starts first" << endl;
        wait();
        current_player = "robot";
    } else if(robot_hand.size() == 25){
        cout << "The robot got the queen of clubs so you start first" << endl;
        wait();
        current_player = "human";
    }
    
    startOldMaid(discard_pile, human_hand, robot_hand, current_player);

}
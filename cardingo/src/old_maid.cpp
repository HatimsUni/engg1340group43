#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include "../include/old_maid.h"
#include "../include/card_dealer.h"
#include "../include/print_text.h"
using namespace std;

// void shuffle_hand(vector<string>& hand){
//     random_device rd;
//     mt19937 g(rd());
//     shuffle(hand.begin(), hand.end(), g);
// }


// void print_cards(vector<string>& hand){
//     for(int i = 0; i < hand.size(); i++){
//         cout << getSuit(hand[i]) << getValue(hand[i]) << endl;
//     }
// }

// void remove_pairs(vector<string>& discard_pile, vector<string>& hand, string current_player){
//     vector<string> thrown_pairs;
//     if(current_player == "human"){
//         cout << "Your hand has:" << endl;
//         print_cards(hand);
        
//         for(int i = 0; i < hand.size(); ++i){
//             for(int j = 0; j < hand.size(); ++j){
//                 if((getValue(hand[i]) == getValue(hand[j])) && ((getSuit(hand[i]) == "H" && getSuit(hand[j]) == "D") || (getSuit(hand[i]) == "S" && getSuit(hand[j]) == "C"))){
//                     discard_pile.push_back(hand[j]);
//                     thrown_pairs.push_back(hand[j]);
//                 } else if((getValue(hand[i]) == getValue(hand[j])) && ((getSuit(hand[i]) == "D" && getSuit(hand[j]) == "H") || (getSuit(hand[i]) == "C" && getSuit(hand[j]) == "S"))){
//                     discard_pile.push_back(hand[j]);
//                     thrown_pairs.push_back(hand[j]);
//                 }
//             }
//         }
//         vector<string>::iterator remover = hand.begin();
//         while(remover != hand.end()){
//             if(find(thrown_pairs.begin(), thrown_pairs.end(), *remover) != thrown_pairs.end()){
//                 remover = hand.erase(remover);
//             } else{
//                 remover++;
//             }
//         }
//         cout << "The thrown away cards are:" << endl;
//         print_cards(thrown_pairs);
        
        
//         cout << "Your hand now is:" << endl;
//         print_cards(hand);
//     } else if (current_player == "robot"){
//         for(int i = 0; i < hand.size(); ++i){
//             for(int j = 0; j < hand.size(); ++j){
//                 if((getValue(hand[i]) == getValue(hand[j])) && ((getSuit(hand[i]) == "H" && getSuit(hand[j]) == "D") || (getSuit(hand[i]) == "S" && getSuit(hand[j]) == "C"))){
//                     discard_pile.push_back(hand[j]);
//                     thrown_pairs.push_back(hand[j]);
//                 } else if((getValue(hand[i]) == getValue(hand[j])) && ((getSuit(hand[i]) == "D" && getSuit(hand[j]) == "H") || (getSuit(hand[i]) == "C" && getSuit(hand[j]) == "S"))){
//                     discard_pile.push_back(hand[j]);
//                     thrown_pairs.push_back(hand[j]);
//                 }
//             }
//         }
//         vector<string>::iterator remover = hand.begin();
//         while(remover != hand.end()){
//             if(find(thrown_pairs.begin(), thrown_pairs.end(), *remover) != thrown_pairs.end()){
//                 remover = hand.erase(remover);
//             } else{
//                 remover++;
//             }
//         }
//         cout << "The robot threw away the cards:" << endl;
//         print_cards(thrown_pairs);
//     }
// }




// void play_turn(vector<string>& discard_pile, vector<string>& human_hand, vector<string>& robot_hand, string current_player){
//     if(current_player == "human"){
//         int choice;
//         cout << "Its your turn" << endl;
//         cout << "The robot has " << robot_hand.size() << " cards" << endl;
//         while (true){
//             if(robot_hand.size() == 1){
//                 cout << "You can only take one card";
//             } else {
//                 cout << "Please pick a card between 1 and " << robot_hand.size() << endl;
//                 cin >> choice;
//                 if((choice < 1) || (choice > robot_hand.size())){
//                     cout << "Invalid input. Please pick again";
//                 } else{
//                     break;
//                 }
//             }
            
//         }
//         cout << "You took the " << getSuit(robot_hand[choice - 1]) << getValue(robot_hand[choice - 1]) << endl;
//         human_hand.push_back(robot_hand[choice-1]);
//         robot_hand.erase(robot_hand.begin() + (choice-1));
//         remove_pairs(discard_pile, human_hand, "human");
//         if(robot_hand.size()==0 && human_hand.size() == 1){
//             cout << "The robot wins";
//             return;
//         } else if (robot_hand.size() == 1 && human_hand.size() == 0){
//             cout << "The player wins";
//             return;
//         } else{
//             shuffle_hand(human_hand);
//             play_turn(discard_pile, human_hand, robot_hand, "robot");
//         }

//     } else if (current_player == "robot"){
//         int choice = rand() % human_hand.size() + 1;
//         cout << "Its your opponents turn" << endl;
//         cout << "You have " << human_hand.size() << " cards" << endl;
//         cout << "The robot picked card number " << choice << endl;
//         cout << "The robot took the " << getSuit(human_hand[choice - 1]) << getValue(human_hand[choice - 1]) << endl;
//         robot_hand.push_back(human_hand[choice-1]);
//         human_hand.erase(human_hand.begin() + (choice-1));
//         remove_pairs(discard_pile, robot_hand, "robot");
//         if(robot_hand.size()==0 && human_hand.size() == 1){
//             cout << "The robot wins";
//             return;
//         } else if (robot_hand.size() == 1 && human_hand.size() == 0){
//             cout << "The player wins";
//             return;
//         } else{
//             shuffle_hand(robot_hand);
//             play_turn(discard_pile, human_hand, robot_hand, "human");
//         }
//     }
// }

void play_old_maid(vector<string>& discard_pile, vector<string>& human_hand, vector<string>& robot_hand, string current_player){
    // remove_pairs(discard_pile, human_hand, "human");
    // remove_pairs(discard_pile, robot_hand, "robot");
    // if(current_player == "human"){
    //     play_turn(discard_pile, human_hand, robot_hand, "human");
    // } else if(current_player == "robot"){
    //     play_turn(discard_pile, human_hand, robot_hand, "robot");
    // }
    print("hello");
}

// void start_old_maid(){
    vector<string> deck = newDeck();
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
        cout << "You got the queen of spades so you threw it away and the robot starts first" << endl;
        current_player = "robot";
    } else if(robot_hand.size() == 25){
        cout << "The robot got the queen of spades so you start first" << endl;
        current_player = "human";
    }
    
    play_old_maid(discard_pile, human_hand, robot_hand, current_player);

}
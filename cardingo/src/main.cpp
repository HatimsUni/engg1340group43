#include <iostream>
#include <string>
#include "../include/crazy_eights.h"
#include "../include/blackjack.h"
#include "../include/higher_lower.h"
#include "../include/trump.h"
#include "../include/old_maid.h"
#include "../include/card_dealer.h"
#include "../include/file_handler.h"
#include "../include/print_text.h"
using namespace std;

void chooseCrazyEights(){
    // string reply;
    // play_crazy_eights();
    // while (true){
    //     print("Would you like to play again? (y/n)");
    //     getline(cin, reply);
    //     if (reply == "y"){
    //         choose_crazy_eights();
    //         return;
    //     } else if  (reply == "n"){
    //         print("Thank you. Returning to the game chooser screen");
    //         return;
    //     } else {
    //         print("Wrong input. Please input your answer again");
    //     }
    // }
}

void chooseBlackjack(){
    string reply;
    playBlackjack();
    while (true){
        print("Would you like to play again? (y/n)");
        getline(cin, reply);
        if (reply == "y"){
            chooseBlackjack();
            return;
        } else if  (reply == "n"){
            print("Thank you. Returning to the game chooser screen");
            return;
        } else {
            print("Wrong input. Please input your answer again");
        }
    }
}

void chooseHigerLower(){
    string reply;
    playHigherLower();
    while (true){
        print("Would you like to play again? (y/n)");
        getline(cin, reply);
        if (reply == "y"){
            chooseHigherLower();
            return;
        } else if  (reply == "n"){
            print("Thank you. Returning to the game chooser screen");
            return;
        } else {
            print("Wrong input. Please input your answer again");
        }
    }
}

void chooseTrump(){
    string reply;
    playTrump();
    while (true){
        print("Would you like to play again? (y/n)");
        getline(cin, reply);
        if (reply == "y"){
            chooseTrump();
            return;
        } else if  (reply == "n"){
            print("Thank you. Returning to the game chooser screen");
            return;
        } else {
            print("Wrong input. Please input your answer again");
        }
    }
}


void chooseOldMaid(){
    string reply;
    playOldMaid();
    while (true){
        print("Would you like to play again? (y/n)");
        getline(cin, reply);
        if (reply == "y"){
            chooseOldMaid();
            return;
        } else if  (reply == "n"){
            print("Thank you. Returning to the game chooser screen");
            return;
        } else {
            print("Wrong input. Please input your answer again");
        }
    }
}

void chooseGame(){
    string input;
    int number;
    while(true){
        print("We have many card games, please pick one by entering the number (0-5)");
        print("1 Crazy Eights");
        print("2 Blackjack");
        print("3 Higer Lower");
        print("4 Trump");
        print("5 Old Maid");
        print("0 Exit");
        getline(cin, input);
        
        if (input.size() == 1 && input.find_first_not_of("012345") == string::npos){
            number = stoi(input);
            if (number == 0){
                print("Thank you for playing");
                return;
            } else if (number == 1){
                printGameHeading("crazyeights");
                chooseCrazyEights();
            } else if (number == 2){
                printGameHeading("blackjack");
                chooseBlackjack();
            } else if (number == 3){
                printGameHeading("higherlower");
                chooseHigerLower();
            } else if (number == 4){
                printGameHeading("trump");
                chooseTrump();
            } else if (number == 5){
                printGameHeading("oldmaid");
                chooseOldMaid();
            }
        } else {
            print("Invalid input, please reenter a number from 0-5");
        }
    }
}



int main() {
    printMainHeading();
    chooseGame();
    printMainEnding();
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include "../include/crazy_eights.h"
#include "../include/blackjack.h"
#include "../include/trump.h"
#include "../include/old_maid.h"
#include "../include/card_dealer.h"
#include "../include/file_handler.h"
#include "../include/higher_lower.h"
#include "../include/print_text.h"
#include "../include/sleep.h"
using namespace std;

void chooseCrazyEights(string username)
{
    // if the user chooses crazy eights this function will run
    // this will play crazy eights and once the game has finished it will ask if the user wants to play again
    // if the user wants to play again, it will play crazy eights
    // if the user doesnt want to play they will be brought back to the game chooser screen
    string reply;
    int score;
    score = playCrazyEights();
    updateFile(username, 1, 1, 0, 0, 0, 0, score);
    getline(cin, reply);
    while (true)
    {
        print("Would you like to play again? (y/n)", "magenta", true);
        wait();
        getline(cin, reply);
        if (reply == "y")
        {
            chooseCrazyEights(username);
            return;
        }
        else if (reply == "n")
        {
            print("Thank you. Returning to the game chooser screen", "blue", true);
            wait();
            return;
        }
        else
        {
            print("Wrong input. Please input your answer again", "red", true);
            wait();
        }
    }
}

void chooseBlackjack(string username)
{
    // if the user chooses blackjack this function will run
    // this will play blackjack and once the game has finished it will ask if the user wants to play again
    // if the user wants to play again, it will play blackjack
    // if the user doesnt want to play they will be brought back to the game chooser screen
    string reply;
    int score;
    score = playBlackjack();
    updateFile(username, 1, 0, 1, 0, 0, 0, score);
    getline(cin, reply);
    while (true)
    {
        print("Would you like to play again? (y/n)", "magenta", true);
        wait();
        getline(cin, reply);
        if (reply == "y")
        {
            chooseBlackjack(username);
            return;
        }
        else if (reply == "n")
        {
            print("Thank you. Returning to the game chooser screen", "blue", true);
            wait();
            return;
        }
        else
        {
            print("Wrong input. Please input your answer again", "red", true);
            wait();
        }
    }
}

void chooseHigherLower(string username)
{
    // if the user chooses higher lower this function will run
    // this will play higher lower and once the game has finished it will ask if the user wants to play again
    // if the user wants to play again, it will play  higher lower
    // if the user doesnt want to play they will be brought back to the game chooser screen
    string reply;
    int score;
    score = playHigherLower();
    updateFile(username, 1, 0, 0, 1, 0, 0, score);
    getline(cin, reply);
    while (true)
    {
        print("Would you like to play again? (y/n)", "magenta", true);
        wait();
        getline(cin, reply);
        if (reply == "y")
        {
            chooseHigherLower(username);
            return;
        }
        else if (reply == "n")
        {
            print("Thank you. Returning to the game chooser screen", "blue", true);
            wait();
            return;
        }
        else
        {
            print("Wrong input. Please input your answer again", "red", true);
            wait();
        }
    }
}

void chooseTrump(string username)
{
    // if the user chooses trump this function will run
    // this will play trump and once the game has finished it will ask if the user wants to play again
    // if the user wants to play again, it will play  trump
    // if the user doesnt want to play they will be brought back to the game chooser screen
    string reply;
    int score;
    score = playTrump();
    updateFile(username, 1, 0, 0, 0, 0, 1, score);
    getline(cin, reply);
    while (true)
    {
        print("Would you like to play again? (y/n)", "magenta", true);
        wait();
        getline(cin, reply);
        if (reply == "y")
        {
            chooseTrump(username);
            return;
        }
        else if (reply == "n")
        {
            print("Thank you. Returning to the game chooser screen", "blue", true);
            wait();
            return;
        }
        else
        {
            print("Wrong input. Please input your answer again", "red", true);
            wait();
        }
    }
}

void chooseOldMaid(string username)
{
    // if the user chooses old maid this function will run
    // this will play the old maid game and once the game has finished it will ask if the user wants to play again
    // if the user wants to play again, it will play the old maid game
    // if the user doesnt want to play they will be brought back to the game chooser screen
    string reply;
    int score;
    score = playOldMaid();
    updateFile(username, 1, 0, 0, 0, 1, 0, score);
    getline(cin, reply);
    while (true)
    {
        print("Would you like to play again? (y/n)", "magenta", true);
        wait();
        getline(cin, reply);
        if (reply == "y")
        {
            chooseOldMaid(username);
            return;
        }
        else if (reply == "n")
        {
            print("Thank you. Returning to the game chooser screen", "blue", true);
            wait();
            return;
        }
        else
        {
            print("Wrong input. Please input your answer again", "red", true);
            wait();
        }
    }
}

void chooseGame(string username)
{
    // this is function that allows the user to choose the game they want to play
    // it will prompt the user for a number which corresponds to the game they want to play
    // if the user inputs 0 the game ends
    // once they choose a game the corresponding game function will be played
    string input;
    int number;
    while (true)
    {
        print("We have many card games! Please choose one", "green", true);
        print("1: Crazy Eights", "cyan");
        print("2: Blackjack", "cyan");
        print("3: Higher Lower", "cyan");
        print("4: Trump", "cyan");
        print("5: Old Maid", "cyan");
        print("0: Exit", "red");
        print("Your Choice (0-5): ", "green", true, "");
        getline(cin, input);

        if (input.size() == 1 && input.find_first_not_of("012345") == string::npos)
        {
            number = stoi(input);
            print();
            if (number == 0)
            {
                return;
            }
            else if (number == 1)
            {
                printGameHeading("crazyeights");
                printRules("crazyeights");
                chooseCrazyEights(username);
            }
            else if (number == 2)
            {
                printGameHeading("blackjack");
                printRules("blackjack");
                chooseBlackjack(username);
            }
            else if (number == 3)
            {
                printGameHeading("higherlower");
                printRules("higherlower"); 
                chooseHigherLower(username);               
            }
            else if (number == 4)
            {
                printGameHeading("trump");
                printRules("trump");
                chooseTrump(username);
            }
            else if (number == 5)
            {
                printGameHeading("oldmaid");
                printRules("oldmaid");
                chooseOldMaid(username);
            }
        }
        else
        {
            print("Invalid input, please reenter a number from 0-5", "red", true);
        }
    }
}

int main()
{
    // this is the  main function
    // it will print the heading of our game
    // go  into the the game chooser screen
    // and print the main ending once the user is  done playing
    string username;
    printMainHeading();
    print();
    wait();
    while (true)
    {
        print("Please enter your username: ", "green", true, "");
        getline(cin, username);
        if (username.find(' ') != string::npos)
        {
            print("Username cannot contain spaces!", "red", true);
        }
        else
        {
            break;
        }
        transform(username.begin(), username.end(), username.begin(), [](unsigned char c)
                  { return std::tolower(c); });
    }
    print();
    printData(username);
    updateFile(username);
    chooseGame(username);
    print();
    printMainEnding();
    return 0;
}
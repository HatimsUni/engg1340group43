#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/file_handler.h"
#include "../include/print_text.h"
#include "../include/sleep.h"
using namespace std;

struct Player
{
    // this is a structure of every player in the text file
    // it will keep track of the player's name, games_played, score for each game and total score
    string name;
    int games_played;
    int crazyeights;
    int blackjack;
    int higher_lower;
    int old_maid;
    int trump;
    int score;
};

vector<Player> createVector()
{
    // this function will create a vector of players based on the players in the txt file
    vector<Player> player_data;
    string line, word;
    string name;
    int games_played;
    int crazyeights;
    int blackjack;
    int higher_lower;
    int old_maid;
    int trump;
    int score;

    ifstream fin;
    fin.open("data/users.txt");
    if (fin.fail())
    {
        cout << "Error in opening file!" << endl;
    }
    else
    {
        while (getline(fin, line))
        {
            Player user;
            istringstream line_in(line);
            line_in >> word;
            user.name = word;
            line_in >> word;
            user.games_played = stoi(word);
            line_in >> word;
            user.crazyeights = stoi(word);
            line_in >> word;
            user.blackjack = stoi(word);
            line_in >> word;
            user.higher_lower = stoi(word);
            line_in >> word;
            user.old_maid = stoi(word);
            line_in >> word;
            user.trump = stoi(word);
            line_in >> word;
            user.score = stoi(word);
            player_data.push_back(user);
        }
    }
    fin.close();
    return player_data;
}

vector<string> getRules(string game_name)
{
    vector<string> rules;
    string line;
    ifstream fin;
    if (game_name == "blackjack")
    {
        fin.open("data/blackjack_rules.txt");
        while (getline(fin, line))
        {
            rules.push_back(line);
        }
        fin.close();
        return rules;
    }
    else if (game_name == "crazyeights")
    {
        fin.open("data/crazy_eights_rules.txt");
        while (getline(fin, line))
        {
            rules.push_back(line);
        }
        fin.close();
        return rules;
    }
    else if (game_name == "higherlower")
    {
        fin.open("data/higher_lower_rules.txt");
        while (getline(fin, line))
        {
            rules.push_back(line);
        }
        fin.close();
        return rules;
    }
    else if (game_name == "oldmaid")
    {
        fin.open("data/old_maid_rules.txt");
        while (getline(fin, line))
        {
            rules.push_back(line);
        }
        fin.close();
        return rules;
    }
    else if (game_name == "trump")
    {
        fin.open("data/trump_rules.txt");
        while (getline(fin, line))
        {
            rules.push_back(line);
        }
        fin.close();
        return rules;
    }
    return rules;
}

void printData(string username)
{
    // this function takes in the username as the input
    // it will loop through the txt file and print out any data that has the username
    // if the username is not found it will print that the player does not exist
    vector<Player> player_data = createVector();
    bool player_exists = false;
    for (int i = 0; i < player_data.size(); i++)
    {
        if (player_data[i].name == username && player_data[i].games_played != 0)
        {
            player_exists = true;
            print("You have played " + to_string(player_data[i].games_played) + " games", "cyan");
            print("Your total score is " + to_string(player_data[i].score), "blue");
            if (player_data[i].score == 0) {
                print("You don't have a medal yet, win games to get medals!", "cyan");
            } else {
                print("You have won a ", "magenta", "", "");
                printMedal(player_data[i].score);
                print();
            }
        }
    }
    if (player_exists == false)
    {
        print("This is your first time playing", "cyan");
        print("Win games to win medals!", "magenta", true);
    }
    wait();
    print();
}

void updateFile(string username, int games_played, int crazyeights, int blackjack, int higher_lower, int old_maid, int trump, int score)
{
    // this function will update the txt file
    // if the player is not found in the txt file it will create a new player with the corresponding score
    // if the player is found it will update that player's score in the txt file
    vector<Player> player_data = createVector();
    ofstream fout;
    bool player_exists = false;
    for (int i = 0; i < player_data.size(); i++)
    {
        if (player_data[i].name == username)
        {
            player_exists = true;
        }
    }
    if (player_exists == false)
    {
        fout.open("data/users.txt", ios::app);
        fout << username << " ";
        fout << games_played << " ";
        fout << crazyeights << " ";
        fout << blackjack << " ";
        fout << higher_lower << " ";
        fout << old_maid << " ";
        fout << trump << " ";
        fout << score << " ";
        fout << endl;
    }
    else if (player_exists == true)
    {
        fout.open("data/users.txt");
        for (int i = 0; i < player_data.size(); i++)
        {
            if (player_data[i].name == username)
            {
                player_data[i].games_played += games_played;
                player_data[i].crazyeights += crazyeights;
                player_data[i].blackjack += blackjack;
                player_data[i].higher_lower += higher_lower;
                player_data[i].old_maid += old_maid;
                player_data[i].trump += trump;
                player_data[i].score += score;
            }
        }
        for (int i = 0; i < player_data.size(); i++)
        {
            fout << player_data[i].name << " ";
            fout << player_data[i].games_played << " ";
            fout << player_data[i].crazyeights << " ";
            fout << player_data[i].blackjack << " ";
            fout << player_data[i].higher_lower << " ";
            fout << player_data[i].old_maid << " ";
            fout << player_data[i].trump << " ";
            fout << player_data[i].score << " ";
            fout << endl;
        }
    }
    fout.close();
}

void medal(string username)
{
    // this function takes in the username as input
    // it will look at the total score the player has
    // if the score is <= 10 it will print that you have a bronze medal
    // if the score is > 10 & <=20 it will print that you have a silver medal
    // if the score is > 20 it will print that you have a gold medal
    vector<Player> player_data = createVector();
    bool player_exists = false;
    for (int i = 0; i < player_data.size(); i++)
    {
        if (player_data[i].name == username)
        {
            player_exists = true;
            if (player_data[i].score <= 10)
            {
                cout << "You have a bronze medal";
            }
            else if ((player_data[i].score > 10) && (player_data[i].score <= 20))
            {
                cout << "You have a silver medal";
            }
            else if (player_data[i].score > 20)
            {
                cout << "You have a gold medal";
            }
        }
    }
    if (player_exists == false)
    {
        cout << "Player does not exist";
    }
}
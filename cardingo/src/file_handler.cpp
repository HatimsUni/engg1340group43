#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/file_handler.h"
using namespace std;

struct Player{
    string name;
    int games_played;
    int bigtwo;
    int blackjack;
    int higher_lower;
    int old_maid;
    int trump;
    int score;
};

vector<Player> create_vector(){
    vector<Player> player_data;
    string line, word;
    string name;
    int games_played;
    int bigtwo;
    int blackjack;
    int higher_lower;
    int old_maid;
    int trump;
    int score;
    
    ifstream fin;
    fin.open("games.txt");
    if(fin.fail()){
        cout << "Error in opening file!" << endl;
    } else {
        while(getline(fin, line)){
            Player user;
            istringstream line_in(line);
            line_in >> word;
            user.name = word;
            line_in >> word;
            user.games_played = stoi(word);
            line_in >> word;
            user.bigtwo = stoi(word);
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


void print_data(string username){
    vector<Player> player_data = create_vector();
    bool player_exists = false;
    for (int i = 0; i < player_data.size(); i++){
        if(player_data[i].name == username){
            cout << player_data[i].name;
            cout << player_data[i].games_played;
            cout << player_data[i].bigtwo;
            cout << player_data[i].blackjack;
            cout << player_data[i].higher_lower;
            cout << player_data[i].old_maid;
            cout << player_data[i].trump;
            cout << player_data[i].score << endl;
            player_exists = true;
        }
    }
    if (player_exists == false){
        cout << "Player does not exist";
    }
}

void update_file(string username, int games_played = 0, int bigtwo = 0, int blackjack = 0, int higher_lower = 0, int old_maid = 0, int trump = 0, int score = 0){
    vector<Player> player_data = create_vector();
    ofstream fout;
    bool player_exists = false;
    for(int i = 0; i < player_data.size(); i++){
        if(player_data[i].name == username){
            player_exists = true;
        }
    }
    if(player_exists == false){
        fout.open("games.txt", ios::app);
        fout << username << " ";
        fout << games_played << " ";
        fout << bigtwo << " ";
        fout << blackjack << " ";
        fout << higher_lower << " ";
        fout << old_maid << " ";
        fout << trump << " ";
        fout << score << " ";
        fout << endl;
    } else if(player_exists == true){
        fout.open("games.txt");
        for(int i = 0; i < player_data.size(); i++){
            if(player_data[i].name == username){
                player_data[i].games_played += games_played;
                player_data[i].bigtwo += bigtwo;
                player_data[i].blackjack += blackjack;
                player_data[i].higher_lower += higher_lower;
                player_data[i].old_maid += old_maid;
                player_data[i].trump += trump;
                player_data[i].score += score;
            } 
        }
        for(int i = 0; i < player_data.size(); i++){
            fout << player_data[i].name << " ";
            fout << player_data[i].games_played << " ";
            fout << player_data[i].bigtwo << " ";
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


void medal(string username){
    vector<Player> player_data = create_vector();
    bool player_exists = false;
    for (int i = 0; i < player_data.size(); i++){
        if(player_data[i].name == username){
            player_exists = true;
            if(player_data[i].score <= 10){
                cout << "You have a bronze medal";
            } else if((player_data[i].score >10) && (player_data[i].score <= 20)){
                cout << "You have a silver medal";
            } else if(player_data[i].score > 20){
                cout << "You have a gold medal";
            }
        }
    }
    if (player_exists == false){
        cout << "Player does not exist";
    }
}
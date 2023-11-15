// File: A2_S2_20221077_5.cpp
// Purpose: Manages a list of up to 10 players and their high scores.
// Author: Seif Eldin Khaled Rajab
// Section: S1,S2
// ID: 20221077
// TA: Eng/Khaled Ibrahim
// Date: 5 Nov 2023

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

// define a struct to represent a player with a name and a score
struct Player {
    string name;
    int score;
};

// define a custom comparison function for sorting players by score in descending order
bool comparePlayers(const Player& p1, const Player& p2) {
    return p1.score > p2.score;
}

int main() {
    vector<Player> playerList;
    const int maxPlayers = 10;

    // start an infinite loop to display the menu and process user choices
    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a new player and score\n";
        cout << "2. Print the top 10 players\n";
        cout << "3. Enter a player name and get their highest score\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1/2/3/4): ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            // check if there's room to add a new player
            if (playerList.size() < maxPlayers) {
                Player player;
                cout << "Enter player name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
                getline(cin, player.name); // i used getline built-in function insted of cin to read the entire player name with spaces
                cout << "Enter player score: ";
                cin >> player.score;
                playerList.push_back(player); // add the player to the list
            } else {
                cout << "List is full. Cannot add more players.\n";
            }
        } else if (choice == 2) {
            // sort the list of players by score in descending order
            sort(playerList.begin(), playerList.end(), comparePlayers);

            cout << "Top 10 players and their scores:\n";
            int count = min(static_cast<int>(playerList.size()), 10);
            for (int i = 0; i < count; i++) {
                cout << playerList[i].name << " " << playerList[i].score << endl;
            }
        } else if (choice == 3) {
            string playerName;
            cout << "Enter player name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
            getline(cin, playerName); // read the player's name

            int highestScore = -1;
            for (const Player& player : playerList) {
                if (player.name == playerName && player.score > highestScore) {
                    highestScore = player.score;
                }
            }

            if (highestScore != -1) {
                cout << playerName << "'s highest score is: " << highestScore << endl;
            } else {
                cout << "Player not found or not in the top 10.\n";
            }
        } else if (choice == 4) {
            break; // exit the program
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

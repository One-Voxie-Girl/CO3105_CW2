#include "player_choice.h"

Map player_choice(Map map) {
    vector<string> playerInput;
    string playerInputToken;
    string playerInputString;

    cout << "What do you want to do?" << endl;
    getline(cin, playerInputString);
    stringstream playerInputStream(playerInputString);
    while (getline(playerInputStream, playerInputToken, ' ')) {
        playerInput.push_back(playerInputToken);
    } // Splits the input string into individual words
    return map;
}
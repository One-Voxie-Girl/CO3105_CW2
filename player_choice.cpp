#include "player_choice.h"

void go(Map map, string input) {
    cout << "go";
}

void take(Map map, string input) {
    cout << "take";
}

void kill(Map map, string input){
    cout << "kill";
}

void look(Map map, string input) {
    cout << map.get_room(map.player.get_current_room()).get_desc() << endl;
}


void player_choice(Map map) {
    string playerInput;
    string input1; // Player
    string input2; // Command parameter

    std::map<string, int> inputHash = {
            {"go", 1},
            {"look", 2},
            {"take", 3},
            {"kill", 4}
             };

    cout << "What do you want to do?" << endl;
    getline(cin, playerInput);
    transform(playerInput.begin(), playerInput.end(), playerInput.begin(), ::tolower);
    istringstream inputStream(playerInput);
    inputStream >> input1 >> input2;
    while(!inputStream.eof()) {
        input2 += " ";
        string tempInput;
        inputStream >> tempInput;
        input2 += tempInput;
    } // Splits the input string into the command and the parameter
    cout << input1 << endl << input2 << endl;

    switch (inputHash[input1]) {
        case 1: // Command: go
            cout << "go true";
            break;
        case 2: // Command: look
            cout << "look true";
            break;
        case 3: // Command: take
            cout << "take true";
            break;
        case 4: // Command: kill
            cout << "kill true";
            break;
    }
}

#include "player_choice.h"

void go(Map &map, string input) {
    string roomid="";
    std::map<string, string> ex= map.rooms[map.get_room_id(map.player.get_room())].get_exits();
    roomid=ex[input];
    if  (roomid==""){
        cout << "exit not found" << endl;
    } else {
        map.player.set_room(roomid);
        cout << map.rooms[map.get_room_id(map.player.get_room())].print() << endl;
    }
}

void take(Map &map, string input) {
    // Check if item is in room
    Item I= map.rooms[map.get_room_id(map.player.get_room())].pop_item(input);
    if (I.get_id() == "null") {
        cout << "Item not found" << endl;

    } else {
        map.player.add_item(I);
        cout << "You have taken " << input << endl;
    }
    return;
}

void kill(Map &map, string input){
    cout << "kill";
}

void look(Map &map, string input) {
    cout << "look";
}

void list(Map &map) {
    cout << "You have the following items: " << endl;
    for (int i = 0; i < map.player.get_items().size(); i++) {
        cout << map.player.get_items().at(i).get_id() << endl;
    }
}


void player_choice(Map &map) {
    string playerInput;
    string input1; // Player
    string input2; // Command parameter

    std::map<string, int> inputHash = {
            {"go", 1},
            {"look", 2},
            {"take", 3},
            {"kill", 4},
            {"list", 5}
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
            go(map, input2);
            break;
        case 2: // Command: look
            cout << "look true";
            break;
        case 3: // Command: take
            take(map, input2);
            break;
        case 4: // Command: kill
            cout << "kill true";
            break;
        case 5: // Command: list
            list(map);
            break;
    }
}

#include "player_choice.h"

void go(Map &map, string input) {
    string roomid="";
    std::map<string, string> ex= map.rooms[map.get_room_id(map.player.get_room())].get_exits();
    roomid=ex[input];
    if  (roomid==""){
        cout << "exit not found" << endl;
    } else {
        map.player.set_room(roomid);
        if (map.objective.get_type()=="room"){
            map.objective.remove_target(roomid);
        }
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
        if (map.objective.get_type()=="collect") {
            map.objective.remove_target(input);
        }
    }
}

void kill(Map &map, string input){
    vector<string> lookEnemies = map.rooms[map.get_room_id(map.player.get_room())].get_enemies_ids();
    if (find(lookEnemies.begin(), lookEnemies.end(), input) != lookEnemies.end()) {
        Enemy E= map.rooms[map.get_room_id(map.player.get_room())].get_enemy(input);
        vector<string> killedby=E.get_killed_by();

        int killedBySize = E.get_killed_by().size();
        for (int i = 0; i < map.player.get_items().size(); i++) {

            if (find(killedby.begin(), killedby.end(), map.player.get_items().at(i).get_id()) != killedby.end()) {
                killedBySize--;
            }
        }
        if (killedBySize == 0) {
            cout << "You have killed " << input << endl;
            if (map.objective.get_type()=="kill") {
                map.objective.remove_target(input);
            }
            map.rooms[map.get_room_id(map.player.get_room())].pop_enemy(input);
        } else {
            cout << "You do not have the required items to kill " << input << "\nThe enemy retaliates"<< endl;
            map.player.set_health(map.player.get_health()-1);
            cout << "Current health: " << map.player.get_health() << endl;
        }
    } else {
        cout << "Enemy not found" << endl;
    }
}

void look(Map &map, string input) {
    string lookOutput;
    vector<string> lookEnemies = map.rooms[map.get_room_id(map.player.get_room())].get_enemies_ids();
    vector<string> lookItems = map.rooms[map.get_room_id(map.player.get_room())].get_items_ids();
    if (input == "around" or input.empty()) {
        lookOutput = map.rooms[map.get_room_id(map.player.get_room())].print();
    } else if (find(lookEnemies.begin(), lookEnemies.end(), input) != lookEnemies.end()) {
        lookOutput = map.rooms[map.get_room_id(map.player.get_room())].get_enemy(input).get_desc();
    } else if (find(lookItems.begin(), lookItems.end(), input) != lookItems.end()) {
        lookOutput = map.rooms[map.get_room_id(map.player.get_room())].get_item(input).get_desc();
    } else {
        lookOutput = "No item/enemy of that name";
    }
    cout << lookOutput << endl;
}

void list(Map &map, string input) {
    if (input == "items") {
        if (map.player.get_items().empty()) {
            cout << "You have no items" << endl;
            return;
        }else{
            cout << "You have the following items: " << endl;
            for (int i = 0; i < map.player.get_items().size(); i++) {
                cout << map.player.get_items().at(i).get_id() << endl;
            }
        }
    }else{
        cout<<"list what???"<<endl;
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
            {"list", 5},
            {"move", 1}
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

    switch (inputHash[input1]) {
        case 1: // Command: go
            go(map, input2);
            break;
        case 2: // Command: look
            look(map, input2);
            break;
        case 3: // Command: take
            take(map, input2);
            break;
        case 4: // Command: kill
            kill(map, input2);
            break;
        case 5: // Command: list
            list(map, input2);
            break;
        default:
            cout << "Command not found" << endl;
            break;
    }
}

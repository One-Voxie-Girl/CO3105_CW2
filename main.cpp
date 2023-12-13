#include <iostream>
#include <filesystem>
#include "map_parser.h"
#include "Classes/Map/Map.h"
#include "player_choice.h"
namespace fs = filesystem;

int main(int argc, char* argv[]) {
    string path = "..\\maps\\";
    string mapSelection;
    cout << "LIST OF AVAILABLE MAPS:" << endl;
    for (const auto & entry : fs::directory_iterator(path))
        cout << entry.path().stem().string() << endl; // Prints list of files in maps folder
    cout << "Which map would you like to play? " << endl;
    cin >> mapSelection;
    while (!fs::exists("..\\maps\\" + mapSelection + ".json")) { // Checks if filename inputted exists
        cout << "Invalid map name" << endl;
        cin >> mapSelection;
    }

    json j = read_map_data("..\\maps\\" + mapSelection + ".json"); // Reads JSON file
    Map map = init_map(j);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i = 0; i < 100; i++) {
        cout << endl;
    }
    cout << map.rooms[map.get_room_id(map.player.get_room())].print() << endl; // Prints initial room

    while (true){ // Main gameplay loop
        player_choice(map);
        if (map.objective.check_obj(map.player)) { // If all objectives are complete
            cout << "GAME COMPLETE!" << endl;
            break;
        } else if (map.player.get_health() < 1) { // If the player died
            cout << "Your have died" <<"\nGAME OVER" << endl;
            break;
        }
    }
    return 0;
}

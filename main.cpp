#include <iostream>
#include "map_parser.h"
#include "Classes/Map/Map.h"
#include "player_choice.h"

int main(int argc, char* argv[]) {
    json j = read_map_data("..\\maps\\map1.json");
    Map map = init_map(j);
//    cout << map.print() << endl;
    cout << map.rooms[map.get_room_id(map.player.get_room())].print() << endl;
    while (true){
        player_choice(map);
        if (map.objective.check_obj(map.player)) {
            cout << "GAME COMPLETE!" << endl;
            break;
        } else if (map.player.get_health() < 1) {
            cout << "Your have died" <<"\nGAME OVER" << endl;
            break;
        }
    }
    return 0;
}

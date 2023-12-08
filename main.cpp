#include <iostream>
#include "map_parser.h"
#include "Classes/Map/Map.h"
#include "player_choice.h"

int main(int argc, char* argv[]) {
    json j = read_map_data("C:\\Users\\leemi\\CLionProjects\\CO3105_CW2\\maps\\map1.json");
    Map map = init_map(j);
    cout << map.print() << endl;
    player_choice(map);
    return 0;
}

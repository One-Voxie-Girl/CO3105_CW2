#include <iostream>
#include "map_parser.h"
#include "Classes/Map/Map.h"

int main(int argc, char* argv[]) {
    json j = read_map_data("..\\maps\\map1.json");
    Map map = init_map(j);
    cout << map.print() << endl;
    auto b =map.rooms[0].get_exit("east");

    return 0;
}

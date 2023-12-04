#include <iostream>
#include "map_parser.h"
#include "Classes/Map/Map.h"

int main(int argc, char* argv[]) {
    json j = read_map_data("C:\\Users\\onevo\\CLionProjects\\CPP\\CO3105_CW2\\maps\\map1.json");
    Map map = init_map(j);
    cout << map.print() << endl;
    return 0;
}

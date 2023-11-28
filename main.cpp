#include <iostream>
#include "map_parser.h"
#include "Classes/Map/Map.h"

int main(int argc, char* argv[]) {
    json j = read_map_data("C:\\Users\\Temmie\\Clion Projects\\CO3105_CW2\\maps\\map1.json");
    std::cout << j << std::endl;
    return 0;
}

#include <iostream>
#include "map_parser.h"

int main(int argc, char* argv[]) {
    json j = read_map_data("map1.json");
    std::cout << j << std::endl;
    return 0;
}

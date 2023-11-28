//
// Created by Temmie on 27/11/2023.
//

#include "map_parser.h"

// read map data from file
json read_map_data(string filename) {

    ifstream file(filename);
    stringstream buffer;
    buffer << file.rdbuf();
    auto data = json::parse(buffer.str());
    file.close();
    return data;
}





//
// Created by Temmie on 27/11/2023.
//
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using json = nlohmann::json;

#ifndef CO3105_CW2_MAP_PARSER_H
#define CO3105_CW2_MAP_PARSER_H

// read Map data from file
json read_map_data(string filename) ;



#endif //CO3105_CW2_MAP_PARSER_H

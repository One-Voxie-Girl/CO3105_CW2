//
// Created by Temmie on 27/11/2023.
//

#include "map_parser.h"

// read Map data from file
json read_map_data(string filename) {

    ifstream file(filename);
    stringstream buffer;
    buffer << file.rdbuf();
    auto data = json::parse(buffer.str());
    file.close();
    return data;
}

// Initialise Map from json data
Map init_map(json data) {
    Map map;

    for (auto r:data["rooms"]){
        Room room(r["id"], r["desc"], r["exits"]);
        map.add_room(room);
    }

    for (auto e:data["enemies"]){
        Enemy enemy(e["id"], e["desc"], e["aggressiveness"], e["killedby"]);
        map.rooms[map.get_room_id(e["initialroom"])].add_enemy(enemy);
    }

    for (auto o:data["objects"]){
        Item item(o["id"], o["desc"]);
        map.rooms[map.get_room_id(o["initialroom"])].add_item(item);
    }
    Player player(data["player"]["initialroom"]);



    return map;
}




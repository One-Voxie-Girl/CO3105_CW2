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
        Room room;
        room.set_id(r["id"]);
        room.set_desc(r["desc"]);
        room.set_exits(r["exits"]);
        map.add_room(room);
    }

    for (auto e:data["enemies"]){
        Enemy enemy;
        enemy.set_id(e["id"]);
        enemy.set_desc(e["desc"]);
        enemy.set_aggression(e["aggressiveness"]);
        enemy.set_killedBy(e["killedby"]);
        map.get_room(e["initialroom"]);

        map.rooms[map.get_room_id(e["initialroom"])].add_enemy(enemy);

    }

    return map;
}




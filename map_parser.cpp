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
    Player player(data["player"]["initialroom"]);
    Objective obj(data["objective"]["type"],data["objective"]["what"]);
    Map map(player,obj);

    for (auto r:data["rooms"]){
        std::map<string,string> q;
        for (auto e:r["exits"].items()){
            q[e.key()] = e.value();        }
        Room room(r["id"], r["desc"], q);
        map.add_room(room);
    }

    for (auto e:data["enemies"]){
        Enemy enemy(e["id"], e["desc"], e["aggressiveness"], e["killedby"]);
        map.rooms[map.get_room_id(e["initialroom"])].add_enemy(enemy);
    }

    for (auto o:data["objects"]){
        string t=o["type"];
        try {
            t = o["type"];

        } catch (nlohmann::detail::type_error &e) {
            t="";
        }

        Item item(o["id"], o["desc"],t);
        map.rooms[map.get_room_id(o["initialroom"])].add_item(item);
    }



    return map;
}




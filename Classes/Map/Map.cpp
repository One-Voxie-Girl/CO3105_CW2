//
// Created by Temmie on 28/11/2023.
//

#include "Map.h"

#include <utility>

Map::Map(Player player, Objective objective) : player(std::move(player)), objective(objective) {
    room_count = 0;


}

bool Map::add_room(Room room) {
    rooms.push_back(room);
    room_ids[room.get_id()] = room_count;
    room_count++;
    return true;
}

int Map::get_room_count() {
    return room_count;
}

int Map::get_room_id(string id) {
    return room_ids[id];
}

Room Map::get_room(string id) {
    return rooms.at(room_ids[id]);
}

string Map::print() {
    string output = "";
    output += "Rooms: "+to_string(room_count)+"\n";
    for (int i = 0; i < rooms.size(); i++) {
        output += rooms.at(i).print() + "\n";
    }
    return output;
}

bool Map::add_player(Player player) {
    this->player = player;
    return true;
}

bool Map::add_objective(Objective objective) {
    this->objective=objective;
    return true;
}
//
// Created by Temmie on 28/11/2023.
//

#include "Room.h"

Room::Room() {



}

bool Room::set_id(string id) {
    this->id = id;
    return true;
}

bool Room::set_desc(string desc) {
    this->desc = desc;
    return true;
}

bool Room::set_exits(json exits) {
    this->exits = exits;
    return true;
}

string Room::get_id() {
    return id;
}

bool Room::add_enemy(Enemy enemy) {
    enemies.push_back(enemy);
    return true;
}

vector<Enemy> Room::get_enemies() {
    return enemies;
}

string Room::print() {
    string output = "";
    output += "Room: "+id+"\n";
    output += "Desc: "+desc+"\n";
    output += "Exits: "+exits.dump()+"\n";
    output += "Enemies: "+to_string(enemies.size())+"\n";
    for (int i = 0; i < enemies.size(); i++) {
        output += enemies.at(i).print() + "\n";
    }
    return output;
}
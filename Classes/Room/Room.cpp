//
// Created by Temmie on 28/11/2023.
//

#include "Room.h"



Room::Room(string id, string desc, json exits) {
    this->id = id;
    this->desc = desc;
    this->exits = exits;
}

bool Room::set_id(string newid) {
    this->id = newid;
    return true;
}

bool Room::set_desc(string newdesc) {
    this->desc = newdesc;
    return true;
}

bool Room::set_exits(json newexits) {
    this->exits = newexits;
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
    output += "Items: "+to_string(items.size())+"\n";
    for (int i = 0; i < items.size(); i++) {
        output += items.at(i).print() + "\n";
    }

    return output;
}

bool Room::add_item(Item item) {
    items.push_back(item);
    return true;
}

vector<Item> Room::get_items() {
    return items;
}



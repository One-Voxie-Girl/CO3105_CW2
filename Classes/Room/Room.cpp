//
// Created by Temmie on 28/11/2023.
//

#include "Room.h"



Room::Room(string id, string desc, map<string, string> exits) {
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
    output += "Desc: "+desc+"\n";
    output += "Items: ";
    for (int i = 0; i < items.size(); i++) {
        if (i == items.size()-1) {
            output += items.at(i).get_id();
            break;
        }
        output += items.at(i).get_id() + ",";
    }
    output += "\nEnemies: ";
    for (int i = 0; i < enemies.size(); i++) {
        if (i == enemies.size()-1) {
            output += enemies.at(i).get_id();
            break;
        }
        output += enemies.at(i).get_id() + ", ";
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

Item Room::pop_item(string id) {
    for (int i = 0; i < items.size(); i++) {
        if (items.at(i).get_id() == id) {
            Item item = items.at(i);
            items.erase(items.begin()+i);
            return item;
        }
    }
    return Item("null","","null");

}

Enemy Room::pop_enemy(string id) {
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies.at(i).get_id() == id) {
            Enemy enemy = enemies.at(i);
            enemies.erase(enemies.begin()+i);
            return enemy;
        }
    }
}

map<string, string> Room::get_exits() {
    return exits;
}

string Room::get_exit(string direction) {
    return exits[direction];
}

string Room::get_desc() {
    return desc;
}

vector<string> Room::get_enemies_ids() {
    vector<string> ids;
    for (int i = 0; i < enemies.size(); i++) {
        ids.push_back(enemies.at(i).get_id());
    }
    return ids;
}

vector<string> Room::get_items_ids() {
    vector<string> ids;
    for (int i = 0; i < items.size(); i++) {
        ids.push_back(items.at(i).get_id());
    }
    return ids;
}

Enemy Room::get_enemy(string id){
    for (int i = 0; i<enemies.size();i++){
        if (enemies[i].get_id()==id){
            return enemies[i];
        }
    }
}

Item Room::get_item(string id){
    for (int i = 0; i<items.size();i++){
        if (items[i].get_id()==id){
            return items[i];
        }
    }
}
